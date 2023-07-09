/*
    Derived widget from Gtk::Box.

    Widget para facilitar a criação de elementos music_item.
*/

#ifndef MUSIC_ITEM_WIDGET
#define MUSIC_ITEM_WIDGET

#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/builder.h>

class MusicItem : public Gtk::Box {
public:
    MusicItem(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~MusicItem();
    void setTitle(const std::string& str);
    void setCover(const std::string& file_path);
    void setArtist(const std::string& str);
    void setDuration(const std::string& str);

protected:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Image* cover;
    Gtk::Label* title;
    Gtk::Label* artist;
    Gtk::Label* duration;
};

#endif