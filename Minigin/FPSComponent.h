#pragma once
#include "Component.h"

namespace dae
{
	class TextRenderComponent;
	
	class FPSComponent final : public Component
	{
	public:
		FPSComponent(GameObject* object);
		virtual ~FPSComponent() override;
		
		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;
		
		void Update() override;
		void Render() const override;
	private:
		int m_FPS;
		TextRenderComponent* m_TextRenderComponent;
	};
}