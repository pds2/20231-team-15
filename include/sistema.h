#ifndef SISTEMA_H
#define SISTEMA_H

#include "usuario.h"
#include "banco_usuarios.h"
#include "musica.h"
#include "artista.h"
#include "lista_musica.h"
#include "album.h"
#include "playlist.h"
#include "conjunto_listas.h"
#include "biblioteca.h"
#include "discografia.h"
#include "recomendacao.h"

class id_musica_nao_existe {};
class id_artista_nao_existe {};

class Sistema {
    public:
        //    METODOS DO SISTEMA

        /**
         * @brief Função para iniciar o sistema.
         */
        void iniciar_sistema();

        /**
         * @brief Função para limpar o terminal.
         */
        void limpar_terminal();


        //    METODOS DA CLASSE MÚSICA

        /**
         * @brief Função para inicializar a lista de músicas.
         * @param musicas_path O caminho do arquivo CSV contendo as informações das músicas.
         * @return A lista de músicas inicializada.
         */
        std::vector <Musica> inicializar_musicas(const std::string& arquivo_path);

        /**
         * @brief Função para listar apenas o ID, nome da música e nome do artista.
         * @param lista_musicas A lista de músicas a serem listadas.
         */
        void listar_id_musica_artista(std::vector <Musica> lista_musicas) const;

        /**
         * @brief Função para encontrar o objeto da classe musica por meio do id
         * @param id o id da musica desejada.
         * @param lista_musicas A lista de músicas a ser percorrida.
         */
        Musica identificar_musica_por_id(int id, std::vector <Musica> lista_musicas) const;

        /**
         * @brief Função para visualizar as informações detalhadas da música
         * @param lista_musicas A lista de músicas a ser percorrida.
         */
        void informacoes_da_musica(std::vector <Musica> lista_musicas);


        //    METODOS DA CLASSE ARTISTA

        /**
         * @brief Função para inicializar a lista de artistas.
         * @param lista_musicas A lista de músicas para obter os artistas.
         * @return A lista de artistas inicializada.
         */
        std::vector <Artista> inicializar_artistas(const std::vector <Musica>& lista_musicas);

        /**
         * @brief Função para listar os artistas.
         * @param lista_artistas A lista de artistas a serem listados.
         */
        void listar_artistas(std::vector <Artista> lista_artistas) const;

        /**
         * @brief Função para encontrar o objeto da classe artista por meio do id
         * @param id o id do artista desejado.
         * @param lista_musicas A lista de artistas a ser percorrida.
         */
        Artista identificar_artista_por_id(int id, std::vector <Artista> lista_artistas) const;


        //    METODOS DA CLASSE ALBUM

        /**
         * @brief Função para inicializar a lista de álbuns.
         * @param lista_musicas A lista de músicas para obter os álbuns.
         * @param lista_artistas A lista de artistas para obter os álbuns.
         * @return A lista de álbuns inicializada.
         */
        std::vector <Album> inicializar_albuns(const std::vector <Musica>& lista_musicas, const std::vector <Artista>& lista_artistas);
        
        /**
         * @brief Função para inserir as músicas nos álbuns correspondentes.
         * @param lista_albuns A lista de álbuns onde as músicas serão inseridas.
         * @param lista_musicas A lista de músicas a serem inseridas nos álbuns.
         * @return A lista de álbuns atualizada.
         */
        std::vector <Album> inserir_musicas_album(std::vector <Album> lista_albuns, std::vector <Musica> lista_musicas);
        
        /**
         * @brief Função para listar os álbuns.
         * @param listar_albuns A lista de álbuns a serem listados.
         */
        void listar_albuns(std::vector <Album> listar_albuns) const;

        // METODOS DA CLASSE DISCOGRAFIA
        void exibir_discografia(std::vector <Artista> listar_artistas, std::vector <Album> listar_albuns) const;


        // METODOS DA CLASSE USUARIO

        /**
         * @brief Função para realizar o login do usuário.
         * @param b O objeto BancoUsuarios contendo as informações de usuários e senhas.
         * @return O objeto Usuario correspondente ao usuário que realizou o login com sucesso.
         */
        Usuario login(BancoUsuarios b);

        //METODOS DA CLASSE BIBLIOTECA

        /**
        * @brief Função para exibir as playlists da biblioteca;
        */
        Playlist& buscar_playlist(Biblioteca &b, int id);


        // METODOS DA CLASSE PLAYLIST
        /**
         * @brief Função para criar uma playlist.
         * @param b Recebe a string correspondente ao username do usuário logado.
         * @return A playlist criada.
         */
        Playlist criar_playlist(std::string user);

        /**
         * @brief Função para editar a playlist. Permite adicionar, remover e trocar músicas de lugar.
         * @param b recebe uma referência para a Playlist a ser editada e o vetor de músicas que foi inicializado.
         */
        void editar_playlist(Playlist &p, std::vector<Musica> lista_musicas);


        // METODOS DA CLASSE RECOMENDACAO
        void recomendar_musicas(std::vector <Musica> lista_musicas, std::string parametro);
        void recomendar_musica_aleatoria(std::vector <Musica> lista_musicas);
    private:

};     

#endif