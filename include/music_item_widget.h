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
#include <gtkmm/eventbox.h>

class MusicItem : public Gtk::Box {
public:
    MusicItem(
        BaseObjectType* cobject, 
        const Glib::RefPtr<Gtk::Builder>& builder,
        bool is_playlist = false
    );
    virtual ~MusicItem();
    void setTitle(const std::string& str);
    void setCover(const std::string& file_path);
    void setArtist(const std::string& str);
    void setDuration(const std::string& str);

protected:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Box* cover_wrapper;
    Gtk::Image* type_icon;
    Gtk::Label* type_text;
    Gtk::EventBox* like_wrapper;
    Gtk::Label* title;
    Gtk::Label* artist;
    Gtk::Image* artist_icon;
    Gtk::Label* duration;

    bool onLikeClicked(GdkEventButton* event);
};

#endif