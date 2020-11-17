#include <iostream>

using namespace std;

class no{
    public:
         int item;
         no* proximo;
         no* anterior;
         no(){
         }
};

class Fila{
   private:
        no* primeiroC, *primeiroP;
        no* ultimoC, *ultimoP;
        int tamanhoFilaC, tamanhoFilaP;

   public:
        Fila(){
            tamanhoFilaC=tamanhoFilaP=0;
            primeiroC=ultimoC=primeiroP=ultimoP=NULL;
         }
         void inserir(int elemento);
         void remover();
};

void Fila::inserir(int el, int prioridade){
    no* temp;
    temp=new no;
    temp->item=el;
    temp->anterior=temp->proximo=NULL;
    if(prioridade==1){
        if(tamanhoFilaP==0){
            primeiroP=ultimoP=temp;
    }
        else{
            temp->anterior=ultimoP;
            ultimoP=temp;
        }
        tamanhoFilaP++;
    }
    else{
        if(tamanhoFilaC==0){
            primeiroC=ultimoC=temp;
        }
        else {
            temp->anterior=ultimoC;
            ultimoC=temp;
        }
        tamanhoFilaC++;
    }
}
