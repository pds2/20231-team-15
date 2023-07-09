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

class Sistema {
    public:
        // Funções referentes à classe Usuario
        Usuario login(BancoUsuarios b);

        // Funções referentes à classe playlist
        void criar_playlist(std::string user, std::string nome);

        // Funções referentes à classe música
        std::vector <Musica> inicializar_musicas(const std::string& arquivo_path);
        void listar_id_musica_artista(std::vector <Musica> lista_musicas) const;

        // Funções referentes à classe Artista
        std::vector <Artista> inicializar_artistas(const std::vector <Musica>& lista_musicas);
        void listar_artistas(std::vector <Artista> lista_artistas) const;

        // Funções referentes à classe Album
        std::vector <Album> inicializar_albuns(const std::vector <Musica>& lista_musicas, const std::vector <Artista>& lista_artistas);
        std::vector <Album> inserir_musicas_album(std::vector <Album> lista_albuns, std::vector <Musica> lista_musicas);
        void listar_albuns(std::vector <Album> listar_albuns) const;
};     

#endif