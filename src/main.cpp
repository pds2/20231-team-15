#include <iostream>
#include "../include/playlist.h"
#include "../include/usuario.h"
#include "../include/musica.h"
#include "../include/album.h"
#include "../include/banco_usuarios.h"
#include "../include/lista_musica.h"
#include "../include/artista.h"
#include <vector>


//Main temporário para testar a classe Musica e Artista
int main() {

    Musica musicas;

    std::vector<Musica> listaMusicas = musicas.lerMusicasDoCSV("/home/pedroaugtb/codes/vscode/20231-team-15-1/musicas.csv");

    // Função para imprimir os detalhes de todas as músicas
    //for (auto i = listaMusicas.begin(); i < listaMusicas.end(); i++) {
    //    i->imprimir_detalhes();
    //}

    int a = 0;

    // Função para ver se tem músicas repetidas
    //for (auto i = listaMusicas.begin(); i < listaMusicas.end(); i++) {
    //    for (auto j = i + 1; j < listaMusicas.end(); j++) {
    //        if (i->getTitulo() == j->getTitulo()) {
    //            std::cout << "Música repetida: " << i->getTitulo() << std::endl;
    //            a++;
    //        }
    //    }
    //}
//
    //if(a==0) std::cout << "Não há músicas repetidas" << std::endl;

    //Imprimir musica 101
    listaMusicas[100].imprimir_detalhes();



    return 0;
}
