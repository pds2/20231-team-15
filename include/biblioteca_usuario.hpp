#ifndef TP2_BIBLIOTECA_USUARIO
#define TP2_BIBLIOTECA_USUARIO

#include "biblioteca.hpp"

class BibliotecaUsuario : public Biblioteca {
    public:
        BibliotecaUsuario();
        
    private:
        std::vector <int> v_biblioteca_usuario; 
};

#endif