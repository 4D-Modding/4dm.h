#pragma once

#include "4dm.h"

namespace fdm 
{
	class AudioManager 
	{
	public:
		struct voiceGroupInfo 
		{
			uint32_t handle; 
			float volume; // 0x4
		};
		//inline static SoLoud::Soloud *soloud = reinterpret_cast<SoLoud::Soloud*>((base + 0x29BD00)); 
		inline static std::map<stl::string,AudioManager::voiceGroupInfo>* voiceGroups = reinterpret_cast<std::map<stl::string,AudioManager::voiceGroupInfo>*>((base + idaOffsetFix(0x2BCE0 + 0x270000)));
		//inline static std::map<stl::string,SoLoud::Wav,std::less<stl::string >,std::allocator<std::pair<stl::string const ,SoLoud::Wav> > > sounds = reinterpret_cast<std::map<stl::string,SoLoud::Wav,std::less<stl::string >,std::allocator<std::pair<stl::string const ,SoLoud::Wav> > >*>((base + 0x29BCF0)); 
		inline static std::vector<stl::string>* BGMList = reinterpret_cast<std::vector<stl::string>*>((base + idaOffsetFix(0x53E38 + 0x270000)));
		inline static float* BGMVolume = reinterpret_cast<float*>((base + idaOffsetFix(0x83B0 + 0x270000)));
		inline static int* BGMNextIndex = reinterpret_cast<int*>((base + idaOffsetFix(0x2B3C0 + 0x270000)));
		inline static uint32_t* currentBGM = reinterpret_cast<uint32_t*>((base + idaOffsetFix(0x2B3C4 + 0x270000)));
		inline static m4::Mat5* hyperplaneView = reinterpret_cast<m4::Mat5*>((base + idaOffsetFix(0x87A0 + 0x270000)));

		inline static bool loadSound(const stl::string& sound) 
		{
			return reinterpret_cast<bool (__fastcall*)(const stl::string& sound)>(getFuncAddr((int)Func::AudioManager::loadSound))(sound);
		}
		inline static uint32_t playSound4D(stl::string& sound, stl::string& voiceGroup, const glm::vec4& pos, const glm::vec4& vel) 
		{
			return reinterpret_cast<uint32_t (__fastcall*)(stl::string& sound, stl::string& voiceGroup, const glm::vec4& pos, const glm::vec4& vel)>(getFuncAddr((int)Func::AudioManager::playSound4D))(sound, voiceGroup, pos, vel);
		}
		inline static void setListenerInfo4D(glm::vec4& pos, const m4::Mat5* orientation, const glm::vec4& vel) 
		{
			return reinterpret_cast<void (__fastcall*)(glm::vec4& pos, const m4::Mat5* orientation, const glm::vec4& vel)>(getFuncAddr((int)Func::AudioManager::setListenerInfo4D))(pos, orientation, vel);
		}
		inline static bool loadBGMfromJSON(const stl::string& jsonListPath) 
		{
			return reinterpret_cast<bool (__fastcall*)(const stl::string& jsonListPath)>(getFuncAddr((int)Func::AudioManager::loadBGMfromJSON))(jsonListPath);
		}
		inline static bool updateBGM() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(getFuncAddr((int)Func::AudioManager::updateBGM))();
		}
		/*inline static SoLoud::Wav getSound(stl::string& sound) 
		{
			return reinterpret_cast<SoLoud::Wav (__fastcall*)(stl::string& sound)>(getFuncAddr((int)Func::AudioManager::getSound))(sound);
		}*/
		inline static AudioManager::voiceGroupInfo getVoiceGroupInfo(stl::string& voiceGroup) 
		{
			return reinterpret_cast<AudioManager::voiceGroupInfo (__fastcall*)(stl::string& voiceGroup)>(getFuncAddr((int)Func::AudioManager::getVoiceGroupInfo))(voiceGroup);
		}
	};
}
