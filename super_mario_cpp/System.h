#pragma once
class EntityManager;

class System
{

protected:
	EntityManager *GetEntityManager();

public:
	System();
	void SetEntityManager(EntityManager *entityManager);
	void SetSystemIndex(int index);
	int GetSystemIndex();
	virtual void update() = 0;

private:
	int mSystemIndex;
	EntityManager *mEntityManager;
};



