
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <string>
#include "PeripheralDevice.h"


#ifndef Webcam_h
#define Webcam_h

using std::string;

//PeripheralDevice's derived class.
class Webcam : public PeripheralDevice
{
private:
	string resolution;

public:
	/*-------------------- C'TOR --------------------*/
	Webcam(int price, const string& manufacturer, const string& color, bool isWireless, string resolution = "~");

	/*-------------------- VIRTUAL D'TOR --------------------*/
	// the destructor is virtual in order to enable future subclasses of Mouse.
	virtual ~Webcam();

	/*-------------------- GETTERS --------------------*/
	const string& getResolution() const;

	/*-------------------- SETTERS --------------------*/
	void setResolution(const string& resultion = "~");

	/*-------------------- ADDITIONAL FUNCTIONS --------------------*/
	// The keyword 'override' says that the sub-class provides it's own implementation to the base's method. 
	// Those functions are virtual in order to declare that future derived classes may provide their own implementations.

	//convert to string
	virtual operator string() const override;

	//connect to a Computer
	virtual void connect(Computer* c) override;

};

#endif // !Webcam_h