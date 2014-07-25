#include "abstractfactory.h"

/*****************************
* Concept
******************************/

AbstractProduct* Factory1::createProduct()
{
	return new Product1();
}

AbstractProduct* Factory2::createProduct()
{
	return new Product2();
}

void Product1::use()
{
	cout << "Product1 consumed" << endl;
}
void Product2::use()
{
	cout << "Product2 consumed" << endl;
}
