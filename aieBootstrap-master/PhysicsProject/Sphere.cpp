#include "Sphere.h"
#include <Gizmos.h>

Sphere::Sphere(glm::vec2 a_Position, glm::vec2 a_Velocity, float a_Mass, float a_Radius, glm::vec4 a_Color) : Rigidbody(SPHERE, a_Position, a_Velocity, 0, a_Mass)
{
    m_Radius = a_Radius;
    m_Color = a_Color;
}

Sphere::~Sphere()
{
}

void Sphere::MakeGizmo()
{
    aie::Gizmos::add2DCircle(m_Position, m_Radius, 12, m_Color);
}

bool Sphere::CheckCollision(PhysicsObject* a_PhysicsOther)
{
    Sphere* physicsSphere = dynamic_cast<Sphere*>(a_PhysicsOther);
    
    if (physicsSphere != nullptr)
    {
        float distance = glm::distance(GetPosition(), physicsSphere->GetPosition());

        if (GetRadius() + physicsSphere->GetRadius() > distance)
        {
            return true;
        }
    }

    return false;
}
