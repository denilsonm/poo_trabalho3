#ifndef GAME_H
#define GAME_H

class Game{

	public:

		/*	Funcao checkInterval(int a, int n, int b)

			Se n estiver entre a e b, retorna n. Se n for
			menor que a, retorna a. Se n for maior que b,\
			retorna b. Em outras palavras, forca que n
			esteja no intervalo fechado [a, b]

		*/

		static int checkInterval(int a, int n, int b);

		/*	Funcao generateRandom(int a, int b)

			Retorna um numero aleatorio entre a e b

		*/

		static int generateRandom(int a, int b);
};

#endif