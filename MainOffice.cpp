
//Student1 David Afik, davidafik97@gmail.com, 318267721.
//Student2 Yam Romano, yam.romano1@gmail.com, 327054847. 

#include "MainOffice.h"

/*-------------------- GETTE INSTANCE --------------------*/
MainOffice & MainOffice::getInstance()
{
    static MainOffice instance;
    return instance;
}

/*-------------------- ADD BRANCH --------------------*/
void MainOffice::addBranch(const string& location = "~", int capacity = 0)
{
    map<string, Branch>::iterator iter;
    iter = this->branches.find(location);
    if (iter == this->branches.end())
        this->branches.insert({ location, Branch(location, capacity) });
    else
        throw ExistingBranchError();
}

/*-------------------- DELETE BRANCH --------------------*/
void MainOffice::deleteBranch(const string& location)
{
    map<string, Branch>::iterator iter;
    iter = this->branches.find(location);
    if (iter != this->branches.end()) {
        this->branches.erase(iter);
    }
    else
        throw NonExistingBranchError();
}
/*-------------------- GET BRANCH --------------------*/
map<string, Branch>& MainOffice::getBranches()
{
    return this->branches;
}

/*-------------------- PRINT BY LOCATION--------------------*/
void MainOffice::printByLocation() const
{
    map<string, Branch>::const_iterator iter;
    std::cout << "There are " << this->branches.size() << " KSP branches" << std::endl;
    for (iter = this->branches.begin(); iter != this->branches.end(); ++iter) {
        iter->second.print_catalog_by_id();
    }
}
/*-------------------- CLOSE OFFICE --------------------*/
void MainOffice::closeOffice()
{
    this->branches.clear();
}