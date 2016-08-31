#ifndef QUADTREE_H
#define QUADTREE_H
#include <vector>
/*
 * A generic Quadtree class. This will perform spatial partitioning on a vector of objects, 
 * allowing for faster collision detection. Each instance of this class represents a node 
 * of a quadtree, since nodes are quadtrees themselves.
 */
template <typename T>
class Quadtree
{
public:
	Quadtree(int level, double px, double py, double width, double height);
	~Quadtree();
	void update();
	void collisions();
	void add(T* ent);
	void partition();
	void cleanup();
protected:
	void split();
	void clear();
	bool contains(T* ent);
	bool leaf();
	// The maximum number of "levels", i.e. the amount of times the quadtree may split.
	static const int MAX_LEVEL = 5;
	// The maximum number of objects before the quadtree will split.
	static const int MAX_OBJECTS = 50;
	// The current level of this particular quadtree node. The root is at level 0.
	int level;
	// The position of this node. The root should have a position of 0, 0.
	double position_x;
	double position_y;
	// The size of this node. The root should have a size equal to that of the window.
	double width;
	double height;
	// Object vector. Pointers are necessary to prevent entity duplication across children.
	std::vector<T*> objects;
	// Pointers to the children of this node.
	Quadtree<T>* child[4];
};
#endif
