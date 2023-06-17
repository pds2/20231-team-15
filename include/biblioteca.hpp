#ifndef TP2_BIBLIOTECA
#define TP2_BIBLIOTECA

#include <memory>
#include <vector>

#include "lista_musicas.hpp"


class Biblioteca {
    public: 
        Biblioteca(std::vector<ListaMusicas> v_biblioteca);

        int get_id() const;

        void listar_itens();
        void inserir_item(std::unique_ptr<ListaMusicas> item);
        void excluir_item(std::unique_ptr<ListaMusicas> item);
        void editar_item(std::unique_ptr<ListaMusicas> item);

    private:
        static int contador_id_biblioteca;
        int _id_biblioteca;
        std::vector<std::unique_ptr<ListaMusicas>> _v_biblioteca;
};

#endif