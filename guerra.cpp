#include <iostream>
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

void init(Pilha *jogadorA, Pilha *jogadorB){
	cartaBaralho carta[52];

	int index = 0;
	for(int i = 1; i < 14; i++){
		carta[index++] = cartaBaralho(cartaBaralho::Espadas, i);
		carta[index++] = cartaBaralho(cartaBaralho::Ouros, i);
		carta[index++] = cartaBaralho(cartaBaralho::Paus, i);
		carta[index++] = cartaBaralho(cartaBaralho::Copas, i);
	}
	baguncar(carta, 52);
	for(int i = 0; i < 52; i++) { // Distribui as cartas
		(i % 2 == 0) ? jogadorA->inserir(carta[i]) : jogadorB->inserir(carta[i]);;
	}
}

void mostraRodada(cartaBaralho a, cartaBaralho b) {
	cout << a.valorCarta() << " " << a.valorNaipe() << endl;
	cout << b.valorCarta() << " " << b.valorNaipe() << endl;
	cout << "-------------------------------------" << endl;
}

void comparaCartas(int a, int b) {

}


int main(){
	Pilha jogadorA, jogadorB, prisioneiroA, prisioneiroB;
	init(&jogadorA, &jogadorB);

	// cout<< "----- A ----- " << jogadorA.tamanhoPilha()<<endl;
	// jogadorA.imprime();
	// cout<< "----- B ----- " << jogadorB.tamanhoPilha()<<endl;
	// jogadorB.imprime();

	cout << "Carta Naipe" << endl;

	bool game = true;
	int rodadas = 0;
	while (game) {
		cartaBaralho cartaA, cartaB;
		cartaA = jogadorA.topo();
		cartaB = jogadorB.topo();

		int valorCartaA = cartaA.valorCarta();
		int valorCartaB = cartaB.valorCarta();

		mostraRodada(cartaA, cartaB);

		if (valorCartaA != valorCartaB) {
			if (valorCartaA > valorCartaB) {
				prisioneiroA.inserir(cartaA);
				prisioneiroA.inserir(cartaB);
			} else if (valorCartaB > valorCartaA) {
				prisioneiroB.inserir(cartaA);
				prisioneiroB.inserir(cartaB);
			}

			jogadorA.remover();
			jogadorB.remover();
		}

		// Condições de parada
		if (rodadas >= 5) game = false;

		// Precisa pegar as cartas do prisioneiro
		if (prisioneiroA.tamanhoPilha() >= 35 || prisioneiroB.tamanhoPilha() >= 35)
			game = false;

		rodadas++;
	}

	cout << "Cartas - Jogador A: " << prisioneiroA.tamanhoPilha()<<endl;
	cout << "Cartas - Jogador B: " << prisioneiroB.tamanhoPilha()<<endl;


	return 0;
}
