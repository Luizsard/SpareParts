#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

using namespace std;

class Material {
private:
    string descricao;
    int codSAP;
    int quantidade;
    string endereco;
    int maxQuantidade;
    int minQuantidade;
    int valorUnidade;
    int classe;  // 0 - Mecânico, 1 - Elétrica

public:
    // Construtor
    Material();

    // Setters
    void setInformacoes(string desc, int sap, int qtd, string end, int maxQtd, int minQtd, int valorUN, int cls);

    // Getters
    string getDescricao() const;
    int getCodSAP() const;
    int getQuantidade() const;
    string getEndereco() const;
    int getMaxQuantidade() const;
    int getMinQuantidade() const;
    int getValorUnidade() const;
    int getClasse() const;

    // Métodos para modificar quantidade
    void adicionarQuantidade(int qtd);
    void retirarQuantidade(int qtd);
};

#endif
