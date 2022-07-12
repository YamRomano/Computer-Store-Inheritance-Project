
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <exception>

#ifndef HWExceptions_h
#define HWExceptions_h

class ExistingItemError : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Trying to add an item with an id already in the catalog";
	}
};

class FullCatalogError : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Trying to add an item to a full catalog";
	}
};

class NonExistingItemError : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Trying to delete an item with a non existing id";
	}
};

class NoneExistingItemTypeError : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Trying to get an item with a non existing type";
	}
};

class ConnectError : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Failed connection attempt";
	}
};

class ExistingBranchError : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Trying to add a branch with an already existing location";
	}
};

class NonExistingBranchError : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Trying to delete a branch with an non existing location";
	}
};


#endif // !HWExceptions_h