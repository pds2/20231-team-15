#ifndef LISTAMUSICA_H
#define LISTAMUSICA_H

#include <vector>

#include "musica.h"

class Lista_musica{
    private:
        static int _id;
        int id;
    public:
        Lista_musica();
        Lista_musica(const std::string& caminho_csv);
        int get_tamanho();
        virtual void exibe_musicas();
        virtual void adicionar_musica(Musica musica) = 0;
        int get_id() const;
    protected:
        std::vector<Musica> _lista_musica;

};


#endif