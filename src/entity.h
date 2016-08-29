#ifndef ENTITY_H
#define ENTITY_H
/*
 * Base class for entities which may be used for the quadtree. The quadtree's objects must have 
 * the attributes and methods necessary for collision detection.
 */
class Entity
{
public:
	Entity();
	Entity(float px, float py, float bx, float by);
	Entity(float px, float py, float bx, float by, float ox, float oy);
protected:
	// The entity's position in the window.
	float position_x;
	float position_y;
	// The size of the entity's hitbox.
	float boundary_x;
	float boundary_y;
	// The distance of the hitbox from the entity's defined position.
	float offset_x;
	float offset_y;
};
#endif