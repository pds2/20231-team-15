#include "../include/sistema.h"
#include <iostream>

 
//    METODOS DO SISTEMA

void Sistema::iniciar_sistema() {
    std::cout << "BEM VINDO AO SISTEMA DE MUSICAS!" << std::endl;
    std::cout << "Listagem dos comandos: " << std::endl;
    std::cout << "- Listar as musicas disponiveis no programa: ls_m" << std::endl;
    std::cout << "- Listar os artistas disponiveis no programa: ls_at" << std::endl;
    std::cout << "- Listar os albuns disponiveis no programa: ls_al" << std::endl;
    std::cout << "- Listar a discografia do artista desejado: ls_disc" << std::endl;
    std::cout << "- Receber n recomendacoes de uma musica: r_m" << std::endl;
    std::cout << "- Criar uma Playlist: cp NomeDaPlaylist" << std::endl;
    std::cout << "- Listar Playlists: lp" << std::endl;
    std::cout << "- Editar uma das suas Playlists: edit" << std::endl;
    std::cout << "- Limpar o terminal: clear" << std::endl;
    std::cout << "- Finalizar programa: end\n" << std::endl;
    std::cout << "Digite agora o comando desejado: " << std::endl;
}

void Sistema::limpar_terminal() {
    #ifdef _WIN32
        // Limpar o terminal no Windows
        system("cls");
    #else
        // Limpar o terminal em sistemas UNIX (Linux, macOS, etc.)
        system("clear");
    #endif
    iniciar_sistema();
}


//    METODOS DA CLASSE MÚSICA

std::vector <Musica> Sistema::inicializar_musicas(const std::string& musicas_path) {
    Musica musicas;
    std::vector<Musica> lista_musicas = musicas.ler_musicas_do_csv(musicas_path);

    //Função para ver se tem músicas repetidas
    musicas.musica_repetida(lista_musicas);
    return lista_musicas;
}

void Sistema::listar_id_musica_artista(std::vector <Musica> lista_musicas) const {
    for (auto i = lista_musicas.begin(); i < lista_musicas.end(); i++) {
        i->imprimir_id_musica_artista();
    }
}

Musica Sistema::identificar_musica_por_id(int id, std::vector <Musica> lista_musicas) const {
    for (const auto& musica : lista_musicas) {
        if (musica.get_id() == id) {
            return musica;
        }
    }
    throw id_musica_nao_existe();
}


//    METODOS DA CLASSE ARTISTA

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

void Sistema::listar_artistas(std::vector <Artista> lista_artistas) const {
    for (auto i = lista_artistas.begin(); i < lista_artistas.end(); i++) {
        i->imprimir_artista();
    }
}

Artista Sistema::identificar_artista_por_id(int id, std::vector <Artista> lista_artistas) const {
    for (const auto& artista : lista_artistas) {
        if (artista.get_id() == id) {
            return artista;
        }
    }
    throw id_artista_nao_existe();
}


//    METODOS DA CLASSE ALBUM

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
                album.adicionar_musica(musica);
            }
        }
    }
    return lista_albuns;
}

void Sistema::listar_albuns(std::vector <Album> listar_albuns) const {
    for (auto i = listar_albuns.begin(); i < listar_albuns.end(); i++) {
        i->imprimir_informacoes();
    }
}

// METODOS DA CLASSE DISCOGRAFIA

void Sistema::exibir_discografia(std::vector <Artista> listar_artistas, std::vector <Album> listar_albuns) const {

    while (true) {
        std::cout << "Digite o id do artista que deseja visualizar a discografia: ";
        int id_artista;
        std::cin >> id_artista;
        Artista artista;
        try {
            artista = identificar_artista_por_id(id_artista, listar_artistas);

            Discografia discografia(artista);

            for (const auto& album : listar_albuns) {
                if (album.get_autor() == artista.get_nome()) {
                    discografia.inserir_item(album);
                }
            }
            
            discografia.listar_itens();

        } catch (id_artista_nao_existe &e) {
            std::cout << "Id do artista eh inexistente." << std::endl;
        }   
        break;
    }
}


// METODOS DA CLASSE USUARIO

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

//METODOS DA CLASSE BIBLIOTECA



// METODOS DA CLASSE PLAYLIST

//NÃO FUNCIONA BEM NO MAIN --- REVISAR (O ERRO NAO NECESSARIAMENTE TA AQUI)
Playlist Sistema::criar_playlist(std::string user){
    std::string nome;
    std::cout << "Digite o nome da playlist:" << std::endl;
    std::getline(std::cin, nome);
    Playlist p(nome, user);

    return p;
}


void Sistema::editar_playlist(Playlist &p, std::vector<Musica> lista_musicas) {
    p.exibe_musicas();
    std::cout <<"EDIÇÃO DE PLAYLIST ------ COMANDOS:" <<std::endl;
    std::cout <<"Adicionar Música: a" <<std::endl;
    std::cout <<"Remover Música: r" << std::endl;
    std::cout <<"Trocar duas Músicas: t" << std::endl;
    std::cout <<"Salvar alterações e sair: sair" << std::endl;
    std::string edit;
    while (std::getline(std::cin, edit) && edit != "sair") {
    if (edit == "t") {
        int m1, m2;
        std::cin >> m1 >> m2;
        p.trocar_musica(m1, m2);
    }
    else if (edit == "r") {
        int id;
        std::cin >> id;
        bool idEncontrado = false;
        for (Musica m : lista_musicas) {
            if (m.get_id() == id) {
                p.remover_musica(m);
                idEncontrado = true;
                break;
            }
        }
        if (!idEncontrado) {
            std::cout << "ID inválido." << std::endl;
        }
    }
        else if (edit == "a") {
            int id;
            std::cin >> id;
            bool idEncontrado = false;
            for (Musica m : lista_musicas) {
                if (m.get_id() == id) {
                    p.adicionar_musica(m);
                    idEncontrado = true;
                    break;
                }
            }
                if (!idEncontrado) {
                    std::cout << "ID inválido." << std::endl;
            }
        }
    }
}


// METODOS DA CLASSE RECOMENDACAO

void Sistema::recomendar_musicas(std::vector <Musica> lista_musicas) {

    while (true) {
        std::cout << "Digite o id da musica que deseja uma recomendacao: ";
        int id_musica;
        std::cin >> id_musica;

        Musica musica;

        try {
            musica = identificar_musica_por_id(id_musica, lista_musicas);

            std::cout << "Digite o numero de recomendacoes que deseja: ";
            int numero_recomendacoes;
            std::cin >> numero_recomendacoes;

            try {
                Recomendacao recomendacao(lista_musicas);
                auto recomendacoes = recomendacao.recomendar_n_musicas(numero_recomendacoes, musica);
                
                std::cout << "Recomendacao para a musica: " << musica.get_titulo() << std::endl;
                for (const auto& musica_recomendada : recomendacoes) {
                    std::cout << "\n" << std::endl;
                    musica_recomendada.imprimir_detalhes();
                }

            } catch (numero_de_musicas_superior_ao_existente &e) {
                std::cout << "Numero de musicas desejado para recomendacao eh superior ao numero existente no sistema." << std::endl;     
            }

        } catch (id_musica_nao_existe &e) {
            std::cout << "Id da musica eh inexistente." << std::endl;
        }

        break;
    }
}
