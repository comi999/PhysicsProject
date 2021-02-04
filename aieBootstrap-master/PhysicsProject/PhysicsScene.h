#pragma once
#include "glm/glm.hpp"	
#include <vector>

class PhysicsObject;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void AddActor(PhysicsObject* a_Actor);
	void RemoveActor(PhysicsObject* a_Actor);

	// This will call the update of each PhysicsObject and updates internally. This will handle
	// collision detection and resolution;
	void Update(float a_DeltaTime);

	// Called once per frame and handles the rendering of PhysicsObjects
	// Will add to a loop of Gizmo objects to render.
	void Draw();
	void DebugScene();

	void SetGravity(const glm::vec2 a_Gravity) { m_Gravity = a_Gravity; }
	glm::vec2 GetGravity() const { return m_Gravity; }

	void SetTimeStep(const float a_TimeStep) { m_TimeStep = a_TimeStep; }
	float GetTimeStep() { return m_TimeStep; }

protected:
	glm::vec2 m_Gravity;
	float m_TimeStep;

	std::vector<PhysicsObject*> m_Actors;

};

