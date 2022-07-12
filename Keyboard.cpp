
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include "Keyboard.h"

/*-------------------- C'TOR  --------------------*/
Keyboard::Keyboard(int price, const string & manufacturer, const string & color, bool isWireless, int numOfKeys) :
	PeripheralDevice(price, manufacturer, color, isWireless), numOfKeys(numOfKeys)
{
}

/*-------------------- D'TOR --------------------*/
Keyboard::~Keyboard()
{
}

/*-------------------- GETTERS --------------------*/
int Keyboard::getNumOfKeys() const
{
	return this->numOfKeys;
}

/*-------------------- SETTERS --------------------*/
void Keyboard::setNumOfKeys(int numOfKeys)
{
	this->numOfKeys = numOfKeys;
}

/*-------------------- TO STRING OPERATOR --------------------*/
Keyboard::operator string() const
{
	return this->PeripheralDevice::operator string() + ", Keyboard with " + std::to_string(this->numOfKeys) + " keys";
}

/*-------------------- CONNECT --------------------*/
void Keyboard::connect(Computer* c)
{
	std::cout << "Connecting a keyboard" << std::endl;
	this->PeripheralDevice::connect(c);

}