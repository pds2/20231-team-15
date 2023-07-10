#include "../include/usuario.h"

Usuario::Usuario( std::string username, std::string password):
        username_(username), password_ (password){}
        
std::string Usuario::get_nome(){
    return username_;
}
std::string Usuario::get_senha(){
    return password_;
}