
typedef int Tipo_item;


class Stack{
    private:
     int top;
     Tipo_item* estrutura;
     const int max_item = 100;


    public:
     Stack(); // construtora
     ~Stack(); // destrutora 
     bool full(); // verifica pilha cheia
     bool empty(); // verifica pilha vazia
     void push(Tipo_item item); // inseri elementos
     Tipo_item pop(); // retirar elementos
     void imprimir(); 
     int size(); // tamanoho pilha        
};