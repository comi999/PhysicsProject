#pragma once
#include "Rigidbody.h"

class Sphere : public Rigidbody
{
public:
	Sphere(glm::vec2 a_Position, glm::vec2 a_Velocity, float a_Mass, float a_Radius, glm::vec4 a_Color);
	~Sphere();

	void MakeGizmo();
	bool CheckCollision(PhysicsObject* a_PhysicsOther);

	float GetRadius() { return m_Radius; }
	glm::vec4 GetColor() { return m_Color; }

protected:
	float m_Radius;
	glm::vec4 m_Color;
};

