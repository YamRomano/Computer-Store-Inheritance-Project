
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <string>
#include "PeripheralDevice.h"

#ifndef Keyboard_h
#define Keyboard_h

//PeripheralDevice's derived class.
class Keyboard : public PeripheralDevice
{
private:
	int numOfKeys;

public:
	/*-------------------- C'TOR --------------------*/
	Keyboard(int price, const string& manufacturer, const string& color, bool isWireless, int numOfKeys);

	/*-------------------- VIRTUAL D'TOR --------------------*/
	// the destructor is virtual in order to enable future subclasses of Keyboard.
	virtual ~Keyboard();

	/*-------------------- GETTERS --------------------*/
	int getNumOfKeys() const;

	/*-------------------- SETTERS --------------------*/
	void setNumOfKeys(int numOfKeys = 0);

	/*-------------------- ADDITIONAL FUNCTIONS --------------------*/
	// The keyword 'override' says that the sub-class provides it's own implementation to the base's method. 
	// Those functions are virtual in order to declare that future derived classes may provide their own implementations.

	//convert to string
	virtual operator string() const override;

	//connect to a computer
	virtual void connect(Computer* c)  override;

};

#endif // !Keyboard_h