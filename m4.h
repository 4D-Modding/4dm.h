#pragma once

#include "4dm.h"

namespace fdm
{
	namespace m4
	{
		struct BiVector4
		{
			union { float b01 = 0, xy; };
			union { float b02 = 0, xz; };
			union { float b03 = 0, xw; };
			union { float b12 = 0, yz; };
			union { float b13 = 0, yw; };
			union { float b23 = 0, zw; };

			BiVector4() { }

			BiVector4(float b01, float b02, float b03, float b12, float b13, float b23) : b01(b01), b02(b02), b03(b03), b12(b12), b13(b13), b23(b23) { }

			BiVector4(const nlohmann::json& j)
			{
				reinterpret_cast<void(__thiscall*)(BiVector4*, const nlohmann::json & j)>(
					getFuncAddr((int)Func::m4::BiVector4::BiVector4A)
					)(this, j);
			}

			nlohmann::json toJson()
			{
				nlohmann::json result{};
				return reinterpret_cast<nlohmann::json&(__thiscall*)(m4::BiVector4 * self, nlohmann::json * result)>(getFuncAddr((int)Func::m4::BiVector4::toJson))(this, &result);
				return result;
			}

			void normalize()
			{
				float l = glm::sqrt((b01 * b01) + (b02 * b02) + (b03 * b03) + (b12 * b12) + (b13 * b13) + (b23 * b23));

				if (l == 0) return;

				b01 /= l;
				b02 /= l;
				b03 /= l;
				b12 /= l;
				b13 /= l;
				b23 /= l;
			}

			BiVector4 normalized() const
			{
				BiVector4 b = *this;
				b.normalize();
				return b;
			}

			constexpr bool operator==(const BiVector4& b) const
			{
				return xy == b.xy && xz == b.xz && xw == b.xw && yz == b.yz && yw == b.yw && zw == b.zw;
			}
		};
		inline glm::vec4 cross(const glm::vec4& u, const glm::vec4& v, const glm::vec4& w)
		{
			//  intermediate values
			float a = (v.x * w.y) - (v.y * w.x);
			float b = (v.x * w.z) - (v.z * w.x);
			float c = (v.x * w.w) - (v.w * w.x);
			float d = (v.y * w.z) - (v.z * w.y);
			float e = (v.y * w.w) - (v.w * w.y);
			float f = (v.z * w.w) - (v.w * w.z);

			// result vector
			glm::vec4 res;

			res.x = (u.y * f) - (u.z * e) + (u.w * d);
			res.y = -(u.x * f) + (u.z * c) - (u.w * b);
			res.z = (u.x * e) - (u.y * c) + (u.w * a);
			res.w = -(u.x * d) + (u.y * b) - (u.z * a);

			return res;
		}
		inline BiVector4 wedge(const glm::vec4& u, const glm::vec4& v)
		{
			BiVector4 result{};

			result.xy = u.x * v.y - u.y * v.x;
			result.xz = u.x * v.z - u.z * v.x;
			result.xw = u.x * v.w - u.w * v.x;
			result.yz = u.y * v.z - u.z * v.y;
			result.yw = u.y * v.w - u.w * v.y;
			result.zw = u.z * v.w - u.w * v.z;

			return result.normalized();
		}
		
		class Rotor
		{
		public:
			float a = 1;
			BiVector4 b{ };
			float b0123 = 0;
			Rotor() { }
			Rotor(const BiVector4& plane, float radians)
			{
				float cosHalf = glm::cos(radians * 0.5f);
				float sinHalf = glm::sin(radians * 0.5f);

				a = cosHalf;

				b.b01 = sinHalf * plane.b01;
				b.b02 = sinHalf * plane.b02;
				b.b03 = sinHalf * plane.b03;
				b.b12 = sinHalf * plane.b12;
				b.b13 = sinHalf * plane.b13;
				b.b23 = sinHalf * plane.b23;
			}
			Rotor(const glm::vec4& from, const glm::vec4& to)
			{
				float dot = glm::max(-1.0f, glm::min(1.0f, glm::dot(from, to)));
				if (dot == 1)
				{
					a = 1;
					b = {};
					return;
				}

				// calculate the half angle
				float radians = glm::acos(dot);
				a = glm::cos(radians / 2.f);
				float sina = glm::sin(radians / 2.f);
				// the left side of the products have b a, not a b, so flip
				b = wedge(to, from);
				b.b01 *= sina;
				b.b02 *= sina;
				b.b03 *= sina;
				b.b12 *= sina;
				b.b13 *= sina;
				b.b23 *= sina;

				normalize();
			}
			Rotor(float a, const BiVector4& b, float b0123) : a(a), b(b), b0123(b0123) { }
			Rotor operator*(const Rotor& r) const
			{
				Rotor result;

				result.a =
					(b.b01 * r.b.b01)
					+ (a * r.a)
					+ (b.b02 * r.b.b02)
					+ (b.b03 * r.b.b03)
					+ (b.b12 * r.b.b12)
					+ (b.b13 * r.b.b13)
					+ (b.b23 * r.b.b23)
					+ (b0123 * r.b0123);
				result.b.b01 =
					(result.a * r.b.b01)
					+ (b.b01 * r.a)
					- (b.b02 * r.b.b12)
					- (b.b03 * r.b.b13)
					+ (b.b12 * r.b.b02)
					+ (b.b13 * r.b.b03)
					- (b.b23 * r.b0123)
					- (b0123 * r.b.b23);
				result.b.b02 =
					(result.a * r.b.b02)
					+ (result.b.b01 * r.b.b12)
					+ (b.b02 * r.a)
					- (b.b03 * r.b.b23)
					- (b.b12 * r.b.b01)
					+ (b.b13 * r.b0123)
					+ (b.b23 * r.b.b03)
					+ (b0123 * r.b.b13);
				result.b.b03 =
					+(result.a * r.b.b03)
					+ (result.b.b01 * r.b.b13)
					+ (result.b.b02 * r.b.b23)
					+ (b.b03 * r.a)
					- (b.b12 * r.b0123)
					- (b.b13 * r.b.b01)
					- (b.b23 * r.b.b02)
					- (b0123 * r.b.b12);
				result.b.b12 =
					(result.a * r.b.b12)
					- (result.b.b01 * r.b.b02)
					+ (result.b.b02 * r.b.b01)
					- (result.b.b03 * r.b0123)
					+ (b.b12 * r.a)
					- (b.b13 * r.b.b23)
					+ (b.b23 * r.b.b13)
					- (b0123 * r.b.b03);
				result.b.b13 =
					(result.a * r.b.b13)
					- (result.b.b01 * r.b.b03)
					+ (result.b.b02 * r.b0123)
					+ (result.b.b03 * r.b.b01)
					+ (result.b.b12 * r.b.b23)
					+ (b.b13 * r.a)
					- (b.b23 * r.b.b12)
					+ (b0123 * r.b.b02);
				result.b.b23 =
					(result.a * r.b.b23)
					- (result.b.b01 * r.b0123)
					- (result.b.b02 * r.b.b03)
					+ (result.b.b03 * r.b.b02)
					- (result.b.b12 * r.b.b13)
					+ (result.b.b13 * r.b.b12)
					+ (b.b23 * r.a)
					- (b0123 * r.b.b01);
				result.b0123 =
					(result.a * r.b.b23)
					+ (result.b.b01 * r.b0123)
					- (result.b.b02 * r.b.b13)
					+ (result.b.b03 * r.b.b12)
					+ (result.b.b12 * r.b.b03)
					- (result.b.b13 * r.b.b02)
					+ (result.b.b23 * r.b.b01)
					+ (b0123 * r.a);

				return result;
			}
			Rotor& operator*=(const Rotor& r)
			{
				Rotor result = *this * r;

				*this = result;

				return *this;
			}
			glm::vec4 rotate(const glm::vec4& v) const
			{
				glm::vec4 result{ 0 };

				float xyz = b.xy * v.z - b.xz * v.y + b.yz * v.x + b0123 * v.w;
				float xyw = -b.xw * v.y + b.xy * v.w + b.yw * v.x + -b0123 * v.z;
				float xzw = -b.xw * v.z + b.xz * v.w + b.zw * v.x + b0123 * v.y;
				float yzw = -b.yw * v.z + b.yz * v.w + b.zw * v.y + -b0123 * v.x;

				float sX = a * v.x + b.xw * v.w + b.xy * v.y + b.xz * v.z;
				float sY = a * v.y + -b.xy * v.x + b.yw * v.w + b.yz * v.z;
				float sZ = a * v.z + -b.xz * v.x - b.yz * v.y + b.zw * v.w;
				float sW = a * v.w + -b.xw * v.x - b.yw * v.y - b.zw * v.z;

				result.x = a * sX + (-sY * -b.xy - sZ * -b.xz - sW * -b.xw) + (b.yw * xyw + b.yz * xyz + b.zw * xzw) + (b0123 * yzw);
				result.y = a * sY + (sX * -b.xy - sZ * -b.yz - sW * -b.yw) + (-b.xw * xyw - b.xz * xyz + b.zw * yzw) + (-b0123 * xzw);
				result.z = a * sZ + (sX * -b.xz + sY * -b.yz - sW * -b.zw) + (-b.xw * xzw + b.xy * xyz - b.yw * yzw) + (b0123 * xyw);
				result.w = a * sW + (sX * -b.xw + sY * -b.yw + sZ * -b.zw) + (b.xy * xyw + b.xz * xzw + b.yz * yzw) + (-b0123 * xyz);

				return result;
			}
			void normalize()
			{
				float l = glm::sqrt(a * a + b.xy * b.xy + b.xz * b.xz + b.xw * b.xw +
					b.yz * b.yz + b.yw * b.yw + b.zw * b.zw + b0123 * b0123);

				if (l == 0) return;

				a /= l;
				b.xy /= l;
				b.xz /= l;
				b.xw /= l;
				b.yz /= l;
				b.yw /= l;
				b.zw /= l;
				b0123 /= l;
			}

			Rotor normalized() const
			{
				Rotor r = *this;
				r.normalize();
				return r;
			}
		};
		class Mat5
		{
		public:
			float value[5][5] = { 0.f };
			Mat5(float x = 0.f)
			{
				value[0][0] = value[1][1] = value[2][2] = value[3][3] = value[4][4] = x;
			}
			Mat5(nlohmann::json& j)
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, nlohmann::json&)>(
					getFuncAddr((int)Func::m4::Mat5::Mat5A)
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
			nlohmann::json toJson() const
			{
				nlohmann::json result{};
				return reinterpret_cast<nlohmann::json&(__thiscall*)(const m4::Mat5* self, nlohmann::json* result)>(getFuncAddr((int)Func::m4::Mat5::toJson))(this, &result);
				return result;
			}
			inline static Mat5 identity()
			{
				return { 1 };
			}
			Mat5 operator*(const Mat5& other) const
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

				std::memcpy(&value[0][0], &result.value[0][0], sizeof(value));

				return *this;
			}
			glm::vec4 multiply(const glm::vec4& v, float finalComp) const
			{
				glm::vec4 result;
				for (int row = 0; row < 4; ++row)
				{
					result[row] = 0;
					for (int col = 0; col < 5; ++col)
					{
						result[row] += value[col][row] * v[col];
					}
				}
				return result;
			}
			glm::vec4 operator*(const glm::vec4& v) const
			{
				return multiply(v, 1.0f);
			}
			void translate(const glm::vec4& v)
			{
				value[4][0] += (value[0][0] * v.x) + (value[1][0] * v.y) + (value[2][0] * v.z) + (value[3][0] * v.w);
				value[4][1] += (value[0][1] * v.x) + (value[1][1] * v.y) + (value[2][1] * v.z) + (value[3][1] * v.w);
				value[4][2] += (value[0][2] * v.x) + (value[1][2] * v.y) + (value[2][2] * v.z) + (value[3][2] * v.w);
				value[4][3] += (value[0][3] * v.x) + (value[1][3] * v.y) + (value[2][3] * v.z) + (value[3][3] * v.w);
			}
			void scale(const glm::vec4& s)
			{
				for (int row = 0; row < 5; ++row)
					for (int col = 0; col < 4; ++col)
						value[col][row] *= s[col];
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

		//inline nlohmann::json i64vec3ToJson(const glm::i64vec3& vec)
		//{
		//	return reinterpret_cast<nlohmann::json(__fastcall*)(const glm::i64vec3 & vec)>(getFuncAddr((int)Func::m4::i64vec3ToJson))(vec);
		//}
		//inline nlohmann::json ivec4ToJson(const glm::ivec4& vec)
		//{
		//	return reinterpret_cast<nlohmann::json(__fastcall*)(const glm::ivec4 & vec)>(getFuncAddr((int)Func::m4::ivec4ToJson))(vec);
		//}
		//inline glm::ivec4 ivec4FromJson(const nlohmann::json& j)
		//{
		//	return reinterpret_cast<glm::ivec4(__fastcall*)(const nlohmann::json & j)>(FUNC_M4_IVEC4FROMJSON)(j);
		//}
		//inline nlohmann::json vec4ToJson(const glm::vec4& vec)
		//{
		//	return reinterpret_cast<nlohmann::json(__fastcall*)(const glm::vec4 & vec)>(getFuncAddr((int)Func::m4::vec4ToJson))(vec);
		//}
		//inline glm::vec4 vec4FromJson(const nlohmann::json& j)
		//{
		//	return reinterpret_cast<glm::vec4(__fastcall*)(const nlohmann::json & j)>(getFuncAddr((int)Func::m4::vec4FromJson))(j);
		//}
		template<typename T>
		inline nlohmann::json vec3ToJson(const glm::vec<3, T>& v)
		{
			return nlohmann::json{ v.x, v.y, v.z };
		}
		template<typename T>
		inline nlohmann::json vec4ToJson(const glm::vec<4, T>& v)
		{
			return nlohmann::json{ v.x, v.y, v.z, v.w };
		}
		template<typename T>
		inline glm::vec<3, T> vec3FromJson(const nlohmann::json& j)
		{
			return glm::vec<3, T>{ j[0].get<T>(), j[1].get<T>(), j[2].get<T>() };
		}
		template<typename T>
		inline glm::vec<4, T> vec4FromJson(const nlohmann::json& j)
		{
			return glm::vec<4, T>{ j[0].get<T>(), j[1].get<T>(), j[2].get<T>(), j[3].get<T>() };
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
