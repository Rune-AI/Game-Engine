#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"

#include "TextRenderComponent.h"
#include "TextureRenderComponent.h"

#include "TransformComponent.h"
#include <glm/ext/vector_float2.hpp>


dae::GameObject::GameObject()
{
	/*AddComponent<TransformComponent>(glm::vec2{ 100,100 }, 0.f);
	m_TransformComponent = GetComponent<TransformComponent>();*/
}

dae::GameObject::~GameObject() = default;

using namespace dae;

void dae::GameObject::Update()
{
	for (const auto& component : m_pComponents)
	{
		component->Update();
	}
	// todo : add erase flag, indexes to erase and erase them in update to avoid unexpected behaviors
}

void dae::GameObject::Render() const
{
	for (const auto& component : m_pComponents)
	{
		component->Render();
	}
}

template TextRenderComponent* GameObject::GetComponent<TextRenderComponent>();
template<typename T>
inline T* dae::GameObject::GetComponent()
{
	for (const auto& component : m_pComponents)
	{
		T* pT = dynamic_cast<T*>(component.get());
		if (pT)
		{
			return pT;
		}
	}
	return nullptr;
}

template<typename T>
void dae::GameObject::RemoveComponent()
{
	for (auto it = m_pComponents.begin(); it != m_pComponents.end(); ++it)
	{
		T* pT = dynamic_cast<T*>((*it).get());
		if (pT)
		{
			m_pComponents.erase(it);
			return;
		}
	}
}

template <typename T, typename...Args>
void dae::GameObject::AddComponent(Args&&...args)
{
	static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");
	auto component = new T{ this, std::forward<Args>(args)... };
	m_pComponents.emplace_back(component);
}

template<typename T>
void dae::GameObject::AddComponent()
{
	static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");
	auto component = new T{ this };
	m_pComponents.emplace_back(component);
}

template<typename T>
void dae::GameObject::HasComponent()
{
	for (const auto& pComponent : m_pComponents)
	{
		if (dynamic_cast<T*>(pComponent.get()))
		{
			return true;
		}
	}

	return false;
}

void dae::GameObject::AddChild(GameObject* pChild)
{
	if (pChild)
	{
		// Remove child from current parent if it has one
		if (pChild->m_pParent)
		{
			pChild->m_pParent->RemoveChild(pChild);
		}

		// Add child to this object's children
		m_pChildren.emplace_back(pChild);
		pChild->m_pParent = this;
	}
}

void dae::GameObject::RemoveChild(GameObject* pChild)
{
	if (pChild)
	{
		// Find the child in this object's children and remove it
		/*auto it = std::find_if(m_pChildren.begin(), m_pChildren.end(),
			[pChild](const auto& pChildInList) { return pChildInList == pChild; });*/

		auto it = std::find(m_pChildren.begin(), m_pChildren.end(), pChild);

		if (it != m_pChildren.end())
		{
			(*it)->m_pParent = nullptr;
			m_pChildren.erase(it);
		}
	}
}

void dae::GameObject::SetParent(GameObject* parent, bool keepWorldTransform)
{
	if (parent == m_pParent)
	{
		return;
	}

	if (m_pParent)
	{
		m_pParent->RemoveChild(this);
	}

	if (parent)
	{
		parent->AddChild(this);

		if (keepWorldTransform)
		{

		}

		//if (keepWorldTransform)
		//{

		//	//SetLocalPosition(GetLocalPosition() - m_transform.GetWorldPosition());
		//	//SetPositionDirty();

		//	// Compute new world transform based on new parent's transform
		//	/*Transform parentTransform = parent->GetWorldTransform();
		//	Transform localTransform = m_transform;*/

		//	// Set new local transform
		//	//SetTransform(parentTransform.Inverse() * localTransform);
		//	//m_transform = parentTransform + localTransform;

		//	// Recompute world transform
		//	//m_transform = parentTransform * m_transform;
		//}
	}
	else
	{
		// No parent, so set world transform equal to local transform
		//m_transform = GetTransform();
	}
}

dae::GameObject* dae::GameObject::GetParent()
{
	return nullptr;
}

const std::vector<GameObject*>& dae::GameObject::GetChildren() const
{
	return m_pChildren;
}