#include "EntityManager.h"
#include "Main.h"
#include <vector>
#include "Entity.h"
#include "Component.h"
#include "System.h"

const int MAX_COMPONENTS_PER_TYPE = 5;


EntityManager::EntityManager() {
	mComponents.resize((COMPONENT_ID_TOTALCOMPONENTS+1) * MAX_COMPONENTS_PER_TYPE);
}


Entity *EntityManager::CreateEntity() {
	Entity *e = new Entity(Main::EntityIndex);
	Main::EntityIndex++;
	mEntities.push_back(e);
	return e;
}

Entity *EntityManager::GetEntityWithId(int Id) {
	for (Entity *e : mEntities) {
		if (e->GetId() == Id) {
			return e;
		}
	}

	return nullptr;
}


bool EntityManager::DestroyAllEntities() {
	for (Entity *e : mEntities) {
		DestroyEntity(e);
	}

	return true;
}

void EntityManager::DestroyEntity(Entity *entity) {
	mEntities.erase(mEntities.begin() + entity->GetId());
	delete entity;
	entity = nullptr;
}

Component *EntityManager::AddComponentToEntity(Entity *entity, Component *component) {
	if (entity == NULL) {
		printf("Entity is null!");
		return nullptr;
	}

	int startIndex = GetComponentIndexById(component->GetComponentId());

	printf("Added Component! %u = %u\n",startIndex + entity->GetId());
	mComponents[startIndex + entity->GetId()] = component;
	return component;
}

bool EntityManager::RemoveComponentFromEntity(Entity *entity, Component *component) {
	if (entity == NULL) {
		printf("Entity is null!");
		return false;
	}

	int startIndex = GetComponentIndexById(component->GetComponentId());
	mComponents[startIndex + entity->GetId()] = nullptr;
	return true;
}


Component *EntityManager::GetComponentFromEntity(Entity *entity, EComponentId componentId) {
	if (entity == NULL) {
		printf("Entity is null!");
		return false;
	}


	int startIndex = GetComponentIndexById(componentId);
	return mComponents[startIndex + entity->GetId()];
}

std::vector<Entity *> EntityManager::GetEntitiesWithComponents(std::initializer_list<EComponentId> componentIds) {

	std::vector<Entity *> entities = std::vector<Entity *>();
	for (Entity *entity : mEntities) {
		bool isEntityHaveAllComponents = true;
		for (EComponentId componentId : componentIds) {
			if (GetComponentFromEntity(entity, componentId) == false) {
				isEntityHaveAllComponents = false;
			}
		}
		if (isEntityHaveAllComponents) {
			entities.push_back(entity);
		}
	}

	return entities;
}

int EntityManager::GetComponentIndexById(EComponentId componentId)
{
	return (int)componentId * MAX_COMPONENTS_PER_TYPE;
}

void EntityManager::RegisterSystem(System *system) {
	if (system && system->GetSystemIndex() == -1) {
		mSystems.push_back(system);
		system->SetSystemIndex(mSystems.size() - 1);
		system->SetEntityManager(this);
	}
}

void EntityManager::UnRegisterSystem(System *system) {
	if (system && system->GetSystemIndex() != -1 && system->GetSystemIndex() < mSystems.size()) {
		mSystems.erase(mSystems.begin() + system->GetSystemIndex());
		system->SetSystemIndex(-1);
		system->SetEntityManager(nullptr);
	}
}

void EntityManager::UpdateSystems() {
	for (System *system : mSystems) {
		if (system) {
			system->update();
		}
	}
}