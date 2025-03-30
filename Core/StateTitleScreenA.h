#pragma once

#include "../4dm.h"

#include "Counter.h"
#include "BetterText.h"
#include "ModElement.h"

namespace fdm::Core
{
	namespace StateTitleScreenA
	{
		inline gui::Text& modloaderText = *reinterpret_cast<gui::Text*>(getDataAddr((int)Data::Core::StateTitleScreenA::modloaderText));
		inline gui::Button& modsBtn = *reinterpret_cast<gui::Button*>(getDataAddr((int)Data::Core::StateTitleScreenA::modsBtn));
		inline Counter& counterCriticals = *reinterpret_cast<Counter*>(getDataAddr((int)Data::Core::StateTitleScreenA::counterCriticals));
		inline Counter& counterWarnings = *reinterpret_cast<Counter*>(getDataAddr((int)Data::Core::StateTitleScreenA::counterWarnings));

		inline static void modsBtnCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void* user)>(getFuncAddr((int)Func::Core::StateTitleScreenA::modsBtnCallback))(user);
		}
	}
}
