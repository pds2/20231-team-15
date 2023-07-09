#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario{
    private:
        std::string username_;
        std::string password_;
    public:
        Usuario( std::string username, std::string password);
        Usuario() = default;
        std::string get_nome();
        std::string get_senha();
};

#endif