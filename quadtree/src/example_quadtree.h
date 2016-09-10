#ifndef EXAMPLE_QUADTREE_H
#define EXAMPLE_QUADTREE_H

#include "quadtree.h"

/*
 * An example implementation of the Quadtree class. The collisions() and contains() methods make use 
 * of the methods provided by ExampleEntity.
 */
template<typename T>
class ExampleQuadtree<T> : public Quadtree<T>
{
public:
	ExampleQuadtree()
	{

	}
	void collisions();
private:
	void contains(T* obj);
};

// Perform collision detection on all objects in this node.
template<typename T>
void ExampleQuadtree::collisions()
{
	for (T* i : objects)
	{
		for (T* i2 : objects)
		{
			if (i->check_collision(i2))
			{
				i->collide(i2);
				i2->collide(i);
			}
		}
	}
}

// Check whether this node contains the specified object.
template<typename T>
void ExampleQuadtree::contains(T* obj)
{
	return position_x <= obj->get_position_x() + obj->get_boundary_x() + obj->get_offset_x()
		&& position_x + width >= obj->get_position_x() + obj->get_offset_x()
		&& position_y <= obj->get_position_y() + obj->get_boundary_y() + obj->get_offset_y()
		&& position_y + height >= obj->get_position_y() + obj->get_offset_y();
}

#endif
