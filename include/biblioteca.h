#ifndef TP2_BIBLIOTECA
#define TP2_BIBLIOTECA

#include <memory>
#include <vector>

#include "playlist.h"

class Biblioteca {
    public: 
        Biblioteca();

        void listar_itens();
        void inserir_item(const Playlist &item);
        void excluir_item(const Playlist &item);
        // void editar_item(const Playlist &item);

    private:
        std::vector<Playlist> m_biblioteca;
};

#endif