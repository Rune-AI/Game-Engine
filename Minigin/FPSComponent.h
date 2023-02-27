#pragma once
#include "Component.h"

namespace dae
{
	class TextObject;
	
	class FPSComponent final : public Component
	{
	public:
		FPSComponent(std::shared_ptr<TextObject> to);
		~FPSComponent() override;
		void Update(GameObject& go) override;
		void Render(const GameObject& go) const override;
	private:
		int m_FPS;
		std::shared_ptr<TextObject> m_TextObject;
	};
}