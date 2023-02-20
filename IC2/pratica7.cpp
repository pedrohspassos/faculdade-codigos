// Pedro Henrique da Silva Passos   Numero USP: 12683096
/* 
- Seja um registro (estrutura) com os campos: nome (string) e número de inscrição (int).
Pede-se
a. Faça uma função para ordenar, via QuickSort, um vetor com N registros. A
ordenação deve ser de acordo com o número de inscrição;
b. Imprima na tela o número de comparações entre chaves, movimentações de
registros e chamadas da função recursiva realizadas pelo algoritmo. Utilize
contadores para isso.
c. Mostre os números de comparações e movimentações e desenhe as respectivas
árvores de recursão para as 3 sequências a seguir (no qual apenas o número de
inscrição é apresentado):
45 56 12 43 95 19 8 67
8 12 19 43 45 56 67 95
95 67 56 45 43 19 12 8

*/


#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// contadores
int mov = 0;
int comp = 0;
int chamadas = 0;

struct Registro
{

    string nome;
    int num_insc;
};

void quicksort(Registro *dadosAux, int tamanho);
void qsort(Registro *dadosAux1, int L, int R);

void quicksort(Registro *dadosAux, int tamanho)
{
    chamadas++;
    qsort(dadosAux, 1, tamanho);
}

// responsavel por pegar o elemnto pivo
void qsort(Registro *dadosAux1, int L, int R)
{

    // Auxilio para arvore recursividade
    cout << "|L= " << L << "|";
    cout << "|R= " << R << "|\n";
    int j, i;
    Registro x, w;

    i = L; // indice inicio vetor
    j = R; // indice final vetor
    x.num_insc = dadosAux1[(L + R) / 2].num_insc;
    mov++;
    do
    {

        while (dadosAux1[i].num_insc < x.num_insc)
        {
            i++;
            comp++;
        }
        comp++;

        while (x.num_insc < dadosAux1[j].num_insc)
        {
            j--;
            comp++;
        }
        comp++;

        if (i <= j)
        {
            mov++;
            w = dadosAux1[i];
            mov++;
            dadosAux1[i] = dadosAux1[j];
            mov++;
            dadosAux1[j] = w;
            i++;
            j--;
        }

    } while (i <= j);

    // tenho valores de i / j (se modificam a cada chamda recursiva)
    if (L < j)
    {
        chamadas++;
        qsort(dadosAux1, L, j);
    }
    if (i < R)
    {
        chamadas++;
        qsort(dadosAux1, i, R);
    }
}

int main()
{

    Registro *dados;
    int qtd_reg;

    cout << "Entre com a quantidade de resgistros que deseja cadastrar: ";
    cin >> qtd_reg;

    dados = new Registro[qtd_reg + 1]; // pq nao estou comecando do indice 0

    for (int i = 1; i <= qtd_reg; i++)
    {

        cout << "Entre com o nome do registro " << i << ": ";
        cin >> dados[i].nome;
        cout << "Entre com o nume de inscricao do registro  " << i << ": ";
        cin >> dados[i].num_insc;
    }

    // Mostra qual dos 3 vetores foram utilizados
    cout << "\n################ Vetor usado ######################## \n";
    for (int i = 1; i <= qtd_reg; i++)
    {
        cout << "|" << dados[i].num_insc << "|";
    }
    cout << endl;
    cout << "\n################ Resgistros nao ordenados ######################## \n";
    for (int i = 1; i <= qtd_reg; i++)
    {
        cout << "\n-Dados do registro " << i << "\n";
        cout << "Nome: " << dados[i].nome << "\n";
        cout << "Numero de inscricao: " << dados[i].num_insc << "\n";
    }

    cout << "\n## Valores de L e R em cada chamada ##\n";

    // Chamanda da funcao
    quicksort(dados, qtd_reg);

    cout << "\n################ Resgistros ordenados ######################## \n";
    for (int i = 1; i <= qtd_reg; i++)
    {
        cout << "\n-Dados do registro " << i << "\n";
        cout << "Nome: " << dados[i].nome << "\n";
        cout << "Numero de inscricao: " << dados[i].num_insc << "\n";
    }

    // saida pedida
    cout << "\n################## Comparacoes ##################\n";
    cout << "Qtd: " << comp << "\n";
    cout << "################## Movimentacoes #################\n";
    cout << "Qtd: " << mov << "\n";
    cout << "################## Chamada Funcao (estou considerando a primeira chamada da qsort pelo quicksort) ##################\n";
    cout << "Qtd: " << chamadas;

    delete[] dados;

    return 0;
}
