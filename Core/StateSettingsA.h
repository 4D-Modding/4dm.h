#pragma once

#include "../4dm.h"

namespace fdm::Core
{
	namespace StateSettingsA
	{
		inline gui::Text& modloaderOptionsText = *reinterpret_cast<gui::Text*>(getDataAddr((int)Data::Core::StateSettingsA::modloaderOptionsText));
		inline gui::CheckBox& autoUpdateCheckBox = *reinterpret_cast<gui::CheckBox*>(getDataAddr((int)Data::Core::StateSettingsA::autoUpdateCheckBox));

		inline static void autoUpdateCheckBoxCallback(void* user, bool checked)
		{
			reinterpret_cast<void(__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::Core::StateSettingsA::autoUpdateCheckBoxCallback))(user, checked);
		}
	}
}
