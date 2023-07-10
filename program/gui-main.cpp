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

    // Library ListBox
    Gtk::ListBox* library_list = nullptr;
    builder->get_widget("library-list", library_list);

    // ### EXIBE TODAS AS MÚSICAS ###
    builder = Gtk::Builder::create();

    MusicItem* music_item = nullptr;
    auto it = lista_musica.begin();
    Musica musica;
    for (int i = 0; i < 10; i++) {  
        it += i;
        musica = *it;

        // Constrói widget music_item do arquivo de ui
        builder->add_from_file("music-item.xml");
        builder->get_widget_derived("music-item", music_item);

        // Define campos do music_item
        music_item->setId(musica.get_id());
        music_item->setListaMusica(&lista_musica);
        std::string cover_path = "./images/covers/"+std::to_string(musica.get_id())+".png";
        music_item->setTitle(musica.get_titulo());
        music_item->setArtist(musica.get_artista());
        music_item->setCover(cover_path);

        // Adiciona music_item ao ListBox
        music_list_box->append(*music_item);
    }

    // ### INSERE PLAYLIST NA BIBLIOTECA ###
    MusicItem* playlist_item = nullptr;
    builder->add_from_file("music-item.xml");
    builder->get_widget_derived("music-item", playlist_item, true);

    library_list->append(*playlist_item);
    playlist_item->setArtist("15 músicas");
    playlist_item->setCover("./images/icons/playlist-icon.png");

    return app->run(*window);
}
