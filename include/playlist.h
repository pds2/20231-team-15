#ifndef PLAYLIST_H
#define PLAYLIST_H
#include<string>
#include "Usuario.h"
#include "ListaMusica.h"

class Playlist : public Lista_musica {
    private:
        std::string _nome;
        Usuario _usuario;
    public:
        Playlist(std::string nome, Usuario usuario);
        std::string get_usuario();
        void adicionar_musica (Musica m) override;

};

#endif