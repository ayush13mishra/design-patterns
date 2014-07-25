#include "singleton.h"
using namespace SINGLETON;

Singleton* Singleton::_instance = NULL;
Singleton* Singleton::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new Singleton();
	}
	return _instance;
}
