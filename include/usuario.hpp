#ifndef TP2_PLAYLIST
#define TP2_PLAYLIST

#include "lista_musicas.hpp"

class Playlist : public ListaMusicas {
    public:
        Playlist(const int &id_usuario, std::vector <int> lista_musicas);
        
    private:
        int _id_usuario;

};

#endif