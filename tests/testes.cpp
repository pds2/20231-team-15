#include "../third_party/doctest.h"

#include "../include/album.h"
#include "../include/artista.h"
#include "../include/biblioteca.h"
#include "../include/conjunto_listas.h"
#include "../include/discografia.h"
#include "../include/lista_musica.h"
#include "../include/musica.h"
#include "../include/playlist.h"
#include "../include/recomendacao.h"
#include "../include/sistema.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Testes da classe música
TEST_CASE("01 - Teste construtor da classe Musica") {
    Musica musica(1, "Artista", "Título", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5);

    CHECK(musica.get_id() == 1);
    CHECK(musica.get_artista() == "Artista");
    CHECK(musica.get_titulo() == "Título");
    CHECK(musica.get_album() == "Álbum");
    CHECK(musica.get_genero() == "Gênero");
    CHECK(musica.get_ano() == 2021);
    CHECK(musica.get_dancabilidade() == 5);
    CHECK(musica.get_sentimento() == 7);
    CHECK(musica.get_barulho() == 3);
    CHECK(musica.get_media() == 4.5);
}

// Testes da função imprimir detalhes da classe Musica
TEST_CASE("02 - Teste da função imprimir_detalhes da classe Musica") {
    Musica musica(1, "Artista", "Título", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5);

    SUBCASE("Verificar a impressão dos detalhes") {
        std::ostringstream output;
        std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

        musica.imprimir_detalhes();

        std::cout.rdbuf(oldOutput);

        std::string expectedOutput = "Id: 1\n"
                                     "Artista: Artista\n"
                                     "Título: Título\n"
                                     "Álbum: Álbum\n"
                                     "Gênero: Gênero\n"
                                     "Ano: 2021\n"
                                     "Dancabilidade: 5\n"
                                     "Sentimento: 7\n"
                                     "Barulho: 3\n"
                                     "Média: 4.5\n";

        CHECK(output.str() == expectedOutput);
    }
}

// Testes da função ler músicas do csv da classe Musica
TEST_CASE("03 - Teste da função ler_musicas_do_csv da classe Musica") {
    Musica musica;
    std::vector<Musica> musicas = musica.ler_musicas_do_csv("./musicas.csv");

    CHECK(musicas.size() > 0);
}

// Testes da classe Artista
TEST_CASE("04 - Teste construtor da classe Artista") {
    Artista artista("Nome do Artista");

    CHECK(artista.get_nome() == "Nome do Artista");
}

// Testes da função armazenar_musicas da classe Artista
TEST_CASE("05 - Teste da função armazenar_musicas da classe Artista") {
    Artista artista("Nome do Artista");

    SUBCASE("Verificar armazenamento de músicas do artista") {
        std::vector<Musica> musicas;
        musicas.push_back(Musica(1, "Nome do Artista", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5));
        musicas.push_back(Musica(2, "Outro Artista", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5));
        musicas.push_back(Musica(3, "Nome do Artista", "Título 3", "Álbum 3", "Gênero 3", 2023, 3, 5, 1, 2.5));

        artista.armazenar_musicas(musicas);

        // Verificar se as músicas foram armazenadas corretamente dentro do objeto Artista
        const std::vector<Musica>& artistas_musicas = artista.get_artistas_musicas();
        CHECK(artistas_musicas.size() == 2);
        CHECK(artistas_musicas[0].get_titulo() == "Título 1");
        CHECK(artistas_musicas[0].get_album() == "Álbum 1");
        CHECK(artistas_musicas[0].get_ano() == 2021);
        CHECK(artistas_musicas[1].get_titulo() == "Título 3");
        CHECK(artistas_musicas[1].get_album() == "Álbum 3");
        CHECK(artistas_musicas[1].get_ano() == 2023);
    }
}


// Testes da função imprimir_discografia da classe Artista
TEST_CASE("06 - Teste da função imprimir_discografia da classe Artista") {
    Artista artista("Nome do Artista");

    SUBCASE("Verificar a impressão da discografia do artista") {
        std::ostringstream output;
        std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

        // Simulando o armazenamento de músicas no objeto Artista
        std::vector<Musica> musicas;
        musicas.push_back(Musica(1, "Nome do Artista", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5));
        musicas.push_back(Musica(2, "Outro Artista", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5));
        musicas.push_back(Musica(3, "Nome do Artista", "Título 3", "Álbum 3", "Gênero 3", 2023, 3, 5, 1, 2.5));
        artista.armazenar_musicas(musicas);

        artista.imprimir_discografia();

        std::cout.rdbuf(oldOutput);

        std::string expectedOutput = "Discografia de Nome do Artista:\n"
                                     "Título 1 - Álbum 1 (2021)\n"
                                     "Título 3 - Álbum 3 (2023)\n";

        CHECK(output.str() == expectedOutput);
    }
}

// Testes da classe Album
TEST_CASE("07 - Teste da adição de músicas no Album") {
    Artista artista("Artista");
    Album album("Álbum", artista);
    Musica musica1(1, "Artista", "Musica 1" , "Álbum", "Gênero", 2021, 5, 7, 3, 4.5);
    Musica musica2(2, "Artista", "Música 2", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5);

    CHECK_NOTHROW(album.adicionar_musica(musica1));
    CHECK_THROWS_AS(album.adicionar_musica(musica1), musica_repetida_album_e);
    CHECK_NOTHROW(album.adicionar_musica(musica2));
    CHECK_THROWS_AS(album.adicionar_musica(musica2), musica_repetida_album_e);
}

// Testes da função imprimir_informacoes da classe Album
TEST_CASE("08 - Teste da impressão de informações do Album") {
    Artista artista("Artista");
    Album album("Álbum", artista);
    Musica musica(1, "Artista", "Música", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5);
    album.adicionar_musica(musica);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    album.imprimir_informacoes();
    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput = "Id: 1  Nome: Álbum          Artista: Artista\n";
    CHECK(output.str() == expectedOutput);
}

// Testes da classe Biblioteca
TEST_CASE("09 - Teste Biblioteca") {
    Biblioteca biblioteca;

    Playlist playlist1("Playlist 1", "pedro");
    Playlist playlist2("Playlist 2", "rubão");

    biblioteca.inserir_item(playlist1);
    biblioteca.inserir_item(playlist2);

    std::vector<Playlist>::iterator it = biblioteca.begin();
    CHECK_EQ(it->get_nome(), "Playlist 1");
    CHECK_EQ(it->get_usuario(), "pedro");
    it++;
    CHECK_EQ(it->get_nome(), "Playlist 2");
    CHECK_EQ(it->get_usuario(), "rubão");
    it++;
    CHECK_EQ(it, biblioteca.end());
}

// Testes da classe Discografia
TEST_CASE("10 - Teste Discografia") {
    Artista artista("Artista Teste");
    Discografia discografia(artista);

    Album album1("Album 1", artista);
    Album album2("Album 2", artista);

    SUBCASE("Teste inserir_item e listar_itens") {
        discografia.inserir_item(album1);
        discografia.inserir_item(album2);

        std::stringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

        discografia.listar_itens();

        int a = album1.get_id();
        int b = album2.get_id();

        char expectedOutput[100];
        std::sprintf(expectedOutput, "Artista: Artista Teste\n1. Album 1 ID:%d\n2. Album 2 ID:%d\n", a, b);
        CHECK_EQ(output.str(), expectedOutput);

        std::cout.rdbuf(oldCoutBuffer);
    }
}

// Testes da classe recomendação
TEST_CASE("11 - Teste Recomendacao") {
    std::vector<Musica> lista_musicas;

    // Crie algumas músicas para a lista de músicas
    Musica musica1(1, "Artista 1", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5);
    Musica musica2(2, "Artista 2", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5);
    Musica musica3(3, "Artista 3", "Título 3", "Álbum 3", "Gênero 3", 2023, 3, 5, 1, 2.5);
    lista_musicas.push_back(musica1);
    lista_musicas.push_back(musica2);
    lista_musicas.push_back(musica3);

    Recomendacao recomendacao(lista_musicas);

    SUBCASE("Teste ordenar_musicas") {
        // Crie uma música de referência para testar a ordenação
        Musica musica_referencia(4, "Artista 4", "Título 4", "Álbum 4", "Gênero 4", 2024, 6, 8, 4, 5.5);

        auto ordenadas = recomendacao.ordenar_musicas_media(musica_referencia);

        // Verifique se as músicas estão ordenadas corretamente
        for (size_t i = 1; i < ordenadas.size(); i++) {
            double diferenca_atual = ordenadas[i].first;
            double diferenca_anterior = ordenadas[i - 1].first;
            CHECK(diferenca_atual >= diferenca_anterior);
        }
    }

    SUBCASE("Teste recomendar_n_musicas") {
        // Crie uma música de referência para as recomendações
        Musica musica_referencia(5, "Artista 5", "Título 5", "Álbum 5", "Gênero 5", 2025, 7, 9, 5, 6.5);

        int numero_de_musicas = 2;
        std::vector<Musica> recomendadas = recomendacao.recomendar_n_musicas(numero_de_musicas, musica_referencia, "media");

        // Verifique se o número de músicas recomendadas é igual ao esperado
        CHECK(recomendadas.size() == numero_de_musicas);

        // Verifique se as músicas recomendadas estão na lista de músicas original
        for (const Musica& musica : recomendadas) {
            bool encontrada = false;
            for (const Musica& musica_original : lista_musicas) {
                if (musica.get_id() == musica_original.get_id()) {
                    encontrada = true;
                    break;
                }
            }
            CHECK(encontrada);
        }
    }
}

// Testes da classe Playlist
TEST_CASE("12 - Teste Playlist") {
    std::string nome = "Minha Playlist";
    std::string username = "usuario123";

    Playlist playlist(nome, username);

    SUBCASE("Teste get_nome e get_usuario") {
        CHECK_EQ(playlist.get_nome(), nome);
        CHECK_EQ(playlist.get_usuario(), username);
    }

    SUBCASE("Teste adicionar_musica e get_tamanho") {
        Musica musica1(1, "Artista 1", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5);
        Musica musica2(2, "Artista 2", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5);

        playlist.adicionar_musica(musica1);
        playlist.adicionar_musica(musica2);

        CHECK_EQ(playlist.get_tamanho(), 2);
    }

    SUBCASE("Teste remover_musica e get_tamanho") {
        Musica musica1(1, "Artista 1", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5);
        Musica musica2(2, "Artista 2", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5);

        playlist.adicionar_musica(musica1);
        playlist.adicionar_musica(musica2);

        playlist.remover_musica(musica1);

        CHECK_EQ(playlist.get_tamanho(), 1);
    }

    
    SUBCASE("Teste trocar_musica") {
        Musica musica1(1, "Artista 1", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5);
        Musica musica2(2, "Artista 2", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5);
        Musica musica3(3, "Artista 3", "Título 3", "Álbum 3", "Gênero 3", 2023, 3, 5, 1, 2.5);

        playlist.adicionar_musica(musica1);
        playlist.adicionar_musica(musica2);
        playlist.adicionar_musica(musica3);


        SUBCASE("Teste de troca válida") {
            int posicao1 = 0;
            int posicao2 = 2;

            playlist.trocar_musica(posicao1, posicao2);

            CHECK_EQ(playlist.get_musica_da_posicao(posicao1).get_id(), musica3.get_id());
            CHECK_EQ(playlist.get_musica_da_posicao(posicao2).get_id(), musica1.get_id());
        }

        SUBCASE("Teste de troca inválida") {
            int posicao1 = -1;
            int posicao2 = 5;

            // Redirecionar a saída para um stringstream para capturar a mensagem de erro
            std::stringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

            playlist.trocar_musica(posicao1, posicao2);

            std::string expectedOutput = "Posições inválidas!\n";

            CHECK_EQ(output.str(), expectedOutput);

            std::cout.rdbuf(oldCoutBuffer);
        }
    }
}



