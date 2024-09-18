#ifndef TECNICO_H
#define TECNICO_H

#include <string>

class Tecnico {
private:
    int idTEC;
    std::string nometec;
    std::string senha;
    bool cadastrado;

public:
    Tecnico();
    bool login(const std::string& nome, const std::string& senha) const;

    void cadastrar();


    bool isCadastrado() const;


    std::string getNome() const;


};



#endif // TECNICO_H
