#include "../include/lista_musicas.hpp"

ListaMusicas::ListaMusicas() {
    _id_lista_musicas = ++contador_id_lista_musicas;
};

ListaMusicas::ListaMusicas(const std::vector <int> & lista_musicas) {
    _id_lista_musicas = ++contador_id_lista_musicas;
    v_lista_musicas = lista_musicas;
};