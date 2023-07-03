#include <iostream>
#include "musica.cpp"
#include "artista.cpp"
#include "recomendacao.cpp"

//Main temporário para testar a classe Musica e Artista
int main() {

    Musica musicas;
    
    std::vector<Musica> listaMusicas = musicas.lerMusicasDoCSV("../musicas.csv");

    Recomendacao recomendacao = Recomendacao(listaMusicas);

    // Função para imprimir os detalhes de todas as músicas
    // for (auto i = listaMusicas.begin(); i < listaMusicas.end(); i++) {
    //     i->imprimirDetalhes();
    // }

    auto musicas_recomendadas_ordem = recomendacao.recomendar_musicas(listaMusicas[2]);
    std::cout << listaMusicas[2].getTitulo() << std::endl;

    std::cout << "MAIS RECOMENDADAS" << std::endl;

    for (int i = 0; i < listaMusicas.size(); i++) {
        std::cout << musicas_recomendadas_ordem[i].second.getTitulo() << ":" << musicas_recomendadas_ordem[i].first << std::endl;
    }

    return 0;
}
