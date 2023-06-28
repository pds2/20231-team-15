#ifndef TP2_LISTA_MUSICAS
#define TP2_LISTA_MUSICAS

#include <vector>

class ListaMusicas {
    public:
        ListaMusicas();
        ListaMusicas(const std::vector <int> & lista_musicas);
        // void set_v(std::vector <int> v_lista_musicas);
    
    private:
        static int contador_id_lista_musicas;
        int _id_lista_musicas;
        std::vector <int> v_lista_musicas;
};

#endif