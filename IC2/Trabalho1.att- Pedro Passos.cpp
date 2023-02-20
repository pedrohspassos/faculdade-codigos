/*
Pedro Henrique da Silva Passos

Sejam os seguintes algoritmos de ordenação:
 Inserção direta
 Inserção binária
 Seleção
 Bubblesort
 Heapsort
 Fusão
 QuickSort
Pede-se:
a) Implemente os algoritmos relacionados para vetores de inteiros com tamanho n (digitado pelo usuário).
b) Obtenha os gráficos dos números de comparações entre chaves e de movimentações realizadas nos algoritmos considerando-se pelo menos 5 diferentes valores de n para:
(1) vetores de entrada em ordem crescente
(2) vetores de entrada em ordem decrescente
(3) vetores de entrada com valores aleatórios

*/

#include <iostream>
using namespace std;
// contadores
int mov = 0;
int comp = 0;

// Funcoes "extras"
void menu(int *vetorV, int tamanho);
void menuOrdem(int *vetorV, int tamanho);
void vetorCres(int *vetorV, int tamanho);
void vetorDescres(int *vetorV, int tamanho);
void vetorAleat(int *vetorV, int tamanho);

// Funcoes de ordenacao
void insercD(int *vetorAux, int tamanho);
void insercB(int *vetorAux, int tamanho);
void selecao(int *vetorAux, int tamanho);
void bubblesort(int *vetorAux, int tamanho);
void mergesort(int *vetorA, int tamanhoN);
void mpass(int *vetorA, int tamanhoN, int p, int *vetorC);
void merge(int *vetorA, int inicio, int meio, int fim, int *vetorC);
void heapify(int *vetorAux, int L, int R);
void heapsort(int *vetorAux, int tamanho);
void quicksort(int *vetorAux, int tamanho);
void qsort(int *vetorAux, int L, int R);

void menu(int *vetorV, int tamanho)
{

    int opcao;
    do
    {
        cout << "\n\n===================================================================" << endl;
        cout << "       *** Bem vindo, escolha umas das opcoes para continuar ***           \n\n";
        cout << "Digite [1] para vetor em ordem crescente\n";
        cout << "Digite [2] para vetor em ordem decrescente.\n";
        cout << "Digite [3] para vetor com entradas aleatorias.\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            vetorCres(vetorV, tamanho);
            opcao = 4;
            break;
        case 2:
            vetorDescres(vetorV, tamanho);
            opcao = 4;
            break;
        case 3:
            vetorAleat(vetorV, tamanho);
            opcao = 4;
            break;
        default:
            break;
        }

    } while (opcao != 4);
}

void menuOrdem(int *vetorV, int tamanho)
{

    int opcao;
    do
    {
        cout << "\n\n===========================================================================" << endl;
        cout << "       ***  Escolha um dos metodos ***           \n\n";
        cout << "Digite [1] para Insercao Direta.\n";
        cout << "Digite [2] para Insercao Binaria.\n";
        cout << "Digite [3] para Selecao.\n";
        cout << "Digite [4] para Bubblesort.\n";
        cout << "Digite [5] para Mergesort. \n";
        cout << "Digite [6] para Heapsort.\n";
        cout << "Digite [7] para Quicksort. \n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            insercD(vetorV, tamanho);
            opcao = 8;
            break;
        case 2:
            insercB(vetorV, tamanho);
            opcao = 8;
            break;
        case 3:
            selecao(vetorV, tamanho);
            opcao = 8;
            break;
        case 4:
            bubblesort(vetorV, tamanho);
            opcao = 8;
            break;
        case 5:
            mergesort(vetorV, tamanho);
            opcao = 8;
            break;
        case 6:
            heapsort(vetorV, tamanho);
            opcao = 8;
            break;
        case 7:
            quicksort(vetorV, tamanho);
            opcao = 8;
            break;

        default:
            break;
        }

    } while (opcao != 8);
}
void vetorCres(int *vetorV, int tamanho)
{

    int i, j, aux;

    // ordenar elementos
    for (i = 1; i <= tamanho; i++)
    {
        for (j = i; j <= tamanho; j++)
        {
            if (vetorV[i] > vetorV[j])
            {
                aux = vetorV[i];
                vetorV[i] = vetorV[j];
                vetorV[j] = aux;
            }
        }
    }

    cout << "\n*** Vetor ordem crescente *** " << endl;

    for (i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorV[i] << "|";
    }
}
void vetorDescres(int *vetorV, int tamanho)
{
    int i, j, aux;

    // ordenar elementos
    for (i = 1; i <= tamanho; i++)
    {
        for (j = i; j <= tamanho; j++)
        {
            if (vetorV[i] < vetorV[j])
            {
                aux = vetorV[i];
                vetorV[i] = vetorV[j];
                vetorV[j] = aux;
            }
        }
    }

    cout << "\n*** Vetor ordem decresrescente *** " << endl;
    for (i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorV[i] << "|";
    }
}
void vetorAleat(int *vetorV, int tamanho)
{
    int i;
    cout << "\n*** Vetor ordem aleatoria *** " << endl;
    for (i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorV[i] << "|";
    }
}
// Insercao direta
void insercD(int *vetorAux, int tamanho)
{

    int num_atual;
    int j;
    for (int i = 2; i <= tamanho; i++)
    {

        num_atual = vetorAux[i];
        mov++;
        vetorAux[0] = num_atual;
        mov++;
        j = i;

        while (num_atual < vetorAux[j - 1])
        {
            comp++;
            vetorAux[j] = vetorAux[j - 1];
            mov++;
            j--;
        }
        comp++;
        vetorAux[j] = num_atual;
        mov++;
    }
    cout << "\n===============================================";
    cout << "\n*** Vetor ordenado Insercao Direta***\n"
         << endl;
    for (int i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorAux[i] << "|";
    }
}

// Insercao binaria
void insercB(int *vetorAux, int tamanho)
{
    int i, j, valor_atual, L, R, meio;

    for (i = 2; i <= tamanho; i++)
    {
        // Ordenando vetor
        valor_atual = vetorAux[i];
        mov++;
        L = 1;
        R = i;

        while (L < R)
        {
            meio = (L + R) / 2;
            if (vetorAux[meio] <= valor_atual)
            {
                L = meio + 1;
                comp++;
            }
            else
            {
                R = meio;
                comp++;
            }
        }

        j = i;

        while (j > R)
        {
            vetorAux[j] = vetorAux[j - 1];
            j--;
            mov++;
        }
        vetorAux[R] = valor_atual;
        mov++;
    }

    cout << "\n================================================";
    cout << "\n*** Vetor ordenado Insercao Binaria *** " << endl;
    for (int i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorAux[i] << "|";
    }
}

// Ordenando por selecao
void selecao(int *vetorAux, int tamanho)
{

    int indice_menor, num_atual;

    for (int i = 1; i < tamanho; i++)
    {
        indice_menor = i;
        for (int j = i + 1; j <= tamanho; j++)
        {
            if (vetorAux[j] < vetorAux[indice_menor])
            {
                indice_menor = j;
            }
            comp++;
        }

        num_atual = vetorAux[i];
        mov++;
        vetorAux[i] = vetorAux[indice_menor];
        mov++;
        vetorAux[indice_menor] = num_atual;
        mov++;
    }

    cout << "\n================================================";
    cout << "\n*** Vetor ordenado Selecao *** " << endl;
    for (int i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorAux[i] << "|";
    }
}

// BubbleSort
void bubblesort(int *vetorAux, int tamanho)
{
    int num_atual;

    for (int i = 2; i <= tamanho; i++)
    {
        for (int j = tamanho; j >= i; j--)
        {
            if (vetorAux[j - 1] > vetorAux[j])
            {
                num_atual = vetorAux[j - 1];
                mov++;
                vetorAux[j - 1] = vetorAux[j];
                mov++;
                vetorAux[j] = num_atual;
                mov++;
            }
            comp++;
        }
    }

    cout << "\n================================================";
    cout << "\n*** Vetor ordenado Bubblesort *** " << endl;
    for (int i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorAux[i] << "|";
    }
}

// Fusao (sao 3 funcoes)
// Primeira:ordena duas seq que ja estao ordenadas
void merge(int *vetorA, int inicio, int meio, int fim, int *vetorC)
{

    int i, j, k;

    i = inicio;
    j = meio + 1;
    k = inicio - 1;

    // coloca em ordem os elementos do vetorA no vetorC
    while (i <= meio && j <= fim)
    {
        k++;

        if (vetorA[i] < vetorA[j])
        {
            comp++;
            vetorC[k] = vetorA[i];
            mov++;
            i++;
        }
        else
        {
            comp++;
            vetorC[k] = vetorA[j];
            mov++;
            j++;
        }
    }

    // verifica vetor acabou e copia os valores para o vetorC
    while (i <= meio)
    {
        k++;
        vetorC[k] = vetorA[i];
        mov++;
        i++;
    }

    while (j <= fim)
    {
        k++;
        vetorC[k] = vetorA[j];
        mov++;
        j++;
    }
}
// Segunda
void mpass(int *vetorA, int tamanhoN, int p, int *vetorC)
{

    int i;
    i = 1;

    while (i <= tamanhoN - 2 * p + 1)
    {

        merge(vetorA, i, i + p - 1, i + 2 * p - 1, vetorC);
        i = i + 2 * p;
    }
    if (i + p - 1 < tamanhoN)
    {
        merge(vetorA, i, i + p - 1, tamanhoN, vetorC);
    }
    else
    {
        for (int j = i; j <= tamanhoN; j++)
        {
            vetorC[j] = vetorA[j];
            mov++;
        }
    }
}
// Terceira
void mergesort(int *vetorA, int tamanhoN)
{
    int p = 1;
    int vetorC[tamanhoN];
    while (p < tamanhoN)
    {
        mpass(vetorA, tamanhoN, p, vetorC);
        p = 2 * p;
        mpass(vetorC, tamanhoN, p, vetorA);
        p = 2 * p;
    }

    cout << "\n================================================";
    cout << "\n*** Vetor ordenado mergesort *** " << endl;
    for (int i = 1; i <= tamanhoN; i++)
    {
        cout << "|" << vetorA[i] << "|";
    }
}
// HeapSort (sao 2 funcoes)
void heapify(int *vetorAux, int L, int R)
{

    int i, j, x;

    i = L;
    j = 2 * L;
    x = vetorAux[L];
    mov++;
    // verificando qual dos filhos eh maior
    if ((j < R) && (vetorAux[j] < vetorAux[j + 1]))
    {
        j++;
    }
    comp++;

    while ((j <= R) && (x < vetorAux[j]))
    {
        comp++;
        vetorAux[i] = vetorAux[j];
        mov++;
        i = j;
        j = 2 * j;
        if ((j < R) && (vetorAux[j] < vetorAux[j + 1]))
        {
            j++;
        }
        comp++;
    }
    comp++;

    vetorAux[i] = x;
    mov++;
}

void heapsort(int *vetorAux, int tamanho)
{

    int L, R, w;
    for (L = tamanho / 2; L >= 1; L--)
    {
        heapify(vetorAux, L, tamanho);
    }

    for (R = tamanho; R >= 2; R--)
    {
        w = vetorAux[1];
        mov++;
        vetorAux[1] = vetorAux[R];
        mov++;
        vetorAux[R] = w;
        mov++;
        heapify(vetorAux, 1, R - 1);
    }

    cout << "\n================================================";
    cout << "\n*** Vetor ordenado Heapsort *** " << endl;
    for (int i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorAux[i] << "|";
    }
}

// QuickSort ( 2 funcoes)
void quicksort(int *vetorAux, int tamanho)
{

    qsort(vetorAux, 1, tamanho);

    cout << "\n================================================";
    cout << "\n*** Vetor ordenado Quicksort *** " << endl;
    for (int i = 1; i <= tamanho; i++)
    {
        cout << "|" << vetorAux[i] << "|";
    }
}

void qsort(int *vetorAux, int L, int R)
{

    int j, i, x, w;

    i = L;
    j = R;
    x = vetorAux[(L + R) / 2];
    mov++;

    do
    {
        while (vetorAux[i] < x)
        {
            i++;
            comp++;
        }
        comp++;
        while (x < vetorAux[j])
        {
            j--;
            comp++;
        }
        comp++;
        if (i <= j)
        {
            w = vetorAux[i];
            mov++;
            vetorAux[i] = vetorAux[j];
            mov++;
            vetorAux[j] = w;
            mov++;
            i++;
            j--;
        }

    } while (i <= j);

    if (L < j)
    {

        qsort(vetorAux, L, j);
    }
    if (i < R)
    {
        qsort(vetorAux, i, R);
    }
}

int main()
{

    int tamanhoN;
    int *vetorV;
    cout << "***** Entre com o tamanho o vetor *****" << endl;
    cin >> tamanhoN;

    vetorV = new int[tamanhoN];

    int vetor, i, j, aux;

    cout << "\n*** Vetor *** " << endl;
    for (i = 1; i <= tamanhoN; i++)
    {
        // Gero os vetores aleatorios
        vetorV[i] = 1 + (rand() % 600);
        cout << "|" << vetorV[i] << "|";
    }

    // escolhe qual o tipo do vetor sera usado(crescente,decrescente,aleatorio)
    menu(vetorV, tamanhoN);

    // escolhe tipo ordenacao que quero fazer
    menuOrdem(vetorV, tamanhoN);

    cout << "\n\n################## Comparacoes ##################\n";
    cout << "Qtd: " << comp << "\n";
    cout << "################## Movimentacoes #################\n";
    cout << "Qtd: " << mov << "\n";

    delete[] vetorV;
    return 0;
}