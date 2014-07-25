#ifndef ABSTRACT_FACTORY_H_INCLUDED
#define ABSTRACT_FACTORY_H_INCLUDED

#include "iostream"
using namespace std;

/*
 *************************************************************************************************
 * Concept
 *************************************************************************************************
 */

// an abstract product
class AbstractProduct
{
public:
	virtual ~AbstractProduct() { }
	virtual void use() = 0;
};


// an abstract facory
class AbstractFactory
{
public:
	virtual AbstractProduct* createProduct() = 0;
};


// factory1 of product1
class Factory1 : public AbstractFactory
{
public:
	virtual AbstractProduct* createProduct(); // returns 'Product1' as 'AbstractProduct'
};
// factory2 of product2
class Factory2 : public AbstractFactory
{
public:
	virtual AbstractProduct* createProduct(); // returns 'Product2' as 'AbstractProduct'
};


// a product1
class Product1 : public AbstractProduct
{
public:
	virtual void use();
};
// a product2
class Product2 : public AbstractProduct
{
public:
	virtual void use();
};

#define USE_FACTORY_DEPENDING_ON_USECASE 1
#ifdef USE_FACTORY_DEPENDING_ON_USECASE
class Application : public Factory1
#else
class Application : public Factory2
#endif
{
};

/***************************************************************************************************/

#endif // ABSTRACT_FACTORY_EX_H_INCLUDED
