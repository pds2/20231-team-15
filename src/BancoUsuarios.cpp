        #include "BancoUsuarios.h"
        
        
        void BancoUsuarios::adicionar_usuario(std::string& nome, std::string& senha){
            usuarios_[nome] = Usuario(nome, senha);
        }
        bool BancoUsuarios::verificar_usuario(std::string& nome){
            return usuarios_.count(nome) > 0;
        }
        bool BancoUsuarios::verificar_senha(std::string& nome, std::string& senha){
            if (usuarios_.count(nome) > 0){
                if (usuarios_[nome].get_senha() == senha){
                    return true;
                } else {
                    throw senha_incorreta_e();
                    return false;
                }
            } else {
                throw usuario_nao_existe_e();
                return false;
            }
        }
        genero BancoUsuarios::gosto_do_usuario(std::string& nome){
            return usuarios_[nome].get_gosto();
        }