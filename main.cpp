#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definição da classe Material
class Material {
public:
    string nome;
    string codigoSAP;
    int quantidadeMaxima;
    int quantidadeMinima;
    int quantidadeAtual;
    string rastreabilidade;

    Material(string nome, string codigoSAP, int quantidadeMaxima, int quantidadeMinima, int quantidadeAtual, string rastreabilidade)
        : nome(nome), codigoSAP(codigoSAP), quantidadeMaxima(quantidadeMaxima), quantidadeMinima(quantidadeMinima), quantidadeAtual(quantidadeAtual), rastreabilidade(rastreabilidade) {}
};

// Definição da classe Técnico
class Tecnico {
public:
    string nome;
    string senha;
    string registro;

    Tecnico(string nome, string senha, string registro) : nome(nome), senha(senha), registro(registro) {}
};

// Funções auxiliares
void limparTela() {
    // Código para limpar a tela baseado no sistema operacional
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Unix/Linux
    #endif
}

bool loginTecnico(const vector<Tecnico>& tecnicos, const string& nome, const string& senha) {
    for (const auto& tecnico : tecnicos) {
        if (tecnico.nome == nome && tecnico.senha == senha) {
            return true;
        }
    }
    return false;
}

void exibirMenuPrincipal() {
    cout << "1. Login Técnico\n";
    cout << "2. Cadastrar Técnico\n";
    cout << "3. Sair\n";
    cout << "Escolha uma opção: ";
}

void exibirMenuTecnico(const string& nome) {
    cout << "Bem-vindo, " << nome << "!\n";
    cout << "1. Cadastrar Material\n";
    cout << "2. Adicionar Material\n";
    cout << "3. Retirar Material\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opção: ";
}

void cadastrarMaterial(vector<Material>& materiais) {
    string nome, codigoSAP, rastreabilidade;
    int quantidadeMaxima, quantidadeMinima, quantidadeAtual;

    cout << "Digite o nome do material: ";
    cin.ignore();  // Limpa o buffer do cin
    getline(cin, nome);
    cout << "Digite o código SAP: ";
    getline(cin, codigoSAP);
    cout << "Digite a quantidade máxima: ";
    cin >> quantidadeMaxima;
    cout << "Digite a quantidade mínima: ";
    cin >> quantidadeMinima;
    cout << "Digite a quantidade atual: ";
    cin >> quantidadeAtual;
    cout << "Digite a rastreabilidade: ";
    cin.ignore();  // Limpa o buffer do cin
    getline(cin, rastreabilidade);

    materiais.push_back(Material(nome, codigoSAP, quantidadeMaxima, quantidadeMinima, quantidadeAtual, rastreabilidade));
    cout << "Material cadastrado com sucesso!\n";
}

void adicionarMaterial(vector<Material>& materiais) {
    string codigoSAP;
    int quantidade;

    cout << "Digite o código SAP do material: ";
    cin.ignore();  // Limpa o buffer do cin
    getline(cin, codigoSAP);
    cout << "Digite a quantidade a ser adicionada: ";
    cin >> quantidade;

    for (auto& material : materiais) {
        if (material.codigoSAP == codigoSAP) {
            material.quantidadeAtual += quantidade;
            cout << "Quantidade adicionada com sucesso!\n";
            return;
        }
    }
    cout << "Material não encontrado.\n";
}

void retirarMaterial(vector<Material>& materiais) {
    string codigoSAP;
    int quantidade;

    cout << "Digite o código SAP do material: ";
    cin.ignore();  // Limpa o buffer do cin
    getline(cin, codigoSAP);
    cout << "Digite a quantidade a ser retirada: ";
    cin >> quantidade;

    for (auto& material : materiais) {
        if (material.codigoSAP == codigoSAP) {
            if (material.quantidadeAtual >= quantidade) {
                material.quantidadeAtual -= quantidade;
                cout << "Quantidade retirada com sucesso!\n";
            } else {
                cout << "Quantidade insuficiente.\n";
            }
            return;
        }
    }
    cout << "Material não encontrado.\n";
}

void cadastrarTecnico(vector<Tecnico>& tecnicos) {
    string nome, senha, registro;

    cout << "Digite o nome do técnico: ";
    cin.ignore();  // Limpa o buffer do cin
    getline(cin, nome);
    cout << "Digite a senha do técnico: ";
    getline(cin, senha);
    cout << "Digite o registro do técnico: ";
    getline(cin, registro);

    tecnicos.push_back(Tecnico(nome, senha, registro));
    cout << "Técnico cadastrado com sucesso!\n";
}

int main() {
    vector<Tecnico> tecnicos = { {"joao", "senha123", "001"}, {"maria", "senha456", "002"} };
    vector<Material> materiais;

    while (true) {
        int opcao;
        limparTela();
        exibirMenuPrincipal();
        cin >> opcao;

        if (opcao == 1) {
            string nome, senha;
            cout << "Digite seu nome: ";
            cin.ignore();  // Limpa o buffer do cin
            getline(cin, nome);
            cout << "Digite sua senha: ";
            getline(cin, senha);

            if (loginTecnico(tecnicos, nome, senha)) {
                while (true) {
                    int opcaoTecnico;
                    limparTela();
                    exibirMenuTecnico(nome);
                    cin >> opcaoTecnico;

                    if (opcaoTecnico == 1) {
                        cadastrarMaterial(materiais);
                    } else if (opcaoTecnico == 2) {
                        adicionarMaterial(materiais);
                    } else if (opcaoTecnico == 3) {
                        retirarMaterial(materiais);
                    } else if (opcaoTecnico == 4) {
                        break;
                    } else {
                        cout << "Opção inválida.\n";
                    }
                }
            } else {
                cout << "Nome ou senha inválidos.\n";
            }
        } else if (opcao == 2) {
            cadastrarTecnico(tecnicos);
        } else if (opcao == 3) {
            break;
        } else {
            cout << "Opção inválida.\n";
        }
    }

    return 0;
}
