#ifndef ALBUM_H
#define ALBUM_H
#include<string>
#include "artista.h"
#include "ListaMusica.h"

class Album : public Lista_musica {
    private:
        std::string _nome;
        Artista _artista;
    public:
        std::string get_autor();
        Album(Artista artista);
        void adicionar_musica(Musica m);

};


#endif