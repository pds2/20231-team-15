#ifndef CONJUNTO_LISTAS
#define CONJUNTO_LISTAS

#include <memory>
#include <vector>

// #include "album.h"

class Conjunto_listas {
    public: 
        Conjunto_listas();

        int get_id() const;
        virtual void listar_itens() = 0;
        virtual void excluir_item(int id) = 0;

    private:
        static int contador_id_conjunto_listas;
        int _id_conjunto_listas;
};

#endif