#pragma once
#include "GameObject.h"

namespace dae
{
	class Component
	{
	public:
		virtual ~Component() = default;
		
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;
		
		virtual void Update() = 0;
		virtual void Render() const = 0;
		
		bool GetCanBeRemoved();

		friend class GameObject;
	protected:
		explicit Component(GameObject* pOwner) : m_pOwner{ pOwner } {}
		GameObject* GetOwner() const;
		void SetCanBeRemoved(bool value);
		GameObject* m_pOwner{}; 
		bool m_MarkedForDeletion{};
		bool m_CanBeRemoved{};
	};
}