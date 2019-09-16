#include "Main.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Component.h"
#include "ApplyVelocityToPositionSystem.h"

int Main::EntityIndex = 0;
EntityManager entityManager;

void tryGetEntity(int id);


int main(int argc, char *argv[]) {
	entityManager = EntityManager();

	for (int i = 0; i < 5; i++) {
		Entity *e = entityManager.CreateEntity();
		printf("Entity Created with ID: %u \n", e->GetId());
	}

	tryGetEntity(5);

	Entity *entity = entityManager.GetEntityWithId(3);
	entityManager.AddComponentToEntity(entity, new TransformComponent(5, 3));
	entityManager.AddComponentToEntity(entity, new VelocityComponent(5, 3));

	TransformComponent *component = (TransformComponent *)entityManager.GetComponentFromEntity(entity, COMPONENT_ID_TRANSFORM);

	if (component) {
		std::cout << *component << std::endl;
	}

	std::vector<Entity *> entities = entityManager.GetEntitiesWithComponents({ COMPONENT_ID_TRANSFORM, COMPONENT_ID_VELOCITY });
	std::cout << "Entities with those components " << entities.size() << std::endl;

	entityManager.RegisterSystem(new ApplyVelocityToPositionSystem());

	while (true)
	{
		entityManager.UpdateSystems();
	}

	return 0;
}

void tryGetEntity(int id) {
	Entity *entity = entityManager.GetEntityWithId(id);
	if (entity == nullptr) {
		printf("Entity %u not found! \n", id);
	}
}