#ifndef DISCOGRAFIA_H
#define DISCOGRAFIA_H

#include <vector>

#include "conjunto_listas.h"
#include "artista.h"
#include "album.h"

/**

    @class Discografia

    @brief Representa a discografia de um artista.

    A classe Discografia é derivada da classe Conjunto_listas e contém uma coleção de álbuns de um artista específico.
**/
    class Discografia : public Conjunto_listas {
    public:
    /*
        @brief Construtor da classe Discografia.
        @param artista O artista cuja discografia é representada.
        */
        Discografia(const Artista& artista);

    /**
        @brief Lista todos os itens da discografia.
        */
        void listar_itens();

    /**
        @brief Insere um item (álbum) na discografia.
        @param item O álbum a ser inserido.
        */
        void inserir_item(const Album &item);

    private:
        Artista _artista; // O artista cuja discografia é representada 
        std::vector<Album> m_discografia; // Coleção de álbuns da discografia 
};

#endif // DISCOGRAFIA_H