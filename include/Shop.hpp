#ifndef SHOP_HPP
#define SHOP_HPP

#include <type_traits>
#include <string>
#include <vector>

#include "Item.hpp"
#include "Character.hpp"

using namespace std;

template <typename T>
class Shop{
    static_assert(std::is_base_of<Item, T>::value, "The template from Shop class must inherit from Item");

    private:
    vector<T*> stock;

    public:
    
    Shop(int numOfProducts);
    ~Shop();

    void buy(Character *buyer, int id);
    void sell(Character *seller, int id);

    operator string() const;
};

#endif
