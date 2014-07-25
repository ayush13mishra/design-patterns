#include "abstractfactory_example.h"
using namespace ABSTRACT_FACTORY_EXAMPLE;

// Example

Button* WinFactory::createButton()
{
	return new WinButton();	// dynamic_cast <AbstractProduct*> ()
}

Button* OSXFactory::createButton()
{
	return new OSXButton();	// dynamic_cast <AbstractProduct*> ()
}

void WinButton::use()
{
	cout << "WinButton consumed" << endl;
}
void OSXButton::use()
{
	cout << "OSXButton consumed" << endl;
}
