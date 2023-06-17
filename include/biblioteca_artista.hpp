#ifndef TP2_BIBLIOTECA_ARTISTA
#define TP2_BIBLIOTECA_ARTISTA

#include "biblioteca.hpp"

class BibliotecaArtista : public Biblioteca {
    public:
        BibliotecaArtista();
        
    private:
        std::vector <int> v_biblioteca_artista; 
};

#endif