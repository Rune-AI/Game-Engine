#pragma once
#include <memory>
#include <vector>
#include <string>
#include "TransformComponent.h"

namespace dae
{
	class Component;

	class GameObject final
	{
	public:
		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		
		virtual void Update();
		virtual void Render() const;

		template<typename T>
		T* GetComponent();

		template<typename T>
		void RemoveComponent();

		template<typename T>
		void AddComponent();

		template<typename T, typename...Args>
		void AddComponent(Args&&... args);

		template<typename T>
		void HasComponent();
		
		void AddChild(GameObject* pChild);
		void RemoveChild(GameObject* pChild);
		void SetParent(GameObject* parent, bool keepWorldTransform);
		GameObject* GetParent();
		const std::vector<GameObject*>& GetChildren() const;

		//TransformComponent* GetTransform() const { return m_TransformComponent; }

	private:
		//TransformComponent* m_TransformComponent;
		std::vector<std::unique_ptr<Component>> m_pComponents;

		GameObject* m_pParent;
		std::vector<GameObject*> m_pChildren;
		
		bool m_IsDirty{};
	};
}
