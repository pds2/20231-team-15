#ifndef CONJUNTO_LISTAS
#define CONJUNTO_LISTAS

#include <memory>
#include <vector>

class Conjunto_listas {
    public: 
        Conjunto_listas();
        int get_id() const;
        virtual void listar_itens() = 0;

    private:
        static int contador_id_conjunto_listas;
        int _id_conjunto_listas;
};

#endif