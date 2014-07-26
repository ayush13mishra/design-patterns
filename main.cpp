// designpatterns.cpp : Defines the entry point for the console application.

/*
*******************************************************************************************************************
* LAZY INITIALIZATION
*******************************************************************************************************************
*/
#include "lazy_initialization.h"
void test_LazyInitialization()
{
	cout << " -- test_LazyInitialization -- " << endl;
	using namespace LAZY_INITIALIZATION;

	Object *p = LazyInitialization::getObjectInstance();
	cout << p << endl;

	LazyInitialization::disposeObjectInstance(&p);
	cout << p << endl;
	LazyInitialization::disposeObjectInstance(&p);
	cout << p << endl;

	cout << endl;
}

/*
*******************************************************************************************************************
* PROTOTYPE
*******************************************************************************************************************
*/
#include "prototype.h"
void test_Prototype()
{
	cout << " -- test_Prototype -- " << endl;
	using namespace PROTOTYPE;

	// Prototype
	ConcretePrototype1 *p1 = new ConcretePrototype1();
	p1->doSomeComplexOperation_And_saveStateToSelf();
	cout << p1->getState() << endl;

	// Client creates a new object by asking a 'Prototype' to clone itself
	ConcretePrototype1 *p2 = (ConcretePrototype1 *)p1->clone();
	cout << p2->getState() << endl;
	// p2 doesnt require to do same doSomeComplexOperation_And_saveStateToSelf(), since same operation state is received from older object p1

	cout << endl;
}


/*
*******************************************************************************************************************
* SINGLETON
*******************************************************************************************************************
*/
#include "builder.h"

void test_Builder()
{
	cout << " -- test_Builder -- " << endl;
	using namespace BUILDER;

	// Builder
	// Client creates Director object and configures with Builder object
	Builder concreteBuilder;

	Director director(concreteBuilder);

	director.Construct(Product::PART1, "Part 1");
	director.Construct(Product::PART2, "Part 2");
	// director.Construct(Product::PART3, "Part 3");
	director.Construct(Product::PART4, "Part 4");

	Product &p = concreteBuilder.getResult();
	p.see();

	cout << endl;
}

/*
*******************************************************************************************************************
* SINGLETON
*******************************************************************************************************************
*/
#include "singleton.h"
void test_Singleton()
{
	cout << " -- test_Singleton -- " << endl;
	using namespace SINGLETON;


	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	assert(p1 == p2); // This assertion should pass

	cout << p1 << endl;
	cout << p2 << endl;

	Singleton::disposeInstance();
	Singleton::disposeInstance();
	cout << endl;
}


/*
 *******************************************************************************************************************
 * FACTORY METHOD
 *******************************************************************************************************************
 */
#include "factorymethod_intfcimpl.h"
#include "factorymethod_subclassing.h"

void test_FactoryMethod_UsingInterfaceImpl()
{
	cout << " -- test_FactoryMethod_UsingInterfaceImpl -- " << endl;
	using namespace FACTORY_METHOD__USING_INTERFACE_IMPL;
	// User knows abstract factory, concrete factory, & abstract product,    but not concrete product
	//		gets abstract product from concrete factory
	Factory *pF = new Factory();				// Example: SedanFactory
	AbstractProduct *pAP = pF->factoryMethod();	// Example: Car
	pAP->use(); // User uses  concrete product   without knowning it		// Example: getCarType gives Sedan
	delete pAP;
	delete pF;

	cout << endl;
}

void test_FactoryMethod_Subclassing()
{
	cout << " -- test_FactoryMethod_Subclassing -- " << endl;
	using namespace FACTORY_METHOD__USING_SUBCLASSING;
	Container *p1 = new Container();
	SpecialContainer *p2 = new SpecialContainer();

	cout << endl;
}

/*
 *******************************************************************************************************************
 * ABSTRACT FACTORY
 *******************************************************************************************************************
 */
#include "abstractfactory.h"
#include "abstractfactory_example.h"
// using namespace FACTORY_METHOD__USING_INTERFACE_IMPL;

// --- FRAMEWORK GENERATED CODE - START ---
//		when user chooses appname as 'myApp' for 'Application', and
//		when user chooses appname as 'myGUIApp' for 'GUIApplication'
//			these classese are framework created 
class myApp : public ABSTRACT_FACTORY::Application
{
public:

	// Assume this function is where framework allows user to write code here - see below for implementation
	void run();
};

class myGUIApp : public ABSTRACT_FACTORY_EXAMPLE::GUIApplication
{
public:

	// Assume this function is where framework allows user to write code here - see below for implementation
	void run();
};
// --- FRAMEWORK GENERATED CODE - END ---

// --- USER CODE - START ---
// Concept
void myApp::run() // say this is where framework allows user to write code here
{
	// user only knows    AbstractFactory & AbstractProduct    interfaces
	ABSTRACT_FACTORY::AbstractProduct *pAP = this->createProduct();
	pAP->use(); // User uses  concrete product   without knowning the   concrete factory & concrete product
	delete pAP; pAP = NULL;
}

// Example
void myGUIApp::run() // say this is where framework allows user to write code here
{
	// user only knows    AbstractFactory & AbstractProduct    interfaces
	ABSTRACT_FACTORY_EXAMPLE::Button *pAP = this->createButton();
	pAP->use(); // User uses  concrete product   without known the   concrete factory & concrete product
	delete pAP; pAP = NULL;
}
// --- USER CODE - END ---

void test_AbstractFactory()
{
	cout << " -- test_AbstractFactory -- " << endl;
	//	Assume this is also framework code
	(new myApp())->run();
	(new myGUIApp())->run();

	cout << endl;
}

/*
 *******************************************************************************************************************
 *******************************************************************************************************************
 */

int main(int argc, int *argv[])
{
	test_AbstractFactory();

	test_FactoryMethod_UsingInterfaceImpl();
	test_FactoryMethod_Subclassing();

	test_Singleton();

	test_Builder();

	test_Prototype();

	test_LazyInitialization();

	return 0;
}
