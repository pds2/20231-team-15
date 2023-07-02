#ifndef TP2_LISTA_MUSICAS
#define TP2_LISTA_MUSICAS

#include <vector>

class ListaMusicas {
    public:
        ListaMusicas(const std::vector <int> & lista_musicas);
        int get_id_lista_musicas() const;
        void printar();
    
    private:
        static int contador_id_lista_musicas;
        int _id_lista_musicas;
        std::vector <int> m_lista_musicas;
};

#endif