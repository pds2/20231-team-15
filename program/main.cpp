#include <iostream>
#include <vector>

#include "../src/playlist.cpp"
#include "../src/usuario.cpp"
#include "../src/musica.cpp"
#include "../src/album.cpp"
#include "../src/banco_usuarios.cpp"
#include "../src/lista_musica.cpp"
#include "../src/artista.cpp"
#include "../src/conjunto_listas.cpp"
#include "../src/discografia.cpp"
#include "../src/biblioteca.cpp"
#include "../src/sistema.cpp"
#include "../src/recomendacao.cpp"

int main() {

    // Inicializando o sistema
    Sistema sistema;

    // Caminho do arquivo csv contendo as músicas
    std::string musicas_path = "../musicas.csv";

    // Incicializando músicas, artistas e albuns
    auto lista_musicas = sistema.inicializar_musicas(musicas_path);
    auto lista_artistas = sistema.inicializar_artistas(lista_musicas);
    auto lista_albuns = sistema.inicializar_albuns(lista_musicas, lista_artistas);

    // Inicio do programa
    sistema.iniciar_sistema();

    while (true) {
        std::string comando;
        std::cin >> comando;
        if (comando == "ls_m") {
            sistema.listar_id_musica_artista(lista_musicas);
        } else if (comando == "ls_at") {
            sistema.listar_artistas(lista_artistas);
        } else if (comando == "ls_al") {
            sistema.listar_albuns(lista_albuns);
        } else if (comando == "ls_disc") {
            sistema.exibir_discografia(lista_artistas, lista_albuns);
        } else if (comando == "r_m") {
            sistema.recomendar_musicas(lista_musicas);
        } else if (comando == "clear") {
            sistema.limpar_terminal();
        }else if (comando == "end") {
            break;
        } else {
            std::cout << "Comando inválido." << std::endl;
        }
    }
    
    return 0;
}