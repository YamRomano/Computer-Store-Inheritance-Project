
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include "PeripheralDevice.h"

/*-------------------- C'TOR --------------------*/
PeripheralDevice::PeripheralDevice(int price, const string & manufacturer, const string & color, bool isWireless)
	: Item(price, manufacturer), color(color), isWireless(isWireless), connectedComputer(NULL)
{
}
/*-------------------- D'TOR --------------------*/
PeripheralDevice::~PeripheralDevice()
{
	this->disconnect();
}

/*-------------------- GETTERS --------------------*/
const string& PeripheralDevice::getColor() const
{
	return this->color;
}
bool PeripheralDevice::getIsWireless() const
{
	return this->isWireless;
}

const Computer* PeripheralDevice::getConnectedComputer() const
{
	return this->connectedComputer;
}

/*-------------------- SETTERS --------------------*/
void PeripheralDevice::setColor(const string& color)
{
	this->color = color;
}

void PeripheralDevice::setIsWireless(bool isWireless)
{
	this->isWireless = isWireless;
}

/*-------------------- TO STRING OPERATOR --------------------*/
PeripheralDevice::operator string() const
{
	return this->Item::operator string() + ", " + (this->isWireless ? "Wireless" : "Wired") + ", " + this->color;
}

/*-------------------- CONNECT --------------------*/
void PeripheralDevice::connect(Computer* c)
{
	if (!this->connectedComputer) {
		std::cout << (string)(*this) << " is Connecting to computer: " << (string)*c << std::endl;
		c->connectDevice(this);
		this->connectedComputer = c;
	}
	else if (this->connectedComputer != c)
		throw ConnectError();
}

/*-------------------- DISCONNECT --------------------*/
void PeripheralDevice::disconnect()
{
	if (this->connectedComputer)
		this->connectedComputer->disconnectDevice(this->getId());
	this->connectedComputer = NULL;
}