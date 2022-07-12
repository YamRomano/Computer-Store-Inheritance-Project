
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <string>
#include "PeripheralDevice.h"

#ifndef Mouse_h
#define Mouse_h

//PeripheralDevice's derived class.
class Mouse : public PeripheralDevice
{
private:
	int dpi;

public:
	/*-------------------- C'TOR --------------------*/
	Mouse(int price, const string& manufacturer, const string& color, bool isWireless, int dpi);

	/*-------------------- VIRTUAL D'TOR --------------------*/
	// the destructor is virtual in order to enable future subclasses of Mouse.
	virtual ~Mouse();

	/*-------------------- GETTERS --------------------*/
	int getDpi() const;

	/*-------------------- SETTERS --------------------*/
	void setDpi(int dpi);

	/*-------------------- ADDITIONAL FUNCTIONS --------------------*/
	// The keyword 'override' says that the sub-class provides it's own implementation to the base's method. 
	// Those functions are virtual in order to declare that future derived classes may provide their own implementations.

	//convert to string
	virtual operator string() const override;

	//connect to a Computer
	virtual void connect(Computer* c) override;
};

#endif // !Mouse_h