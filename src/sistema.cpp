#include "../include/sistema.h"
#include <iostream>

std::vector <Musica> Sistema::inicializar_musicas(const std::string& musicas_path) {
    Musica musicas;
    std::vector<Musica> lista_musicas = musicas.ler_musicas_do_csv(musicas_path);

    //Função para ver se tem músicas repetidas
    musicas.musica_repetida(lista_musicas);
    return lista_musicas;
}

std::vector <Artista> Sistema::inicializar_artistas(const std::vector <Musica>& lista_musicas) {
    std::vector <Artista> lista_artistas;
    for (const auto &musica : lista_musicas) {
        Artista artista(musica.get_artista());
        lista_artistas.push_back(artista);
    }

    for (auto it_1 = lista_artistas.begin(); it_1 != lista_artistas.end(); ++it_1) {
        for (auto it_2 = lista_artistas.begin(); it_2 != lista_artistas.end(); ++it_2) {
            if (it_1->get_nome() == it_2->get_nome() && it_1->get_id() != it_2->get_id()) {
                lista_artistas.erase(it_2);
            }
        }
    }
    return lista_artistas;
}

std::vector <Album> Sistema::inicializar_albuns(const std::vector <Musica>& lista_musicas, const std::vector <Artista>& lista_artistas) {

    std::vector <Album> lista_albuns;
    for (const auto& musica : lista_musicas) {
        for (const auto& artista : lista_artistas) {
            if (musica.get_artista() == artista.get_nome()) {
                Album album(musica.get_album(), artista);
                lista_albuns.push_back(album);
            }
        }
    }

    for (auto it_1 = lista_albuns.begin(); it_1 != lista_albuns.end(); ++it_1) {
        for (auto it_2 = lista_albuns.begin(); it_2 != lista_albuns.end(); ++it_2) {
            if (it_1->get_nome() == it_2->get_nome() && it_1->get_id() != it_2->get_id()) {

                lista_albuns.erase(it_2);
            }
        }
    }

    lista_albuns = inserir_musicas_album(lista_albuns, lista_musicas);
    return lista_albuns;
}

std::vector <Album> Sistema::inserir_musicas_album(std::vector <Album> lista_albuns, std::vector <Musica> lista_musicas) {

    for (auto& album : lista_albuns) {
        for (const auto& musica : lista_musicas) {
            if (album.get_nome() == musica.get_album()) {
                // std::cout << "\n Album: " << std::endl;
                album.adicionar_musica(musica);
                // album.exibe_musicas();
            }
        }
    }

    // std::cout << "\n\nTeste final: " << std::endl;
    // lista_albuns[0].exibe_musicas();

    return lista_albuns;
}

Usuario Sistema::login(BancoUsuarios b){
        std::string username;
        std::string senha;

        while (true) {
        std::cout << "Digite o Usuário:" << std::endl;
        std::cin >> username;
        std::cout << "Digite a Senha:" << std::endl;
        std::cin >> senha;

        try {
            if (!b.verificar_usuario(username)) {
                throw usuario_nao_existe_e();
            }
            if (b.verificar_senha(username, senha)) {
                std::cout << "Welcome!!" << std::endl;
                break;
            } else {
                throw senha_incorreta_e();
            }
        } catch (usuario_nao_existe_e &u) {
            std::cout << "Usuário não existe. Digite novamente." << std::endl;
        } catch (senha_incorreta_e &s) {
            std::cout << "Senha incorreta. Digite novamente." << std::endl;
        }
    }
    Usuario u = Usuario(username, senha);
    return u;
}

// listar todas as musicas disponiveis no sistema, com seu respectivo id e artista
void Sistema::listar_id_musica_artista(std::vector <Musica> lista_musicas) const {
    for (auto i = lista_musicas.begin(); i < lista_musicas.end(); i++) {
        i->imprimir_id_musica_artista();
    }
}

// listar todos os artistas
void Sistema::listar_artistas(std::vector <Artista> lista_artistas) const {
    for (auto i = lista_artistas.begin(); i < lista_artistas.end(); i++) {
        i->imprimir_artista();
    }
}

// listar musicas de um album
void Sistema::listar_albuns(std::vector <Album> listar_albuns) const {
    for (auto i = listar_albuns.begin(); i < listar_albuns.end(); i++) {
        i->imprimir_informacoes();
    }
}