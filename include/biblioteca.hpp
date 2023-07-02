#ifndef TP2_BIBLIOTECA
#define TP2_BIBLIOTECA

#include <memory>
#include <vector>

#include "lista_musicas.hpp"


class Biblioteca {
    public: 
        Biblioteca();

        int get_id() const;

        void listar_itens();
        void inserir_item(const ListaMusicas &item);
        void excluir_item(const ListaMusicas &item);
        void editar_item(const ListaMusicas &item);

    private:
        static int contador_id_biblioteca;
        int _id_biblioteca;
        std::vector<ListaMusicas> m_biblioteca;
};

#endif