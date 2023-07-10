#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <algorithm>
#include <string>
#include <exception>

#include "usuario.h"
#include "lista_musica.h"

class musica_repetida_playlist_e : public std::exception {};

class Playlist : public Lista_musica {
    private:
        std::string _nome;
        std::string _username;
    public:
        ~Playlist();
        Playlist(std::string nome, std::string _username);
        std::string get_usuario();
        std::string get_nome();
        void adicionar_musica (Musica m);
        void remover_musica (Musica m);
        void trocar_musica (int musica1, int musica2);
};

#endif