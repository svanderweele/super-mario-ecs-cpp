#include "System.h"

EntityManager *System::GetEntityManager()
{
	return mEntityManager;
}

System::System() {
	mSystemIndex = -1;
}

void System::SetEntityManager(EntityManager *entityManager)
{
	mEntityManager = entityManager;
}

int System::GetSystemIndex() {
	return mSystemIndex;
}

void System::SetSystemIndex(int value) {
	mSystemIndex = value;
}

