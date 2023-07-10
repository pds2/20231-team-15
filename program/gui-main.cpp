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

    return music_item;
}

void handleLikeClicked(MusicItem* music_item) {
    std::cout << "De fora funcionou kkkk" << std::endl;
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

protected:
    Glib::RefPtr<Gtk::Builder> builder;
};

int main(int argc, char* argv[])
{
    std::string musicas_path = "./musicas.csv";

    Musica musicas;
    std::vector<Musica> lista_musica = musicas.ler_musicas_do_csv(musicas_path);

    //Função para imprimir os detalhes de todas as músicas
    // for (auto i = lista_musica.begin(); i < lista_musica.end(); i++) {
    //     i->imprimir_detalhes();
    // }

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

    // Song ListBox
    Gtk::ListBox* music_list_box = nullptr;
    builder->get_widget("music-list-box", music_list_box);

    LibraryList* library_list = nullptr;
    builder->get_widget_derived("library-list", library_list);

    // ### EXIBE TODAS AS MÚSICAS ###
    builder = Gtk::Builder::create();

    auto it = lista_musica.begin();
    Musica musica;
    for (int i = 0; i < 10; i++) {  
        it += i;
        musica = *it;

        // Cria widget music_item
        MusicItem* music_item = createMusicItem(
            builder, 
            &musica
        );

        // music_item->signal_like_clicked().connect(sigc::ptr_fun(&handleLikeClicked));
        music_item->signal_like_clicked()
            .connect(sigc::mem_fun(library_list, &LibraryList::appendMusic));
        // sigc::mem_fun(&listBox, &MyCustomListBox::onLikeButtonClicked)

        // Adiciona music_item ao ListBox
        music_list_box->append(*music_item);
    }

    return app->run(*window);
}
