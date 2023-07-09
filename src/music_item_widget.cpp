#include "../include/music_item_widget.h"

MusicItem::MusicItem(
    BaseObjectType* cobject, 
    const Glib::RefPtr<Gtk::Builder>& builder
) : 
    Gtk::Box(cobject), builder{builder},
    cover{nullptr}, 
    title{nullptr},
    artist{nullptr},
    duration{nullptr}
{
    // Seleciona widgets do builder.
    builder->get_widget("cover", cover);
    builder->get_widget("title", title);
    builder->get_widget("artist", artist);
    builder->get_widget("duration", duration);
}

MusicItem::~MusicItem() {};

void MusicItem::setCover(const std::string& file_path) {
    auto pixbuf = Gdk::Pixbuf::create_from_file(file_path);
    pixbuf = pixbuf->scale_simple(80, 80, Gdk::INTERP_BILINEAR);

    cover->set(pixbuf);
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