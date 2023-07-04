#ifndef BANCO_USUARIOS_H
#define BANCO_USUARIOS_H

#include <sstream>
#include <fstream>
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
        bool verificar_usuario(const std::string& nome);
        bool verificar_senha(const std::string& nome, const std::string& senha);
        void adicionar_usuario(const std::string& nome, const std::string& senha);
};

#endif