#ifndef SINGLETON_H_INCLUDED
#define SINGLETON_H_INCLUDED
#include "common.h"

namespace SINGLETON
{
	class Singleton												// Example: Room
	{
	private:
		static Singleton *_instance;
		Singleton()
		{ // .. 
		}
	public:
		static Singleton* getInstance();
	};
}
#endif // SINGLETON_H_INCLUDED
