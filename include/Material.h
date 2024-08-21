#ifndef MATERIAL_H
#define MATERIAL_H


class Material
{
    public:

        string descricao;
        string rastreabilidade;
        int QTD;
        int codSAP;
        int maxQTD;
        int minQTD;
        int valorUN;

        // Classificar o tipo do material
        enum classificacao {
        MECANICA,
        ELETRICA,
        };
        classificacao Classe;
        Material();
        virtual ~Material();

    protected:

    private:
};

#endif // MATERIAL_H
