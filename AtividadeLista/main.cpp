#include <iostream>

#define MAX 100

class ListaSequencial {
private:
    int dados[MAX];
    int tamanho;

public:
    ListaSequencial() {
        tamanho = 0;
    }

    bool estaVazia() const {
        return tamanho == 0;
    }

    bool estaCheia() const {
        return tamanho == MAX;
    }

    int obterTamanho() const {
        return tamanho;
    }

    int obterElemento(int pos) const {
        if (pos < 1 || pos > tamanho) {
            std::cerr << "Posição inválida.\n";
            return -1;
        }
        return dados[pos - 1];
    }

    bool modificarElemento(int pos, int novoValor) {
        if (pos < 1 || pos > tamanho) {
            std::cerr << "Posição inválida.\n";
            return false;
        }
        dados[pos - 1] = novoValor;
        return true;
    }

    bool inserirElemento(int pos, int valor) {
        if (estaCheia()) {
            std::cerr << "Lista cheia.\n";
            return false;
        }
        if (pos < 1 || pos > tamanho + 1) {
            std::cerr << "Posição inválida.\n";
            return false;
        }
        for (int i = tamanho; i >= pos; --i) {
            dados[i] = dados[i - 1];
        }
        dados[pos - 1] = valor;
        tamanho++;
        return true;
    }

    bool removerElemento(int pos) {
        if (estaVazia()) {
            std::cerr << "Lista vazia.\n";
            return false;
        }
        if (pos < 1 || pos > tamanho) {
            std::cerr << "Posição inválida.\n";
            return false;
        }
        for (int i = pos - 1; i < tamanho - 1; ++i) {
            dados[i] = dados[i + 1];
        }
        tamanho--;
        return true;
    }

    void exibir() const {
        if (estaVazia()) {
            std::cout << "Lista vazia.\n";
            return;
        }
        std::cout << "Lista: ";
        for (int i = 0; i < tamanho; ++i) {
            std::cout << dados[i] << " ";
        }
        std::cout << "\n";
    }
};

// Função menu
void exibirMenu() {
    std::cout << "\n=== Menu ===\n";
    std::cout << "1. Inserir elemento\n";
    std::cout << "2. Remover elemento\n";
    std::cout << "3. Modificar elemento\n";
    std::cout << "4. Obter elemento\n";
    std::cout << "5. Exibir lista\n";
    std::cout << "6. Tamanho da lista\n";
    std::cout << "7. Verificar se está vazia\n";
    std::cout << "8. Verificar se está cheia\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    ListaSequencial lista;
    int opcao, pos, valor;

    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Posição para inserir (1 a " << lista.obterTamanho() + 1 << "): ";
                std::cin >> pos;
                std::cout << "Valor: ";
                std::cin >> valor;
                lista.inserirElemento(pos, valor);
                break;

            case 2:
                std::cout << "Posição para remover (1 a " << lista.obterTamanho() << "): ";
                std::cin >> pos;
                lista.removerElemento(pos);
                break;

            case 3:
                std::cout << "Posição para modificar (1 a " << lista.obterTamanho() << "): ";
                std::cin >> pos;
                std::cout << "Novo valor: ";
                std::cin >> valor;
                lista.modificarElemento(pos, valor);
                break;

            case 4:
                std::cout << "Posição para obter (1 a " << lista.obterTamanho() << "): ";
                std::cin >> pos;
                std::cout << "Elemento: " << lista.obterElemento(pos) << "\n";
                break;

            case 5:
                lista.exibir();
                break;

            case 6:
                std::cout << "Tamanho: " << lista.obterTamanho() << "\n";
                break;

            case 7:
                std::cout << (lista.estaVazia() ? "Lista está vazia.\n" : "Lista NÃO está vazia.\n");
                break;

            case 8:
                std::cout << (lista.estaCheia() ? "Lista está cheia.\n" : "Lista NÃO está cheia.\n");
                break;

            case 0:
                std::cout << "Encerrando...\n";
                break;

            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
