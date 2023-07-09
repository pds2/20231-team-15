#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

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
TEST_CASE("Teste construtor da classe Musica") {
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
TEST_CASE("Teste construtor padrão da classe Musica") {
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
TEST_CASE("Teste da função imprimir_detalhes da classe Musica") {
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
TEST_CASE("Teste da função ler_musicas_do_csv da classe Musica") {
    Musica musica;
    std::vector<Musica> musicas = musica.ler_musicas_do_csv("../musicas.csv");

    CHECK(musicas.size() > 0);
}

// Testes da função imprimir todas músicas da classe Musica
TEST_CASE("Teste da função musica_repetida da classe Musica") {
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
