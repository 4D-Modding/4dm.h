#pragma once

#include "../4dm.h"

namespace fdm::Core
{
	class Counter : public gui::Element
	{
	private:
		uint32_t _count = 0;
		stl::string _countStr;
		TexRenderer img;

		int xOffset = 0;
		int yOffset = 0;
		gui::AlignmentX xAlign = gui::ALIGN_LEFT;
		gui::AlignmentY yAlign = gui::ALIGN_TOP;

	public:
		inline static TexRenderer& numbers = *reinterpret_cast<TexRenderer*>(getDataAddr((int)Data::Core::Counter::numbers));
		
		float scale = 1;

		Counter() { }

		Counter(const stl::string& imgPath, const stl::string& folderOverride = "assets/modloader")
		{
			reinterpret_cast<void(__thiscall*)(Counter * self, const stl::string & imgPath, const stl::string & folderOverride)>(getFuncAddr((int)Func::Core::Counter::Counter))(this, imgPath, folderOverride);
		}

		void setCount(uint32_t count)
		{
			reinterpret_cast<void(__thiscall*)(Counter * self, uint32_t count)>(getFuncAddr((int)Func::Core::Counter::setCount))(this, count);
		}

		uint32_t getCount() const
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const Counter * self)>(getFuncAddr((int)Func::Core::Counter::getCount))(this);
		}

		void render(gui::Window* w) override
		{
			reinterpret_cast<void(__thiscall*)(Counter * self, gui::Window* w)>(getFuncAddr((int)Func::Core::Counter::render))(this, w);
		}

		void alignX(gui::AlignmentX alignment) override { xAlign = alignment; }
		void alignY(gui::AlignmentY alignment) override { yAlign = alignment; }
		void offsetX(int offset) override { xOffset = offset; }
		void offsetY(int offset) override { yOffset = offset; }
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			reinterpret_cast<void(__thiscall*)(const Counter * self, const gui::Window *, int*, int*)>(getFuncAddr((int)Func::Core::Counter::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			reinterpret_cast<void(__thiscall*)(const Counter * self, const gui::Window *, int*, int*)>(getFuncAddr((int)Func::Core::Counter::getSize))(this, w, width, height);
		}
	};
}
