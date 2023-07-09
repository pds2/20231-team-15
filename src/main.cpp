#include <iostream>
#include "./playlist.cpp"
#include "./usuario.cpp"
#include "./musica.cpp"
#include "./album.cpp"
#include "./banco_usuarios.cpp"
#include "./lista_musica.cpp"
#include "./artista.cpp"
#include "./discografia.cpp"
#include "./biblioteca.cpp"
#include "./conjunto_listas.cpp"
#include "./sistema.cpp"
#include "./recomendacao.cpp"
#include <vector>


//Main temporário para testar a classe Musica e Artista
int main() {

    // Inicializando o sistema
    Sistema sistema;
    // Recomendacao recomendacao;  

    // Caminho do arquivo csv contendo as músicas
    std::string musicas_path = "../musicas.csv";
    auto lista_musicas = sistema.inicializar_musicas(musicas_path);
    auto lista_artistas = sistema.inicializar_artistas(lista_musicas);
    auto lista_albuns = sistema.inicializar_albuns(lista_musicas, lista_artistas);
    
    //Função para imprimir os detalhes de todas as músicas
    //musicas.imprimir_todas_musicas(listaMusicas);

    // Listar todas as músicas no programa, apenas com id, titulo e artista
    // sistema.listar_id_musica_artista(lista_musicas);
    // Listar todos os artistas no programa
    // sistema.listar_artistas(lista_artistas);
    // Listar todos os albuns no programa
    // sistema.listar_albuns(lista_albuns);

    lista_albuns[5].exibe_musicas();

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
