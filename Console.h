#pragma once

#include "4dm.h"

namespace fdm
{
	enum Color
	{
		BLACK = 30,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE
	};
	enum Variant
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

		Mode(Color color = WHITE, Variant variant = NORMAL) : color(color), variant(variant) {}
	};
}

// some std extensions
namespace std
{
	inline string to_string(const fdm::Mode& mode) noexcept
	{
		stringstream ss;
		ss << "\x1B[";
		ss << mode.variant << ';' << mode.color << 'm';
		return ss.str();
	}
	inline ostream& operator<<(ostream& os, const fdm::Mode& mode)
	{
		os << to_string(mode);
		return os;
	}
}

namespace fdm
{
	class Console
	{
	public:
		inline static std::mutex* inputMutex = reinterpret_cast<std::mutex*>((fdm::base + 0x2BDF40));
		inline static std::vector<std::string>* inStrings = reinterpret_cast<std::vector<std::string>*>((fdm::base + 0x2C4050));

		// example usage: `Console::print(Mode(GREEN, BRIGHT), "Player ", Mode(WHITE, BRIGHT), playerName, Mode(GREEN, BRIGHT), " joined the game!\n")`. if you dont want to put a new line symbol at the end of the string, use Console::printLine instead, which does it for you
		template <typename... Args>
		inline static void print(Args const&... args)
		{
			std::cout << Mode();
			(std::cout << ... << args);
			std::cout << Mode();
		}

		// example usage: `Console::print(Mode(GREEN, BRIGHT), "Player ", Mode(WHITE, BRIGHT), playerName, Mode(GREEN, BRIGHT), " joined the game!\n")`. if you dont want a new line symbol at the end of the string, use Console::print instead.
		template <typename... Args>
		inline static void printLine(Args const&... args)
		{
			std::cout << Mode();
			(std::cout << ... << args);
			std::cout << '\n';
			std::cout << Mode();
		}
	};
}