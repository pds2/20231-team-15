#include "../include/lista_musicas.hpp"

int ListaMusicas::contador_id_lista_musicas = 0;

ListaMusicas::ListaMusicas(const std::vector <int> & lista_musicas) {
    _id_lista_musicas = ++contador_id_lista_musicas;
    m_lista_musicas = lista_musicas;
};

int ListaMusicas::get_id_lista_musicas() const {
    return _id_lista_musicas;
};

void ListaMusicas::printar() {
    std::cout << _id_lista_musicas << std::endl;
};
