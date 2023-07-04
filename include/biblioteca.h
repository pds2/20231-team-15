#ifndef TP2_BIBLIOTECA
#define TP2_BIBLIOTECA

#include <memory>
#include <vector>

#include "lista_musicas.h"

class Biblioteca {
    public: 
        Biblioteca();

        int get_id() const;

        void listar_itens();
        void inserir_item(const ListaMusica &item);
        void excluir_item(const ListaMusica &item);
        void editar_item(const ListaMusica &item);

    private:
        static int contador_id_biblioteca;
        int _id_biblioteca;
        std::vector<ListaMusica> m_biblioteca;
};

#endif