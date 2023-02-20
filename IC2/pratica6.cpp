/*
- Pedro Henrique Da Silva Passos  Numero USP - 12683096
obs1: nao foi usado arquivos
obs2: nao foi usado strcmp, pois o seguinte erro estava aparecendo na hora da comparacao (msm que ambas variaves fossem do tipo string)
- error: cannot convert 'std::string' {aka 'std::__cxx11::basic_string<char>'} to 'const char*'  

-A prefeitura de uma cidade faz uma pesquisa sobre os domicílios na área urbana. Em
cada domicilio, são coletados dados sobre renda média mensal, número total de
ocupantes, endereço e número de ocupantes em idade escolar. Faça:
a. um programa que leia estes dados, faça a ordenação por inserção direta e salve
os dados ordenados em um arquivo. Os dados devem ser ordenados de acordo
com o endereço.
b. um programa que leia o arquivo e tenha um menu que permita(nao foi usado arquivo):
i. Listar todos os domicílios, com as respectivas informações;
ii. Buscar os dados do domicílio quando um determinado endereço é
digitado. Para a busca, deve-se utilizar busca binária;
iii. Sair.

*/

#include <iostream>  
#include <string>  
#include <string.h> 
using namespace std;
const int maximo = 200; 

struct Dados_domicilio
{

    float renda_mensal;
    int ocupantes_total;
    int ocupantes_escola;
    string endereco;
};

//Declaracao do escopo das funcoes que estao sendo usadas
void insercD(Dados_domicilio *dados2, int tamanho);
void menu(Dados_domicilio *dadosMenu, int tamanho);
void mostrar(Dados_domicilio *dadosM, int tamanho);
void buscaB(Dados_domicilio *dadosB, int tamanho);


//Funcao que ordena os registros
 void insercD(Dados_domicilio *dados2, int tamanho){

    int j;
   Dados_domicilio aux;

      for(int i = 2; i <=tamanho;i++){
        aux= dados2[i];
        j = i;
            
            while(aux.endereco < dados2[j-1].endereco){
                dados2[j] = dados2[j-1];
                j = j -1;
            }
            
        dados2[j]=aux;
    }

 }

//Funcao menu
 void menu(Dados_domicilio *dadosMenu, int tamanho){
    bool flag = true;

    while(flag){    

         int opcao = 0;

         cout << "\n\n===================================================================" << endl;
         cout << "       *** Bem vindo, escolha umas das opcoes para continuar ***           \n\n";
         cout << "Digite [1] para mostrar os registros cadastrados em ordem.\n";
         cout << "Digite [2] para mostrar os dados do domicilio escolhido.\n";
         cout << "Digite [3] para sair do programa.\n";
         cin >> opcao;

        switch (opcao)
        {
            case 1: 
                mostrar(dadosMenu, tamanho);
                break;

            case 2:
                buscaB(dadosMenu,tamanho);
                break;
            case 3:
                flag = false;
                break;  
            default:
            cout << "\n Opcao invalida!.";
            break;      
        }   
    }

 }
 
 //funcao que mostra registros ordenados de acordo com o endereço
void mostrar(Dados_domicilio *dadosM, int tamanho){

    cout << "\n################ Resgistros ordenados ######################## \n";
    // Mostra depois da ordenação
    for(int i = 1; i <= tamanho; i++){
        cout << "\nDados do registro " << i << " (depois da ordenacao)" << "\n";
        cout << "Renda mensal: " << dadosM[i].renda_mensal << "\n";
        cout << "Ocupantes totais: " << dadosM[i].ocupantes_total << "\n"; 
        cout << "Ocupantes em idade escolar: " << dadosM[i].ocupantes_escola << "\n"; 
        cout << "Endereco: " << dadosM[i].endereco << "\n";
    }
}

//funcao que busca os dados do domicilio, de acordo com o endereço dado (dando erro caso queira o primeiro registro)
void buscaB(Dados_domicilio *dadosB, int tamanho){
    string ender;
    int L, R, m;
    
    cout << "\nDigite o endereco do respectivo registro que deseja buscar: ";
    cin.ignore();
    getline(cin, ender);

    L=1;
    R = tamanho;

        while (L < R){
             m = (L+R)/2;
             if(dadosB[m].endereco < ender){
                L = m + 1;
             } else{
                R = m;      
             }
        }  
         
    if(dadosB[R].endereco == ender){
        cout << "\n################ Dados encontrados ######################## \n";
        cout << "\nDados do registro: " << R << "\n";
        cout << "Renda mensal: " << dadosB[R].renda_mensal << "\n";
        cout << "Ocupantes totais: " << dadosB[R].ocupantes_total << "\n"; 
        cout << "Ocupantes em idade escolar: " << dadosB[R].ocupantes_escola << "\n"; 
        cout << "Endereco: " << dadosB[R].endereco << "\n";
     }else{
            
            cout << "\n!!! Endereco nao encontrado, tente novamente !!!!";
            }
}

int main(){

    Dados_domicilio dados[maximo];
    int qtd_reg;
    
    cout << "Entre com a quantidade de resgistros que deseja cadastrar: ";
    cin >> qtd_reg;

    for(int i = 1; i <= qtd_reg; i++){
        cout << " Entre com a renda mensal do resgistro " << i  << ": ";
        cin >> dados[i].renda_mensal;
        cout << " Entre com os ocupantes totais do resgistro " << i << ": ";
        cin >> dados[i].ocupantes_total;     
        cout << " Entre com  numero de ocupantes em idade escolar do resgistro " << i << ": ";
        cin >> dados[i].ocupantes_escola; 
        cout << " Entre com o endereco do registro (em letra minuscula) " << i  << ": ";
        cin.ignore();
        getline(cin, dados[i].endereco);  
         
    }
    cout << "\n################ Resgistros nao ordenados ######################## \n";

    // Mostra antes da ordenação
      for(int i = 1; i <= qtd_reg; i++){

        cout << "\nDados do registro " << i << " (antes da ordenacao)" << "\n";
        cout << "Renda mensal: " << dados[i].renda_mensal << "\n";
        cout << "Ocupantes totais: " << dados[i].ocupantes_total << "\n"; 
        cout << "Ocupantes em idade escolar: " << dados[i].ocupantes_escola << "\n"; 
        cout << "Endereco: " << dados[i].endereco << "\n";
    }

    // Chamada da funcao de insercao direta
    insercD(dados, qtd_reg);

    // Chamada funcao menu
    menu(dados,qtd_reg);

    return 0;
}







