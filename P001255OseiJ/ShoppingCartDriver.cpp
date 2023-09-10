// TO BE COMPLETED: ShoppingCartDriver.cpp
#include <iostream>
#include "ShoppingCart.h"
#include<iomanip>

using namespace std;

char getMenuChoice();
void processMenuChoice(char, ShoppingCart&);

int main() {
	string custName;
	char choice;

	// COMPLETE THIS FUNCTION

	// Asks user to enter customer name
	// Displays title, customer name, and date
	// choice = getMenuChoice();
	//
	// set up while loop to check for choice of 'q'
	//		if not 'q', processMenuChoice
	//		call getMenuChoice() again
	cout << endl;
	cout <<"\n\t****Shopping Cart****" << endl << endl;

	cout << "\tEnter customer's name: ";
	getline(cin, custName);
	cout << endl;
	cout << "\tCustomer Name: " << custName << " Today's Date: " << getDateString();
	cout << endl;

	ShoppingCart Cart(custName);
	do {
		choice = getMenuChoice();
		processMenuChoice(choice, Cart);

	} while (choice != 'q');

}

char getMenuChoice() {
	string menuOptions = "adcpstoq";
	char choice = ' ';

	// COMPLETE THIS FUNCTION
	//	Display the menu
	 //cout << endl;
	cout <<"\n\t--Online Shopping Menu --" << endl;
	cout <<"\ta - Add item to cart" << endl;
	cout <<"\td - Remove item from cart" << endl;
	cout <<"\tc-Change item quantity" << endl;
	cout <<"\tp-Change item price" << endl;
	cout <<"\to-Output shopping cart" << endl;
	cout <<"\tq-Quit" << endl;
	//	Consider using string function "find" to determine
	//		if the choice is one of the letters in menuOptions string above

	//  Once a "valid" choice is made, return the choice to "main()"
	cout << endl;
	cout <<"\tChoose Option: ";
	cin >> choice;

	if (menuOptions.find(choice) != string::npos) {
		return choice;
	}
}

void processMenuChoice(char choice, ShoppingCart& theCart) {
	string name = "";
	double price = 0.0;
	int quantity = 0;

	// COMPLETE THE "switch" below
	//	refer to sample runs for I/O formatting

	switch (choice) {
	case 'a':
		// get the item name, price, quantity from user
		// call addItemToCart with an Item object as an argument
		cout << endl;
		cout <<"\t--Add Item to Cart--" << endl;
		cout <<"\tEnter the item name: ";
		cin.ignore();
		getline(cin, name);
		cout <<"\tEnter the item price:";
		cin >> price;
		cout <<"\tEnter the item quantity:";
		cin >> quantity;
		theCart.addItemToCart(Item(name, price, quantity));
		break;

	case 'd':
		// get the item name from user
		// call removeItemFromCart with name as the argument
		cout << "\t--Remove Item from Cart--" << endl;
		cout <<"\tEnter name of Item to remove: ";
		cin.ignore();
		getline(cin, name);
		theCart.removeItemFromCart(name);
		break;

	case 'c':
		// get the item name and new quantity from user
		// call changeItemQuantity with name and new quantity as arguments
		cout <<"\t--Change Item Quantity--" << endl;
		cout <<"\tEnter the item name:";
		cin.ignore();
		getline(cin, name);
		cout <<"\tEnter the new quantity:";
		cin >> quantity;
		theCart.changeItemQuantity(name, quantity);
		break;

	case 'p':
		// get the item name and new price from user
		// call changeItemPrice with name and new price as arguments
		cout <<"\t--Change Item Price--";
		cout <<"\tEnter item name:";
		cin.ignore();
		getline(cin, name);
		cout <<"\tEnter the new price:";
		cin >> price;
		theCart.changeItemPrice(name, price);
		break;

	case 'o':
		// display cart info -- see sample runs
		theCart.outputCartInfo();
		break;
	}
}