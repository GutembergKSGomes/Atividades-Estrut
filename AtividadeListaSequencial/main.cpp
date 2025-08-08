#include <iostream>
using namespace std;

#define TAMANHO_MAX 5

class Fila {
private:
    int dados[TAMANHO_MAX];
    int inicio;
    int fim;
    int tamanho;

public:
    Fila() {
        inicio = 0;
        fim = 0;
        tamanho = 0;
    }

    bool estaVazia() const {
        return tamanho == 0;
    }

    bool estaCheia() const {
        return tamanho == TAMANHO_MAX;
    }

    bool inserir(int valor) {
        if (estaCheia()) return false;
        dados[fim] = valor;
        fim = (fim + 1) % TAMANHO_MAX;
        tamanho++;
        return true;
    }

    bool remover(int &valor) {
        if (estaVazia()) return false;
        valor = dados[inicio];
        inicio = (inicio + 1) % TAMANHO_MAX;
        tamanho--;
        return true;
    }

    bool consultarInicio(int &valor) const {
        if (estaVazia()) return false;
        valor = dados[inicio];
        return true;
    }

    void exibirFila() const {
        if (estaVazia()) {
            cout << "[Fila vazia]" << endl;
            return;
        }

        cout << "Fila: ";
        for (int i = 0; i < tamanho; ++i) {
            int indice = (inicio + i) % TAMANHO_MAX;
            cout << dados[indice] << " ";
        }
        cout << endl;
    }
};

int main() {
    Fila fila;
    int opcao, valor;

    do {
        cout << "\n========== MENU DA FILA ==========\n";
        cout << "1. Inserir elemento\n";
        cout << "2. Remover elemento\n";
        cout << "3. Consultar inicio\n";
        cout << "4. Verificar se esta vazia\n";
        cout << "5. Verificar se esta cheia\n";
        cout << "6. Exibir fila\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite o valor a inserir: ";
            cin >> valor;
            if (fila.inserir(valor))
                cout << "Valor inserido com sucesso!\n";
            else
                cout << "Fila cheia. Nao foi possível inserir.\n";
            break;

        case 2:
            if (fila.remover(valor))
                cout << "Valor removido: " << valor << endl;
            else
                cout << "Fila vazia. Nada a remover.\n";
            break;

        case 3:
            if (fila.consultarInicio(valor))
                cout << "Inicio da fila: " << valor << endl;
            else
                cout << "Fila vazia.\n";
            break;

        case 4:
            cout << (fila.estaVazia() ? "A fila esta vazia.\n" : "A fila NAO esta vazia.\n");
            break;

        case 5:
            cout << (fila.estaCheia() ? "A fila esta cheia.\n" : "A fila NAO esta cheia.\n");
            break;

        case 6:
            fila.exibirFila();
            break;

        case 0:
            cout << "Encerrando o programa.\n";
            break;

        default:
            cout << "Opcao inválida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
