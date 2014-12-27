#pragma once

/////////////////////////////////////////////////////////////////////////////
//Coder: Rye Nguyen
//Quadtree algorithm
//Purpose: push each entity into a region to detect collision effeciently

using namespace stdio_fw;

#include <list>

#define MAX_LEVEL				5
#define	MAX_OBJECTS_IN_REGION	3

class Entity;

struct Quadtree
{
	int					m_level;
	Rect				m_region;

	//List of entities in a region
	//If region devide into 4 sub-region
	//Entity List must be clear and turn into respectively sub-region
	std::list<Entity*>	m_entity_list;


	//Sub-region
	//Init when Entity List have more entities than MAX_OBJECTS_IN_REGION
	Quadtree**			m_nodes;

	Quadtree(int level, Rect region);


	//Clear Quadtree
	void				Clear();



	//Insert an entity into respectively region
	//Split to 4 sub-region if needed
	void				Insert(Entity* entity);



	//Get all entity that can collide with entity
	std::list<Entity*>*	Retrieve(std::list<Entity*>* return_objects_list, Entity* entity);



	//Check to find the suitable region for entity
	bool				IsContain(Entity* entity);



	//Split into 4 sub-region
	//
	void				Split();
};

/////////////////////////////////////////////////////////////////////////////