#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>

/*
* A template Quadtree class. This will perform spatial partitioning on a vector of objects,
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
	void add(T* obj);
protected:
	void partition();
	virtual void split();
	virtual bool contains(T* obj);
	virtual void collisions();
	void clear();
	void cleanup();
	bool leaf();
	/*
	 * MAX_LEVEL: The maximum number of "levels", i.e. the amount of times the quadtree may split.
	 * MAX_OBJECTS: The maximum number of objects before the quadtree will split.
	 * RESERVED_OBJECTS: The number of objects to reserve in the vector
	 */
	static const int MAX_LEVEL = 5;
	static const int MAX_OBJECTS = 50;
	static const int RESERVED_OBJECTS = 4096;
	// The current level of this particular quadtree node. The root is at level 0.
	int level;
	// The position of this node. The root should have a position of 0, 0.
	double position_x;
	double position_y;
	// The size of this node. The root should have a size equal to that of the window.
	double width;
	double height;
	std::vector<T*> objects;
	Quadtree<T>* child[4];
};

// Constructor
template <typename T>
Quadtree<T>::Quadtree(int level, double px, double py, double width, double height) : level(level), position_x(px), position_y(py), width(width), height(height)
{
	if (level > MAX_LEVEL) Quadtree::level = MAX_LEVEL;
	for (int i = 0; i < 4; i++) child[i] = NULL;
	objects.reserve(RESERVED_OBJECTS);
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
	for (T* i : objects) i->update();
	clear();
}

// Add an object to the vector.
template <typename T>
void Quadtree<T>::add(T* obj)
{
	objects.push_back(obj);
}

// Recursive function to assign entities to their appropriate nodes.
template <typename T>
void Quadtree<T>::partition()
{
	if (objects.size() > MAX_OBJECTS && level < MAX_LEVEL) split();
	if (!leaf())
	{
		for (T* i : objects) for (int x = 0; x < 4; x++) if (child[x]->contains(i)) child[x]->add(i);
		for (int i = 0; i < 4; i++) child[i]->partition();
	}
}

// Create four equally sized child nodes.
template <typename T>
void Quadtree<T>::split()
{
	child[0] = new Quadtree<T>(level + 1, position_x, position_y, width * 0.5, height * 0.5);
	child[1] = new Quadtree<T>(level + 1, position_x + width * 0.5, position_y, width * 0.5, height * 0.5);
	child[2] = new Quadtree<T>(level + 1, position_x, position_y + height * 0.5, width * 0.5, height * 0.5);
	child[3] = new Quadtree<T>(level + 1, position_x + width * 0.5, position_y + height * 0.5, width * 0.5, height * 0.5);
}

// Check whether this node contains the specified object.
template <typename T>
bool Quadtree<T>::contains(T* obj)
{
	return false;
}

// Perform collision detection on all objects in this node.
template <typename T>
void Quadtree<T>::collisions()
{
	
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

// Clear the whole quadtree.
template <typename T>
void Quadtree<T>::cleanup()
{
	for (std::vector<T*>::iterator i = objects.begin(); i != objects.end();)
	{
		delete (*i);
		i = objects.erase(i);
	}
	clear();
}

// Check whether this is a leaf node (i.e. it has no children).
template <typename T>
bool Quadtree<T>::leaf()
{
	return child[0] == NULL && child[1] == NULL && child[2] == NULL && child[3] == NULL;
}

#endif
