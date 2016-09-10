#include <iostream>
#include "example_entity.h"
#include "example_quadtree.h"

const int SCREEN_W = 512;
const int SCREEN_H = 512;

// Example subclass of ExampleEntity.
class Square : public ExampleEntity
{
public:
	Square(double px, double py, double bx, double by) : ExampleEntity(px, py, bx, by)
	{

	}
};

// Main Function - initialises a quadtree and updates it.
int main()
{
	ExampleQuadtree<Square> square_tree = ExampleQuadtree<Square>(0, 0, 0, SCREEN_W, SCREEN_H);
	/* 
	 * This adds 120 Squares to the quadtree. The positioning will cause the quadtree to split, then cause the
	 * upper left quadrant to split again.
	 */
	for (int i = 0; i < 30; i++) for (int j = 0; j < 4; j++) square_tree.add(new Square(4 + i * 12, 4 + j * 12, 4, 4));
	square_tree.update();
	std::cin.get();
	return 0;
}
