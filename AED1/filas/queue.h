typedef int Tipo_Item; // caso queria mudar o tipo de item a fila, basta mudar aqui

class queue{
  private:
  int first, last; //  first = onde remover / last = onde inserir (usanndo o modulo)
  Tipo_Item* estrutura; //declarando o vetor do tipo item
  const int max_item = 100;

  public:
  queue(); // construtor
  ~queue(); // destrutor
  bool isempty();
  bool isfull();
  void enqueue(Tipo_Item item); //inserir item = push
  Tipo_Item dequeue(); // remover item = pop
  void print();


};