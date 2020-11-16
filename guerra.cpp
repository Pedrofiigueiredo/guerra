#include <iostream>
#include <ctime>
#include "cartaBaralho.h"
#include "pilha.h"
#include "utils.h" /* baguncar(), init(), mostraRodada(), comparaCartas(), pegaDoPrisioneiro()*/

using namespace std;

void menu() {
	cout <<"**************************************"<<endl;
	cout <<"********        GUERRA        ********"<<endl;
	cout <<"**************************************"<<endl;

	cout << "\nComo o jogo funciona:\n\n";
	cout << "1. Cada jogador começa com 26 cartas viradas para baixo\n";
	cout << "2. Os jogadores viram a carta do topo para cima no combate\n";
	cout << "3. A maior carta ganha\n";
	cout << "4. O vencedor leva as cartas para a pilha 'prisioneiro'\n";
	cout << "*  Se empatar, continuam virando as cartas até desempatar\n";
	cout << "5. Isso se repete até a rodada 60 ou alguém capturar 35 cartas\n";
	cout << "6. Quem capturar mais cartas é o vencedor!\n";
}

int main() {
	Baralho baralho;
	Pilha jogadorA, jogadorB, areaCombate, prisioneiroA, prisioneiroB;
	int qtdCartasA, qtdCartasB;
	baralho.init(&jogadorA, &jogadorB);
	char begin;
	bool game;

	menu();
	cout << "\n\nPronto para começar (s)? ";
	cin >> begin;
	cout << "\n\n\n\n";
	if (begin == 's') game = true;

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
		if (rodadas >= 60) {
			game = false;
			cout << "\nChegamos em 60 rodadas" << endl;
		};
		qtdCartasA = prisioneiroA.tamanhoPilha() + jogadorA.tamanhoPilha();
		qtdCartasB = prisioneiroB.tamanhoPilha() + jogadorB.tamanhoPilha();

		if ( qtdCartasA >= 35 || qtdCartasB >= 35)
			game = false;

		rodadas++;
	}

	cout << "\nCartas - Jogador A: " << qtdCartasA<<endl;
	cout << "Cartas - Jogador B: " << qtdCartasB<<endl;

	return 0;
}
