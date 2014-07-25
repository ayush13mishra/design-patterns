// designpatterns.cpp : Defines the entry point for the console application.

/*
 *******************************************************************************************************************
 * FACTORY METHOD - START
 *******************************************************************************************************************
 */
#include "factorymethod_intfcimpl.h"
#include "factorymethod_subclassing.h"

void Test_FactoryMethod_UsingInterfaceImpl()
{
	cout << " -- Test_FactoryMethod_UsingInterfaceImpl -- " << endl;
	using namespace FACTORY_METHOD__USING_INTERFACE_IMPL;
	// User knows abstract factory, concrete factory, & abstract product,    but not concrete product
	//		gets abstract product from concrete factory
	Factory *pF = new Factory();				// Example: SedanFactory
	AbstractProduct *pAP = pF->factoryMethod();	// Example: Car
	pAP->use(); // User uses  concrete product   without knowning it		// Example: getCarType gives Sedan
	delete pAP;
	delete pF;
}

void Test_FactoryMethod_Subclassing()
{
	cout << " -- Test_FactoryMethod_Subclassing -- " << endl;
	using namespace FACTORY_METHOD__USING_SUBCLASSING;
	Container *p1 = new Container();
	SpecialContainer *p2 = new SpecialContainer();
}

/*
 *******************************************************************************************************************
 * FACTORY METHOD - END
 *******************************************************************************************************************
 */


/*
 *******************************************************************************************************************
 * ABSTRACT FACTORY - START
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

void Test_AbstractFactory()
{
	cout << " -- Test_AbstractFactory -- " << endl;
	//	Assume this is also framework code
	(new myApp())->run();
	(new myGUIApp())->run();
}

/*
 *******************************************************************************************************************
 * ABSTRACT FACTORY - END
 *******************************************************************************************************************
 */

int main(int argc, int *argv[])
{
	Test_AbstractFactory();

	Test_FactoryMethod_UsingInterfaceImpl();
	Test_FactoryMethod_Subclassing();

	return 0;
}
