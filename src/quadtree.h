#ifndef QUADTREE_H
#define QUADTREE_H
#include <vector>
/*
 * A generic Quadtree class. This will perform spatial partitioning on a vector of objects, 
 * allowing for faster collision detection.
 */
class Quadtree
{
public:
	Quadtree(int level, float position_x, float position_y, int width, int height);
	~Quadtree();
	void update();
	void collisions();
	void add();
	void partition();
	void cleanup();
protected:
	void split();
	void clear();
	bool contains();
	bool leaf();
	static const int MAX_LEVEL = 5;
	unsigned int max_objects;
	int level;
	float position_x;
	float position_y;
	int width;
	int height;
	// int is a placeholder; this will be changed to a generic type
	std::vector<int> objects;
	Quadtree* child[4];
};
#endif