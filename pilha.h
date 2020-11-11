#include <iostream>

using namespace std;

class Lista{
	protected:
		cartaBaralho minhaLista[52];
		int tamanhoLista=0;
		int tamanhoMaximo=52;

		void abreEspacoLista(int posicao);  // assinatura do metodo - tipo de retorno, nome do metodo e parametros com seus tipos

		void fechaEspacoLista(int posicao);

	public:
		Lista(){//construtor da classe
		}
		void inserir(cartaBaralho elemento); //inserir na ultima posicao da lista

		void inserir(cartaBaralho elemento, int posicao); //inserir na posicao desejada

		void remover(int posicao);

		void imprimeLista();

		int mostraElemento(int posicao);

};

void Lista::abreEspacoLista(int posicao){
		for(int i=tamanhoLista; i>=posicao; i--){
			minhaLista[i]=minhaLista[i-1];
		}
	}

void Lista::fechaEspacoLista(int posicao){
		for(int i=posicao; i<tamanhoLista; i++){
			minhaLista[i]=minhaLista[i+1];
		}
	}

void Lista::inserir(cartaBaralho elemento){
	if(tamanhoLista<tamanhoMaximo){
		minhaLista[tamanhoLista]=elemento;
		tamanhoLista++;
	}
}

void Lista::inserir(cartaBaralho elemento, int posicao){ //inserir um novo elemento na lista se houver espaco
		if((tamanhoLista<tamanhoMaximo)&&(posicao<=tamanhoLista)){
			abreEspacoLista(posicao);
			minhaLista[posicao]=elemento;
			tamanhoLista++;
		}
	}

void Lista::remover(int posicao){//assumindo que nao existem valores negativos na lista
		if(posicao<tamanhoLista){
			fechaEspacoLista(posicao);
			tamanhoLista--;
		}
		else{
			cout<<"Posicao nao existe na lista"<<endl;
		}
	}

void Lista::imprimeLista(){
		cout<<"******** LISTA ***********"<<endl;
		for(int i = 0 ; i<tamanhoLista; i++){
			cout<<minhaLista[i].valorCarta()<<"\t"<<minhaLista[i].valorNaipe()<<endl;
		}
	}

int Lista::mostraElemento(int posicao){
	if(posicao<tamanhoLista){
		cout<<minhaLista[posicao].valorCarta()<<"\t"<<minhaLista[posicao].valorNaipe()<<endl;
	}
	else{
		cout<<"Posicao nao existe na lista"<<endl;
	}
}

class Pilha:public Lista{
	public:
		Pilha(){//construtor da classe
		}
		
		void inserir(cartaBaralho elemento){ //inserir na ultima posicao da lista
			Lista::inserir(elemento);
		}
		
		void remover(){ //posicao comeca com 0
			Lista::remover(Lista::tamanhoLista - 1);
		}
		
		int topo(){
			Lista::mostraElemento(Lista::tamanhoLista - 1);
		}
		
		bool vazia(){
			if(Lista::tamanhoLista == 0){
				return true;
			}else{
				return false;
			} 
		}
		
		bool cheia(){
			if(Lista::tamanhoLista == Lista::tamanhoMaximo){
				return true;
			}else{
				return false;
			} 
		}
		
		void imprime(){
			cout<<"******** Baralho ***********"<<endl;
			for(int i = 0 ; i<tamanhoLista; i++){
				cout<<Lista::minhaLista[i].valorCarta()<<"\t";
				if(Lista::minhaLista[i].valorNaipe() == 0){
					cout<<"Espadas"<<endl;
				}else if(Lista::minhaLista[i].valorNaipe() == 1){
					cout<<"Ouros"<<endl;
				}else if(Lista::minhaLista[i].valorNaipe() == 2){
					cout<<"Paus"<<endl;
				}else{
					cout<<"Copas"<<endl;
				}
			}
		}

};

