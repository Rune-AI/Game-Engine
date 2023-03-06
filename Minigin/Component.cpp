#include "Component.h"

dae::GameObject* dae::Component::GetOwner() const
{
	return m_pOwner;
}

void dae::Component::SetCanBeRemoved(bool value)
{
	m_CanBeRemoved = value;
}

bool dae::Component::GetCanBeRemoved()
{
	return m_CanBeRemoved;
}
