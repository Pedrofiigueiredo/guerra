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
	string naipe[] = {"Espadas", "Ouros", "Paus", "Copas"};
	string c[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	cout <<"\t"<< c[a.valorCarta() - 1] <<"\t"<< naipe[a.valorNaipe()] << endl;
	cout <<"\t"<< c[b.valorCarta() - 1] <<"\t"<< naipe[b.valorNaipe()] << endl;
}

void comparaCartas(cartaBaralho a, cartaBaralho b, Pilha *areaCombate, Pilha *prisioneiroA, Pilha *prisioneiroB) {
	if (a.valorCarta() != b.valorCarta()) {
		cartaBaralho carta;
		if (a.valorCarta() > b.valorCarta()){
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
		cout << "--------------------------------------" << endl;
	}
}
void pegaDoPrisioneiro(Pilha *jogadorA, Pilha *jogadorB, Pilha *prisioneiroA, Pilha *prisioneiroB){
	cartaBaralho carta;
	if (jogadorA->tamanhoPilha() == 0){
		while(!prisioneiroA->vazia()){
			carta = prisioneiroA->topo();
			carta.vira();
			jogadorA->inserir(carta);
			prisioneiroA->remover();
		}
	}
	if (jogadorB->tamanhoPilha() == 0){
		while(!prisioneiroB->vazia()){
			carta = prisioneiroB->topo();
			carta.vira();
			jogadorB->inserir(carta);
			prisioneiroB->remover();
		}
	}
}

int main(){
	Pilha jogadorA, jogadorB, areaCombate, prisioneiroA, prisioneiroB;
	int qtdCartasA, qtdCartasB;
	init(&jogadorA, &jogadorB);
//	 cout<< "----- A ----- " << jogadorA.tamanhoPilha()<<endl;
//	 jogadorA.imprime();
//	 cout<< "----- B ----- " << jogadorB.tamanhoPilha()<<endl;
//	 jogadorB.imprime();
	cout <<"**************************************"<<endl;
	cout <<"********     ***GUERRA***     ********"<<endl;
	cout <<"**************************************"<<endl;
	cout << "\tCarta\tNaipe" << endl;
	cout <<"======================================"<<endl;
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
		int valorCartaA = cartaA.valorCarta();
		int valorCartaB = cartaB.valorCarta();
		mostraRodada(cartaA, cartaB);
		comparaCartas(cartaA, cartaB, &areaCombate, &prisioneiroA, &prisioneiroB);
		if (jogadorA.tamanhoPilha() == 0 || jogadorB.tamanhoPilha() == 0){
			pegaDoPrisioneiro(&jogadorA, &jogadorB, &prisioneiroA, &prisioneiroB);
		}
		// Condicoes de parada
		if (rodadas >= 60) game = false;
		qtdCartasA = prisioneiroA.tamanhoPilha() + jogadorA.tamanhoPilha();
		qtdCartasB = prisioneiroB.tamanhoPilha() + jogadorB.tamanhoPilha();
		// Precisa pegar as cartas do prisioneiro
		if ( qtdCartasA >= 35 || qtdCartasB >= 35)
			game = false;

		rodadas++;
	}

	cout << "Cartas - Jogador A: " << qtdCartasA<<endl;
	cout << "Cartas - Jogador B: " << qtdCartasB<<endl;

	return 0;
}
