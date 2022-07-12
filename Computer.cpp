
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include "Computer.h"

/*-------------------- FIND ITEM BY ID --------------------*/
vector<Item*>::iterator findItemById(vector<Item*>::iterator begin, const vector<Item*>::iterator & end, int id)
{
	for (; begin != end; ++begin)
		if ((*begin)->getId() == id)
			return begin;
	return end;
}

/*-------------------- C'TOR --------------------*/
Computer::Computer(int price, const string& manufacturer, const string& cpu, bool isLaptop, int usbPorts) :
	Item(price, manufacturer), cpu(cpu), isLaptop(isLaptop), usbPorts(usbPorts)
{
}
/*-------------------- D'TOR --------------------*/
Computer::~Computer()
{
}

/*-------------------- GETTERS --------------------*/
const string& Computer::getCpu() const
{
	return this->cpu;
}

bool Computer::getIsLaptop() const
{
	return this->isLaptop;
}

int Computer::getPorts() const
{
	return this->usbPorts;
}

bool Computer::getIsTypeConnected(const Item* item) const
{
	for (Item* i : this->connectedItems)
		if (typeid(*i) == typeid(*item))
			return true;
	return false;
}

/*-------------------- SETTERS --------------------*/
void Computer::setCpu(const string& cpu)
{
	this->cpu = cpu;
}

void Computer::setIsLaptop(bool isLaptop)
{
	this->isLaptop = isLaptop;
}

/*-------------------- TO STRING OPERATOR --------------------*/
Computer::operator string() const
{
	return this->Item::operator string() + ", " + (this->isLaptop ? "Laptop" : "Desktop") + ", " + this->cpu;
}

/*-------------------- CONNETC --------------------*/
void Computer::connectDevice(Item* item)
{
	if ((this->connectedItems.size() >= this->usbPorts) || getIsTypeConnected(item))
		throw ConnectError();
	else
		this->connectedItems.push_back(item);
}

/*-------------------- DISCONNECT --------------------*/
void Computer::disconnectDevice(int id)
{
	vector<Item*>::const_iterator iter;
	iter = findItemById(this->connectedItems.begin(), this->connectedItems.end(), id);
	if (iter != this->connectedItems.end())
		this->connectedItems.erase(iter);
}

void Computer::print_connected() const
{
	vector<Item*>::const_iterator iter;
	std::cout << "There are " << this->connectedItems.size() << " connection to " << string(*this) << std::endl;
	for (Item* item : this->connectedItems)
		std::cout << string(*item) << std::endl;
}

