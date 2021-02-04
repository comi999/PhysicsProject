#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Rigidbody.h"

#include <iostream>
#include <list>

PhysicsScene::PhysicsScene() : m_TimeStep(0.01f), m_Gravity(glm::vec2(0, 0))
{

}

PhysicsScene::~PhysicsScene()
{
	for (auto physicsActor : m_Actors)
	{
		delete physicsActor;
	}
}

void PhysicsScene::AddActor(PhysicsObject* a_Actor)
{
	m_Actors.push_back(a_Actor);
}

void PhysicsScene::RemoveActor(PhysicsObject* a_Actor)
{
	auto it = std::find(m_Actors.begin(), m_Actors.end(), a_Actor);
	if (it != m_Actors.end())
		m_Actors.erase(it);
}

void PhysicsScene::Update(float a_DeltaTime)
{
	static std::list<PhysicsObject*> dirty; // MUST REMOVE
	static float accumulatedTime = 0.0f;
	accumulatedTime += a_DeltaTime;

	while (accumulatedTime >= m_TimeStep)
	{
		for (auto pActor : m_Actors)
		{
			pActor->FixedUpdate(m_Gravity, m_TimeStep);
		}
		accumulatedTime -= m_TimeStep;
	}

	for (auto physicsActor : m_Actors)
	{
		for (auto physicsOther : m_Actors)
		{
			if (physicsActor == physicsOther)
			{
				continue;
			}
			if (std::find(dirty.begin(), dirty.end(), physicsActor) != dirty.end() &&
				std::find(dirty.begin(), dirty.end(), physicsOther) != dirty.end())
			{
				continue;
			}

			Rigidbody* physicsRigid = dynamic_cast<Rigidbody*>(physicsActor);

			if (physicsRigid->CheckCollision(physicsOther) == true)
			{
				physicsRigid->ApplyForceToOther(dynamic_cast<Rigidbody*>(physicsOther), physicsRigid->GetVelocity() * physicsRigid->GetMass());
				dirty.push_back(physicsRigid);
				dirty.push_back(physicsOther);
			}
		}

		dirty.clear();
	}
}

void PhysicsScene::Draw()
{
	for (auto pActor : m_Actors)
	{
		pActor->MakeGizmo();
	}
}

void PhysicsScene::DebugScene()
{
	int count = 0;
	for (auto physicsActor : m_Actors)
	{
		std::cout << count << " : ";
		physicsActor->Debug();
		count++;
	}
}
