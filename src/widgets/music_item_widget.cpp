#include <iostream>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include "../include/music_item_widget.h"

MusicItem::MusicItem(
    BaseObjectType* cobject, 
    const Glib::RefPtr<Gtk::Builder>& builder,
    bool is_playlist
) : 
    Gtk::Box(cobject), builder{builder},
    data{nullptr},
    cover_wrapper{nullptr},
    type_icon{nullptr},
    type_text{nullptr},
    like_wrapper{nullptr},
    like_icon{nullptr},
    title{nullptr},
    artist{nullptr},
    artist_icon{nullptr},
    duration{nullptr}
{
    // Get widgets from the ui file
    builder->get_widget("cover-wrapper", cover_wrapper);
    builder->get_widget("type-icon", type_icon);
    builder->get_widget("type-text", type_text);
    builder->get_widget("like-wrapper", like_wrapper);
    builder->get_widget("like-icon", like_icon);
    builder->get_widget("title", title);
    builder->get_widget("artist", artist);
    builder->get_widget("artist-icon", artist_icon);
    builder->get_widget("duration", duration);

    // Add handler to like-wrapper
    like_wrapper->signal_button_press_event().connect(
        sigc::mem_fun(*this, &MusicItem::onLikeClicked)
    );

    // Check if Widget is not a playlist
    if (!is_playlist) {
        type_text->hide();
        return;
    }

    // Widget is a playlist. Add styles related to the playlist item.    
    duration->hide();
    like_wrapper->hide();
    type_icon->hide();
    artist_icon->hide();
}

MusicItem::~MusicItem() {};

void MusicItem::setData(Musica* data)  {
    this->data = data;
}

Musica* MusicItem::getData() {
    return data;
}

void MusicItem::setCover(const std::string& file_path) {
    // Cover size
    cover_wrapper->set_size_request(80, 80);

    auto styleContext = cover_wrapper->get_style_context();
    auto cssProvider = Gtk::CssProvider::create();

    // Set background-image to cover image
    std::string css_data = "box {"
                          "   background-image: url('" + file_path + "');"
                          "}";

    // Apply css to music-item
    cssProvider->load_from_data(css_data);
    styleContext->add_provider(cssProvider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void MusicItem::setTitle(const std::string& str) {
    title->set_label(str);
}

void MusicItem::setArtist(const std::string& str) {
    artist->set_label(str);
}

void MusicItem::setDuration(const std::string& str) {
    duration->set_label(str);
}

void MusicItem::setLike(bool is_liked) {
    std::string heart_path = "./images/icons/heart-icon.png";
    std::string heart_filled_path = "./images/icons/heart-solid-icon.png";

    // Update data
    data->set_is_liked(is_liked);

    // Update icon
    if (is_liked) 
        like_icon->set(heart_filled_path);
    else 
        like_icon->set(heart_path);
}

bool MusicItem::onLikeClicked(GdkEventButton* event) {
    bool is_liked = !(data->get_is_liked());

    // MusicItem was liked
    if (is_liked) 
        signal_liked_.emit(this); // Emit liked signal.
    else
        signal_unliked_.emit(this); // Emit unliked sigal.

    return true;
}

// Signals
sigc::signal<void, MusicItem*> MusicItem::signal_liked() {
    return signal_liked_;
}

sigc::signal<void, MusicItem*> MusicItem::signal_unliked() {
    return signal_unliked_;
}