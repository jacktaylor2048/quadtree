#ifndef EXAMPLE_QUADTREE_H
#define EXAMPLE_QUADTREE_H

#include "quadtree.h"

/*
 * An example implementation of the Quadtree class. The collisions() and contains() methods make use 
 * of the methods provided by ExampleEntity.
 */
template<typename T>
class ExampleQuadtree : public Quadtree<T>
{
public:
	ExampleQuadtree(int level, double px, double py, double width, double height);
	void collisions();
private:
	void split();
	bool contains(T* obj);
};

// Constructor
template<typename T>
ExampleQuadtree<T>::ExampleQuadtree(int level, double px, double py, double width, double height) : Quadtree<T>(level, px, py, width, height)
{
	
}

// Perform collision detection on all objects in this node.
template<typename T>
void ExampleQuadtree<T>::collisions()
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

// Create four equally sized child nodes.
template <typename T>
void ExampleQuadtree<T>::split()
{
	child[0] = new ExampleQuadtree<T>(level + 1, position_x, position_y, width * 0.5, height * 0.5);
	child[1] = new ExampleQuadtree<T>(level + 1, position_x + width * 0.5, position_y, width * 0.5, height * 0.5);
	child[2] = new ExampleQuadtree<T>(level + 1, position_x, position_y + height * 0.5, width * 0.5, height * 0.5);
	child[3] = new ExampleQuadtree<T>(level + 1, position_x + width * 0.5, position_y + height * 0.5, width * 0.5, height * 0.5);
}

// Check whether this node contains the specified object.
template<typename T>
bool ExampleQuadtree<T>::contains(T* obj)
{
	return position_x <= obj->get_position_x() + obj->get_boundary_x() + obj->get_offset_x()
		&& position_x + width >= obj->get_position_x() + obj->get_offset_x()
		&& position_y <= obj->get_position_y() + obj->get_boundary_y() + obj->get_offset_y()
		&& position_y + height >= obj->get_position_y() + obj->get_offset_y();
}

#endif
