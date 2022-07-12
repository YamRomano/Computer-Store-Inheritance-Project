
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include <map>
#include <exception>
#include "Branch.h"

#ifndef MainOffice_h
#define MainOffice_h

using std::string;
using std::map;

class MainOffice
{
private:
	map<string, Branch> branches;
	MainOffice() {};
	MainOffice(const MainOffice&) = delete;
	const MainOffice& operator=(const MainOffice&) = delete;
	~MainOffice() {};

public:
	static MainOffice& getInstance();
	void addBranch(const string& location, int capacity);
	void deleteBranch(const string& location);
	map<string, Branch>& getBranches();
	void printByLocation() const;
	void closeOffice();
};

#endif // !MainOffice_h