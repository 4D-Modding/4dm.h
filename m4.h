#pragma once
#ifndef M4_H
#define M4_H
#include "4dm.h"
namespace fdm
{
	namespace m4
	{
		struct BiVector4
		{
		public:
			float b01;
			float b02;
			float b03;
			float b12;
			float b13;
			float b23;
			
			void normalize()
			{
				return reinterpret_cast<void(__thiscall*)(BiVector4*)>(
					FUNC_M4_BIVECTOR4_NORMALIZE
					)(this);
			}
			BiVector4 normalized() const
			{
				BiVector4 b = *this;
				b.normalize();
				return b;
			}
		};
		inline glm::vec4 cross(const glm::vec4& u, const glm::vec4& v, const glm::vec4& w)
		{
			return reinterpret_cast<glm::vec4& (__fastcall*)(glm::vec4*, const glm::vec4&, const glm::vec4&, const glm::vec4&)>(
				FUNC_M4_CROSS
				)(nullptr, u, v, w);
		}
		inline BiVector4 wedge(const glm::vec4& u, const glm::vec4& v)
		{
			return reinterpret_cast<BiVector4 & (__fastcall*)(BiVector4* result, const glm::vec4&, const glm::vec4&)>(
				FUNC_M4_WEDGE
				)(nullptr, u, v);
		}
		class Rotor 
		{
		public:
			float a;
			struct BiVector4 b;
			float b0123;
			Rotor(const BiVector4& plane, float radians) 
			{
				reinterpret_cast<void(__thiscall*)(Rotor*, const BiVector4&, float)>(
					FUNC_M4_ROTOR_ROTOR
					)(this, plane, radians);
			}
			void operator*=(const Rotor& r) 
			{
				return reinterpret_cast<void(__thiscall*)(Rotor*, const Rotor&)>(
					FUNC_M4_ROTOR_OPERATOR_MULT_EQ
					)(this, r);
			}
			glm::vec4 rotate(const glm::vec4& v) 
			{
				return reinterpret_cast<glm::vec4(__thiscall*)(Rotor*, glm::vec4*, const glm::vec4&)>(
					FUNC_M4_ROTOR_ROTATE
					)(this, nullptr, v);
			}
			void normalize() 
			{
				return reinterpret_cast<void(__thiscall*)(Rotor*)>(
					FUNC_M4_ROTOR_NORMALIZE
					)(this);
			}
		};
		class Mat5
		{
		public:
			float value[5][5];
			// 0.0
			Mat5() 
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, float)>(
					FUNC_M4_MAT5_MAT5
					)(this, 0.0);
			}
			Mat5(float x)
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, float)>(
					FUNC_M4_MAT5_MAT5
					)(this, x);
			}
			Mat5 operator*(const Mat5& other)
			{
				return reinterpret_cast<Mat5(__thiscall*)(Mat5*, Mat5*, const Mat5&)>(
					FUNC_M4_MAT5_OPERATOR_MULT
					)(this, nullptr, other);
			}
			Mat5 operator*=(const Mat5& other)
			{
				return reinterpret_cast<Mat5(__thiscall*)(Mat5*, Mat5*, const Mat5&)>(
					FUNC_M4_MAT5_OPERATOR_MULT_EQ
					)(this, nullptr, other);
			}
			glm::vec4 multiply(const glm::vec4& v, float finalComp)
			{
				return reinterpret_cast<glm::vec4(__thiscall*)(Mat5*, glm::vec4*, const glm::vec4&, float)>(
					FUNC_M4_MAT5_MULTIPLY
					)(this, nullptr, v, finalComp);
			}
			glm::vec4 operator*(const glm::vec4& v)
			{
				return multiply(v, 1.0f);
			}
			void translate(const glm::vec4& v)
			{
				return reinterpret_cast<void(__thiscall*)(Mat5*, const glm::vec4&)>(
					FUNC_M4_MAT5_TRANSLATE
					)(this, v);
			}
			void scale(const glm::vec4& s)
			{
				return reinterpret_cast<void(__thiscall*)(Mat5*, const glm::vec4&)>(
					FUNC_M4_MAT5_SCALE
					)(this, s);
			}
			float* operator[](int index)
			{
				return value[index];
			}
		};
		inline Mat5 createCamera(const glm::vec4& eye, const glm::vec4& forward, const glm::vec4& up, const glm::vec4& left, const glm::vec4& over)
		{
			Mat5 cameraD{ 1 };

			cameraD[0][0] = left.x;
			cameraD[1][0] = left.y;
			cameraD[2][0] = left.z;
			cameraD[3][0] = left.w;
			cameraD[0][1] = up.x;
			cameraD[1][1] = up.y;
			cameraD[2][1] = up.z;
			cameraD[3][1] = up.w;
			cameraD[0][2] = forward.x;
			cameraD[1][2] = forward.y;
			cameraD[2][2] = forward.z;
			cameraD[3][2] = forward.w;
			cameraD[0][3] = over.x;
			cameraD[1][3] = over.y;
			cameraD[2][3] = over.z;
			cameraD[3][3] = over.w;

			Mat5 cameraP{ 1 };
			cameraP[4][0] = -eye.x;
			cameraP[4][1] = -eye.y;
			cameraP[4][2] = -eye.z;
			cameraP[4][3] = -eye.w;

			return cameraD * cameraP;
		}
		inline glm::vec4 adjustToMaxHorizSpeed(const glm::vec4& vel, const glm::vec4& deltaVel, float maxHorizSpeed)
		{
			return reinterpret_cast<glm::vec4& (__fastcall*)(glm::vec4*, const glm::vec4&, const glm::vec4&, float)>(
				FUNC_M4_ADJUSTTOMAXHORIZSPEED
				)(nullptr, vel, deltaVel, maxHorizSpeed);
		}
	}
}
#endif