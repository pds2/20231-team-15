#ifndef SISTEMA_H
#define SISTEMA_H
#include "usuario.h"
#include "banco_usuarios.h"

class Sistema {
    public:
        Usuario login(BancoUsuarios b);
        void criar_playlist(std::string user, std::string nome);
};
        

#endif