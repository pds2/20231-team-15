#ifndef USUARIO_H
#define USUARIO_H

#include <string>

enum genero {
    Pop, Rock, Funk, Sertanejo, Eletronica, Pagode, Samba, MPB
};

class Usuario{
    private:
        std::string username_;
        std::string password_;
        genero gosto_;
    public:
        Usuario( std::string username, std::string password);
        Usuario() = default;
        std::string get_nome();
        std::string get_senha();
        genero get_gosto();
};


#endif