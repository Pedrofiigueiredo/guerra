class Baralho {
	public:
		Baralho() {}
		void baguncar(cartaBaralho a[], int tamanho);
		void init(Pilha *jogadorA, Pilha *jogadorB);
};

void Baralho::baguncar(cartaBaralho a[], int tamanho) {
	srand((unsigned)time(0));
	for(int i=tamanho-1; i>=1; --i){
    	swap(a[i], a[rand()%i]);
	}
}

void Baralho::init(Pilha *jogadorA, Pilha *jogadorB) { /* Inicializa, embaralha e distribui */
	cartaBaralho carta[52];
	int index = 0;
	for (int i = 1; i < 14; i++) {
		carta[index++] = cartaBaralho(cartaBaralho::Espadas, i);
		carta[index++] = cartaBaralho(cartaBaralho::Ouros, i);
		carta[index++] = cartaBaralho(cartaBaralho::Paus, i);
		carta[index++] = cartaBaralho(cartaBaralho::Copas, i);
	}
	baguncar(carta, 52);
	for (int i = 0; i < 52; i++) // Distribui as cartas
		(i % 2 == 0) ? jogadorA->inserir(carta[i]) : jogadorB->inserir(carta[i]);;
}

void mostraRodada(cartaBaralho a, cartaBaralho b) {
	string naipe[] = {"Espadas", "Ouros", "Paus", "Copas"};
	string c[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	cout <<" [eu] "<< c[a.valorCarta() - 1] <<"  "<< naipe[a.valorNaipe()] << endl;
	cout <<" [pc] "<< c[b.valorCarta() - 1] <<"  "<< naipe[b.valorNaipe()] << endl;
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

void pegaDoPrisioneiro(Pilha *jogadorA, Pilha *jogadorB, Pilha *prisioneiroA, Pilha *prisioneiroB) {
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
