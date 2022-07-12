
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <iostream>
#include <string>
#include <vector>
#include "HWExceptions.h"
#include "Item.h"

using std::string;
using std::vector;

#ifndef Computer_h
#define Computer_h

// Item's derived class.
class Computer : public Item
{
private:
	string cpu;
	bool isLaptop;
	const int usbPorts;
	vector<Item*> connectedItems;

public:
	/*-------------------- C'TOR --------------------*/
	Computer(int price = 0, const string& manufacturer = "~", const string& cpu = "~", bool isLaptop = false, int usbPorts = 0);

	/*-------------------- VIRTUAL D'TOR --------------------*/
	// the destructor is virtual in order to enable future subclasses of Computer.
	virtual ~Computer();

	/*-------------------- GETTERS --------------------*/
	const string& getCpu() const;
	bool getIsLaptop() const;
	int getPorts() const;
	// return true if connected an item of the same type as the argument item, false otherwise.
	bool getIsTypeConnected(const Item* item) const;

	/*-------------------- SETTERS --------------------*/
	void setCpu(const string& cpu = "~");
	void setIsLaptop(bool isLaptop);

	/*-------------------- ADDITIONAL FUNCTIONS --------------------*/
	// The keyword 'override' says that the sub-class provides it's own implementation to the base's operator string method. 

	//convert to string
	virtual operator string() const override;

	// connect items to usb ports
	void connectDevice(Item* item);

	//disconnect
	void disconnectDevice(int id);

	// print connected devices
	void print_connected() const;
};

#endif // !Computer_h