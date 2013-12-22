#include "precomp.h"
#include "Unit.h"


Unit::Unit(void) :
	hitPoints(0)	
{
	/*
	std::vector<CL_Contour> contourvector;
	
	CL_Contour c1;
	//CL_Contour *c2;
	contourvector.push_back(c1);
	contourvector.back().get_points().push_back(CL_Pointf(0.0f, 10.0f));
	contourvector.back().get_points().push_back(CL_Pointf(10.0f, 10.0f));
	contourvector.back().get_points().push_back(CL_Pointf(10.0f, 0.0f));
	contourvector.back().get_points().push_back(CL_Pointf(0.0f, 0.0f));

	CL_CollisionOutline outline(contourvector, 10, 10);
	*/
}

void Unit::Update(void){
	Entity::Update();
	if(hitPoints <= 0){
		Destroy();
	}
}

void Unit::TakeDamage(int damage){
	hitPoints -= damage;
}