#include "quadtree.h"
// Constructor
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
Quadtree::~Quadtree()
{

}
void Quadtree::update()
{

}
void Quadtree::collisions()
{

}
void Quadtree::add()
{

}
void Quadtree::partition()
{

}
void Quadtree::cleanup()
{

}
void Quadtree::split()
{

}
void Quadtree::clear()
{

}
bool Quadtree::contains()
{

}
bool Quadtree::leaf()
{

}