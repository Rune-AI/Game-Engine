#pragma once
#include <string>
#include <memory>
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextObject final : public Component
	{
	public:
		void Update(GameObject& go) override;
		void Render(const GameObject& go) const override;

		void SetText(const std::string& text);

		TextObject(const std::string& text, std::shared_ptr<Font> font);
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	private:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
