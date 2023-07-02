#ifndef BANCO_USUARIOS_H
#define BANCO_USUARIOS_H

#include <map>
#include "Usuario.h"

class senha_incorreta_e{};
class usuario_nao_existe_e{};

class BancoUsuarios{
    private:
        std::map<std::string, Usuario> _usuarios;
    public:
        void adicionar_usuario(std::string& nome, std::string& senha);
        bool verificar_usuario(std::string& nome);
        bool verificar_senha(std::string& nome, std::string& senha);
        genero gosto_do_usuario(std::string& nome);

};

#endif