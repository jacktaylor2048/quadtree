#ifndef QUADTREE_H
#define QUADTREE_H
#include <vector>
/*
 * A generic Quadtree class. This will perform spatial partitioning on a vector of objects, 
 * allowing for faster collision detection. Each instance of this class represents a node 
 * of a quadtree, since nodes are quadtrees themselves.
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
	// The maximum number of "levels", i.e. the amount of times the quadtree may split.
	static const int MAX_LEVEL = 5;
	// The maximum number of objects before the quadtree will split.
	unsigned int max_objects;
	// The current level of this particular quadtree node. The root is at level 0.
	int level;
	// The position of this node. The root should have a position of 0, 0.
	float position_x;
	float position_y;
	// The size of this node. The root should have a size equal to that of the window.
	int width;
	int height;
	// int is a placeholder; this will be changed to a generic type
	std::vector<int> objects;
	// Pointers to the children of this node.
	Quadtree* child[4];
};
#endif