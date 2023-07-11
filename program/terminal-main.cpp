#include <iostream>
#include <vector>

#include "../include/sistema.h"


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
        } else if (comando == "ls_im") {
            sistema.informacoes_da_musica(lista_musicas);
        } else if (comando == "ls_disc") {
            sistema.exibir_discografia(lista_artistas, lista_albuns);
        } else if (comando == "r_m") {
            sistema.recomendar_musicas(lista_musicas, "media");
        } else if (comando == "r_m_d") {
            sistema.recomendar_musicas(lista_musicas, "dancabilidade");
        } else if (comando == "r_m_b") {
            sistema.recomendar_musicas(lista_musicas, "barulho");
        } else if (comando == "r_m_a") {
            sistema.recomendar_musicas(lista_musicas, "ano");
        } else if (comando == "r_m_al") {
            sistema.recomendar_musica_aleatoria(lista_musicas);
        } else if (comando == "clear") {
            sistema.limpar_terminal();
        } else if (comando == "ajuda") {
            sistema.listar_comandos();
        } else if (comando == "end") {
            break;
        } else if (comando == "cp") {
            Playlist p = sistema.criar_playlist("admin");
            b.inserir_item(p);
            std::cout << "Playlist criada!" << std::endl;
        } else if (comando == "lp") {
            if (b.ta_vazia()){
                std::cout << "Sem playlists na biblioteca!" << std::endl;
            } else {
                b.listar_itens();
            }
        } else if (comando == "vp") {
             if (b.ta_vazia()){
                std::cout << "Sem playlists na biblioteca!" << std::endl;
            } else  {
                for (Playlist x : b) {
                        std::cout << x.get_nome() << ":"<< std::endl;
                        x.mostrar_playlist();
                    }
                }
        } else if (comando == "edit") {
            b.listar_itens();
            int id;
            std::cout << "Qual o ID da playlist que deseja editar?" << std::endl;
            std::cin >> id;
            for (Playlist &x : b) {
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