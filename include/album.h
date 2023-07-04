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
        std::string get_autor();
        Album(Artista artista);
        void adicionar_musica(Musica m) override;

};


#endif