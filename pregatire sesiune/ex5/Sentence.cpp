#include "Sentence.h"

Sentence::Sentence(string name)
{
	this->name = name;
}

Sentence& Sentence::operator+=(Procesor* p)
{
	procesators.push_back(p);
	return *this;
}

void Sentence::RunAll()
{
	for (auto p : procesators)
		cout << "Name:" << p->GetName() << " => " << p->Compute(this->name) << "\n";
}

void Sentence::ListAll()
{
	for (auto p : procesators)
		cout << "Name:" << p->GetName() << " \n";
}

void Sentence::Run(string numeFunc)
{
	for (auto p : procesators)
		if (p->GetName() == numeFunc)
			cout << p->Compute(name);
}
