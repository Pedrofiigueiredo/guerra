# include "cartaBaralho.h"
# include "pilha.h" 
# include <ctime>

using namespace std;

void baguncar(cartaBaralho a[], int tamanho){
	srand((unsigned)time(0));
	for(int i=tamanho-1; i>=1; --i){
    	swap(a[i], a[rand()%i]);
	} 
}

void init(Pilha *baralho){
	cartaBaralho carta[52];
	int index = 0;
	for(int i = 1; i < 14; i++){
		carta[index++] = cartaBaralho(cartaBaralho::Espadas, i);
		carta[index++] = cartaBaralho(cartaBaralho::Ouros, i);
		carta[index++] = cartaBaralho(cartaBaralho::Paus, i);
		carta[index++] = cartaBaralho(cartaBaralho::Copas, i);
	}
	baguncar(carta, 52);
	for(int i = 0; i < 52; i++){
		baralho->inserir(carta[i]);
	}
}


int main(){
	Pilha baralho;
	init(&baralho);
	baralho.imprime();


	return 0;
}
