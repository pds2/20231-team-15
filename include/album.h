#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <exception>

#include "artista.h"
#include "lista_musica.h"

// Exceções

/**
 * @brief Classe de exceção para músicas repetidas no álbum.
 */
class musica_repetida_album_e : public std::exception {
public:
    /**
     * @brief Retorna uma mensagem descrevendo o erro.
     * @return A mensagem de erro.
     */
    const char* what() const noexcept override {
        return "Música já existente no álbum!";
    }
};

// Classe Album

/**
 * @brief Classe que representa um álbum de músicas.
 */
class Album : public Lista_musica {
private:
    std::string _nome;      ///< Nome do álbum.
    Artista _artista;       ///< Artista do álbum.
public:
    /**
     * @brief Construtor da classe Album.
     * @param nome O nome do álbum.
     * @param artista O artista do álbum.
     */
    Album(std::string nome, Artista artista);

    // Getters

    /**
     * @brief Obtém o nome do álbum.
     * @return O nome do álbum.
     */
    std::string get_nome() const;

    /**
     * @brief Obtém o nome do autor do álbum.
     * @return O nome do autor do álbum.
     */
    std::string get_autor() const;

    /**
     * @brief Obtém o artista do álbum.
     * @return O artista do álbum.
     */
    Artista get_artista() const;

    // Métodos

    /**
     * @brief Adiciona uma música ao álbum.
     * @param m A música a ser adicionada.
     * @throws musica_repetida_album_e se a música já existe no álbum.
     */
    void adicionar_musica(Musica &m);

    /**
     * @brief Exibe as músicas do álbum.
     */
    void exibe_musicas();

    /**
     * @brief Imprime as informações do álbum.
     */
    void imprimir_informacoes();
};

#endif
