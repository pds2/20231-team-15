#include "../include/artista.h"
#include "../include/musica.h"

// Construtor
Artista::Artista(const std::string& nome) {
    _nome = nome;
}
 
// Função para armazenar as músicas do artista
void Artista::armazenarMusicas(const std::vector<Musica>& musicas) const{
    std::vector<Musica> artistasMusicas;
    for (const auto& musica : musicas) {
        if (Musica().getArtista() == _nome) {
            artistasMusicas.push_back(musica);
        }
    }
}

void Artista::imprimirDiscografia() const {
    std::cout << "Discografia de " << _nome << ":" << std::endl;
    for (const auto& musica : Musica().lerMusicasDoCSV("musicas.csv")) {
        if (musica.getArtista() == _nome) {
            std::cout << musica.getTitulo() << " - " << musica.getAlbum() << " (" << musica.getAno() << ")" << std::endl;
        }
    }
}
