#include "../include/music_item_widget.h"
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>


MusicItem::MusicItem(
    BaseObjectType* cobject, 
    const Glib::RefPtr<Gtk::Builder>& builder
) : 
    Gtk::Box(cobject), builder{builder},
    cover_wrapper{nullptr},
    title{nullptr},
    artist{nullptr},
    duration{nullptr}
{
    // Get widgets from the ui file
    builder->get_widget("cover-wrapper", cover_wrapper);
    builder->get_widget("title", title);
    builder->get_widget("artist", artist);
    builder->get_widget("duration", duration);
}

MusicItem::~MusicItem() {};

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