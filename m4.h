#pragma once

#include "4dm.h"

namespace fdm
{
	namespace m4
	{
		struct BiVector4
		{
			float b01;
			float b02;
			float b03;
			float b12;
			float b13;
			float b23;

			BiVector4(float b01 = 0.f, float b02 = 0.f, float b03 = 0.f, float b12 = 0.f, float b13 = 0.f, float b23 = 0.f) : b01(b01), b02(b02), b03(b03), b12(b12), b13(b13), b23(b23) {}

			BiVector4(const nlohmann::json& j)
			{
				reinterpret_cast<void(__thiscall*)(BiVector4*, const nlohmann::json & j)>(
					getFuncAddr((int)Func::m4_Nested::BiVector4::BiVector4A)
					)(this, j);
			}

			nlohmann::json toJson()
			{
				nlohmann::json result{};
				return reinterpret_cast<nlohmann::json&(__thiscall*)(m4::BiVector4 * self, nlohmann::json * result)>(getFuncAddr((int)Func::m4_Nested::BiVector4::toJson))(this, &result);
				return result;
			}

			void normalize()
			{
				return reinterpret_cast<void(__thiscall*)(BiVector4*)>(
					getFuncAddr((int)Func::m4_Nested::BiVector4::normalize)
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
			glm::vec4 result{};
			return reinterpret_cast<glm::vec4& (__fastcall*)(glm::vec4*, const glm::vec4&, const glm::vec4&, const glm::vec4&)>(
				getFuncAddr((int)Func::m4::cross)
				)(&result, u, v, w);
			return result;
		}
		inline BiVector4 wedge(const glm::vec4& u, const glm::vec4& v)
		{
			BiVector4 result{};

			result.b01 = u.x * v.y - u.y * v.x;
			result.b02 = v.z * u.x - u.z * v.x;
			result.b03 = u.x * v.w - u.w * v.x;
			result.b12 = v.z * u.y - v.y * u.z;
			result.b13 = v.w * u.y - u.w * v.y;
			result.b23 = v.w * u.z - u.w * v.z;

			return result.normalized();
		}
		class Rotor
		{
		public:
			float a;
			BiVector4 b;
			float b0123;
			Rotor(const BiVector4& plane, float radians)
			{
				reinterpret_cast<void(__thiscall*)(Rotor*, const BiVector4&, float)>(
					getFuncAddr((int)Func::m4_Nested::Rotor::RotorA)
					)(this, plane, radians);
			}
			Rotor(const glm::vec4& from, const glm::vec4& to)
			{
				reinterpret_cast<void(__thiscall*)(Rotor*, const glm::vec4 & from, const glm::vec4 & to)>(
					getFuncAddr((int)Func::m4_Nested::Rotor::Rotor)
					)(this, from, to);
			}
			Rotor& operator*=(const Rotor& r)
			{
				reinterpret_cast<void(__thiscall*)(Rotor*, const Rotor&)>(
					getFuncAddr((int)Func::m4_Nested::Rotor::operatorMultEq)
					)(this, r);
				return *this;
			}
			glm::vec4 rotate(const glm::vec4& v) const
			{
				glm::vec4 result{};
				return reinterpret_cast<glm::vec4&(__thiscall*)(const Rotor*, glm::vec4*, const glm::vec4&)>(
					getFuncAddr((int)Func::m4_Nested::Rotor::rotate)
					)(this, &result, v);

				return result;
			}
			void normalize()
			{
				return reinterpret_cast<void(__thiscall*)(Rotor*)>(
					getFuncAddr((int)Func::m4_Nested::Rotor::normalize)
					)(this);
			}
		};
		class Mat5
		{
		public:
			float value[5][5] = { 0.f };
			// 0.0
			Mat5()
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, float)>(
					getFuncAddr((int)Func::m4_Nested::Mat5::Mat5)
					)(this, 0.0);
			}
			Mat5(float x)
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, float)>(
					getFuncAddr((int)Func::m4_Nested::Mat5::Mat5)
					)(this, x);
			}
			Mat5(nlohmann::json& j)
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, nlohmann::json&)>(
					getFuncAddr((int)Func::m4_Nested::Mat5::Mat5A)
					)(this, j);
			}
			Mat5(const Rotor& rotor)
			{
				glm::vec4 x = rotor.rotate({ 1, 0, 0, 0 });
				value[0][0] = x[0];
				value[0][1] = x[1];
				value[0][2] = x[2];
				value[0][3] = x[3];
				glm::vec4 y = rotor.rotate({ 0, 1, 0, 0 });
				value[1][0] = y[0];
				value[1][1] = y[1];
				value[1][2] = y[2];
				value[1][3] = y[3];
				glm::vec4 z = rotor.rotate({ 0, 0, 1, 0 });
				value[2][0] = z[0];
				value[2][1] = z[1];
				value[2][2] = z[2];
				value[2][3] = z[3];
				glm::vec4 w = rotor.rotate({ 0, 0, 0, 1 });
				value[3][0] = w[0];
				value[3][1] = w[1];
				value[3][2] = w[2];
				value[3][3] = w[3];

				value[4][4] = 1.0;
			}
			nlohmann::json toJson()
			{
				nlohmann::json result{};
				return reinterpret_cast<nlohmann::json&(__thiscall*)(m4::Mat5* self, nlohmann::json* result)>(getFuncAddr((int)Func::m4_Nested::Mat5::toJson))(this, &result);
				return result;
			}
			inline static Mat5 identity()
			{
				return { 1 };
			}
			Mat5& operator*(const Mat5& other) const
			{
				Mat5 result;

				for (int col = 0; col < 5; ++col)
				{
					for (int row = 0; row < 5; ++row)
					{
						for (int k = 0; k < 5; ++k)
						{
							result.value[col][row] += value[k][row] * other.value[col][k];
						}
					}
				}

				return result;
			}
			Mat5& operator*=(const Mat5& other)
			{
				Mat5 result = *this * other;

				std::swap(this->value, result.value);

				return *this;
			}
			glm::vec4 multiply(const glm::vec4& v, float finalComp)
			{
				glm::vec4 result{};
				return reinterpret_cast<glm::vec4&(__thiscall*)(Mat5*, glm::vec4*, const glm::vec4&, float)>(
					getFuncAddr((int)Func::m4_Nested::Mat5::multiply)
					)(this, &result, v, finalComp);
				return result;
			}
			glm::vec4 operator*(const glm::vec4& v)
			{
				return multiply(v, 1.0f);
			}
			void translate(const glm::vec4& v)
			{
				return reinterpret_cast<void(__thiscall*)(Mat5*, const glm::vec4&)>(
					getFuncAddr((int)Func::m4_Nested::Mat5::translate)
					)(this, v);
			}
			void scale(const glm::vec4& s)
			{
				return reinterpret_cast<void(__thiscall*)(Mat5*, const glm::vec4&)>(
					getFuncAddr((int)Func::m4_Nested::Mat5::scale)
					)(this, s);
			}

			float* operator[](int index)
			{
				return value[index];
			}
			const float* operator[](int index) const
			{
				return value[index];
			}

			// uhh. helpful little function i made
			inline static Mat5 inverse(Mat5 m)
			{
				Mat5 s{ 1 };
				Mat5 t{ m };

				// Forward elimination
				for (int i = 0; i < 5 - 1; ++i) {
					int pivot = i;
					float pivotsize = t[i][i];

					for (int j = i + 1; j < 5; ++j) {
						float tmp = t[j][i];
						if (fabs(tmp) > fabs(pivotsize)) {
							pivotsize = tmp;
							pivot = j;
						}
					}

					if (pivotsize == 0.0f) return s;

					if (pivot != i) {
						for (int j = 0; j < 5; ++j) {
							float tmp;
							tmp = t[i][j];
							t[i][j] = t[pivot][j];
							t[pivot][j] = tmp;
							tmp = s[i][j];
							s[i][j] = s[pivot][j];
							s[pivot][j] = tmp;
						}
					}

					for (int j = i + 1; j < 5; ++j) {
						float f = t[j][i] / t[i][i];
						for (int k = i + 1; k < 5; ++k) {
							t[j][k] -= f * t[i][k];
						}
						for (int k = 0; k < 5; ++k) {
							s[j][k] -= f * s[i][k];
						}
						t[j][i] = 0.0f;
					}
				}

				// Backward substitution
				for (int i = 0; i < 5; ++i) {
					float f = t[i][i];
					if (f == 0.0f) return m4::Mat5{ 1 };

					for (int j = 0; j < 5; ++j) {
						t[i][j] /= f;
						s[i][j] /= f;
					}

					for (int j = 0; j < i; ++j) {
						f = t[j][i];
						for (int k = 0; k < 5; ++k) {
							t[j][k] -= f * t[i][k];
							s[j][k] -= f * s[i][k];
						}
					}
				}

				return s;
			}
		};
		inline Mat5 createCamera(const glm::vec4& eye, const glm::vec4& forward, const glm::vec4& up, const glm::vec4& right, const glm::vec4& over)
		{
			Mat5 result;

			return reinterpret_cast<Mat5 & (__fastcall*)(Mat5*, const glm::vec4 & eye, const glm::vec4 & forward, const glm::vec4 & up, const glm::vec4 & right, const glm::vec4 & over)>(
				getFuncAddr((int)Func::m4::createCamera)
				)(&result, eye, forward, up, right, over);
			return result;
			/*
			Mat5 cameraD{ 1 };

			cameraD[0][0] = right.x;
			cameraD[1][0] = right.y;
			cameraD[2][0] = right.z;
			cameraD[3][0] = right.w;
			cameraD[0][1] = up.x;
			cameraD[1][1] = up.y;
			cameraD[2][1] = up.z;
			cameraD[3][1] = up.w;
			cameraD[0][2] = -forward.x;
			cameraD[1][2] = -forward.y;
			cameraD[2][2] = -forward.z;
			cameraD[3][2] = -forward.w;
			cameraD[0][3] = over.x;
			cameraD[1][3] = over.y;
			cameraD[2][3] = over.z;
			cameraD[3][3] = over.w;

			Mat5 cameraP{ 1 };
			cameraP[4][0] = -eye.x;
			cameraP[4][1] = -eye.y;
			cameraP[4][2] = -eye.z;
			cameraP[4][3] = -eye.w;

			return cameraD * cameraP;*/
		}
		inline glm::vec4 adjustToMaxHorizSpeed(const glm::vec4& vel, const glm::vec4& deltaVel, float maxHorizSpeed)
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 & (__fastcall*)(glm::vec4*, const glm::vec4&, const glm::vec4&, float)>(
				getFuncAddr((int)Func::m4::adjustToMaxHorizSpeed)
				)(&result, vel, deltaVel, maxHorizSpeed);
		}

		inline nlohmann::json i64vec3ToJson(const glm::i64vec3& vec)
		{
			return reinterpret_cast<nlohmann::json(__fastcall*)(const glm::i64vec3 & vec)>(getFuncAddr((int)Func::m4::i64vec3ToJson))(vec);
		}
		inline nlohmann::json ivec4ToJson(const glm::ivec4& vec)
		{
			return reinterpret_cast<nlohmann::json(__fastcall*)(const glm::ivec4 & vec)>(getFuncAddr((int)Func::m4::ivec4ToJson))(vec);
		}
		//inline glm::ivec4 ivec4FromJson(const nlohmann::json& j)
		//{
		//	return reinterpret_cast<glm::ivec4(__fastcall*)(const nlohmann::json & j)>(FUNC_M4_IVEC4FROMJSON)(j);
		//}
		inline nlohmann::json vec4ToJson(const glm::vec4& vec)
		{
			return reinterpret_cast<nlohmann::json(__fastcall*)(const glm::vec4 & vec)>(getFuncAddr((int)Func::m4::vec4ToJson))(vec);
		}
		inline glm::vec4 vec4FromJson(const nlohmann::json& j)
		{
			return reinterpret_cast<glm::vec4(__fastcall*)(const nlohmann::json & j)>(getFuncAddr((int)Func::m4::vec4FromJson))(j);
		}

		inline void printMat5(const Mat5& m)
		{
			printf("%f;%f;%f;%f;%f;\n%f;%f;%f;%f;%f;\n%f;%f;%f;%f;%f;\n%f;%f;%f;%f;%f;\n%f;%f;%f;%f;%f;\n\n",
				m[0][0], m[0][1], m[0][2], m[0][3], m[0][4],
				m[1][0], m[1][1], m[1][2], m[1][3], m[1][4],
				m[2][0], m[2][1], m[2][2], m[2][3], m[2][4],
				m[3][0], m[3][1], m[3][2], m[3][3], m[3][4],
				m[4][0], m[4][1], m[4][2], m[4][3], m[4][4]);
		}
	}
}
