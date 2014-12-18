#include "stdafx.h"
#include "Quadtree.h"

/////////////////////////////////////////////////////////////////////////////
//Coder: Rye Nguyen
//Quadtree algorithm
//Purpose: push each entity into a region to detect collision effeciently

Quadtree::Quadtree(int level, Rect region)
{
	m_level = level;
	m_region = region;
}

void Quadtree::Clear()
{
	//Clear all nodes
	if(m_nodes)
	{
		for(int i = 0; i < 4; i++)
		{
			m_nodes[i]->Clear();
			delete m_nodes[i];
		}
		SAFE_DEL(m_nodes);
	}

	//Clear current quadtree
	m_entity_list.clear();
}

void Quadtree::Insert(Entity* entity)
{
	//Insert entity into corresponding nodes
	if(m_nodes)
	{
		if(m_nodes[0]->IsContain(entity))
			m_nodes[0]->Insert(entity);
		if(m_nodes[1]->IsContain(entity))
			m_nodes[1]->Insert(entity);
		if(m_nodes[2]->IsContain(entity))
			m_nodes[2]->Insert(entity);
		if(m_nodes[3]->IsContain(entity))
			m_nodes[3]->Insert(entity);
	}

	//Insert entity into current quadtree
	if(this->IsContain(entity))
		m_entity_list.push_back(entity);

	//Split and move all objects in list into it’s corresponding nodes
	if(m_entity_list.size() > MAX_OBJECTS_IN_REGION && m_level < MAX_LEVEL)
	{
		Split();

		while(!m_entity_list.empty())
		{
			if(m_nodes[0]->IsContain(m_entity_list.back()))
				m_nodes[0]->Insert(m_entity_list.back());
			if(m_nodes[1]->IsContain(m_entity_list.back()))
				m_nodes[1]->Insert(m_entity_list.back());
			if(m_nodes[2]->IsContain(m_entity_list.back()))
				m_nodes[2]->Insert(m_entity_list.back());
			if(m_nodes[3]->IsContain(m_entity_list.back()))
				m_nodes[3]->Insert(m_entity_list.back());

			m_entity_list.pop_back();
		}
	}
}

std::list<Entity*>* Quadtree::Retrieve(std::list<Entity*>* return_objects_list, Entity* entity)
{
	if(m_nodes != NULL)
	{
		if(m_nodes[0]->IsContain(entity))
			m_nodes[0]->Retrieve(return_objects_list, entity);
		if(m_nodes[1]->IsContain(entity))
			m_nodes[1]->Retrieve(return_objects_list, entity);
		if(m_nodes[2]->IsContain(entity))
			m_nodes[2]->Retrieve(return_objects_list, entity);
		if(m_nodes[3]->IsContain(entity))
			m_nodes[3]->Retrieve(return_objects_list, entity);
	}

	//Add all entities in current region into return_objects_list
	if(this->IsContain(entity))
	{
		for(std::list<Entity*>::iterator i = m_entity_list.begin(); i != m_entity_list.end(); i++)
		{
			if(entity != i._Ptr->_Myval)
				return_objects_list->push_back(i._Ptr->_Myval);
		}
	}

	return return_objects_list;
}

bool Quadtree::IsContain(Entity* entity)
{
	/*Rect bound = entity->GetBoundingBox();

	return !( bound.x + bound.width < m_region.x ||
		bound.y + bound.height < m_region.y ||
		bound.x > m_region.x + m_region.width ||
		bound.y > m_region.y + m_region.height );*/

	return false;
}

void Quadtree::Split()
{
	m_nodes = new Quadtree*[4];

	m_nodes[0] = new Quadtree(m_level + 1, Rect(m_region.x, m_region.y, m_region.width / 2, m_region.height / 2));
	m_nodes[1] = new Quadtree(m_level + 1, Rect(m_region.x + m_region.width / 2, m_region.y, m_region.width / 2, m_region.height / 2));
	m_nodes[2] = new Quadtree(m_level + 1, Rect(m_region.x, m_region.y + m_region.height / 2, m_region.width / 2, m_region.height / 2));
	m_nodes[3] = new Quadtree(m_level + 1, Rect(m_region.x + m_region.width / 2, m_region.y + m_region.height / 2, m_region.width / 2, m_region.height / 2));
}

/////////////////////////////////////////////////////////////////////////////