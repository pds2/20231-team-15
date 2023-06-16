#ifndef LISTAMUSICA_H
#define LISTAMUSICA_H

#include <vector>

class ListaMusica{
    private:
        std::vector<Musica> listamusica_
    public:
        virtual void adicionar_musica(Musica musica) = 0;

};


#endif