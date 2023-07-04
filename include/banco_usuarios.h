#ifndef BANCO_USUARIOS_H
#define BANCO_USUARIOS_H

#include <string>
#include <map>

#include "usuario.h"

class senha_incorreta_e{};
class usuario_nao_existe_e{};
class arquivo_nao_encontrado_e{};

class BancoUsuarios{
    private:
        std::map<std::string, Usuario> _usuarios;
        std::string _endereco_arquivo;
    public:
        BancoUsuarios(std::string endereco);
        void salvar_usuarios();
        void adicionar_usuario(std::string& nome, std::string& senha);
        bool verificar_usuario(std::string& nome);
        bool verificar_senha(std::string& nome, std::string& senha);
};

#endif