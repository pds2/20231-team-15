#include <iostream>
#include <string>
#include <vector>
#include <gtkmm.h>
#include "../include/musica.h"

int main(int argc, char* argv[])
{
    std::string musicas_path = "./musicas.csv";

    Musica musicas;
    std::vector<Musica> listaMusicas = musicas.ler_musicas_do_csv(musicas_path);

    //Função para imprimir os detalhes de todas as músicas
    for (auto i = listaMusicas.begin(); i < listaMusicas.end(); i++) {
        i->imprimir_detalhes();
    }

    // Constroi app do GTK
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    // Build UI from the XML file
    auto builder = Gtk::Builder::create();
    builder->add_from_file("my-ui.glade");

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

    // Widget lista de músicas
    Gtk::ListBox* music_list_box = nullptr;
    builder->get_widget("music-list-box", music_list_box);

    // Widget musica-item
    auto builder2 = Gtk::Builder::create();
    builder2->add_from_file("music-item.xml");
    Gtk::Widget* music_item = nullptr;
    builder2->get_widget("music-item", music_item);
    music_list_box->add(*music_item);

    return app->run(*window);
}
