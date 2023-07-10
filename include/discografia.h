#ifndef DISCOGRAFIA
#define DISCOGRAFIA

#include <memory>
#include <vector>

#include "conjunto_listas.h"
#include "album.h"

class Discografia : public Conjunto_listas {
    public: 
        Discografia();
        void listar_itens();
        void inserir_item(const Album &item);
        void excluir_item(const Album &item);

    private:
        std::vector<Album> m_discografia;
};

#endif