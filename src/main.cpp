#include <iostream>

#include "biblioteca.cpp"
#include "usuario.cpp"
#include "artista.cpp"
#include "lista_musicas.cpp"


int main() {

    std::vector <int> musicas = {0, 1, 2, 3, 4, 5};

    Album album1 = Album(1, musicas);
    Album album2 = Album(1, musicas);
    Album album3 = Album(1, musicas);

    Playlist playlist1 = Playlist(2, musicas);
    Playlist playlist2 = Playlist(2, musicas);
    Playlist playlist3 = Playlist(2, musicas);

    Biblioteca biblioteca_artista1 = Biblioteca();
    Biblioteca biblioteca_usuario1 = Biblioteca();

    biblioteca_artista1.inserir_item(album1);
    biblioteca_artista1.inserir_item(album2);
    biblioteca_artista1.inserir_item(album3);

    biblioteca_artista1.listar_itens();

    biblioteca_artista1.excluir_item(album2);

    biblioteca_artista1.listar_itens();

    return 0;
}