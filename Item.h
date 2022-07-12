
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <string>
using std::string;

#ifndef Item_h
#define Item_h
#define ID 318267721 

//Abstract Base Class
class Item
{
private:
	int price;
	string manufacturer;
	int id;

	//the Id for the the next Item to be constracted
	static int nextId;

public:
	/*-------------------- C'TOR --------------------*/
	Item(int price, const string& manufacturer);

	/*-------------------- VIRTUAL D'TOR --------------------*/
	// the destructor is virtual in order to delete its sub-classes properly.
	virtual ~Item();

	/*-------------------- GETTERS --------------------*/
	int getPrice() const;
	const string& getManufacturer() const;
	int getId() const;

	/*-------------------- SETTERS --------------------*/
	void setPrice(int price);
	void setManufacturer(const string& manufacturer);

	/*-------------------- ADDITIONAL FUNCTIONS --------------------*/
	// This function is pure virtual in order to make its subclasses to provide their own implementations.
	virtual operator string() const = 0;
};

#endif // !Item_h