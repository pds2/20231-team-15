        #include "BancoUsuarios.h"
        
        
        void BancoUsuarios::adicionar_usuario(std::string& nome, std::string& senha){
            _usuarios[nome] = Usuario(nome, senha);
        }
        bool BancoUsuarios::verificar_usuario(std::string& nome){
            return _usuarios.count(nome) > 0;
        }
        bool BancoUsuarios::verificar_senha(std::string& nome, std::string& senha){
            if (_usuarios.count(nome) > 0){
                if (_usuarios[nome].get_senha() == senha){
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
            return _usuarios[nome].get_gosto();
        }