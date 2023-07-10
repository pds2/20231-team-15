#ifndef DISCOGRAFIA
#define DISCOGRAFIA

#include <vector>

#include "conjunto_listas.h"
#include "artista.h"
#include "album.h"

class Discografia : public Conjunto_listas {
    public: 
        Discografia(const Artista& artista);
        void listar_itens();
        void inserir_item(const Album &item);
        void excluir_item(int id);

    private:
        Artista _artista;
        std::vector<Album> m_discografia;
};

#endif