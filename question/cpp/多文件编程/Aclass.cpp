#include "Aclass.h"



Aclass::Aclass()
{
	cout << "Aclass::Aclass()" << endl;
}


Aclass::~Aclass()
{
	cout << "Aclass::~Aclass()" << endl;
}

void Aclass::show(Bclass * b) {
	cout << "Class Aclass voie show(Bclass b)" << endl;
}
