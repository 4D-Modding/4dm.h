#pragma once

#include "4dm.h"

namespace fdm 
{
	class AudioManager 
	{
	public:
		struct voiceGroupInfo 
		{
			SoLoud::handle handle;
			float volume; // 0x4
		};
		inline static SoLoud::Soloud& soloud = *reinterpret_cast<SoLoud::Soloud*>(getDataAddr((int)Data::AudioManager::soloud));
		inline static std::map<stl::string, AudioManager::voiceGroupInfo>& voiceGroups = *reinterpret_cast<std::map<stl::string, AudioManager::voiceGroupInfo>*>(getDataAddr((int)Data::AudioManager::voiceGroups));
		inline static std::map<stl::string, SoLoud::Wav>& sounds = *reinterpret_cast<std::map<stl::string, SoLoud::Wav>*>(getDataAddr((int)Data::AudioManager::sounds));
		inline static std::vector<stl::string>& BGMList = *reinterpret_cast<std::vector<stl::string>*>(getDataAddr((int)Data::AudioManager::BGMList));
		inline static float& BGMVolume = *reinterpret_cast<float*>(getDataAddr((int)Data::AudioManager::BGMVolume));
		inline static int& BGMNextIndex = *reinterpret_cast<int*>(getDataAddr((int)Data::AudioManager::BGMNextIndex));
		inline static SoLoud::handle& currentBGM = *reinterpret_cast<SoLoud::handle*>(getDataAddr((int)Data::AudioManager::currentBGM));
		inline static m4::Mat5& hyperplaneView = *reinterpret_cast<m4::Mat5*>(getDataAddr((int)Data::AudioManager::hyperplaneView));
		inline static SoLoud::Wav* getSound(const stl::string& sound)
		{
			return reinterpret_cast<SoLoud::Wav * (__fastcall*)(const stl::string&)>(getFuncAddr((int)Func::AudioManager::getSound))(sound);
		}
		inline static AudioManager::voiceGroupInfo* getVoiceGroupInfo(const stl::string& voiceGroup)
		{
			return reinterpret_cast<AudioManager::voiceGroupInfo * (__fastcall*)(const stl::string&)>(getFuncAddr((int)Func::AudioManager::getVoiceGroupInfo))(voiceGroup);
		}
		inline static bool loadBGMfromJSON(const stl::string& jsonListPath)
		{
			return reinterpret_cast<bool(__fastcall*)(const stl::string&)>(getFuncAddr((int)Func::AudioManager::loadBGMfromJSON))(jsonListPath);
		}
		inline static bool loadSound(const stl::string& sound)
		{
			return reinterpret_cast<bool(__fastcall*)(const stl::string&)>(getFuncAddr((int)Func::AudioManager::loadSound))(sound);
		}
		inline static SoLoud::handle playSound4D(const stl::string& sound, const stl::string& voiceGroup, const glm::vec4& pos, const glm::vec4& vel)
		{
			return reinterpret_cast<SoLoud::handle(__fastcall*)(const stl::string&, const stl::string&, const glm::vec4&, const glm::vec4&)>(getFuncAddr((int)Func::AudioManager::playSound4D))(sound, voiceGroup, pos, vel);
		}
		inline static void setListenerInfo4D(const glm::vec4& pos, const m4::Mat5& orientation, const glm::vec4& vel)
		{
			return reinterpret_cast<void(__fastcall*)(const glm::vec4&, const m4::Mat5&, const glm::vec4&)>(getFuncAddr((int)Func::AudioManager::setListenerInfo4D))(pos, orientation, vel);
		}
		inline static bool updateBGM()
		{
			return reinterpret_cast<bool(__fastcall*)()>(getFuncAddr((int)Func::AudioManager::updateBGM))();
		}
	};
}
