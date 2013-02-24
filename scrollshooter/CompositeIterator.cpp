#include "precomp.h"
#include "CompositeIterator.h"


CompositeIterator::CompositeIterator(std::vector<gameComponentPtr> *collection):
	Iterator(collection)
{
}


CompositeIterator::~CompositeIterator(void)
{
}
