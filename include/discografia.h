#ifndef TP2_DISCOGRAFIA
#define TP2_DISCOGRAFIA

#include <memory>
#include <vector>

#include "album.h"

class Discografia {
    public: 
        Discografia();
        void listar_itens();
        void inserir_item(const Album &item);
        void excluir_item(const Album &item);

    private:
        std::vector<Album> m_discografia;
};

#endif