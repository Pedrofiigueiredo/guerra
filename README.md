# Guerra
## Descricao:

O jogo de cartas chamado Guerra é bem simples, é um jogo entre 2 jogadores em que o
objetivo é deixar o oponente sem nenhuma carta. O jogo possui a seguinte estrutura:

1. Pega-se um baralho e divide-se em duas pilhas, com as cartas viradas para baixo.
2. Cada jogador vira a carta do topo de sua pilha e coloca virada para cima na área de combate
A carta maior vence a batalha e as duas cartas vão para o monte de prisioneiros correspondentes,
viradas para cima. Caso exista um empate, os jogadores continuam jogando as cartas sobre as abertas
na área de combate, até que um vença e todas as cartas vão então para o monte de prisioneiros do
vencedor. A ordem das cartas no monte de prisioneiros não importa.

## Termina quando:
Na sequência trava-se um novo combate. E o jogo continua. Quando acabarem as cartas de um dos
jogadores ele pega o monte de seus prisioneiros, vira todas as cartas e continua a guerra.
O jogo termina quando:
1. Um dos jogadores não tiver mais cartas (pode demorar).
2. Determina-se no início quantos combates serão travados e verifica-se o vencedor como o
jogador com mais cartas ao final dos combates.
3. Os dois jogadores decidem interromper o jogo. Vence aquele que tiver mais cartas neste
momento.
---
Para que você implemente este jogo é fornecido o arquivo cartaBaralho.h que define a classe
cartaBaralho e seus operadores.

Você deve criar as estrturas necessárias para implementar o jogo de Guerra. Note que o jogo é
estruturado sobre 6 estruturas de pilhas sendo:

- Duas pilhas de carta, inicialmente com o mesmo número de cartas, viradas para baixo
(Jogadores A e B).
- Duas pilhas de cartas, viradas para cima (Prisioneiros A e B)
- Duas pilhas de cartas, viradas para cima, que definem a área de combate e que, em caso de
empates, pode acumular mais que uma carta.

## Etapas de Desenvolvimento:
1. Defina uma TAD Pilha de carta de baralho herdando de alguma das listas já definidas (note que
o número de cartas em um baralho é finito e conhecido). Implemente os métodos necessários
para a pilha. Você pode ainda definir pilhas diferentes para cada uma das funções do jogo, mas
todas devem estar em um mesmo arquivo, pilhaCarta.h.
Jogador A
Jogador B
Combate
Prisioneiros A
Prisioneiros B
2. Crie um programa principal onde o jogo deve acontecer e vá criando dentro deste programa,
métodos para ir testando as suas pilhas. Você pode comentar estes testes depois para jogar
uma partida de Guerra.
3. Defina uma classe que cria um baralho, embaralha e coloca as cartas em duas pilhas distintas
(jogador A e jogador B)
4. Voce pode definir o jogo dentro do programa principal ou ainda criar um arquivo guerra.h onde
as funcionalidades do jogo serão implementadas.
5. Apresente as regras do jogo no início pra que o usuário saiba jogar contra o computador e com
opções para interromper o jogo e terminar.
