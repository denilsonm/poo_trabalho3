#ifndef EQUIPMENT_H
#define EQUIPMENT_H

/*
        Interface Equipment
*/
class Equipment{
    public:
    /*
     * Nome: getAttackPts
     * Descricao: (puramente virtual) retorna os pontos de ataque do equipamento
     * Saida: (int) pontos de ataque
    */
    virtual int getAttackPts() = 0;
    
    /*
     * Nome: getDefensePts
     * Descricao: (puramente virtual) retorna os pontos de defesa do equipamento
     * Saida: (int) pontos de defesa
    */
    virtual int getDefensePts() = 0;

    /*
     * Nome: MaximumEquipped
     * Descricao: (puramente virtual) retorna a quantidade máxima desse item que pode ser equipada
     * Saida: (int) quantidade máxima
    */
    virtual int MaximumEquipped() = 0;
    
    /*
     * Nome: getName
     * Descricao: (puramente virtual) retorna o nome do equipamento
     * Saida: (string) nome do equipamento
    */
    virtual string getName() const = 0;
};

#endif
