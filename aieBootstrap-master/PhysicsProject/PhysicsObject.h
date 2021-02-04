#pragma once
#include "glm/glm.hpp"

// This is a pure abstract class. It will be used as a
// base for the derived classes that will use FixedUpdate

enum ShapeType
{
	PLANE = 0,
	SPHERE,
	BOX
};

class PhysicsObject
{
public:
	virtual void FixedUpdate(glm::vec2 a_Gravity, float a_TimeStep) = 0;
	virtual void Debug() = 0;
	virtual void MakeGizmo() = 0;
	virtual void ResetPosition();

protected:
	ShapeType m_ShapeID;
	PhysicsObject(ShapeType a_ShapeID) : m_ShapeID(a_ShapeID) {}
};

