#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED
#include "common.h"

namespace PROTOTYPE
{
	// To implement the pattern, 
	//		declare an abstract base class that 
	//			specifies a pure virtual clone() method.
	//	Any class that needs a "polymorphic constructor" capability
	//		derives itself from the abstract base class, and 
	//		implements the clone() operation.

	class Prototype // Abstract class
	{
	public:
		virtual ~Prototype() { } // virtual destructor bcoz 'clone' returns 'ConcretePrototype1' as 'Prototype'
		virtual Prototype* clone() = 0; // Acts as a virtual copy constructor - clones itself
	};
	class ConcretePrototype1 : public Prototype
	{
	public:
		virtual Prototype* clone();  // 'clone' returns 'ConcretePrototype1' as 'Prototype'
		void doSomeComplexOperation_And_saveStateToSelf();  // 'clone' returns 'ConcretePrototype1' as 'Prototype'
		int getState();
	private:
		// Does the Copy constructor need to be private (and so constructor in public)?
		int _exampleAsState;
	};
};

#endif // PROTOTYPE_H_INCLUDED
