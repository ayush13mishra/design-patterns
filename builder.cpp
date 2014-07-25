#include "builder.h"
using namespace BUILDER;


void Product::see()
{
	cout << "Product is built with: " << (part1 + " " + part2 + " " + part3 + " " + part4).c_str();
}


//	Constructs and assembles parts to build the objects.
void ConcreteBuilder::buildProductPart1(string partValue)
{
	product.part1 = partValue;
}
void ConcreteBuilder::buildProductPart2(string partValue)
{
	product.part2 = partValue;
}
void ConcreteBuilder::buildProductPart3(string partValue)
{
	product.part3 = partValue;
}
void ConcreteBuilder::buildProductPart4(string partValue)
{
	product.part4 = partValue;
}
Product& ConcreteBuilder::getResult()
{
	return product;
}


Director::Director(Builder &builder1) : builder(builder1)
{
}
void Director::Construct(enum PartType partType, string partValue)
{
	switch (partType)
	{
	case BUILDER::PART1:
		builder.buildProductPart1(partValue);
		break;
	case BUILDER::PART2:
		builder.buildProductPart2(partValue);
		break;
	case BUILDER::PART3:
		builder.buildProductPart3(partValue);
		break;
	case BUILDER::PART4:
		builder.buildProductPart4(partValue);
		break;
	default:
		break;
	}
}
