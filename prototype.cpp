#include "prototype.h"
using namespace PROTOTYPE;

void ConcretePrototype1::doSomeComplexOperation_And_saveStateToSelf()
{
	// Did some complex operation, saved state into self.
	_exampleAsState = 999;
}

int ConcretePrototype1::getState()
{
	return _exampleAsState;
}

Prototype* ConcretePrototype1::clone()  // 'clone' returns 'ConcretePrototype1' as 'Prototype'
{
	return  (new ConcretePrototype1(*this));		// calls Copy constructor   // dynamic_cast <Prototype*>
}
