#ifndef TP2_BIBLIOTECA
#define TP2_BIBLIOTECA

#include <memory>
#include <vector>

class Conjunto_listas {
    public: 
        Conjunto_listas();

        int get_id() const;
        virtual void listar_itens() = 0;
        virtual void inserir_item() = 0;
        virtual void excluir_item() = 0;

    private:
        static int contador_id_conjunto_listas;
        int _id_conjunto_listas;
};

#endif