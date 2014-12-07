#include "Shop.hpp"

#include <sstream>

Shop::Shop(int numOfProducts)
{
    for(unsigned int i = 0; i < numOfProducts; i++)
        stock.push_back(new T());
}

Shop::~Shop()
{
    for(unsigned int i = 0; i < stock.size(); i++)
        delete stock.at(i);
}

void Shop::buy(Character *buyer, int id)
{
    if(id < 0 || id >= stock.size())
        return;

    if(buyer->getInventory().getGold() >= stock[id].getPrice() && buyer->getInventory().getAvailableSpace() > 0)
    {
        buyer->getInventory().addGold(-stock[id].getPrice());

        buyer->getInventory().insertItem(stock[id]);
    }
}

void Shop::sell(Character *seller, int id)
{
    if(id < 0 || id >= seller.getInventory().getItemAmount()
        return;

    seller->getInventory().addGold(seller.getInventory().searchItem(id).getPrice() * 0.6);
    seller->getInventory().removeItem(id);
}

string Shop::operator string() const
{
    ostringstream buffer;

    buffer << "These are our products, to buy one type the corresponding number: " << endl << endl;
    
    for(unsigned int i = 0; i < stock.size(); i++)
        buffer << i << " - " << stock[i]->getName() << endl;

    return buffer.str();
}
