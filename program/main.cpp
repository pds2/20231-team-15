#include <iostream>
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
#include <vector>


//Main temporário para testar a classe Musica e Artista
int main() {
    // Caminho do arquivo csv contendo as músicas
    std::string musicas_path = "./musicas.csv";

    Musica musicas;
    std::vector<Musica> listaMusicas = musicas.ler_musicas_do_csv(musicas_path);
    
    //Função para imprimir os detalhes de todas as músicas
    for (auto i = listaMusicas.begin(); i < listaMusicas.end(); i++) {
        i->imprimir_detalhes();
    }
    
    //int a = 0;
    // //Função para ver se tem músicas repetidas
    //for (auto i = listaMusicas.begin(); i < listaMusicas.end(); i++) {
    //    for (auto j = i + 1; j < listaMusicas.end(); j++) {
    //        if (i->get_titulo() == j->get_titulo()) {
    //            std::cout << "Música repetida: " << i->get_titulo() << std::endl;
    //            a++;
    //        }
    //    }
    //}
    

    //if(a==0) std::cout << "Não há músicas repetidas" << std::endl;

    //Imprimir musica 101
    //listaMusicas[100].imprimir_detalhes();    
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
