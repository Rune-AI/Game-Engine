#pragma once
#include <memory>
#include "Component.h"

namespace dae
{
	class Texture2D;
	class Transform;
	
	class TextureRenderComponent final : public Component
	{
	public:
		TextureRenderComponent() = default;
		TextureRenderComponent(GameObject* object);
		TextureRenderComponent(GameObject* object, const std::string& textureFile);

		~TextureRenderComponent() override = default;
		
		TextureRenderComponent(const TextureRenderComponent& other) = delete;
		TextureRenderComponent(TextureRenderComponent&& other) = delete;
		TextureRenderComponent& operator=(const TextureRenderComponent& other) = delete;
		TextureRenderComponent& operator=(TextureRenderComponent&& other) = delete;

		void Update() override;
		void Render() const override;
		void SetTexture(const std::string& filename);

	private:
		std::shared_ptr<Texture2D> m_pTexture{};
	};
}

