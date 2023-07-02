#include <iostream>
#include "musica.cpp"
#include "artista.cpp"

int main() {

    Musica musicas;
    
    std::vector<Musica> listaMusicas = musicas.lerMusicasDoCSV("/home/pedroaugtb/codes/vscode/20231-team-15-1/musicas.csv");

    // Função para imprimir os detalhes de todas as músicas
    for (auto i = listaMusicas.begin(); i < listaMusicas.end(); i++) {
        i->imprimirDetalhes();
    }
    
    return 0;
}
