#include "Shop.h"

Shop& Shop::Add(Article* a)
{
    items.push_back(a);
    return *this;
}

int Shop::GetTotalPrice()
{
    int total = 0;
    for (int i = 0; i < items.size(); i++)
        total += items[i]->GetPrice() * items[i]->GetQuantity();

    return total;
}

int Shop::GetQuantity(string type)
{
    int cantitate = 0;
    for (int i = 0; i < items.size(); i++)
        if (items[i]->GetType() == type)
            cantitate += items[i]->GetQuantity();

    return cantitate;
}

void Shop::List()
{
    for (int i = 0; i < items.size(); i++)
        items[i]->Print();
}
