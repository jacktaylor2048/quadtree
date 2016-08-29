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
template <typename T>
void Quadtree<T>::collisions()
{

}
template <typename T>
void Quadtree<T>::add()
{

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
template <typename T>
bool Quadtree<T>::contains()
{

}
template <typename T>
bool Quadtree<T>::leaf()
{

}