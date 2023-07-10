#include <iostream>
#include <vector>

#include "../src/playlist.cpp"
#include "../src/usuario.cpp"
#include "../src/musica.cpp"
#include "../src/album.cpp"
#include "../src/banco_usuarios.cpp"
#include "../src/lista_musica.cpp"
#include "../src/artista.cpp"
#include "../src/discografia.cpp"
#include "../src/biblioteca.cpp"
#include "../src/conjunto_listas.cpp"
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

    // Inicializando recomendação;
    // Recomendacao recomendacao(lista_musicas);

    // int numero_de_musicas = 5;
    // sistema.recomendar_n_musicas(numero_de_musicas, lista_musicas[2], lista_musicas);
    
    //Função para imprimir os detalhes de todas as músicas
    //musicas.imprimir_todas_musicas(listaMusicas);

    // Listar todas as músicas no programa, apenas com id, titulo e artista
    // sistema.listar_id_musica_artista(lista_musicas);
    // Listar todos os artistas no programa
    // sistema.listar_artistas(lista_artistas);
    // Listar todos os albuns no programa
    // sistema.listar_albuns(lista_albuns);

    // lista_albuns[5].exibe_musicas();

    //Imprimir musica 101
    // listaMusicas[100].imprimir_detalhes();   


    //std::string user, senha;
    //BancoUsuarios b = BancoUsuarios("usuarios.txt");
    //b.adicionar_usuario("dayrinho123", "lalala13"); 
//
    //while (true) {
    //    std::cout << "Digite o Usuário:" << std::endl;
    //    std::cin >> user;
    //    std::cout << "Digite a Senha:" << std::endl;
    //    std::cin >> senha;
//
    //    try {
    //        if (!b.verificar_usuario(user)) {
    //            throw usuario_nao_existe_e();
    //        }
    //        if (b.verificar_senha(user, senha)) {
    //            std::cout << "Welcome!!" << std::endl;
    //            break;
    //        } else {
    //            throw senha_incorreta_e();
    //        }
    //    } catch (usuario_nao_existe_e &u) {
    //        std::cout << "Usuário não existe. Digite novamente." << std::endl;
    //    } catch (senha_incorreta_e &s) {
    //        std::cout << "Senha incorreta. Digite novamente." << std::endl;
    //    }
    //}
    //Usuario u = Usuario(user, senha);
    return 0;
}