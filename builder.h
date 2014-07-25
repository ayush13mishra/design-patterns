#ifndef BUILDER_H_INCLUDED
#define BUILDER_H_INCLUDED
#include "common.h"

namespace BUILDER
{
	class Product // Concrete
	{
	public:
		string part1, part2, part3, part4;
		void see();
	};

	// Abstract interface for creating objects (product).
	class Builder
	{
	public:
		virtual void buildProductPart1(string partValue) = 0;
		virtual void buildProductPart2(string partValue) = 0;
		virtual void buildProductPart3(string partValue) = 0;
		virtual void buildProductPart4(string partValue) = 0;
	};

	//	Constructs and assembles parts to build the objects.
	class ConcreteBuilder : public Builder
	{
		Product product;
	public:
		virtual void buildProductPart1(string partValue);
		virtual void buildProductPart2(string partValue);
		virtual void buildProductPart3(string partValue);
		virtual void buildProductPart4(string partValue);
		Product& getResult();
	};
	// --------------------------------------------------
	enum PartType
	{
		PART1, PART2, PART3, PART4
	};
	class Director
	{
		Builder &builder;
	public:
		Director(Builder &builder1);
		void Construct(enum PartType partType, string partValue);
	};
	// --------------------------------------------------

}
#endif // BUILDER_H_INCLUDED
