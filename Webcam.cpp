
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include "Webcam.h"

/*-------------------- C'TOR --------------------*/
Webcam::Webcam(int price, const string & manufacturer, const string & color, bool isWireless, string resolution) :
	PeripheralDevice(price, manufacturer, color, isWireless), resolution(resolution)
{
}

/*-------------------- D'TOR --------------------*/
Webcam::~Webcam()
{
}

/*-------------------- GETTERS --------------------*/
const string& Webcam::getResolution() const
{
	return this->resolution;
}

/*-------------------- SETTERS --------------------*/
void Webcam::setResolution(const string& resultion)
{
	this->resolution = resultion;
}

/*-------------------- TO STRING OPERATOR --------------------*/
Webcam::operator string() const
{
	return this->PeripheralDevice::operator string() + ", Webcam with " + this->resolution + " resolution";
}

/*-------------------- CONNECT --------------------*/
void Webcam::connect(Computer* c)
{
	std::cout << "Connecting a webcam" << std::endl;
	this->PeripheralDevice::connect(c);
}