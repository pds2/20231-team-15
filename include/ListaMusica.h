#ifndef LISTAMUSICA_H
#define LISTAMUSICA_H

#include"musica.h"
#include <vector>

class ListaMusica{
    private:
        static int _id;
    protected:
        std::vector<Musica> _listamusica;
    public:
        ListaMusica() = default;
        ListaMusica(int id);
        int get_tamanho();
        void exibe_musicas();
        virtual void adicionar_musica(Musica musica) = 0;

};


#endif