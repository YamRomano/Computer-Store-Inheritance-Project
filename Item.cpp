
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <iostream>
#include "Item.h"

int Item::nextId = 1;
/*-------------------- C'TOR --------------------*/
Item::Item(int price, const string& manufacturer) : price(price), manufacturer(manufacturer), id((Item::nextId)++)
{
}

/*-------------------- D'TOR --------------------*/
Item::~Item()
{
	std::cout << "Throwing away an item" << std::endl;
}

/*-------------------- GETTERS --------------------*/
int Item::getPrice() const
{
	return this->price;
}

const string& Item::getManufacturer() const
{
	return this->manufacturer;
}

int Item::getId() const
{
	return this->id;
}

/*-------------------- SETTERS --------------------*/
void Item::setPrice(int price)
{
	this->price = price;
}

void Item::setManufacturer(const string& manufacturer)
{
	this->manufacturer = manufacturer;
}
/*-------------------- ADDITIONAL FUNCTIONS --------------------*/

Item::operator string() const
{
	return ("id " + std::to_string(this->id) + ": " + this->manufacturer + " " + std::to_string(this->price) + "$");
}