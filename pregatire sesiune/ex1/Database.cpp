#include "Database.h"

Database& Database::operator+=(Entry *e)
{
    this->entries.push_back(e);
    return *this;
}

Database& Database::operator-=(string name)
{
    for (int i = 0; i < this->entries.size(); i++)
        if (entries[i]->GetName() == name)
            entries.erase(entries.begin() + i);
    return *this;
}


vector<Entry*>::iterator Database::begin()
{
    return entries.begin();
}

vector<Entry*>::iterator Database::end()
{
    return entries.end();
}

void Database::Print()
{
    for (int i = 0; i < this->entries.size(); i++)
    {
        entries[i]->Print();
    }
    cout << "\n";

}
