#include "lazy_initialization.h"
using namespace LAZY_INITIALIZATION;

Object* LazyInitialization::getObjectInstance()
{
	return new Object();
}

// implement call through atexit() for automatic delete?
void LazyInitialization::disposeObjectInstance(Object** pObjectInstance)
{
	if (*pObjectInstance != NULL)
	{
		delete *pObjectInstance;
		*pObjectInstance = NULL;
	}
}
