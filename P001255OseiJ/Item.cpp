#include "Item.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

Item::Item(string name, double price, int quantity)
{
	itemName = name;
	itemPrice = price;
	itemQuantity = quantity;
}

void Item::setItemName(string name)
{
	itemName = name;
}

void Item::setItemPrice(double price)
{
	itemPrice = price;
}

void Item::setItemQuantity(int quantity)
{
	itemQuantity = quantity;
}

string Item::getItemName() const
{
	return itemName;
}

double Item::getItemPrice() const
{
	return itemPrice;
}

int Item::getItemQuantity() const
{
	return itemQuantity;
}

void Item::outputItemInfo()
{
	cout << fixed << setprecision(2);
	cout << "\t" << this->getItemName() << " " << this->getItemQuantity() << " @ $" << this->getItemPrice() << " = $";
	cout << this->getItemQuantity() * this->getItemPrice() << endl;

}
