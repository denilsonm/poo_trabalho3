#include <vector>
#include <string>
#include <sstream>

#include "Character.hpp"

template <typename T>
class Shop{
    private:
    vector<T*> stock;

    public:
    ~Shop(){
        for(unsigned int i = 0; i < stock.size(); i++)
            delete stock.at(i);
    }

    void addProduct(T* product)
    {
        stock.push_back(product);
    }

    void buy(Character *buyer, int id){
        if(id < 0 || id >= stock.size())
            return;

        if(buyer->getInventory().getGold() >= stock[id]->getPrice() && buyer->getInventory().getAvailableSpace() > 0){

            buyer->getInventory().addGold(-stock[id]->getPrice());

            buyer->getInventory().insertItem(stock[id]);
        }
    }

    void sell(Character *seller, int id){

        if(id < 0 || id >= seller->getInventory().getItemAmount())
            return;

        seller->getInventory().addGold(seller->getInventory().searchItem(id)->getPrice() * 0.6);
        seller->getInventory().removeItem(id);
    }

    operator string() const{

        ostringstream buffer;

        buffer << "These are our products, to buy one type the corresponding number: " << endl << endl;
    
        for(unsigned int i = 0; i < stock.size(); i++)
            buffer << i << " - " << stock[i]->getName() << endl;

        return buffer.str();
    }
};
