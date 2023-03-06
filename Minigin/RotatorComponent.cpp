#include "RotatorComponent.h"

dae::RotatorComponent::RotatorComponent(GameObject* gameobject)
	: Component(gameobject)
{
}

void dae::RotatorComponent::Update()
{
	//m_TransformComponent->AddLocalRotation(50.f * TIME.GetDeltaTime());
}

void dae::RotatorComponent::Render() const
{
}