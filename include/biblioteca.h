#ifndef BIBLIOTECA
#define BIBLIOTECA

#include <memory>
#include <vector>

#include "conjunto_listas.h"
#include "playlist.h"

class Biblioteca : public Conjunto_listas {
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