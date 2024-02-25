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
		inline static std::map<std::string,AudioManager::voiceGroupInfo>* voiceGroups = reinterpret_cast<std::map<std::string,AudioManager::voiceGroupInfo>*>((base + idaOffsetFix(0x2BCE0 + 0x270000)));
		//inline static std::map<std::string,SoLoud::Wav,std::less<std::string >,std::allocator<std::pair<std::string const ,SoLoud::Wav> > > sounds = reinterpret_cast<std::map<std::string,SoLoud::Wav,std::less<std::string >,std::allocator<std::pair<std::string const ,SoLoud::Wav> > >*>((base + 0x29BCF0)); 
		inline static std::vector<std::string>* BGMList = reinterpret_cast<std::vector<std::string>*>((base + idaOffsetFix(0x53E38 + 0x270000)));
		inline static float* BGMVolume = reinterpret_cast<float*>((base + idaOffsetFix(0x83B0 + 0x270000)));
		inline static int* BGMNextIndex = reinterpret_cast<int*>((base + idaOffsetFix(0x2B3C0 + 0x270000)));
		inline static uint32_t* currentBGM = reinterpret_cast<uint32_t*>((base + idaOffsetFix(0x2B3C4 + 0x270000)));
		inline static m4::Mat5* hyperplaneView = reinterpret_cast<m4::Mat5*>((base + idaOffsetFix(0x87A0 + 0x270000)));

		inline static bool loadSound(const std::string& sound) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& sound)>(getFuncAddr((int)Func::AudioManager::loadSound))(sound);
		}
		inline static uint32_t playSound4D(std::string& sound, std::string& voiceGroup, const glm::vec4& pos, const glm::vec4& vel) 
		{
			return reinterpret_cast<uint32_t (__fastcall*)(std::string& sound, std::string& voiceGroup, const glm::vec4& pos, const glm::vec4& vel)>(getFuncAddr((int)Func::AudioManager::playSound4D))(sound, voiceGroup, pos, vel);
		}
		inline static void setListenerInfo4D(glm::vec4& pos, const m4::Mat5* orientation, const glm::vec4& vel) 
		{
			return reinterpret_cast<void (__fastcall*)(glm::vec4& pos, const m4::Mat5* orientation, const glm::vec4& vel)>(getFuncAddr((int)Func::AudioManager::setListenerInfo4D))(pos, orientation, vel);
		}
		inline static bool loadBGMfromJSON(const std::string& jsonListPath) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& jsonListPath)>(getFuncAddr((int)Func::AudioManager::loadBGMfromJSON))(jsonListPath);
		}
		inline static bool updateBGM() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(getFuncAddr((int)Func::AudioManager::updateBGM))();
		}
		/*inline static SoLoud::Wav getSound(std::string& sound) 
		{
			return reinterpret_cast<SoLoud::Wav (__fastcall*)(std::string& sound)>(getFuncAddr((int)Func::AudioManager::getSound))(sound);
		}*/
		inline static AudioManager::voiceGroupInfo getVoiceGroupInfo(std::string& voiceGroup) 
		{
			return reinterpret_cast<AudioManager::voiceGroupInfo (__fastcall*)(std::string& voiceGroup)>(getFuncAddr((int)Func::AudioManager::getVoiceGroupInfo))(voiceGroup);
		}
	};
}
