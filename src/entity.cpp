#include "entity.h"
// Default Constructor
Entity::Entity()
{
	position_x = 0;
	position_y = 0;
	boundary_x = 0;
	boundary_y = 0;
	offset_x = 0;
	offset_y = 0;
}
// Basic Constructor (excludes offsets)
Entity::Entity(float px, float py, float bx, float by)
{
	position_x = px;
	position_y = py;
	boundary_x = bx;
	boundary_y = by;
	offset_x = 0;
	offset_y = 0;
}
// Full Constructor (includes offsets)
Entity::Entity(float px, float py, float bx, float by, float ox, float oy)
{
	position_x = px;
	position_y = py;
	boundary_x = bx;
	boundary_y = by;
	offset_x = ox;
	offset_y = oy;
}