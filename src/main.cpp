#include <iostream>
#include <gtkmm.h>

int main(int argc, char* argv[])
{
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

  return app->run(*window);
}
