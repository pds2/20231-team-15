#include "../include/sistema.h"
#include <iostream>

 
//    METODOS DO SISTEMA

#include <iostream>
#include <string>

void Sistema::iniciar_sistema() {
    std::string titulo = "BEM VINDO AO SISTEMA DE MÚSICAS!";
    std::string linha = std::string(titulo.length(), '-');

    // Imprime borda superior
    std::cout << "\033[38;5;98m+" << linha << "+\033[0m" << std::endl;

    // Imprime título centralizado
    std::cout << "\033[38;5;98m|" << std::string((linha.length() - titulo.length()) / 2, ' ') << "\033[38;5;92m" << titulo << "\033[38;5;98m" << std::string((linha.length() - titulo.length()) / 2, ' ') << "|\033[0m" << std::endl;

    // Imprime borda inferior
    std::cout << "\033[38;5;98m+" << linha << "+\033[0m" << std::endl;

    std::cout << "\033[38;5;98mListagem dos comandos:\033[0m" << std::endl;
    std::cout << "\033[38;5;98m---------------------------------\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mListar as músicas disponíveis no programa:\033[0m \033[38;5;92mls_m\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mListar os artistas disponíveis no programa:\033[0m \033[38;5;92mls_at\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mListar os álbuns disponíveis no programa:\033[0m \033[38;5;92mls_al\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mListar informações de uma música específica:\033[0m \033[38;5;92mls_im\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mListar a discografia do artista desejado:\033[0m \033[38;5;92mls_disc\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mReceber n recomendações de uma música:\033[0m \033[38;5;92mr_m\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mReceber n recomendações de uma música baseado em sua dançabilidade:\033[0m \033[38;5;92mr_m_d\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mReceber n recomendações de uma música baseado em seu barulho:\033[0m \033[38;5;92mr_m_b\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mReceber n recomendações de uma música baseado no seu ano de lançamento:\033[0m \033[38;5;92mr_m_a\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mReceber uma recomendação de música aleatória:\033[0m \033[38;5;92mr_m_al\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mCriar uma Playlist:\033[0m \033[38;5;92mcp\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mListar Playlists:\033[0m \033[38;5;92mlp\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mVer as músicas da playlist:\033[0m \033[38;5;92mvp\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mEditar uma das suas Playlists:\033[0m \033[38;5;92medit\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mLimpar o terminal:\033[0m \033[38;5;92mclear\033[0m" << std::endl;
    std::cout << "- \033[38;5;98mFinalizar programa:\033[0m \033[38;5;92mend\033[0m" << std::endl;
    std::cout << "\033[38;5;98m---------------------------------\033[0m" << std::endl;

    std::cout << "\033[38;5;98mDigite agora o comando desejado:\033[0m" << std::endl;
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

void Sistema::informacoes_da_musica(std::vector <Musica> lista_musicas) {
    while (true) {
        std::cout << "Digite o id da musica que deseja visualizar os detalhes: ";
        int id_musica;
        std::cin >> id_musica;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Musica musica;

        try {
            musica = identificar_musica_por_id(id_musica, lista_musicas);

            musica.imprimir_detalhes();

        } catch (id_artista_nao_existe &e) {
            std::cout << "Id do artista eh inexistente." << std::endl;
        }   
        break;
    }
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
        for (auto& musica : lista_musicas) {
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

// METODOS DA CLASSE PLAYLIST

Playlist Sistema::criar_playlist(std::string user){
    std::string nome;
    std::cout << "Digite o nome da playlist:" << std::endl;
    std::getline(std::cin, nome);
    Playlist p(nome, user);

    return p;
}


void Sistema::editar_playlist(Playlist &p, std::vector<Musica> lista_musicas) {
    p.mostrar_playlist();
    std::cout << "\033[1;35mEDIÇÃO DE PLAYLIST ------ COMANDOS:\033[0m" << std::endl;
    std::cout << "\033[1;34mAdicionar Música: \033[1;35ma\033[0m" << std::endl;
    std::cout << "\033[1;34mRemover Música: \033[1;35mr\033[0m" << std::endl;
    std::cout << "\033[1;34mTrocar duas Músicas: \033[1;35mt\033[0m" << std::endl;
    std::cout << "\033[1;34mSalvar alterações e sair: \033[1;35msair\033[0m" << std::endl;
    std::string edit;
    while (std::cin >> edit) {
        if (edit == "t") {
            int m1, m2;
            std::cout << "Digite o índice da primeira música" << std::endl;
            std::cin >> m1;
            std::cout << "Digite o índice da segunda música" << std::endl;
            std::cin >> m2;
            p.trocar_musica(m1-1, m2-1);
            std::cout<< "Você trocou a música " << m1 << " com a música " << m2 << "." << std::endl;
        } else if (edit == "r") {
            int sizeantes = p.get_tamanho();
            int id;
            std::cout << "Digite o ID da música a ser removida" << std::endl;
            std::cin >> id;
            bool idEncontrado = false;
            auto it = p.begin();
            while (it != p.end()) {
                if (it->get_id() == id) {
                    idEncontrado = true;
                    p.erase(it);
                    if (sizeantes > p.get_tamanho()) {
                        std::cout << "Música " << id << " removida com sucesso!" << std::endl;
                    }
                } else {
                    ++it;
                }
            }

            if (!idEncontrado) {
                std::cout << "ID não encontrado." << std::endl;
            }       
            } else if (edit == "a") {
                int sizeantes = p.get_tamanho();
                int id;
                std::cout << "Digite o ID da música a ser adicionada." << std::endl;
                std::cin >> id;
                bool idEncontrado = false;
                for (Musica &m : lista_musicas) {
                    if (m.get_id() == id){
                        p.adicionar_musica(m);
                        idEncontrado = true;
                        if (sizeantes < p.get_tamanho()){
                            std::cout << "Música " << m.get_id() << " adicionada." << std::endl;
                        }
                    }
                }
                    if (!idEncontrado) {
                        std::cout << "ID inválido." << std::endl;
                }
            } else if (edit == "sair"){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpar o fluxo de entrada
                this->limpar_terminal();
                break;
            }
    }
}


// METODOS DA CLASSE RECOMENDACAO

void Sistema::recomendar_musicas(std::vector <Musica> lista_musicas, std::string parametro) {

    while (true) {

        // std::cout << "Digite o parametro que deseja para a recomendacao: ";
        //     if () {

        //     }

        std::cout << "Digite o id da musica que deseja uma recomendacao: ";
        int id_musica;
        std::cin >> id_musica;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        Musica musica;

        try {
            musica = identificar_musica_por_id(id_musica, lista_musicas);

            std::cout << "Digite o numero de recomendacoes que deseja: ";
            int numero_recomendacoes;
            std::cin >> numero_recomendacoes;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (musica.get_id() == 101) {
                std::cout << "Nao e possivel recomendar algo melhor que" << musica.get_titulo() << std::endl;
                break;
            }

            try {
                Recomendacao recomendacao(lista_musicas);
                auto recomendacoes = recomendacao.recomendar_n_musicas(numero_recomendacoes, musica, parametro);
                
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

void Sistema::recomendar_musica_aleatoria(std::vector <Musica> lista_musicas) {
    Recomendacao recomendacao(lista_musicas);
    Musica musica = recomendacao.recomendar_aleatoria();

    std::cout << "Musica Recomendada: " << std::endl;
    musica.imprimir_detalhes();
}
