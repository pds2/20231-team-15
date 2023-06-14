#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
#include <vector>
#include "musica.h"

class Artista {
public:
    Artista(const std::string& nome);

    void adicionarMusica(const Musica& musica);
    void imprimirMusicasEAlbuns() const;
    std::string getNome() const; // Método para obter o nome do artista

private:
    std::string nome;
    std::vector<Musica> musicas;
};

#endif  // ARTISTA_H
