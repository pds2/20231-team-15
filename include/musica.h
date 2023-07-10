#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

/**

    @class Musica
    @brief Representa uma música.
**/
class Musica {
    private:
        int _id; // ID da música 
        std::string _titulo; // Título da música 
        std::string _artista; // Artista da música 
        std::string _album; // Álbum da música 
        std::string _genero; // Gênero da música 
        int _ano; // Ano de lançamento da música 
        int _dancabilidade; // Índice de dancabilidade da música 
        int _sentimento; // Índice de sentimento da música 
        int _barulho; // Índice de barulho da música 
        double _media; // Média da música 

    public:
/**
* @brief Construtor default da classe Musica.
*/
        Musica();

/**
 * @brief Construtor da classe Musica.
 * @param id O ID da música.
 * @param artista O artista da música.
 * @param titulo O título da música.
 * @param album O álbum da música.
 * @param genero O gênero da música.
 * @param ano O ano de lançamento da música.
 * @param dancabilidade O índice de dancabilidade da música.
 * @param sentimento O índice de sentimento da música.
 * @param barulho O índice de barulho da música.
 * @param media A média da música.
 */
        Musica(int id, const std::string& artista, const std::string& titulo, const std::string& album,
               const std::string& genero, int ano, int dancabilidade, int sentimento, int barulho, double media);

/**
 * @brief Retorna o título da música.
 * @return O título da música.
 */
        std::string get_titulo() const;

/**
 * @brief Retorna o artista da música.
 * @return O artista da música.
 */
        std::string get_artista() const;

/**
 * @brief Retorna o álbum da música.
 * @return O álbum da música.
 */
        std::string get_album() const;

/**
 * @brief Retorna o gênero da música.
 * @return O gênero da música.
 */
        std::string get_genero() const;

/**
 * @brief Retorna o ano de lançamento da música.
 * @return O ano de lançamento da música.
 */
        int get_ano() const;

/**
 * @brief Retorna o ID da música.
 * @return O ID da música.
 */
        int get_id() const;

/**
 * @brief Retorna o índice de dancabilidade da música.
 * @return O índice de dancabilidade da música.
 */
        int get_dancabilidade() const;

/**
 * @brief Retorna o índice de sentimento da música.
 * @return O índice de sentimento da música.
 */
        int get_sentimento() const;

/**
 * @brief Retorna o índice de barulho da música.
 * @return O índice de barulho da música.
 */
        int get_barulho() const;

/**
 * @brief Retorna a média da música.
 * @return A média da música.
 */
        double get_media() const;

/**
 * @brief Retorna a própria música.
 * @return A própria música.
 */
        Musica get_musica() const;

/**
 * @brief Imprime os detalhes da música.
 */
        void imprimir_detalhes() const;

/**
 * @brief Imprime todas as músicas de um vetor.
 * @param musicas O vetor contendo as músicas a serem impressas.
 */
        void imprimir_todas_musicas(std::vector<Musica>) const;

/**
 * @brief Verifica se a música já está presente no vetor de músicas.
 * @param musicas O vetor de músicas a ser verificado.
 */
        void musica_repetida(std::vector<Musica>) const;

/**
 * @brief Lê as músicas de um arquivo CSV e armazena-as em um vetor.
 * @param nomeArquivo O nome do arquivo CSV contendo as músicas.
 * @return Um vetor contendo as músicas lidas do arquivo.
 */
        std::vector<Musica> ler_musicas_do_csv(const std::string& nomeArquivo);

/**
 * @brief Imprime somente o ID, artista e título da música.
 */
        void imprimir_id_musica_artista();

};

#endif // MUSICA_H