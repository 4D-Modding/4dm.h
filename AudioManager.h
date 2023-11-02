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
		inline static std::map<std::string,AudioManager::voiceGroupInfo>* voiceGroups = reinterpret_cast<std::map<std::string,AudioManager::voiceGroupInfo>*>((base + 0x29BCE0));
		//inline static std::map<std::string,SoLoud::Wav,std::less<std::string >,std::allocator<std::pair<std::string const ,SoLoud::Wav> > > sounds = reinterpret_cast<std::map<std::string,SoLoud::Wav,std::less<std::string >,std::allocator<std::pair<std::string const ,SoLoud::Wav> > >*>((base + 0x29BCF0)); 
		inline static std::vector<std::string>* BGMList = reinterpret_cast<std::vector<std::string>*>((base + 0x2C3E38));
		inline static float* BGMVolume = reinterpret_cast<float*>((base + 0x2783B0));
		inline static int* BGMNextIndex = reinterpret_cast<int*>((base + 0x29B3C0));
		inline static uint32_t* currentBGM = reinterpret_cast<uint32_t*>((base + 0x29B3C4));
		inline static m4::Mat5* hyperplaneView = reinterpret_cast<m4::Mat5*>((base + 0x2787A0));

		inline static bool loadSound(const std::string& sound) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& sound)>(FUNC_AUDIOMANAGER_LOADSOUND)(sound);
		}
		inline static uint32_t playSound4D(std::string& sound, std::string& voiceGroup, const glm::vec4& pos, const glm::vec4& vel) 
		{
			return reinterpret_cast<uint32_t (__fastcall*)(std::string& sound, std::string& voiceGroup, const glm::vec4& pos, const glm::vec4& vel)>(FUNC_AUDIOMANAGER_PLAYSOUND4D)(sound, voiceGroup, pos, vel);
		}
		inline static void setListenerInfo4D(glm::vec4& pos, const m4::Mat5* orientation, const glm::vec4& vel) 
		{
			return reinterpret_cast<void (__fastcall*)(glm::vec4& pos, const m4::Mat5* orientation, const glm::vec4& vel)>(FUNC_AUDIOMANAGER_SETLISTENERINFO4D)(pos, orientation, vel);
		}
		inline static bool loadBGMfromJSON(const std::string& jsonListPath) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& jsonListPath)>(FUNC_AUDIOMANAGER_LOADBGMFROMJSON)(jsonListPath);
		}
		inline static bool updateBGM() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(FUNC_AUDIOMANAGER_UPDATEBGM)();
		}
		/*inline static SoLoud::Wav getSound(std::string& sound) 
		{
			return reinterpret_cast<SoLoud::Wav (__fastcall*)(std::string& sound)>(FUNC_AUDIOMANAGER_GETSOUND)(sound);
		}*/
		inline static AudioManager::voiceGroupInfo getVoiceGroupInfo(std::string& voiceGroup) 
		{
			return reinterpret_cast<AudioManager::voiceGroupInfo (__fastcall*)(std::string& voiceGroup)>(FUNC_AUDIOMANAGER_GETVOICEGROUPINFO)(voiceGroup);
		}
	};
}
