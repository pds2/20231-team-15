#include "../include/artista.h"
#include <iostream>

Artista::Artista(const std::string& nome) : nome(nome) {}

void Artista::adicionarMusica(const Musica& musica) {
    musicas.push_back(musica);
}

void Artista::imprimirMusicasEAlbuns() const {
    std::cout << "Artista: " << nome << std::endl << std::endl;

    for (const Musica& musica : musicas) {
        std::cout << "Título: " << musica.getTitulo() << std::endl;
        std::cout << "Álbum: " << musica.getAlbum() << std::endl;
        std::cout << std::endl;
    }
}

std::string Artista::getNome() const {
    return nome;
}