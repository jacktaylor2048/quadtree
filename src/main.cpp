#include "entity.h"
#include "quadtree.h"
int main()
{
	Quadtree<Entity*> tree = Quadtree<Entity*>(0, 0, 0, 128, 128);
	for (int i = 0; i < 1000; i++) tree.add(new Entity(rand() % 128, rand() % 128, 8, 8));
	return 0;
}
