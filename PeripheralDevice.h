
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <iostream>
#include <string>
#include "Item.h"
#include "Computer.h"

using std::string;

#ifndef PeripheralDevice_h
#define PeripheralDevice_h

//Abstract Base Class. Item's derived class.
class PeripheralDevice : public Item
{
private:
	string color;
	bool isWireless;
	Computer* connectedComputer;

public:
	/*-------------------- C'TOR --------------------*/
	PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless);

	/*-------------------- VIRTUAL D'TOR --------------------*/
	virtual ~PeripheralDevice();

	/*-------------------- GETTERS --------------------*/
	const string& getColor() const;
	bool getIsWireless() const;
	const Computer* getConnectedComputer() const;

	/*-------------------- SETTERS --------------------*/
	void setColor(const string& color);
	void setIsWireless(bool isWireless);

	/*-------------------- ADDITIONAL FUNCTIONS --------------------*/
	// The keyword 'override' says that the sub-class provides it's own implementation to the base's method. 
	// Those functions are pure virtual in order to declare that the derived classes must provide their own implementations.

	//convert to string
	virtual operator string() const override = 0;

	//connect to a computer
	virtual void connect(Computer* c) = 0;

	//disconnect from the computer
	virtual void disconnect();
};

#endif // !PeripheralDevice_h