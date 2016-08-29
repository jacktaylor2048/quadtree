#include "entity.h"
// Default Constructor
Entity::Entity() : position_x(0), position_y(0), boundary_x(0), boundary_y(0), offset_x(0), offset_y(0)
{
	
}
// Basic Constructor (excludes offsets)
Entity::Entity(float px, float py, float bx, float by) : position_x(px), position_y(py), boundary_x(bx), boundary_y(by), offset_x(0), offset_y(0)
{
	
}
// Full Constructor (includes offsets)
Entity::Entity(float px, float py, float bx, float by, float ox, float oy) : position_x(px), position_y(py), boundary_x(bx), boundary_y(by), offset_x(ox), offset_y(oy)
{
	
}
// Return true if this entity is colliding with other entity
bool Entity::check_collision(Entity* ent)
{
	return position_x + boundary_x + offset_x > ent->get_position_x() + ent->get_offset_x()
		&& position_x + offset_x < ent->get_position_x() + ent->get_boundary_x() + ent->get_offset_x()
		&& position_y + boundary_y + offset_y > ent->get_position_y() + ent->get_offset_y()
		&& position_y + offset_y < ent->get_position_y() + ent->get_boundary_y() + ent->get_offset_y();
}
// Virtual method; inherited classes would define collision behaviour here.
void Entity::collide(Entity* ent)
{

}
float Entity::get_position_x()
{
	return position_x;
}
float Entity::get_position_y()
{
	return position_y;
}
float Entity::get_boundary_x()
{
	return boundary_x;
}
float Entity::get_boundary_y()
{
	return boundary_y;
}
float Entity::get_offset_x()
{
	return offset_x;
}
float Entity::get_offset_y()
{
	return offset_y;
}