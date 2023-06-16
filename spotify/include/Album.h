#ifndef ALBUM_H
#define ALBUM_H

class Album : public ListaMusica {
    private:
        Artista artista_;
    public:
        Album(Artista artista); 
};


#endif