#pragma once

#include "../4dm.h"
#include "../sdl/SDL_ttf.h"

namespace fdm::Core
{
	// A font renderer for .ttf/.otf fonts using the SDL2_ttf library (which is included in the game but only used in credits)
	class TTFRenderer
	{
	private:
		TexRenderer tr;

		stl::string text = "";
		glm::mat4 model{ 1 };
		int fontSize = 8;

		TTF_Font* font = nullptr;
		SDL_Surface* initial = nullptr;
		SDL_Surface* intermediary = nullptr;

		Tex2D tex;
		bool linearFiltering = true;

		int wrapLength = 0;
		int style = TTF_STYLE_NORMAL;
		int hinting = TTF_HINTING_NORMAL;
		int wrappedAlign = TTF_WRAPPED_ALIGN_LEFT;

		bool shouldUpdate = true;

	public:
		enum class StyleFlags : int
		{
			NORMAL = TTF_STYLE_NORMAL,
			BOLD = TTF_STYLE_BOLD,
			ITALIC = TTF_STYLE_ITALIC,
			UNDERLINE = TTF_STYLE_UNDERLINE,
			STRIKETHROUGH = TTF_STYLE_STRIKETHROUGH
		};
		enum class Hinting : int
		{
			NORMAL = TTF_HINTING_NORMAL,
			LIGHT = TTF_HINTING_LIGHT,
			MONO = TTF_HINTING_MONO,
			NONE = TTF_HINTING_NONE,
			LIGHT_SUBPIXEL = TTF_HINTING_LIGHT_SUBPIXEL
		};
		enum class WrappedAlign : int
		{
			LEFT = TTF_WRAPPED_ALIGN_LEFT,
			CENTER = TTF_WRAPPED_ALIGN_CENTER,
			RIGHT = TTF_WRAPPED_ALIGN_RIGHT
		};

		TTFRenderer()
		{
			tex.width = 1;
			tex.height = 1;
		}
		~TTFRenderer()
		{
			tex.~Tex2D();
			tr.~TexRenderer();
			tr.shader = nullptr;
			tr.texture = nullptr;
			if (initial)
			{
				SDL_FreeSurface(initial);
				initial = nullptr;
			}
			if (intermediary)
			{
				SDL_FreeSurface(intermediary);
				intermediary = nullptr;
			}
			if (font)
			{
				TTF_CloseFont(font);
				font = nullptr;
			}
		}

		void updateText()
		{
			if (!font) return;

			shouldUpdate = false;

			TTF_SetFontStyle(font, style);
			TTF_SetFontWrappedAlign(font, wrappedAlign);
			TTF_SetFontHinting(font, hinting);
			TTF_SetFontSize(font, fontSize);
			tex.~Tex2D();
			tex.ID = 0;
			tex.width = 1;
			tex.height = 1;

			if (!text.empty())
			{
				glGenTextures(1, &tex.ID);
				tex.use();

				initial = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), { 255,255,255,255 }, wrapLength);
				intermediary = SDL_CreateRGBSurface(0, initial->w, initial->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
				SDL_BlitSurface(initial, nullptr, intermediary, nullptr);

				tex.width = initial->w;
				tex.height = initial->h;
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, initial->w, initial->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, intermediary->pixels);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, linearFiltering ? GL_LINEAR : GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, linearFiltering ? GL_LINEAR : GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

				glBindTexture(GL_TEXTURE_2D, 0);

				SDL_FreeSurface(initial);
				SDL_FreeSurface(intermediary);
				initial = nullptr;
				intermediary = nullptr;
			}
		}

		void setText(const stl::string& text)
		{
			if (this->text == text) return;
			this->text = text;
			shouldUpdate = true;
			//updateText();
		}

		void setColor(const glm::vec4(&colors)[4])
		{
			tr.setColor(colors);
		}

		void setColor(const glm::vec4& color)
		{
			setColor(
				{
					color,
					color,
					color,
					color
				});
		}

		void setColor(float r, float g, float b, float a)
		{
			setColor(glm::vec4{ r,g,b,a });
		}

		void setModel(const glm::mat4& model)
		{
			this->model = model;

			glBindVertexArray(tr.VAO);

			glBindBuffer(GL_ARRAY_BUFFER, tr.buffers[TexRenderer::VBO_MODEL]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4), &model[0][0], GL_STATIC_DRAW);

			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void setPos(const glm::ivec2& pos, const glm::vec2& scale = glm::vec2{ 1 }, float angle = 0, const glm::vec2& origin = glm::vec2{ 0.5f })
		{
			model = glm::mat4{ 1 };

			model = glm::translate(model, { pos.x, pos.y, 0.0f });
			model = glm::rotate(model, glm::radians(angle), glm::vec3{ 0, 0, 1 });
			model = glm::scale(model, { scale.x * tex.width, scale.y * tex.height, 1.0f });
			model = glm::translate(model, glm::vec3{ -origin.x, -origin.y, 0 });

			setModel(model);
		}

		stl::string getText() const
		{
			return text;
		}

		glm::mat4 getModel() const
		{
			return model;
		}

		void setFontSize(int fontSize)
		{
			if (this->fontSize == fontSize) return;
			this->fontSize = fontSize;
			shouldUpdate = true;
			//updateText();
		}

		int getFontSize() const
		{
			return fontSize;
		}

		void getTextSize(const stl::string& text, int* width, int* height) const
		{
			if (font && !text.empty())
			{
				if (shouldUpdate)
				{
					TTF_SetFontStyle(font, style);
					TTF_SetFontWrappedAlign(font, wrappedAlign);
					TTF_SetFontHinting(font, hinting);
					TTF_SetFontSize(font, fontSize);
					SDL_Surface* initial = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), { 255,255,255,255 }, wrapLength);

					*width = initial->w;
					*height = initial->h;

					SDL_FreeSurface(initial);
					initial = nullptr;
				}
				else
				{
					*width = tex.width;
					*height = tex.height;
				}
				return;
			}
			*width = 1;
			*height = 1;
		}
		void getSize(int* width, int* height) const
		{
			getTextSize(text, width, height);
		}

		void setLinearFiltering(bool filter)
		{
			if (this->linearFiltering == filter) return;
			linearFiltering = filter;
			shouldUpdate = true;
			//updateText();
		}

		bool getLinearFiltering() const
		{
			return linearFiltering;
		}

		void setStyle(StyleFlags style)
		{
			if (this->style == (int)style) return;
			this->style = (int)style;
			shouldUpdate = true;
			//updateText();
		}

		StyleFlags getStyle() const
		{
			return (StyleFlags)style;
		}

		void setHinting(Hinting hinting)
		{
			if (this->hinting == (int)hinting) return;
			this->hinting = (int)hinting;
			shouldUpdate = true;
			//updateText();
		}

		Hinting getHinting() const
		{
			return (Hinting)hinting;
		}

		void setWrappedAlign(WrappedAlign wrappedAlign)
		{
			if (this->wrappedAlign == (int)wrappedAlign) return;
			this->wrappedAlign = (int)wrappedAlign;
			shouldUpdate = true;
			//updateText();
		}

		WrappedAlign getWrappedAlign() const
		{
			return (WrappedAlign)wrappedAlign;
		}

		void setWrapLength(int wrapLength)
		{
			if (this->wrapLength == wrapLength) return;
			this->wrapLength = wrapLength;
			shouldUpdate = true;
			//updateText();
		}
		int getWrapLength() const
		{
			return wrapLength;
		}

		void setFont(const stl::string& fontPath)
		{
			if (font != nullptr)
			{
				TTF_CloseFont(font);
				font = nullptr;
			}

			auto fullPath = std::filesystem::current_path() / fontPath;
			auto fullPathStr = fullPath.string();
			const char* fullPathCStr = fullPathStr.c_str();

			font = TTF_OpenFont(fullPathCStr, fontSize);
			if (!font)
				throw std::runtime_error(std::format("Couldn't load the font \"{}\"\nSDL_TTF Error:{}", fontPath, TTF_GetError()));
		}

		void init(const stl::string& fontPath, const Shader* shader)
		{
			static bool initializedSDL = false;
			if (!initializedSDL)
			{
				SDL_Init(SDL_INIT_EVERYTHING);
				TTF_Init();
				initializedSDL = true;
			}

			tr.shader = shader;
			tex.width = 1;
			tex.height = 1;
			tr.texture = &tex;
			tr.init();
			setColor(glm::vec4{ 1 });
			setModel(model);
			tr.setClip(0, 0, 1, 1);

			setFont(fontPath);
		}

		void render()
		{
			if (shouldUpdate)
				updateText();
			if (!tr.shader || !tr.VAO || !tex.ID) return;
			tr.render();
		}

		TTFRenderer(const stl::string& fontPath, const Shader* shader)
		{
			init(fontPath, shader);
		}

		bool isInitialized() const { return font; }
	};
}
