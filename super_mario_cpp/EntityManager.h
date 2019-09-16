#pragma once
#include <vector>
#include "Component.h"
class Entity;
class Component;
class System;

class EntityManager
{

public:
	EntityManager();

	//Entities
	Entity *CreateEntity();
	Entity *GetEntityWithId(int id);
	bool DestroyAllEntities();
	void DestroyEntity(Entity *entity);

	//Components
	bool AddComponentToEntity(Entity *entity, Component *component);
	bool RemoveComponentFromEntity(Entity *entity, Component *component);
	Component *GetComponentFromEntity(Entity *entity, EComponentId componentId);
	std::vector<Entity *>GetEntitiesWithComponents(std::initializer_list<EComponentId> componentIds);

	//Systems
	void RegisterSystem(System *system);
	void UnRegisterSystem(System *system);
	void UpdateSystems();


private:
	std::vector<Entity *> mEntities;
	std::vector<Component *> mComponents;
	std::vector<System *> mSystems;
	int GetComponentIndexById(EComponentId componentId);

};

