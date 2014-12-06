#include "Potion.hpp"

/*
 * Nome: Potion (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome da pocao, (double) preço, (int) poder de restauracao
*/
Potion::Potion(const string name, double price, int restorepts) : Item(name, price{
    this->restorepts = restorepts;
}

/*
 * Nome: Potion (Construtor de cópia)
 * Descricao: Construtor que copia os atributos de um objeto Potion
 * Entrada: (Potion&) Referencia para um objeto Potion
*/
Potion::Potion(Potion & potion) : Item(potion){
    restorepts = potion.restorepts;
}
