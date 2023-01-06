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
					base + idaOffsetFix(0x759D0)
					)(this);
			}
			BiVector4 normalized() const
			{
				BiVector4 b = *this;
				b.normalize();
				return b;
			}
		};
		glm::vec4 cross(const glm::vec4& u, const glm::vec4& v, const glm::vec4& w)
		{
			glm::vec4* result = new glm::vec4(0.0f);
			return reinterpret_cast<glm::vec4& (__fastcall*)(glm::vec4*, const glm::vec4&, const glm::vec4&, const glm::vec4&)>(
				base + idaOffsetFix(0x75AF0)
				)(result, u, v, w);
		}
		BiVector4 wedge(const glm::vec4& u, const glm::vec4& v) 
		{
			BiVector4* result = new BiVector4();
			return reinterpret_cast<BiVector4 & (__fastcall*)(BiVector4* result, const glm::vec4&, const glm::vec4&)>(
				base + idaOffsetFix(0x75CB0)
				)(result, u, v);
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
					base + idaOffsetFix(0x75D80)
					)(this, plane, radians);
			}
			void operator*=(const Rotor& r) 
			{
				return reinterpret_cast<void(__thiscall*)(Rotor*, const Rotor&)>(
					base + idaOffsetFix(0x75E40)
					)(this, r);
			}
			glm::vec4 rotate(const glm::vec4& v) 
			{
				glm::vec4* result = new glm::vec4(0.0f);
				return reinterpret_cast<glm::vec4(__thiscall*)(Rotor*, glm::vec4*, const glm::vec4&)>(
					base + idaOffsetFix(0x761D0)
					)(this, result, v);
			}
			void normalize() 
			{
				return reinterpret_cast<void(__thiscall*)(Rotor*)>(
					base + idaOffsetFix(0x76660)
					)(this);
			}
		};
		class Mat5
		{
		public:
			float value[5][5];
			Mat5(float x)
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, float)>(
					base + idaOffsetFix(0x767D0)
					)(this, x);
			}
			Mat5 operator*(const Mat5& other)
			{
				Mat5* result = new Mat5(0.0f);
				return reinterpret_cast<Mat5(__thiscall*)(Mat5*, Mat5*, const Mat5&)>(
					base + idaOffsetFix(0x76810)
					)(this, result, other);
			}
			Mat5 operator*=(const Mat5& other)
			{
				Mat5* result = new Mat5(0.0f);
				return reinterpret_cast<Mat5(__thiscall*)(Mat5*, Mat5*, const Mat5&)>(
					base + idaOffsetFix(0x76900)
					)(this, result, other);
			}
			glm::vec4 multiply(const glm::vec4& v, float finalComp)
			{
				glm::vec4* result = new glm::vec4(0.0f);
				return reinterpret_cast<glm::vec4(__thiscall*)(Mat5*, glm::vec4*, const glm::vec4&, float)>(
					base + idaOffsetFix(0x769A0)
					)(this, result, v, finalComp);
			}
			glm::vec4 operator*(const glm::vec4& v)
			{
				return multiply(v, 1.0f);
			}
			void translate(const glm::vec4& v)
			{
				return reinterpret_cast<void(__thiscall*)(Mat5*, const glm::vec4&)>(
					base + idaOffsetFix(0x76AA0)
					)(this, v);
			}
			void scale(const glm::vec4& s)
			{
				return reinterpret_cast<void(__thiscall*)(Mat5*, const glm::vec4&)>(
					base + idaOffsetFix(0x76BA0)
					)(this, s);
			}
			float* operator[](int index)
			{
				return value[index];
			}
		};
		Mat5 createCamera(const glm::vec4& eye, const glm::vec4& forward, const glm::vec4& up, const glm::vec4& left, const glm::vec4& over)
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
		glm::vec4 adjustToMaxHorizSpeed(const glm::vec4& vel, const glm::vec4& deltaVel, float maxHorizSpeed)
		{
			glm::vec4* result = new glm::vec4(0.0f);
			return reinterpret_cast<glm::vec4& (__fastcall*)(glm::vec4*, const glm::vec4&, const glm::vec4&, float)>(
				base + idaOffsetFix(0x76E60)
				)(result, vel, deltaVel, maxHorizSpeed);
		}
	}
}
#endif