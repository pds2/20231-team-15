#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <algorithm>
#include <string>
#include <exception>

#include "usuario.h"
#include "lista_musica.h"

class musica_repetida_playlist_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Música já existente na playlist. Deseja prosseguir?";
    }
};

class Playlist : public Lista_musica {
    private:
        std::string _nome;
        Usuario _usuario;
    public:
        ~Playlist();
        Playlist(std::string nome, Usuario usuario);
        std::string get_usuario();
        void adicionar_musica (Musica m);
        void remover_musica (Musica m);
        void trocar_musica (int musica1, int musica2);
};

#endif