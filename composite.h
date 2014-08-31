#ifndef COMPOSITE_H_INCLUDED
#define COMPOSITE_H_INCLUDED
#include "common.h"
#include <list>

// distribution and location transparency
namespace COMPOSITE
{
    class IComposite
    {
    public:
        virtual void someOperation() = 0;
    };

    class Leaf : public IComposite
    {
    public:
        void someOperation();
    };

    class Composite : public IComposite
    {
        std::list<IComposite *> children;
    public:
        void someOperation();
        void addChild(IComposite *pIC);
        void removeChild(IComposite *pIC);
    };

};
#endif // COMPOSITE_H_INCLUDED
