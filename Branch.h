
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Item.h"
#include "HWExceptions.h"

using std::string;
using std::vector;

#ifndef Branch_h
#define Branch_h

class Branch
{
private:
	vector<Item*> catalog;
	string location;
	int catalogValue;
	const int capacity;

	void print(vector<Item*>::iterator begin, const vector<Item*>::iterator& end) const;

public:
	/*-------------------- C'TOR --------------------*/
	Branch(const string& location = "~", int capacity = 0);
	Branch(const Branch& other);

	/*-------------------- D'TOR --------------------*/
	~Branch();

	//add a new item at the next place
	void addItem(Item* newItem) throw(FullCatalogError, ExistingItemError);

	Item* deleteItem(int id) throw(NonExistingItemError);

	/*-------------------- GETTERS --------------------*/
	const vector < Item*>* getCatalog() const;
	const string& getLocation() const;
	int getCatalogValue() const;

	/*-------------------- SETTERS --------------------*/
	void setLocation(const string& location = "~");

	/*-------------------- PRINT FUNCTIONS --------------------*/
	void print_catalog_by_id() const;
	void print_catalog_by_price() const;

	/*-------------------- OTHER FUNCTIONS --------------------*/
	template<class T>
	T* retrieveFinest(const T* item) const
	{
		Item* maxPrice = NULL;
		for (Item* item : this->catalog)
			if (dynamic_cast<T*>(item) != NULL)
				if ((maxPrice == NULL) || (item->getPrice() > maxPrice->getPrice()))
					maxPrice = item;
		if (maxPrice == NULL)
			throw NoneExistingItemTypeError();
		return dynamic_cast<T*>(maxPrice);//in order to return the same type we've been given
	};
};
#endif // !Branch_h