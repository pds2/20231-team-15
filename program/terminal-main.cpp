#include <iostream>
#include <vector>

#include "../include/playlist.h"
#include "../include/usuario.h"
#include "../include/musica.h"
#include "../include/album.h"
#include "../include/banco_usuarios.h"
#include "../include/lista_musica.h"
#include "../include/artista.h"
#include "../include/discografia.h"
#include "../include/biblioteca.h"
#include "../include/conjunto_listas.h"
#include "../include/sistema.h"
#include "../include/recomendacao.h"

int main() {

    // Inicializando o sistema
    Sistema sistema;

    // Caminho do arquivo csv contendo as músicas
    std::string musicas_path = "./musicas.csv";

    // Incicializando músicas, artistas e albuns
    auto lista_musicas = sistema.inicializar_musicas(musicas_path);
    auto lista_artistas = sistema.inicializar_artistas(lista_musicas);
    auto lista_albuns = sistema.inicializar_albuns(lista_musicas, lista_artistas);

    //Inicializando a Biblioteca (conjunto de playlists)
    Biblioteca b = Biblioteca();

    // Inicio do programa
    sistema.iniciar_sistema();

    while (true) {
        std::string linha;
        std::getline(std::cin, linha);
        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando == "ls_m") {
            sistema.listar_id_musica_artista(lista_musicas);
        } else if (comando == "ls_at") {
            sistema.listar_artistas(lista_artistas);
        } else if (comando == "ls_al") {
            sistema.listar_albuns(lista_albuns);
        } else if (comando == "ls_disc") {
            sistema.exibir_discografia(lista_artistas, lista_albuns);
        }else if (comando == "r_m") {
            sistema.recomendar_musicas(lista_musicas);
        } else if (comando == "clear") {
            sistema.limpar_terminal();
        } else if (comando == "end") {
            break;
        } else if (comando == "cp") {
            std::string usuario;
            iss >> usuario;
            Playlist p = sistema.criar_playlist(usuario);
            b.inserir_item(p);
        } else if (comando == "lp") {
            b.listar_itens();
        } else if (comando == "edit") {
            b.listar_itens();
            int id;
            std::cout << "Qual o ID da playlist que deseja editar?" << std::endl;
            std::cin >> id;
            for (Playlist x : b) {
                if (x.get_id() == id) {
                    sistema.editar_playlist(x, lista_musicas);
                }
            }
        } else {
            std::cout << "Comando inválido." << std::endl;
        }
    }


    return 0;
}