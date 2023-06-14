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
    std::cout << "Músicas do artista " << _nome << ":" << std::endl;
    for (const auto& musica : Musica().getArtista()) {
        if(_nome == Musica().getArtista()) {
            Musica().imprimirDetalhes();
        } 
    }
}
