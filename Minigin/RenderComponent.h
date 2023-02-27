#pragma once
#include <memory>
#include "Component.h"

namespace dae
{
	class Texture2D;
	class Transform;
	
	class RenderComponent final : public Component
	{
	public:
		~RenderComponent() override = default;
		void Update(GameObject& go) override;
		void Render(const GameObject& go) const override;
		void SetTexture(const std::string& filename);

	private:
		std::shared_ptr<Texture2D> m_texture{};
	};
}

