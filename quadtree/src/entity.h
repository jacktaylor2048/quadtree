#ifndef ENTITY_H
#define ENTITY_H
/*
 * Base class for entities which may be used for the quadtree. The quadtree's objects must have 
 * the attributes and methods necessary for collision detection, as defined below.
 */
class Entity
{
public:
	Entity();
	Entity(double px, double py, double bx, double by);
	Entity(double px, double py, double bx, double by, double ox, double oy);
	bool check_collision(Entity* ent);
	virtual void collide(Entity* ent);
	double get_position_x();
	double get_position_y();
	double get_boundary_x();
	double get_boundary_y();
	double get_offset_x();
	double get_offset_y();
protected:
	// The entity's position in the window.
	double position_x;
	double position_y;
	// The size of the entity's hitbox.
	double boundary_x;
	double boundary_y;
	// The distance of the hitbox from the entity's defined position.
	double offset_x;
	double offset_y;
};
#endif
