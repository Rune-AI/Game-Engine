#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Transform.h"

namespace dae
{
	class Texture2D;
	class Component;

	class GameObject final
	{
	public:
		virtual void Update();
		virtual void Render() const;
		
		void SetPosition(float x, float y);

		void AddComponent(std::shared_ptr<Component> component);
		void RemoveComponent(std::shared_ptr<Component> component);
		std::shared_ptr<Component> GetComponent(const std::string& name) const;
		bool HasComponent(const std::string& name) const;
		
		Transform GetTransfrom()const { return m_transform; }
		

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		std::vector<std::shared_ptr<Component>> m_pComponents;
	};
}
