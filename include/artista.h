#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>
#include <vector>
#include <string>

#include "musica.h"

/**

    @class Artista
    @brief Representa um artista musical.
    */
    class Artista {
    private:
    static int contador_id_artista; // Contador de IDs dos artistas */
    int _id_artista; // ID do artista */
    std::string _nome; // Nome do artista */
    std::vector<Musica> artistas_musicas; // Lista de músicas do artista */

public:
/**
* @brief Construtor da classe Artista.
* @param nome O nome do artista.
*/
Artista(const std::string& nome);

/**
 * @brief Construtor default da classe Artista.
 */
Artista();

/**
 * @brief Retorna o nome do artista.
 * @return O nome do artista.
 */
std::string get_nome() const;

/**
 * @brief Retorna o ID do artista.
 * @return O ID do artista.
 */
int get_id() const;

/**
 * @brief Retorna as músicas do artista.
 * @return Um vetor contendo as músicas do artista.
 */
std::vector<Musica> get_artistas_musicas() const;

/**
 * @brief Armazena as músicas do artista.
 * @param musicas Um vetor contendo as músicas a serem armazenadas.
 */
void armazenar_musicas(const std::vector<Musica>& musicas);

/**
 * @brief Imprime as informações do artista.
 */
void imprimir_artista() const;

/**
 * @brief Imprime a discografia do artista.
 */
void imprimir_discografia() const;

/**
 * @brief Imprime as músicas do artista.
 * @param musicas Um vetor contendo as músicas a serem impressas.
 */
void imprimir_musicas(const std::vector<Musica>& musicas) const;

};

#endif // ARTISTA_H