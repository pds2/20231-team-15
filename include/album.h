#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <exception>

#include "artista.h"
#include "lista_musica.h"

class musica_repetida_album_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Música já existente no álbum!";
    }
};

class Album : public Lista_musica {
    private:
        std::string _nome;
        Artista _artista;
    public:
        Album(std::string nome, Artista artista);
        std::string get_nome() const;
        std::string get_autor() const;
        void adicionar_musica(Musica m);
        void exibe_musicas();
        void imprimir_informacoes();
};


#endif