
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include "Mouse.h"

/*-------------------- C'TOR --------------------*/
Mouse::Mouse(int price, const string & manufacturer, const string & color, bool isWireless, int dpi) :
	PeripheralDevice(price, manufacturer, color, isWireless), dpi(dpi)
{
}

/*-------------------- D'TOR --------------------*/
Mouse::~Mouse()
{
}

/*-------------------- GETTERS --------------------*/
int Mouse::getDpi() const
{
	return this->dpi;
}

/*-------------------- SETTERS --------------------*/
void Mouse::setDpi(int dpi)
{
	this->dpi = dpi;
}

/*-------------------- TO STRING OPERATOR --------------------*/
Mouse::operator string() const
{
	return this->PeripheralDevice::operator string() + ", Mouse with dpi : " + std::to_string(this->dpi);
}

/*-------------------- CONNECT --------------------*/
void Mouse::connect(Computer* c)
{
	std::cout << "Connecting a mouse" << std::endl;
	this->PeripheralDevice::connect(c);
}