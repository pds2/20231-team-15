#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <algorithm>
#include <string>
#include <exception>

#include "usuario.h"
#include "lista_musica.h"

/**

    @class musica_repetida_playlist_e
    @brief Exceção para músicas repetidas em uma playlist.
    */
class musica_repetida_playlist_e : public std::exception {};

/**

    @class Playlist
    @brief Representa uma playlist de músicas.
    A classe Playlist é derivada da classe Lista_musica e representa uma coleção de músicas organizadas em uma playlist.
    */
class Playlist : public Lista_musica {
        private:
                std::string _nome; // Nome da playlist
                std::string _username; // Nome de usuário associado à playlist 

        public:
/**
* @brief Destrutor da classe Playlist.
*/
                ~Playlist();

/**
 * @brief Construtor da classe Playlist.
 * @param nome O nome da playlist.
 * @param username O nome de usuário associado à playlist.
 */
                Playlist(std::string nome, std::string username);

/**
 * @brief Retorna o nome de usuário associado à playlist.
 * @return O nome de usuário associado à playlist.
 */
                std::string get_usuario();

/**
 * @brief Retorna o nome da playlist.
 * @return O nome da playlist.
 */
                std::string get_nome();

/**
 * @brief Adiciona uma música à playlist.
 * @param m A música a ser adicionada.
 * @throw musica_repetida_playlist_e se a música já estiver presente na playlist.
 */
                void adicionar_musica(Musica m);

/**
 * @brief Remove uma música da playlist.
 * @param m A música a ser removida.
 */
                void remover_musica(Musica m);

/**
 * @brief Troca a posição de duas músicas na playlist.
 * @param musica1 A posição da primeira música.
 * @param musica2 A posição da segunda música.
 */
                void trocar_musica(int musica1, int musica2);

/**
 * @brief Mostra as músicas presentes na playlist.
 */
                void mostrar_playlist();

/**
 * @brief Retorna a música na posição especificada na playlist.
 * @param pos A posição da música na playlist.
 * @return A música na posição especificada.
 */
                Musica get_musica_da_posicao(int pos);

/**
 * @brief Iterador begin.
 */ 
                std::vector<Musica>::iterator begin();

/**
 * @brief Iterador end.
 */
                std::vector<Musica>::iterator end();

};

#endif // PLAYLIST_H
