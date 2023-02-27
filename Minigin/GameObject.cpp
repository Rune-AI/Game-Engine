#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update()
{
	for (const auto& component : m_pComponents)
	{
		component->Update(*this);
	}
}

void dae::GameObject::Render() const
{
	for (const auto& component : m_pComponents)
	{
		component->Render(*this);
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(std::shared_ptr<Component> component)
{
	m_pComponents.push_back(component);
}

void dae::GameObject::RemoveComponent(std::shared_ptr<Component> component)
{
	for (size_t i{}; i < m_pComponents.size(); ++i)
	{
		if (m_pComponents[i] == component)
		{
			m_pComponents.erase(m_pComponents.begin() + i);
			return;
		}
	}
}

std::shared_ptr<dae::Component> dae::GameObject::GetComponent(const std::string& name) const
{
	// This definitly needs to be improved
	// unhappy with current implementation
	
	for (const auto& component : m_pComponents)
	{
		if (component->GetName() == name)
		{
			return component;
		}
	}
	return nullptr;
}

bool dae::GameObject::HasComponent(const std::string& name) const
{
	// This definitly needs to be improved
	// unhappy with current implementation
	
	for (const auto& component : m_pComponents)
	{
		if (component->GetName() == name)
		{
			return true;
		}
	}
	return false;
}
