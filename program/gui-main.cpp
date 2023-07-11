#include <iostream>
#include <string>
#include <vector>
#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/listbox.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#include <gtkmm/dialog.h>
#include "../include/music_item_widget.h"
#include "../include/musica.h"

MusicItem* createMusicItem(
    Glib::RefPtr<Gtk::Builder> builder, 
    Musica* data
)
{
    MusicItem* music_item = nullptr;

    // Constrói widget music_item do arquivo de ui
    builder->add_from_file("music-item.xml");
    builder->get_widget_derived("music-item", music_item);

    // Define campos do widget music_item.
    music_item->setData(data);
    std::string cover_path = "./images/covers/"+std::to_string(data->get_id())+".png";
    music_item->setTitle(data->get_titulo());
    music_item->setArtist(data->get_artista());
    music_item->setCover(cover_path);
    music_item->setDuration(std::to_string(data->get_ano()));

    return music_item;
}

class LibraryList : public Gtk::ListBox {
public:
    LibraryList(
        BaseObjectType* cobject, 
        const Glib::RefPtr<Gtk::Builder>& builder
    ) : 
        Gtk::ListBox(cobject), builder{builder} 
    {}

    virtual ~LibraryList() {};

    void appendMusic(MusicItem* music_item) {
        Musica* data = music_item->getData();

        // Create new MusicItem widget from "data"
        auto music_builder = Gtk::Builder::create_from_file("music-item.xml");
        MusicItem* new_music_item = createMusicItem(music_builder, data);

        // Append new MusicItem to library_list
        this->append(*new_music_item);
    }

    void removeMusic(MusicItem* music_item) {
        int id = music_item->getData()->get_id();
        std::vector<Gtk::Widget *> children = this->get_children();

        for (auto child : children) {
            auto row = dynamic_cast<Gtk::ListBoxRow*>(child);
            auto item = dynamic_cast<MusicItem*>(row->get_child());

            // Row could not be casted to MusicItem.
            if (item == nullptr) {
                continue;
            }
            
            int current_id = item->getData()->get_id();
            // Remove item with id of unliked item
            if (current_id == id) {
                this->remove(*child);
            }
        }


    }

private:
    Glib::RefPtr<Gtk::Builder> builder;
};

int main(int argc, char* argv[])
{
    std::string musicas_path = "./musicas.csv";

    Musica musicas;
    std::vector<Musica> lista_musica = musicas.ler_musicas_do_csv(musicas_path);
    int like_count = 0;

    // Constroi app do GTK
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    // Build UI from the XML file
    auto builder = Gtk::Builder::create_from_file("my-ui.glade");

    // Load the CSS file
    auto cssProvider = Gtk::CssProvider::create();
    cssProvider->load_from_path("style.css");

    // Apply the CSS styles to the default screen
    auto screen = Gdk::Screen::get_default();
    auto styleContext = Gtk::StyleContext::create();
    styleContext->add_provider_for_screen(screen, cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Get window and show all child widgets
    Gtk::Window* window = nullptr;
    builder->get_widget("my_window", window);
    window->show_all();
    window->maximize();

    //  ### GET WIDGETS FROM UI FILE ###

    // Song ListBox
    Gtk::ListBox* music_list_box = nullptr;
    builder->get_widget("music-list-box", music_list_box);

    // Library list
    LibraryList* library_list = nullptr;
    builder->get_widget_derived("library-list", library_list);

    // Dialog
    Gtk::Dialog* dialog = nullptr;
    Gtk::ListBox* song_list_liked = nullptr;

    builder->get_widget("dialog", dialog);
    builder->get_widget("song-list-liked", song_list_liked);

    // Playlist liked
    Gtk::Box* playlist_liked = nullptr;
    Gtk::Label* song_count_label = nullptr;

    builder->get_widget("playlist-liked", playlist_liked);
    builder->get_widget("song-count", song_count_label);
    song_count_label->set_label(std::to_string(like_count) + " músicas");

    // Show dialog
    playlist_liked->signal_button_press_event().connect([dialog](GdkEventButton* event) -> bool {
        
        std::cout << "CLICKED" << std::endl;

        dialog->set_default_size(700, 700);
        dialog->show_all();
        int response = dialog->run();

        return true;
    });

    // ### EXIBE TODAS AS MÚSICAS ###
    builder = Gtk::Builder::create();

    Musica* musica;
    auto it = lista_musica.begin();
    for (int i = 0; i < 10; i++) {  
        it += i;
        musica = &(*it);

        // Cria widget music_item
        MusicItem* music_item = createMusicItem(
            builder, 
            musica
        );


        // Liked signal
        music_item->signal_liked().connect([
            &like_count, 
            library_list, 
            song_count_label,
            song_list_liked,
            builder](MusicItem* music_item) {
            
            like_count++;
            library_list->appendMusic(music_item);

            song_count_label->set_label(std::to_string(like_count) + " músicas");
            std::cout << "LIKE: " <<  like_count << std::endl;

            // Adiciona música em song-list-liked
            MusicItem* new_music_item = createMusicItem(builder, music_item->getData());
            song_list_liked->append(*new_music_item);
        });

        // Unliked signal
        music_item->signal_unliked()
            .connect(sigc::mem_fun(library_list, &LibraryList::removeMusic));

        music_item->signal_unliked().connect([&like_count, library_list, song_count_label](MusicItem* music_item) {
            
            like_count--;
            library_list->removeMusic(music_item);

            song_count_label->set_label(std::to_string(like_count) + " músicas");
            std::cout << "UNLIKE: " <<  like_count << std::endl;
        });

        // Adiciona music_item ao ListBox
        music_list_box->append(*music_item);
    }

    return app->run(*window);
}
