//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include "Branch.h"

//we will use this functions in stl sort in order to sort by ID
bool compareId(Item* left, Item* right)
{
	return left->getId() < right->getId();
}
//we will use this functions in stl stable sort in order to sort by price
bool comparePrice(Item* left, Item* right)
{
	return left->getPrice() < right->getPrice();
}

/*-------------------- FIND ID FUNCTION --------------------*/
vector<Item*>::iterator findId(vector<Item*>::iterator begin, const vector<Item*>::iterator& end, int id)
{
	for (; begin != end; ++begin)
	{
		if ((*begin)->getId() == id)
			return begin;
	}
	return end;
}
/*-------------------- PRIVATE PRINT FUNCTION --------------------*/
void Branch::print(vector<Item*>::iterator begin, const vector<Item*>::iterator& end) const
{
	std::cout << "Printing KSF branch in " << this->location << std::endl;
	std::cout << "There are " << this->catalog.size() << " item in the catalog" << std::endl;
	std::cout << "Catalog value is: " << this->catalogValue << std::endl;

	for (; begin != end; ++begin)
	{
		std::cout << string(**begin) << std::endl;
	}
}
/*-------------------- C'TOR --------------------*/
Branch::Branch(const string& location, int capacity) : location(location), capacity(capacity), catalogValue(0)
{
}

Branch::Branch(const Branch& other) : location(other.location), capacity(other.capacity), catalogValue(0)
{
}
/*-------------------- D'TOR --------------------*/

Branch::~Branch()
{
	for (vector<Item*>::iterator iter = this->catalog.begin(); iter != this->catalog.end(); ++iter)
	{
		delete* iter;
	}
	this->catalog.clear();
}
/*-------------------- ADD\DELETE FUNCTIONS --------------------*/

void Branch::addItem(Item* newItem)
{
	if (this->catalog.size() == this->capacity) {
		throw FullCatalogError();
	}
	else if (findId(this->catalog.begin(), this->catalog.end(), newItem->getId()) != this->catalog.end())
		throw ExistingItemError();
	else {
		this->catalog.push_back(newItem);
		this->catalogValue += newItem->getPrice();
	}
}

Item* Branch::deleteItem(int id)
{
	vector<Item*>::iterator ItemIter;
	Item* returnItem;

	ItemIter = findId(this->catalog.begin(), this->catalog.end(), id);

	if (ItemIter == this->catalog.end())
		throw NonExistingItemError();
	returnItem = *ItemIter;
	this->catalog.erase(ItemIter);
	return returnItem;
}
/*-------------------- GETTERS --------------------*/

const vector < Item*>* Branch::getCatalog() const
{
	return &(this->catalog);
}

const string& Branch::getLocation() const
{
	return this->location;
}

int Branch::getCatalogValue() const
{
	return this->catalogValue;
}

/*-------------------- SETTERS --------------------*/
void Branch::setLocation(const string& location)
{
	this->location = location;
}

/*-------------------- PRINT BY ID/PRICE FUNCTIONS --------------------*/
//using stl sort and copyCatalog with compareID function
void Branch::print_catalog_by_id() const
{
	vector<Item*> copyCatalog(this->catalog);
	std::sort(copyCatalog.begin(), copyCatalog.end(), compareId);
	print(copyCatalog.begin(), copyCatalog.end());
}
//using stl stable sort and copyCatalog with comparePrice function
void Branch::print_catalog_by_price() const
{
	vector<Item*> copyCatalog(this->catalog);
	std::stable_sort(copyCatalog.begin(), copyCatalog.end(), comparePrice);
	print(copyCatalog.begin(), copyCatalog.end());
}