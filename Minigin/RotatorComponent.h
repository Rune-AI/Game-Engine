#pragma once
#include "Component.h"
#include "TransformComponent.h"

namespace dae
{
	class RotatorComponent final : public Component
	{
	public:
		RotatorComponent(GameObject* gameobject);

		void Update() override;
		void Render() const override;
	private:
		//TransformComponent* m_TransformComponent{};
	};
}
