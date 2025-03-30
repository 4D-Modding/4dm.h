#pragma once

#include "4dm.h"

namespace fdm
{
	class Console
	{
	public:
		enum Color : int
		{
			RESET = 0,
			BLACK = 30,
			RED,
			GREEN,
			YELLOW,
			BLUE,
			MAGENTA,
			CYAN,
			WHITE
		};
		struct TrueColor
		{
			uint8_t r, g, b;
		};
		enum Variant : int
		{
			NORMAL = 0,
			BRIGHT,
			DIM,
			ITALIC,
			UNDERLINE,
			BLINKING,
			INVERSE = 7,
			HIDDEN,
			STRIKETHROUGH
		};
		struct Mode
		{
			Color color;
			Variant variant;

			Mode(Color color = RESET, Variant variant = NORMAL) : color(color), variant(variant) {}

			inline static std::string to_string(const Mode& mode)
			{
				return std::format("\x1B[{};{}m", (int)mode.variant, (int)mode.color);
			}
		};
		struct TCMode
		{
			TrueColor color;
			Variant variant;

			TCMode(TrueColor color = {255,255,255}, Variant variant = NORMAL) : color(color), variant(variant) {}

			inline static std::string to_string(const TCMode& mode)
			{
				return std::format("\x1B[{};38;2;{};{};{}m", (int)mode.variant, (int)mode.color.r, (int)mode.color.g, (int)mode.color.b);
			}
		};

		inline static std::mutex& inputMutex = *reinterpret_cast<std::mutex*>(getDataAddr((int)Data::Console::inputMutex));
		inline static std::vector<stl::string>& inStrings = *reinterpret_cast<std::vector<stl::string>*>(getDataAddr((int)Data::Console::inStrings));

		// example usage: `Console::print(Mode(GREEN, BRIGHT), "Player ", Console::Mode(WHITE, BRIGHT), playerName, Console::Mode(GREEN, BRIGHT), " joined the game!\n")`. if you dont want to put a new line symbol at the end of the string, use Console::printLine instead, which does it for you
		template <typename... Args>
		inline static void print(Args const&... args)
		{
			std::stringstream s;
			s << Mode::to_string(Mode());
			(s << ... << args);
			s << Mode::to_string(Mode());
			printf(s.str().c_str());
		}

		// example usage: `Console::print(Mode(GREEN, BRIGHT), "Player ", Console::Mode(WHITE, BRIGHT), playerName, Console::Mode(GREEN, BRIGHT), " joined the game!\n")`. if you dont want a new line symbol at the end of the string, use Console::print instead.
		template <typename... Args>
		inline static void printLine(Args const&... args)
		{
			std::stringstream s;
			s << Mode::to_string(Mode());
			(s << ... << args);
			s << '\n';
			s << Mode::to_string(Mode());
			printf(s.str().c_str());
		}
	};
}

// some std extensions
namespace std
{
	inline string to_string(const fdm::Console::Mode& mode) noexcept
	{
		return fdm::Console::Mode::to_string(mode);
	}
	inline ostream& operator<<(ostream& os, const fdm::Console::Mode& mode)
	{
		os << to_string(mode);
		return os;
	}
	inline string to_string(const fdm::Console::TCMode& mode) noexcept
	{
		return fdm::Console::TCMode::to_string(mode);
	}
	inline ostream& operator<<(ostream& os, const fdm::Console::TCMode& mode)
	{
		os << to_string(mode);
		return os;
	}
}
