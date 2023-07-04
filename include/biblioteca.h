#ifndef TP2_BIBLIOTECA
#define TP2_BIBLIOTECA

#include <memory>
#include <vector>

#include "lista_musica.h"

class Biblioteca {
    public: 
        Biblioteca();

        int get_id() const;

        void listar_itens();
        void inserir_item(const Lista_musica &item);
        void excluir_item(const Lista_musica &item);
        //void editar_item(const Lista_musica &item);

    private:
        static int contador_id_biblioteca;
        int _id_biblioteca;
        std::vector<Lista_musica> m_biblioteca;
};

#endif