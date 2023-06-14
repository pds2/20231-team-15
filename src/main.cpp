#include <iostream>
#include "musica.cpp"
#include "artista.cpp"

int main() {
    
    std::vector<Musica> musicas = Musica::carregarMusicas("/home/pedroaugtb/codes/vscode/spotify/musicas.csv");

    std::string artistaBuscado = "Queen";

    Musica::imprimirDetalhesPorTitulo(musicas, "Bohemian Rhapsody");

    
    // Criando um objeto Artista para o artista específico
    Artista artista(artistaBuscado);

    // Adicionando as músicas relacionadas ao artista
    for (const Musica& musica : musicas) {
        if (musica.getArtista() == artista.getNome()) {
            artista.adicionarMusica(musica);
        }
    }

    // Imprimindo as músicas e álbuns do artista
    artista.imprimirMusicasEAlbuns();

    return 0;
}
