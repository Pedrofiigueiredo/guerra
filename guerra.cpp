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
}

void comparaCartas(cartaBaralho a, cartaBaralho b, Pilha *areaCombate, Pilha *prisioneiroA, Pilha *prisioneiroB) {
	if (a.valorCarta() != b.valorCarta()) {
		if (a.valorCarta() > b.valorCarta()) {
			while (!areaCombate->vazia()){
				prisioneiroA->inserir(areaCombate->topo());
				areaCombate->remover();
			}
		} else {
			while (!areaCombate->vazia()){
				prisioneiroB->inserir(areaCombate->topo());
				areaCombate->remover();
			}
		}
		cout << "-------------------------------------" << endl;
	}else{
		areaCombate->imprime();
	}
}


int main(){
	Pilha jogadorA, jogadorB, areaCombate, prisioneiroA, prisioneiroB;
	init(&jogadorA, &jogadorB);
//	 cout<< "----- A ----- " << jogadorA.tamanhoPilha()<<endl;
//	 jogadorA.imprime();
//	 cout<< "----- B ----- " << jogadorB.tamanhoPilha()<<endl;
//	 jogadorB.imprime();

	cout << "Carta \t Naipe" << endl;
	bool game = true;
	int rodadas = 0;
	
	while (game) {
		cartaBaralho cartaA, cartaB;
		cartaA = jogadorA.topo();
		cartaB = jogadorB.topo();
		//vira as cartas
		cartaA.vira();
		cartaB.vira();
		//inserir as cartas na area de combate		
		areaCombate.inserir(cartaA);
		areaCombate.inserir(cartaB);
		//remove a primeira carta de cada jogador, pois as cartas estao na area de combate
		jogadorA.remover();
		jogadorB.remover();
//		cout << "Cartas - Jogador A: " << prisioneiroA.tamanhoPilha()<<endl;
//		cout << "Cartas - Jogador B: " << prisioneiroB.tamanhoPilha()<<endl;
		int valorCartaA = cartaA.valorCarta();
		int valorCartaB = cartaB.valorCarta();
		mostraRodada(cartaA, cartaB);
		comparaCartas(cartaA, cartaB, &areaCombate, &prisioneiroA, &prisioneiroB);

		// Condicoes de parada
		if (rodadas >= 20) game = false;

		// Precisa pegar as cartas do prisioneiro
		if (prisioneiroA.tamanhoPilha() >= 35 || prisioneiroB.tamanhoPilha() >= 35)
			game = false;

		rodadas++;
	}

	cout << "Cartas - Jogador A: " << prisioneiroA.tamanhoPilha()<<endl;
	cout << "Cartas - Jogador B: " << prisioneiroB.tamanhoPilha()<<endl;


	return 0;
}
