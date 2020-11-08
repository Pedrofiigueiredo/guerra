#include <iostream>
#include <string>

using namespace std;

//Define a classe Carta de Baralho

class cartaBaralho{
  	public:
	  	// Declara os valores posiveis de Naipe e Cor de carta
	    enum Naipe{Espadas, Ouros, Paus, Copas};
	    enum Cor{Vermelha, Preta};

		// Construtor principal: define Naipe e Valor e virada para baixo
	    cartaBaralho(Naipe np, int valor){
	      cartaValor=valor;
	      cartaNaipe=np;
	      faceParaCima=false;
	    }
	
		//Construtor 2 - Cria uma carta sem Valor ou Naipe	e define que a carta esta virada para baixo
	    cartaBaralho(){
	      faceParaCima=false;
	    }

		// Vira uma carta, se esta virada para baixo passa a estar virada para cima e vice-versa
	    void vira(){
	      faceParaCima = !faceParaCima;
	    }
	
		// Retorna o valor da carta
	    int valorCarta(){
	      return cartaValor;
	    }
	
		// Indica se a carta esta virada para cima ou para baixo
	    bool estaViradaParaCima(){
	      return faceParaCima;
	    }
		
		// Retorna o Naipe de uma carta
	    Naipe valorNaipe(){
	      return cartaNaipe;
	    }
		
		// Define o Naipe de uma carta
	    void setCarta(Naipe np, int valor){
	      cartaNaipe=np;
	      cartaValor=valor;  
	    }
	    
	    //Retorna se a carta eh preta ou vermelha
	    Cor valorCor(){ 
	      if(cartaNaipe==cartaBaralho::Ouros || cartaNaipe==cartaBaralho::Copas){
	        return cartaBaralho::Vermelha;
	      }
	      else{
	        return cartaBaralho::Preta;
	      }
	    }
 	private:
	    bool faceParaCima; // Indica se a carta esta virada para cima ou para baixo
	    int cartaValor;    // Indica o valor da carta, de 1 ate 13, sendo As = 1; Valete = 11; Dama = 12 e Rei = 13
	    Naipe cartaNaipe;  // Indica o Naipe da carta. Nao eh importante  para o jogo Guerra
};


