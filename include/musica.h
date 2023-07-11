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
    int _id;
    std::string _titulo;    
    std::string _artista;
    std::string _album;
    std::string _genero;
    int _ano;
    int _dancabilidade;
    int _sentimento;
    int _barulho;
    double _media;
    bool is_liked;

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

    void set_is_liked(bool is_liked);

    std::string get_titulo() const;
    std::string get_artista() const;
    std::string get_album() const;
    std::string get_genero() const;
    int get_ano() const;
    int get_id() const;
    int get_dancabilidade() const;
    int get_sentimento() const;
    int get_barulho() const;
    double get_media() const;
    bool get_is_liked() const;

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