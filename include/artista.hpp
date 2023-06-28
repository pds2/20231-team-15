#ifndef TP2_ALBUM
#define TP2_ALBUM

#include "lista_musicas.hpp"

class Album : public ListaMusicas {
    public:
        Album(const int &id_artista, std::vector <int> lista_musicas);
        
    private:
        int _id_artista;
};

#endif