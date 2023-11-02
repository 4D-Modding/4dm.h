#pragma once

#include "4dm.h"
#include "Item.h"

namespace fdm 
{
	class PlayerSkinRenderer 
	{
	public:
		inline static MeshRenderer* wireframeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278B80));
		m4::Mat5 transformations[10]; 
		glm::vec4 vel; // 0x3E8
		glm::vec4 walkDir; // 0x3F8
		m4::Mat5 orientationDst; // 0x408
		m4::Mat5 orientationHead; // 0x46C
		m4::Mat5 orientationBody; // 0x4D0
		PAD(0x4);
		double walkAnimProgress; // 0x538
		inline static const float thighAnimDefault = -0.3333333f; 
		float thighAnimL; // 0x540
		float thighAnimR; // 0x544
		inline static const float lowerLegAnimDefault = 1.f; 
		float lowerLegAnimL; // 0x548
		float lowerLegAnimR; // 0x54C
		inline static const float upperArmAnimDefault = 0; 
		float upperArmAnimL; // 0x550
		float upperArmAnimR; // 0x554
		inline static const float forearmAnimDefault = -1.f; 
		float forearmAnimL; // 0x558
		float forearmAnimR; // 0x55C
		bool crouching; // 0x560
		PAD(0x3);
		float crouchingVal; // 0x564
		bool hitting; // 0x568
		PAD(0x3);
		float hittingVal; // 0x56C
		double hitStartTime; // 0x570
		bool performingAction; // 0x578
		bool dead; // 0x579
		PAD(0x6);
		double damageStartTime; // 0x580
		PlayerSkin* skin; // 0x588

		PlayerSkinRenderer(){}
		PlayerSkinRenderer(const PlayerSkin* skin) 
		{
			reinterpret_cast<void(__thiscall*)(PlayerSkinRenderer* self, const PlayerSkin* skin)>(FUNC_PLAYERSKINRENDERER_PLAYERSKINRENDERER)(this, skin);
		}
		void render(const m4::Mat5& MV, const glm::vec4& lightDir, const std::unique_ptr<Item>* handSlot, const std::unique_ptr<Item>* equipmentSlot, bool glasses) 
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinRenderer* self, const m4::Mat5& MV, const glm::vec4& lightDir, const std::unique_ptr<Item>* handSlot, const std::unique_ptr<Item>* equipmentSlot, bool glasses)>(FUNC_PLAYERSKINRENDERER_RENDER)(this, MV, lightDir, handSlot, equipmentSlot, glasses);
		}
		void updateAnimation(double dt) 
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinRenderer* self, double dt)>(FUNC_PLAYERSKINRENDERER_UPDATEANIMATION)(this, dt);
		}
		void resetTransformations() 
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinRenderer* self)>(FUNC_PLAYERSKINRENDERER_RESETTRANSFORMATIONS)(this);
		}
	};
}
