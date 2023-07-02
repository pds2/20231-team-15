#ifndef LISTAMUSICA_H
#define LISTAMUSICA_H

#include <vector>

class ListaMusica{
    private:
        std::vector<Musica> _listamusica;
    public:
        int get_tamanho();
        void exibe_musicas;
        virtual void adicionar_musica(Musica musica) = 0;

};


#endif