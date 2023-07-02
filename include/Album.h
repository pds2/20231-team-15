#ifndef ALBUM_H
#define ALBUM_H

class Album : public ListaMusica {
    private:
        std::string _nome;
        Artista _artista;
    public:
        std::string get_autor()
        Album(Artista artista);
        void adicionar_musica(Musica m) override;

};


#endif