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
// Perform update routine. This would be called any time you need to detect collisions, usually every frame.
template <typename T>
void Quadtree<T>::update()
{
	partition();
	if (leaf()) collisions();
	else for (int i = 0; i < 4; i++) child[i]->collisions();
	clear();
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
// Add an object to the vector.
template <typename T>
void Quadtree<T>::add(T* ent)
{
	objects.push_back(ent);
}
// Recursive function to assign entities to their appropriate nodes.
template <typename T>
void Quadtree<T>::partition()
{
	if (objects.size() > max_objects && level < MAX_LEVEL) split();
	if (!leaf())
	{
		for (auto& i : objects) for (int x = 0; x < 4; x++) if (child[x]->contains(i)) child[x]->add(i);
		for (int i = 0; i < 4; i++) child[i]->partition();
	}
}
// Clear the whole quadtree.
template <typename T>
void Quadtree<T>::cleanup()
{
	for (spritevector::iterator i = sprites.begin(); i != sprites.end();)
	{
		delete (*i);
		i = sprites.erase(i);
	}
	clear();
}
// Create four equally sized child nodes.
template <typename T>
void Quadtree<T>::split()
{
	child[0] = new Quadtree(level + 1, position_x, position_y, width * 0.5, height * 0.5);
	child[1] = new Quadtree(level + 1, position_x + width * 0.5, position_y, width * 0.5, height * 0.5);
	child[2] = new Quadtree(level + 1, position_x, position_y + height * 0.5, width * 0.5, height * 0.5);
	child[3] = new Quadtree(level + 1, position_x + width * 0.5, position_y + height * 0.5, width * 0.5, height * 0.5);
}
// Clear this node's children.
template <typename T>
void Quadtree<T>::clear()
{
	if (!leaf()) for (int i = 0; i < 4; i++)
	{
		child[i]->clear();
		delete child[i];
		child[i] = NULL;
	}
}
// Check whether this node contains the specified entity.
template <typename T>
bool Quadtree<T>::contains(Entity* ent)
{
	return position_x <= ent->get_x() + ent->get_bx() + ent->get_ox()
		&& position_x + width >= ent->get_x() + ent->get_ox()
		&& position_y <= ent->get_y() + ent->get_by() + ent->get_oy()
		&& position_y + height >= ent->get_y() + ent->get_oy();

}
// Check whether this is a leaf node (i.e. it has no children).
template <typename T>
bool Quadtree<T>::leaf()
{
	return child[0] == NULL && child[1] == NULL && child[2] == NULL && child[3] == NULL;
}