#ifndef LISTAMUSICA_H
#define LISTAMUSICA_H
#include "musica.h"

#include <vector>

class Lista_musica{
    private:
        static int _id;
    public:
        Lista_musica(int id);
        Lista_musica() = default;
        int get_tamanho();
        void exibe_musicas();
        virtual void adicionar_musica(Musica musica) = 0;
    protected:
        std::vector<Musica> _lista_musica;

};


#endif