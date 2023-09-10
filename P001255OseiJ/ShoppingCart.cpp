#include "ShoppingCart.h"
#include "Item.h"
#include "DateUtility.h"
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;


ShoppingCart::ShoppingCart(string name)
{
	customerName = name;
}

string ShoppingCart::getCustomerName() const
{
	return customerName;
}

string ShoppingCart::getCurrentDate() const
{
	return currentDate;
}

int ShoppingCart::getItemCount() const
{
	int count = 0;
	for (int i = 0; i < cart.size(); i++) {
		count += cart[i].getItemQuantity();

	}
	return count;
}

int ShoppingCart::findItemInCart(string name)
{
	
	for (int i = 0; i < cart.size(); i++) {
		string index = cart[i].getItemName();
		if (index == name) {
			return i;
		}
	}
	;
}

void ShoppingCart::addItemToCart(Item item)
{
	if (findItemInCart(item.getItemName()) < cart.size()) {
		cout <<"\n\t>>>Item " << item.getItemName() << " already in the cart<<<" << endl;
	}
	else {
		cart.push_back(item);
		item.setItemName(item.getItemName());
		item.setItemPrice(item.getItemPrice());
		item.setItemQuantity(item.getItemQuantity());
		cout << endl;
		cout <<"\n\t>>>Item " << item.getItemName() << " added to cart<<<" << endl;
	}
}

void ShoppingCart::changeItemQuantity(string name, int quantity)
{
	if (findItemInCart(name) < cart.size()) {
		int index = findItemInCart(name);
		cart.at(index).setItemQuantity(quantity);
		cout <<"\n\t>>>Item " << name << " quantity changed to " << quantity << " <<<" << endl;
	}
}

void ShoppingCart::changeItemPrice(string name, double price)
{
	if (findItemInCart(name) < cart.size()) {
		int index = findItemInCart(name);
		cart.at(index).setItemPrice(price);
		cout <<"\n\t>>>Item " << name << " price changed to $" << price << " <<<" << endl;
	}

}

void ShoppingCart::removeItemFromCart(string name)
{
	int index = findItemInCart(name);
	if (index < cart.size()) {
		cart.erase(cart.begin() + index);
		cout <<"\n\t>>>Item " << name << " removed from cart<<<" << endl;
	}
	else {
		cout <<"\n\t>>>Item " << name << " not in the cart<<<" << endl;
	}
}

void ShoppingCart::outputCartInfo()
{
	double sum = 0;
	cout << "\n--Output Shopping Cart --" << endl;
	cout << "\t" << getCustomerName() << "'s Shopping Cart - " << getDateString() << endl << endl;
	cout << "'\tNumbers of Items: " << getItemCount() << endl;
	cout << "\t---------------" << endl;


	if (getItemCount() == 0) {
		cout << "\n\t>>>Shopping Cart is empty<<<" << endl;
	}
	else {
		for (int i = 0; i < cart.size(); i++) {
			cart.at(i).outputItemInfo();
			sum += cart.at(i).getItemPrice() * cart.at(i).getItemQuantity();

		}
		cout << fixed << setprecision(2) << "\n\tTotal: $" << sum << endl;
	}


}