#include "../third_party/doctest.h"

#include "../include/album.h"
#include "../include/artista.h"
#include "../include/banco_usuarios.h"
#include "../include/biblioteca.h"
#include "../include/conjunto_listas.h"
#include "../include/discografia.h"
#include "../include/lista_musica.h"
#include "../include/musica.h"
#include "../include/playlist.h"
#include "../include/recomendacao.h"
#include "../include/sistema.h"
#include "../include/usuario.h"

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

// Testes da classe musica padrão
TEST_CASE("02 - Teste construtor padrão da classe Musica") {
    Musica musica;

    CHECK(musica.get_id() == 0);
    CHECK(musica.get_artista() == "");
    CHECK(musica.get_titulo() == "");
    CHECK(musica.get_album() == "");
    CHECK(musica.get_genero() == "");
    CHECK(musica.get_ano() == 0);
    CHECK(musica.get_dancabilidade() == 0);
    CHECK(musica.get_sentimento() == 0);
    CHECK(musica.get_barulho() == 0);
    CHECK(musica.get_media() == 0.0);
}

// Testes da função imprimir detalhes da classe Musica
TEST_CASE("03 - Teste da função imprimir_detalhes da classe Musica") {
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
TEST_CASE("04 - Teste da função ler_musicas_do_csv da classe Musica") {
    Musica musica;
    std::vector<Musica> musicas = musica.ler_musicas_do_csv("../musicas.csv");

    CHECK(musicas.size() > 0);
}

// Testes da função imprimir todas músicas da classe Musica
TEST_CASE("05 - Teste da função musica_repetida da classe Musica") {
    std::vector<Musica> musicas;
    musicas.push_back(Musica(1, "Artista 1", "Título", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5));
    musicas.push_back(Musica(2, "Artista 2", "Título", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5));
    musicas.push_back(Musica(3, "Artista 3", "Título", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5));
    musicas.push_back(Musica(4, "Artista 4", "Título", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5));
    musicas.push_back(Musica(5, "Artista 1", "Outro Título", "Álbum", "Gênero", 2021, 5, 7, 3, 4.5));

    SUBCASE("Verificar se há músicas repetidas") {
        std::ostringstream output;
        std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

        Musica().musica_repetida(musicas);

        std::cout.rdbuf(oldOutput);

        std::string expectedOutput = "Música repetida: Título\n";

        CHECK(output.str() == expectedOutput);
    }

    SUBCASE("Verificar se não há músicas repetidas") {
        std::ostringstream output;
        std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

        Musica().musica_repetida(musicas);

        std::cout.rdbuf(oldOutput);

        std::string expectedOutput = "Não há músicas repetidas\n";

        CHECK(output.str() == expectedOutput);
    }
}

// Testes da classe Artista
TEST_CASE("06 - Teste construtor da classe Artista") {
    Artista artista("Nome do Artista");

    CHECK(artista.get_nome() == "Nome do Artista");
}

TEST_CASE("07 - Teste da função armazenar_musicas da classe Artista") {
    Artista artista("Nome do Artista");

    SUBCASE("Verificar armazenamento de músicas do artista") {
        std::vector<Musica> musicas;
        musicas.push_back(Musica(1, "Nome do Artista", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5));
        musicas.push_back(Musica(2, "Outro Artista", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5));
        musicas.push_back(Musica(3, "Nome do Artista", "Título 3", "Álbum 3", "Gênero 3", 2023, 3, 5, 1, 2.5));

        artista.armazenar_musicas(musicas);

        // Verificar se as músicas foram armazenadas corretamente dentro do objeto Artista
        const std::vector<Musica>& artistasMusicas = artista.get_artistas_musicas();
        CHECK(artistasMusicas.size() == 2);
        CHECK(artistasMusicas[0].get_titulo() == "Título 1");
        CHECK(artistasMusicas[0].get_album() == "Álbum 1");
        CHECK(artistasMusicas[0].get_ano() == 2021);
        CHECK(artistasMusicas[1].get_titulo() == "Título 3");
        CHECK(artistasMusicas[1].get_album() == "Álbum 3");
        CHECK(artistasMusicas[1].get_ano() == 2023);
    }

    SUBCASE("Verificar armazenamento de músicas de outro artista") {
        std::vector<Musica> musicas;
        musicas.push_back(Musica(1, "Nome do Artista", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5));
        musicas.push_back(Musica(2, "Outro Artista", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5));
        musicas.push_back(Musica(3, "Nome do Artista", "Título 3", "Álbum 3", "Gênero 3", 2023, 3, 5, 1, 2.5));

        artista.armazenar_musicas(musicas);

        // Verificar se as músicas do outro artista não foram armazenadas dentro do objeto Artista
        const std::vector<Musica>& artistasMusicas = artista.get_artistas_musicas();
        CHECK(artistasMusicas.size() == 1);
        CHECK(artistasMusicas[0].get_titulo() == "Título 1");
        CHECK(artistasMusicas[0].get_album() == "Álbum 1");
        CHECK(artistasMusicas[0].get_ano() == 2021);
    }
}

// Testes da função imprimir_discografia da classe Artista
TEST_CASE("08 - Teste da função imprimir_discografia da classe Artista") {
    Artista artista("Nome do Artista");

    SUBCASE("Verificar a impressão da discografia do artista") {
        std::ostringstream output;
        std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

        // Simulando a leitura das músicas do CSV
        std::vector<Musica> musicas;
        musicas.push_back(Musica(1, "Nome do Artista", "Título 1", "Álbum 1", "Gênero 1", 2021, 5, 7, 3, 4.5));
        musicas.push_back(Musica(2, "Outro Artista", "Título 2", "Álbum 2", "Gênero 2", 2022, 4, 6, 2, 3.5));
        musicas.push_back(Musica(3, "Nome do Artista", "Título 3", "Álbum 3", "Gênero 3", 2023, 3, 5, 1, 2.5));

        artista.imprimir_musicas(musicas);

        std::cout.rdbuf(oldOutput);

        std::string expectedOutput = "Discografia de Nome do Artista:\n"
                                     "Título 1 - Álbum 1 (2021)\n"
                                     "Título 3 - Álbum 3 (2023)\n";

        CHECK(output.str() == expectedOutput);
    }
}

