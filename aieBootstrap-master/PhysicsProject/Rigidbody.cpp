#include "Rigidbody.h"

Rigidbody::Rigidbody(ShapeType a_ShapeID, glm::vec2 a_Position, glm::vec2 a_Velocity, float a_Rotation, float a_Mass) : PhysicsObject(a_ShapeID)
{
	m_Position = a_Position;
	m_Velocity = a_Velocity;
	m_Mass = a_Mass;
	m_Rotation = a_Rotation;
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::FixedUpdate(glm::vec2 a_Gravity, float a_TimeStep)
{
	ApplyForce(a_Gravity * GetMass() * a_TimeStep);
	m_Position += GetVelocity() * a_TimeStep;
}

void Rigidbody::ApplyForce(glm::vec2 a_Force)
{
	m_Velocity += a_Force / GetMass();
}

void Rigidbody::ApplyForceToOther(Rigidbody* a_OtherActor, glm::vec2 a_Force)
{
	ApplyForce(-a_Force);
	a_OtherActor->ApplyForce(a_Force);
}
