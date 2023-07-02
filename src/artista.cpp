#include "../include/artista.hpp"

Album::Album(const int &id_artista, std::vector <int> lista_musicas) : ListaMusicas(lista_musicas) {
    _id_artista = id_artista;
    // ListaMusicas::m_lista_musicas = lista_musicas;
};