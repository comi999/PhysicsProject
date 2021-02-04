#pragma once
#include "PhysicsObject.h"

class Rigidbody : public PhysicsObject
{
public:
	Rigidbody(ShapeType a_ShapeID, glm::vec2 a_Position, glm::vec2 a_Velocity, float a_Rotation, float a_Mass);
	~Rigidbody();

	virtual void FixedUpdate(glm::vec2 a_Gravity, float a_TimeStep);
	virtual void Debug() {};
	void ApplyForce(glm::vec2 a_Force);
	void ApplyForceToOther(Rigidbody* a_OtherActor, glm::vec2 a_Force);

	virtual bool CheckCollision(PhysicsObject* a_PhysicsOther) = 0;

	glm::vec2 GetPosition() { return m_Position; }
	glm::vec2 GetVelocity() { return m_Velocity; }
	float GetMass() { return m_Mass; }
	float GetRotation() { return m_Rotation; }

protected:
	glm::vec2 m_Position;
	glm::vec2 m_Velocity;

	float m_Mass;
	float m_Rotation;
};

