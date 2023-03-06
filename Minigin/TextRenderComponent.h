#pragma once
#include <string>
#include <memory>
#include "Component.h"


namespace dae
{
	class Font;
	class Texture2D;
	class TextRenderComponent final : public Component
	{
	public:
		TextRenderComponent(GameObject* object);
		TextRenderComponent(GameObject* object, const std::string& text, std::shared_ptr<Font> font);
		TextRenderComponent(GameObject* object, const std::string& text);
		
		virtual ~TextRenderComponent() = default;
		TextRenderComponent(const TextRenderComponent& other) = delete;
		TextRenderComponent(TextRenderComponent&& other) = delete;
		TextRenderComponent& operator=(const TextRenderComponent& other) = delete;
		TextRenderComponent& operator=(TextRenderComponent&& other) = delete;


		void Update() override;
		void Render() const override;

		void SetText(const std::string& text);

	private:
		bool m_needsUpdate{};
		std::string m_text;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
