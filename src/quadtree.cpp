#include "quadtree.h"
// Constructor
template <typename T>
Quadtree<T>::Quadtree(int level, float position_x, float position_y, int width, int height)
{
	max_objects = 50;
	if (level <= MAX_LEVEL) Quadtree::level = level;
	else Quadtree::level = MAX_LEVEL;
	Quadtree::position_x = position_x;
	Quadtree::position_y = position_y;
	Quadtree::width = width;
	Quadtree::height = height;
	for (int i = 0; i < 4; i++) child[i] = NULL;
	objects.reserve(4096);
}
// Destructor
template <typename T>
Quadtree<T>::~Quadtree()
{
	if (level == 0)
	{
		for (std::vector<T*>::iterator i = objects.begin(); i != objects.end();)
		{
			delete (*i);
			i = objects.erase(i);
		}
	}
	else objects.clear();
}
template <typename T>
void Quadtree<T>::update()
{

}
// Perform collision detection on all objects in this node.
template <typename T>
void Quadtree<T>::collisions()
{
	for (auto& i : objects)
	{
		for (auto& i2 : sprites)
		{
			if (i->check_collision(i2))
			{
				i->collide(i2);
				i2->collide(i);
			}
		}
	}
}
template <typename T>
void Quadtree<T>::add(T* ent)
{
	objects.push_back(ent);
}
template <typename T>
void Quadtree<T>::partition()
{

}
template <typename T>
void Quadtree<T>::cleanup()
{

}
template <typename T>
void Quadtree<T>::split()
{

}
template <typename T>
void Quadtree<T>::clear()
{

}
// Check whether this node contains the specified entity
template <typename T>
bool Quadtree<T>::contains(Entity* ent)
{
	return position_x <= ent->get_x() + ent->get_bx() + ent->get_ox()
		&& position_x + width >= ent->get_x() + ent->get_ox()
		&& position_y <= ent->get_y() + ent->get_by() + ent->get_oy()
		&& position_y + height >= ent->get_y() + ent->get_oy();

}
template <typename T>
bool Quadtree<T>::leaf()
{
	return child[0] == NULL && child[1] == NULL && child[2] == NULL && child[3] == NULL;
}