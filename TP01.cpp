#include <iostream>
#include <iomanip>
using namespace std;

// Variáveis globais
const int f = 15; // fileiras = linhas
const int p = 40; // poltronas = colunas
char m[f][p]; // mapa

void OcuparAssento(int fo, int ao) {
    m[fo][ao] = '#';
}

void LiberarAssento(int fo, int ao) {
    m[fo][ao] = '.';
}

void CalcularMatriz(int caso) {
    if (caso == 2) {
		cout << "\nMapa de assentos:\n" << endl;
		cout << "Legenda:" << endl;
		cout << "Assento ocupado: '#'" << endl;
		cout << "Assento vago: '.'\n" << endl;
	}
  	  
	int tar = 0; // total de assentos reservados
    for (int i = 0; i < f; ++i) {
	int ar = 0; // assentos reservados 
		for (int j = 0; j < p; ++j) {
            if (caso == 2) {
				cout << setw(2) << m[i][j] << " ";
			}
            if (m[i][j] == '#') {
                ar++;
                tar++;
            }
        }
    }
    if (caso == 2) {
		cout << "\n" << endl;
	}
    if (caso == 3) {
      cout << "\nQuantidade de assentos: " << tar << endl;
	}
}

float CalcularValorBilheteria() {
    float t = 0;
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < p; ++j) {
            if (m[i][j] == '#') {
                if (i < 5) { // fileiras 1 a 5
                    t += 50.0;
                } else if (i < 10) { // fileiras 6 a 10
                    t += 30.0;
                } else { // fileiras 11 a 15
                    t += 15.0;
                }
            }
        }
    }
    return t;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    bool continuar = true;
    int input;

    // Inicializar o mapa
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < p; ++j) {
            m[i][j] = '.';
        }
    }

    while (continuar) {
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupação" << endl;
        cout << "3. Faturamento" << endl;
        cout << "Digite o número da opção que deseja: ";
        cin >> input;

        switch (input) {
            case 0:
                cout << "\nPrograma encerrado." << endl;
                continuar = false;
                break;
            case 1:
                cout << "\nQual fileira deseja ocupar? ";
                int fo;
                cin >> fo;
                cout << "Qual assento deseja ocupar? ";
                int ao;
                cin >> ao;
                --fo; 
                --ao;
				if (m[fo][ao] == '#') {
                    cout << "\nEste assento já está ocupado.\n" << endl;
                    break;
                }
				if (fo < 0 || fo >= f || ao < 0 || ao >= p) {
                    cout << "\nFileira ou assento inválidos.\n" << endl;
                    break;
                }
                OcuparAssento(fo, ao);
                cout << "\nAssento reservado com sucesso.\n" << endl;
                break;
            case 2:
                CalcularMatriz(2);
                break;
  			case 3:
				CalcularMatriz(3);
				cout << "Valor da bilheteria: R$ " << CalcularValorBilheteria() << "\n" << endl;		
				break;
            default:
                cout << "\nOpção inválida.\n" << endl;
                break;
        }
    }

    return 0;
}