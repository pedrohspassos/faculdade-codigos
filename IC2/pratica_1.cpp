/* 
Escrever um programa em C++ que
a. Possua uma estrutura chamada estudante com os seguintes
elementos
 Numero USP
 Nota da primeira prova
 Nota da segunda prova
 Média final
b. Tenha um menu que permita realizar as seguintes operações
1. Entrar com dados de um estudante (número USP e notas das
provas)
2. Mostrar dados de um estudante
3. Mostrar a média e desvio padrão para as médias finais de todos
os estudantes cadastrados
4. Sair
Observações:
 procurar dados do estudante usando o número USP
 calcular a média final como a média aritmética entre as duas
provas
 considerar um número máximo de 100 estudantes

*/
#include <iostream> // Pedro Henrique Da Silva Passos  Numero USP - 12683096
#include <cmath>
#include <math.h>

const int max_alunos = 100; // tamanho maximo de alunos que podem sem cadastrados

using namespace std;
void menu();
void entrada(int qtd_alunos); // Declaracao das funcoes que estao sendo usadas
void mostrar(int qtd_alunos);
void calculo(int qtd_alunos);

struct Estudantes
{
    int numero_usp;
    float nota_p1;
    float nota_p2;
    float media_final;
};
Estudantes alunos[max_alunos];

void menu()
{
    int i = 0;
    int qtd_alunos;
    int opcao = 0;
    bool sair = true;
    int flag = 0; // verifica se foi registrado algum
    bool valido;

    cout << "\n\n================================================================================\n\n";
    cout << " ###### Digite a quantidade alunos com que deseja entrar com os dados [maximo 100 alunos] #######\n";
    cin >> qtd_alunos;

    if (qtd_alunos >= 0 && qtd_alunos <= 100)
    {
        do
        {
            cout << "\n\n===================================================================" << endl;
            cout << "       *** Bem vindo, escolha umas das opcoes para continuar ***           \n\n";
            cout << "Digite (1) para entrar com os dados dos estudantes.\n";
            cout << "Digite (2) para mostrar os dados dos estudante.\n";
            cout << "Digite (3) para calcular a media e o desvio padrao dos estudantes.\n";
            cout << "Digite (4) para sair do programa.\n";
            cin >> opcao;

            if (opcao == 1)
            {

                entrada(qtd_alunos);
                flag = 1;
            }
            else if (opcao == 2)
            {
                valido = true;
                while (valido)
                {

                    if (flag >= 1)
                    {
                        mostrar(qtd_alunos);
                        valido = false;
                    }
                    else
                    {
                        cout << "======================================================= \n";
                        cout << " Entre primeiro com os dados dos estudantes.\n\n";
                        entrada(qtd_alunos);
                        valido = false;
                        mostrar(qtd_alunos);
                        flag = 1;
                    }
                }
            }
            else if (opcao == 3)
            {
                valido = true;

                while (valido)
                {

                    if (flag >= 1)
                    {
                        calculo(qtd_alunos);
                        valido = false;
                    }
                    else
                    {
                        cout << "==============================================================================\n";
                        cout << " Antes de fazer os calculos, entre primeiro com os dados dos estudantes. \n\n";
                        entrada(qtd_alunos);
                        valido = false;
                        calculo(qtd_alunos);
                        flag = 1;
                    }
                }
            }
            else if (opcao == 4)
            {
                sair = false;
                cout << "\n *************** Obrigado, volte sempre! ****************** ";
            }
            else
            {
                cout << "\n !!!! Opcao invalida, digite um numero valido !!!!\n";
            }
        } while (sair);
    }
    else
    {
        cout << " \n!!! Erro, o numero maximo de alunos nao foi respeitado. Reinicie o programa !!!\n";
    }
}

void entrada(int qtd_alunos)
{
    int contador;

    for (contador = 0; contador < qtd_alunos; contador++)
    {

        cout << " Digite o numero usp do aluno " << contador + 1 << ": ";
        cin >> alunos[contador].numero_usp;
        cout << " Digite a nota (0 - 10) da p1 do aluno  " << contador + 1 << ": ";
        cin >> alunos[contador].nota_p1;
        cout << " Digite a nota (0 - 10) da p2 do aluno  " << contador + 1 << ": ";
        cin >> alunos[contador].nota_p2; 
        cout << "\n";
    }
} // funcao que pega a entrada dos dados

void mostrar(int qtd_alunos)
{
    double variancia[qtd_alunos];
    double dev1[qtd_alunos];
    double dev2[qtd_alunos];
    double somatorio1[qtd_alunos];
    double somatorio2[qtd_alunos];
    double somatorio_total[qtd_alunos];
    int contador;
    int num_usp;
    int i;
    cout << "=========================================================================================================\n";
    cout << "- Ensira o numero usp do estudante que deseja ver os dados (Daqueles cadastrados anteriormente). \n\n";
    cin >> num_usp;

    for (contador = 0; contador < qtd_alunos; contador++)
    {

        alunos[contador].media_final = (alunos[contador].nota_p1 + alunos[contador].nota_p2) / 2;
        dev1[contador] = alunos[contador].nota_p1 - alunos[contador].media_final;
        dev2[contador] = alunos[contador].nota_p2 - alunos[contador].media_final;
        somatorio1[contador] += (dev1[contador] * dev1[contador]);
        somatorio2[contador] += (dev2[contador] * dev2[contador]);

        somatorio_total[contador] = somatorio1[contador] + somatorio2[contador];

        variancia[contador] = (somatorio_total[contador] / qtd_alunos);

        if (num_usp == alunos[contador].numero_usp)
        {

            cout << "       *** Dados do aluno " << contador + 1 << " ***"
                 << "\n\n";
            cout << "- Numero usp do aluno " << contador + 1 << ": " << alunos[contador].numero_usp << "\n";
            cout << "- A nota da p1 aluno do aluno " << contador + 1 << " eh: " << alunos[contador].nota_p1 << "\n";
            cout << "- A nota da p2 aluno do aluno " << contador + 1 << " eh: " << alunos[contador].nota_p2 << "\n";
            cout << "- A media final do aluno " << contador + 1 << " eh: " << alunos[contador].media_final << "\n";
            cout << "- O desvio padrao amostral do aluno " << contador + 1 << " eh: " << sqrt(variancia[contador]) << "\n\n";
        }
    }
} // funcao que mostra os dados de entrada

void calculo(int qtd_alunos)
{

    double desv_padrao[qtd_alunos];
    int contador;
    double variancia[qtd_alunos];
    double dev1[qtd_alunos];
    double dev2[qtd_alunos];
    double somatorio1[qtd_alunos];
    double somatorio2[qtd_alunos];
    double somatorio_total[qtd_alunos];

    cout << "\n ========= Media final e Desvio padrao ========= \n\n";

    for (contador = 0; contador < qtd_alunos; contador++)
    {

        alunos[contador].media_final = (alunos[contador].nota_p1 + alunos[contador].nota_p2) / 2;
        dev1[contador] = alunos[contador].nota_p1 - alunos[contador].media_final;
        dev2[contador] = alunos[contador].nota_p2 - alunos[contador].media_final;
        somatorio1[contador] += (dev1[contador] * dev1[contador]);
        somatorio2[contador] += (dev2[contador] * dev2[contador]);

        somatorio_total[contador] = somatorio1[contador] + somatorio2[contador];

        variancia[contador] = (somatorio_total[contador] / qtd_alunos);

        cout << "- A media final do aluno " << contador + 1 << " eh: " << alunos[contador].media_final << "\n";
        cout << "- O desvio padrao amostral do aluno " << contador + 1 << " eh: " << sqrt(variancia[contador]) << "\n\n";
    }

} // funcao que calcula o desvio padrao e a media final

int main()
{
    menu(); // chamada da funcao menu
    return 0;
}
