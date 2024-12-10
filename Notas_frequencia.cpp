#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    const int MAX_ALUNOS = 10;
    const float MEDIA_MINIMA = 5.0;
    const int FREQUENCIA_MINIMA = 60;

    string matriculas[MAX_ALUNOS];
    string nomes[MAX_ALUNOS];
    float medias[MAX_ALUNOS];
    int frequencias[MAX_ALUNOS];
    int nAlunos;

    cout << "Quantos alunos deseja cadastrar (máximo " << MAX_ALUNOS << ")? ";
    cin >> nAlunos;
    if (nAlunos > MAX_ALUNOS) nAlunos = MAX_ALUNOS;

    for (int i = 0; i < nAlunos; i++) {
        cout << "\nCadastro do aluno " << (i + 1) << ":\n";
        cout << "Matrícula (até 5 caracteres): ";
        cin >> matriculas[i];
        cout << "Nome (até 10 caracteres): ";
        cin.ignore();
        getline(cin, nomes[i]);
        cout << "Média do aluno (0 a 10): ";
        cin >> medias[i];
        cout << "Frequência do aluno (0 a 100): ";
        cin >> frequencias[i];
    }

    int opcao;
    do {
        cout << "\nMenu de Opções:\n";
        cout << "1. Imprime a média de um aluno\n";
        cout << "2. Imprime a média de todos os alunos\n";
        cout << "3. Imprime a lista de aprovados\n";
        cout << "4. Imprime a lista de reprovados por média\n";
        cout << "5. Imprime a lista de reprovados por frequência\n";
        cout << "6. Imprime a lista de reprovados por média e frequência\n";
        cout << "7. Fim\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            string matricula;
            cout << "Digite a matrícula do aluno: ";
            cin >> matricula;
            bool encontrado = false;

            for (int i = 0; i < nAlunos; i++) {
                if (matriculas[i] == matricula) {
                    cout << "Aluno: " << nomes[i] << " - Média: " << medias[i] << ", Frequência: " << frequencias[i] << "%\n";
                    if (medias[i] >= MEDIA_MINIMA && frequencias[i] >= FREQUENCIA_MINIMA) {
                        cout << "Status: Aprovado\n";
                    } else {
                        cout << "Status: Reprovado\n";
                    }
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "Aluno não encontrado!\n";
            }

        } else if (opcao == 2) {
            float somaMedias = 0;
            for (int i = 0; i < nAlunos; i++) {
                somaMedias += medias[i];
            }
            cout << "Média da turma: " << fixed << setprecision(1) << somaMedias / nAlunos << endl;

        } else if (opcao == 3) {
            cout << "Lista de aprovados:\n";
            for (int i = 0; i < nAlunos; i++) {
                if (medias[i] >= MEDIA_MINIMA && frequencias[i] >= FREQUENCIA_MINIMA) {
                    cout << nomes[i] << " (" << matriculas[i] << ")\n";
                }
            }

        } else if (opcao == 4) {
            cout << "Lista de reprovados por média:\n";
            for (int i = 0; i < nAlunos; i++) {
                if (medias[i] < MEDIA_MINIMA) {
                    cout << nomes[i] << " (" << matriculas[i] << ")\n";
                }
            }

        } else if (opcao == 5) {
            cout << "Lista de reprovados por frequência:\n";
            for (int i = 0; i < nAlunos; i++) {
                if (frequencias[i] < FREQUENCIA_MINIMA) {
                    cout << nomes[i] << " (" << matriculas[i] << ")\n";
                }
            }

        } else if (opcao == 6) {
            cout << "Lista de reprovados por média e frequência:\n";
            for (int i = 0; i < nAlunos; i++) {
                if (medias[i] < MEDIA_MINIMA && frequencias[i] < FREQUENCIA_MINIMA) {
                    cout << nomes[i] << " (" << matriculas[i] << ")\n";
                }
            }

        } else if (opcao == 7) {
            cout << "Encerrando o programa.\n";

        } else {
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 7);

    return 0;
}