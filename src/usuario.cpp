#include "../include/usuario.hpp"

Playlist::Playlist(const int &id_usuario, std::vector <int> lista_musicas) : ListaMusicas(lista_musicas) {
    _id_usuario = id_usuario;
    // ListaMusicas(lista_musicas);
};