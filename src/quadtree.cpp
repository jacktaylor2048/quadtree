#include "quadtree.h"
// Constructor
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
Quadtree::Quadtree(int level, float position_x, float position_y, int width, int height)
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
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
Quadtree::~Quadtree()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
void Quadtree::update()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
void Quadtree::collisions()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
void Quadtree::add()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
void Quadtree::partition()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
void Quadtree::cleanup()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
void Quadtree::split()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
void Quadtree::clear()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
bool Quadtree::contains()
{

}
template <typename T, typename std::enable_if<std::is_base_of<Entity, T>::value>>
bool Quadtree::leaf()
{

}