#pragma once

#include "4dm.h"
#include "vec5.h"

namespace fdm
{
	namespace m4
	{
		struct BiVector4;

		float dot(const BiVector4& a, const BiVector4& b);
		glm::vec4 cross(const glm::vec4& u, const glm::vec4& v, const glm::vec4& w);
		BiVector4 wedge(const glm::vec4& u, const glm::vec4& v);
		BiVector4 normalize(const BiVector4& v);
		float length(const BiVector4& v);
		float length2(const BiVector4& v);

		struct BiVector4
		{
			union { float b01 = 0, xy; };
			union { float b02 = 0, xz; };
			union { float b03 = 0, xw; };
			union { float b12 = 0, yz; };
			union { float b13 = 0, yw; };
			union { float b23 = 0, zw; };

			BiVector4() {}
			BiVector4(float v)
				: xy(v), xz(v), xw(v), yz(v), yw(v), zw(v) {
			}
			BiVector4(float xy, float xz, float xw, float yz, float yw, float zw)
				: xy(xy), xz(xz), xw(xw), yz(yz), yw(yw), zw(zw) {
			}

			BiVector4(const BiVector4& other)
				: xy(other.xy), xz(other.xz), xw(other.xw), yz(other.yz), yw(other.yw), zw(other.zw) {
			}
			BiVector4(BiVector4&& other) noexcept
				: xy(other.xy), xz(other.xz), xw(other.xw), yz(other.yz), yw(other.yw), zw(other.zw)
			{
				other.xy = 0;
				other.xz = 0;
				other.xw = 0;
				other.yz = 0;
				other.yw = 0;
				other.zw = 0;
			}
			BiVector4& operator=(const BiVector4& other)
			{
				this->xy = other.xy;
				this->xz = other.xz;
				this->xw = other.xw;
				this->yz = other.yz;
				this->yw = other.yw;
				this->zw = other.zw;

				return *this;
			}
			BiVector4& operator=(BiVector4&& other) noexcept
			{
				if (this != &other)
				{
					this->xy = other.xy;
					this->xz = other.xz;
					this->xw = other.xw;
					this->yz = other.yz;
					this->yw = other.yw;
					this->zw = other.zw;
					other.xy = 0;
					other.xz = 0;
					other.xw = 0;
					other.yz = 0;
					other.yw = 0;
					other.zw = 0;
				}

				return *this;
			}

			float& operator[](size_t i)
			{
				assert(i < 6);

				return (&xy)[i];
			}
			const float& operator[](size_t i) const
			{
				assert(i < 6);

				return (&xy)[i];
			}

			BiVector4 operator+(const BiVector4& other) const
			{
				return BiVector4
				{
					this->xy + other.xy,
					this->xz + other.xz,
					this->xw + other.xw,
					this->yz + other.yz,
					this->yw + other.yw,
					this->zw + other.zw
				};
			}
			BiVector4 operator+(float v) const
			{
				return BiVector4
				{
					this->xy + v,
					this->xz + v,
					this->xw + v,
					this->yz + v,
					this->yw + v,
					this->zw + v
				};
			}
			BiVector4 operator-(const BiVector4& other) const
			{
				return BiVector4
				{
					this->xy - other.xy,
					this->xz - other.xz,
					this->xw - other.xw,
					this->yz - other.yz,
					this->yw - other.yw,
					this->zw - other.zw
				};
			}
			BiVector4 operator-(float v) const
			{
				return BiVector4
				{
					this->xy - v,
					this->xz - v,
					this->xw - v,
					this->yz - v,
					this->yw - v,
					this->zw - v
				};
			}
			BiVector4 operator-() const
			{
				return BiVector4
				{
					-this->xy,
					-this->xz,
					-this->xw,
					-this->yz,
					-this->yw,
					-this->zw
				};
			}
			BiVector4 operator*(const BiVector4& other) const
			{
				return BiVector4
				{
					this->xy * other.xy,
					this->xz * other.xz,
					this->xw * other.xw,
					this->yz * other.yz,
					this->yw * other.yw,
					this->zw * other.zw
				};
			}
			BiVector4 operator*(float v) const
			{
				return BiVector4
				{
					this->xy * v,
					this->xz * v,
					this->xw * v,
					this->yz * v,
					this->yw * v,
					this->zw * v
				};
			}
			BiVector4 operator/(const BiVector4& other) const
			{
				return BiVector4
				{
					this->xy / other.xy,
					this->xz / other.xz,
					this->xw / other.xw,
					this->yz / other.yz,
					this->yw / other.yw,
					this->zw / other.zw
				};
			}
			BiVector4 operator/(float v) const
			{
				float invV = 1.0f / v;
				return BiVector4
				{
					this->xy * invV,
					this->xz * invV,
					this->xw * invV,
					this->yz * invV,
					this->yw * invV,
					this->zw * invV
				};
			}

			BiVector4& operator+=(const BiVector4& other)
			{
				return *this = *this + other;
			}
			BiVector4& operator+=(float v)
			{
				return *this = *this + v;
			}
			BiVector4& operator-=(const BiVector4& other)
			{
				return *this = *this - other;
			}
			BiVector4& operator-=(float v)
			{
				return *this = *this - v;
			}
			BiVector4& operator*=(const BiVector4& other)
			{
				return *this = *this * other;
			}
			BiVector4& operator*=(float v)
			{
				return *this = *this * v;
			}
			BiVector4& operator/=(const BiVector4& other)
			{
				return *this = *this / other;
			}
			BiVector4& operator/=(float v)
			{
				return *this = *this / v;
			}

			bool operator==(const BiVector4& other) const
			{
				return this->xy == other.xy && this->xz == other.xz && this->xw == other.xw && this->yz == other.yz && this->yw == other.yw && this->zw == other.zw;
			}

			BiVector4 normalized() const
			{
				BiVector4 v = *this;
				v.normalize();
				return v;
			}
			BiVector4& normalize()
			{
				float len = length2(*this);
				if (len <= glm::epsilon<float>() * glm::epsilon<float>())
				{
					return *this;
				}
				return *this /= glm::sqrt(len);
			}

			inline static BiVector4 XY() { return BiVector4{ 1,0,0,0,0,0 }; }
			inline static BiVector4 XZ() { return BiVector4{ 0,1,0,0,0,0 }; }
			inline static BiVector4 XW() { return BiVector4{ 0,0,1,0,0,0 }; }
			inline static BiVector4 YZ() { return BiVector4{ 0,0,0,1,0,0 }; }
			inline static BiVector4 YW() { return BiVector4{ 0,0,0,0,1,0 }; }
			inline static BiVector4 ZW() { return BiVector4{ 0,0,0,0,0,1 }; }

			BiVector4(const nlohmann::json& j)
				: BiVector4(j.at(0).get<float>(), j.at(1).get<float>(), j.at(2).get<float>(), j.at(3).get<float>(), j.at(4).get<float>(), j.at(5).get<float>())
			{}

			nlohmann::json toJson()
			{
				return { xy, xz, xw, yz, yw, zw };
			}
		};

		inline float dot(const BiVector4& a, const BiVector4& b)
		{
			return a.xy * b.xy + a.xz * b.xz + a.xw * b.xw + a.yz * b.yz + a.yw * b.yw + a.zw * b.zw;
		}
		inline glm::vec4 cross(const glm::vec4& u, const glm::vec4& v, const glm::vec4& w)
		{
			// intermediate values
			float a = (v.x * w.y) - (v.y * w.x);
			float b = (v.x * w.z) - (v.z * w.x);
			float c = (v.x * w.w) - (v.w * w.x);
			float d = (v.y * w.z) - (v.z * w.y);
			float e = (v.y * w.w) - (v.w * w.y);
			float f = (v.z * w.w) - (v.w * w.z);

			return glm::vec4
			{
				(u.y * f) - (u.z * e) + (u.w * d),
				-(u.x * f) + (u.z * c) - (u.w * b),
				(u.x * e) - (u.y * c) + (u.w * a),
				-(u.x * d) + (u.y * b) - (u.z * a)
			};
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
		inline BiVector4 normalize(const BiVector4& v)
		{
			return v.normalized();
		}
		inline float length(const BiVector4& v)
		{
			return glm::sqrt(length2(v));
		}
		inline float length2(const BiVector4& v)
		{
			return dot(v, v);
		}

		struct Rotor;

		Rotor normalize(const Rotor& v);
		float length(const Rotor& v);
		float length2(const Rotor& v);

		struct Rotor
		{
			float a = 1;
			BiVector4 b = 0.0f;
			float b0123 = 0.0f;

			Rotor() { }
			Rotor(float a, BiVector4 b, float xyzw)
				: a(a), b(b), b0123(xyzw) {
			}
			Rotor(const BiVector4& plane, float radians)
			{
				float cosHalf = glm::cos(radians * 0.5f);
				float sinHalf = -glm::sin(radians * 0.5f);

				a = cosHalf;

				b = plane;
				b *= sinHalf;
			}
			Rotor(const glm::vec4& from, const glm::vec4& to)
			{
				float dot = glm::clamp(glm::dot(from, to), -1.0f, 1.0f);
				if (dot >= 1.0f - glm::epsilon<float>())
				{
					return;
				}

				// calculate the half angle
				float radians = glm::acos(dot);
				a = glm::cos(radians / 2.f);
				float sina = glm::sin(radians / 2.f);
				// the left side of the products have b a, not a b, so flip
				b = wedge(to, from);
				b *= sina;

				normalize();
			}
			Rotor(const BiVector4& u, const BiVector4& v)
			{
				a =
					- u.xy * v.xy
					- u.xz * v.xz
					- u.xw * v.xw
					- u.yz * v.yz
					- u.yw * v.yw
					- u.zw * v.zw;

				b = BiVector4
				{
					-u.xw * v.yw - u.xz * v.yz + u.yw * v.xw + u.yz * v.xz,
					-u.xw * v.zw + u.xy * v.yz - u.yz * v.xy + u.zw * v.xw,
					+u.xy * v.yw + u.xz * v.zw - u.yw * v.xy - u.zw * v.xz,
					-u.xy * v.xz + u.xz * v.xy - u.yw * v.zw + u.zw * v.yw,
					+u.xw * v.xy - u.xy * v.xw + u.yz * v.zw - u.zw * v.yz,
					+u.xw * v.xz - u.xz * v.xw + u.yw * v.yz - u.yz * v.yw
				};

				b0123 =
					+ u.xw * v.yz
					+ u.xy * v.zw
					- u.xz * v.yw
					- u.yw * v.xz
					+ u.yz * v.xw
					+ u.zw * v.xy;
			}

			Rotor(const Rotor& other)
				: a(other.a), b(other.b), b0123(other.b0123) {
			}
			Rotor(Rotor&& other) noexcept
				: a(other.a), b(other.b), b0123(other.b0123)
			{
				other.a = 1.0f;
				other.b = 0.0f;
				other.b0123 = 0.0f;
			}
			Rotor& operator=(const Rotor& other)
			{
				this->a = other.a;
				this->b = other.b;
				this->b0123 = other.b0123;

				return *this;
			}
			Rotor& operator=(Rotor&& other) noexcept
			{
				if (this != &other)
				{
					this->a = other.a;
					this->b = other.b;
					this->b0123 = other.b0123;
					other.a = 1.0f;
					other.b = 0.0f;
					other.b0123 = 0.0f;
				}

				return *this;
			}

			Rotor operator-() const
			{
				return Rotor{ a, -b, b0123 };
			}
			bool operator==(const Rotor& other) const
			{
				return this->a == other.a && this->b == other.b && this->b0123 == other.b0123;
			}

			Rotor operator*(const Rotor& r) const
			{
				Rotor result{ this->b, r.b };

				result.a +=
					r.a * this->a +
					r.b0123 * this->b0123;
				result.b +=
					r.b * this->a +
					this->b * r.a +
					BiVector4 // r.b * this->xyzw
				{
					-r.b.zw * this->b0123,
					+r.b.yw * this->b0123,
					-r.b.yz * this->b0123,
					-r.b.xw * this->b0123,
					+r.b.xz * this->b0123,
					-r.b.xy * this->b0123,
				} +
				BiVector4 // this->b * r.xyzw
				{
					-this->b.zw * r.b0123,
					+this->b.yw * r.b0123,
					-this->b.yz * r.b0123,
					-this->b.xw * r.b0123,
					+this->b.xz * r.b0123,
					-this->b.xy * r.b0123,
				};
				result.b0123 +=
					this->a * r.b0123 +
					r.a * this->b0123;

				return result;
			}
			Rotor& operator*=(const Rotor& r)
			{
				return *this = *this * r;
			}
			glm::vec4 rotate(const glm::vec4& v) const
			{
				float xyz = b.xy * v.z - b.xz * v.y + b.yz * v.x + b0123 * v.w;
				float xyw = -b.xw * v.y + b.xy * v.w + b.yw * v.x + -b0123 * v.z;
				float xzw = -b.xw * v.z + b.xz * v.w + b.zw * v.x + b0123 * v.y;
				float yzw = -b.yw * v.z + b.yz * v.w + b.zw * v.y + -b0123 * v.x;

				float sX = a * v.x + b.xw * v.w + b.xy * v.y + b.xz * v.z;
				float sY = a * v.y + -b.xy * v.x + b.yw * v.w + b.yz * v.z;
				float sZ = a * v.z + -b.xz * v.x - b.yz * v.y + b.zw * v.w;
				float sW = a * v.w + -b.xw * v.x - b.yw * v.y - b.zw * v.z;

				return glm::vec4
				{
					a * sX + (-sY * -b.xy - sZ * -b.xz - sW * -b.xw) + (b.yw * xyw + b.yz * xyz + b.zw * xzw) + (b0123 * yzw),
					a * sY + (sX * -b.xy - sZ * -b.yz - sW * -b.yw) + (-b.xw * xyw - b.xz * xyz + b.zw * yzw) + (-b0123 * xzw),
					a * sZ + (sX * -b.xz + sY * -b.yz - sW * -b.zw) + (-b.xw * xzw + b.xy * xyz - b.yw * yzw) + (b0123 * xyw),
					a * sW + (sX * -b.xw + sY * -b.yw + sZ * -b.zw) + (b.xy * xyw + b.xz * xzw + b.yz * yzw) + (-b0123 * xyz)
				};
			}

			Rotor& normalize()
			{
				float len = length2(*this);
				if (len <= glm::epsilon<float>() * glm::epsilon<float>())
				{
					return *this;
				}
				len = 1.0f / glm::sqrt(len);
				this->a *= len;
				this->b *= len;
				this->b0123 *= len;

				return *this;
			}

			Rotor normalized() const
			{
				Rotor r = *this;
				r.normalize();
				return r;
			}

			operator glm::mat4() const
			{
				return glm::mat4
				{
					rotate({ 1, 0, 0, 0 }),
					rotate({ 0, 1, 0, 0 }),
					rotate({ 0, 0, 1, 0 }),
					rotate({ 0, 0, 0, 1 })
				};
			}
		};
		inline Rotor normalize(const Rotor& v)
		{
			return v.normalized();
		}
		inline float length(const Rotor& v)
		{
			return glm::sqrt(length2(v));
		}
		inline float length2(const Rotor& v)
		{
			return v.a * v.a + length2(v.b) + v.b0123 * v.b0123;
		}

		class Mat5
		{
		public:
			std::array<vec5, 5> value
			{
				vec5{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
				vec5{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
				vec5{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
				vec5{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
				vec5{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }
			};

			Mat5(float x = 0.0f)
			{
				value[0][0] =
				value[1][1] =
				value[2][2] =
				value[3][3] =
				value[4][4] = x;
			}
			Mat5(const glm::mat4& m)
			{
				value[0] = m[0];
				value[1] = m[1];
				value[2] = m[2];
				value[3] = m[3];
				value[4][4] = 1.0f;
			}
			Mat5(const Rotor& r)
				: Mat5((glm::mat4)r) {
			}
			Mat5(const std::array<vec5, 5>& value)
				: value(value)
			{
			}
			Mat5(const vec5& m0, const vec5& m1, const vec5& m2, const vec5& m3, const vec5& m4)
			{
				value[0] = m0;
				value[1] = m1;
				value[2] = m2;
				value[3] = m3;
				value[4] = m4;
			}
			Mat5(const nlohmann::json& j)
			{
				reinterpret_cast<void(__thiscall*)(Mat5*, const nlohmann::json&)>(
					getFuncAddr((int)Func::m4::Mat5::Mat5A)
					)(this, j);
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
			Mat5(const Mat5& other)
			{
				this->value = other.value;
			}
			Mat5(Mat5&& other) noexcept
			{
				this->value = std::move(other.value);
			}
			Mat5& operator=(const Mat5& other)
			{
				this->value = other.value;

				return *this;
			}
			Mat5& operator=(Mat5&& other) noexcept
			{
				this->value = std::move(other.value);

				return *this;
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
				return *this = *this * other;
			}

			vec5 multiply(const vec5& v) const
			{
				return vec5
				{
					value[0][0] * v[0] + value[1][0] * v[1] + value[2][0] * v[2] + value[3][0] * v[3] + value[4][0] * v[4],
					value[0][1] * v[0] + value[1][1] * v[1] + value[2][1] * v[2] + value[3][1] * v[3] + value[4][1] * v[4],
					value[0][2] * v[0] + value[1][2] * v[1] + value[2][2] * v[2] + value[3][2] * v[3] + value[4][2] * v[4],
					value[0][3] * v[0] + value[1][3] * v[1] + value[2][3] * v[2] + value[3][3] * v[3] + value[4][3] * v[4],
					value[0][4] * v[0] + value[1][4] * v[1] + value[2][4] * v[2] + value[3][4] * v[3] + value[4][4] * v[4]
				};
			}
			glm::vec4 multiply(const glm::vec4& v, float finalComp = 1.0f) const
			{
				return multiply(vec5{ v, finalComp }).xyzw();
			}
			vec5 operator*(const vec5& v) const
			{
				return multiply(v);
			}
			glm::vec4 operator*(const glm::vec4& v) const
			{
				return multiply(v, 1.0f);
			}

			// me when compatibility with old code:
			//vec5& operator[](size_t i)
			//{
			//	assert(i < 5);
			//
			//	return value[i];
			//}
			//const vec5& operator[](size_t i) const
			//{
			//	assert(i < 5);
			//
			//	return value[i];
			//}
			float* operator[](size_t i)
			{
				assert(i < 5);

				return &value[i][0];
			}
			const float* operator[](size_t i) const
			{
				assert(i < 5);

				return &value[i][0];
			}
			vec5& at(size_t i)
			{
				assert(i < 5);

				return value[i];
			}
			const vec5& at(size_t i) const
			{
				assert(i < 5);

				return value[i];
			}
			// why multiple names for the same function? idk. felt like it

			vec5& get(size_t i)
			{
				return at(i);
			}
			const vec5& get(size_t i) const
			{
				return at(i);
			}

			void translate(const glm::vec4& v)
			{
				value[4][0] += (value[0][0] * v.x) + (value[1][0] * v.y) + (value[2][0] * v.z) + (value[3][0] * v.w);
				value[4][1] += (value[0][1] * v.x) + (value[1][1] * v.y) + (value[2][1] * v.z) + (value[3][1] * v.w);
				value[4][2] += (value[0][2] * v.x) + (value[1][2] * v.y) + (value[2][2] * v.z) + (value[3][2] * v.w);
				value[4][3] += (value[0][3] * v.x) + (value[1][3] * v.y) + (value[2][3] * v.z) + (value[3][3] * v.w);
			}
			void translate(float x, float y, float z, float w)
			{
				translate({ x,y,z,w });
			}
			void translate(float a)
			{
				translate(a, a, a, a);
			}
			void scale(const glm::vec4& s)
			{
				for (int row = 0; row < 5; ++row)
					for (int col = 0; col < 4; ++col)
						value[col][row] *= s[col];
			}
			void scale(float x, float y, float z, float w)
			{
				scale({ x,y,z,w });
			}
			void scale(float s)
			{
				scale(s, s, s, s);
			}

			inline static Mat5 transpose(const Mat5& m)
			{
				return Mat5
				{
					{ m[0][0],m[1][0],m[2][0],m[3][0],m[4][0] },
					{ m[0][1],m[1][1],m[2][1],m[3][1],m[4][1] },
					{ m[0][2],m[1][2],m[2][2],m[3][2],m[4][2] },
					{ m[0][3],m[1][3],m[2][3],m[3][3],m[4][3] },
					{ m[0][4],m[1][4],m[2][4],m[3][4],m[4][4] }
				};
			}
			inline static Mat5 inverse(const Mat5& m)
			{
				Mat5 s{ 1 };
				Mat5 t{ m };

				// Forward elimination
				for (int i = 0; i < 5 - 1; ++i)
				{
					int pivot = i;
					float pivotsize = t[i][i];

					for (int j = i + 1; j < 5; ++j)
					{
						float tmp = t[j][i];
						if (fabs(tmp) > fabs(pivotsize))
						{
							pivotsize = tmp;
							pivot = j;
						}
					}

					if (pivotsize == 0.0f) return s;

					if (pivot != i)
					{
						for (int j = 0; j < 5; ++j)
						{
							float tmp;
							tmp = t[i][j];
							t[i][j] = t[pivot][j];
							t[pivot][j] = tmp;
							tmp = s[i][j];
							s[i][j] = s[pivot][j];
							s[pivot][j] = tmp;
						}
					}

					for (int j = i + 1; j < 5; ++j)
					{
						float f = t[j][i] / t[i][i];
						for (int k = i + 1; k < 5; ++k)
						{
							t[j][k] -= f * t[i][k];
						}
						for (int k = 0; k < 5; ++k)
						{
							s[j][k] -= f * s[i][k];
						}
						t[j][i] = 0.0f;
					}
				}

				// Backward substitution
				for (int i = 0; i < 5; ++i)
				{
					float f = t[i][i];
					if (f == 0.0f) return Mat5{ 1 };

					for (int j = 0; j < 5; ++j)
					{
						t[i][j] /= f;
						s[i][j] /= f;
					}

					for (int j = 0; j < i; ++j)
					{
						f = t[j][i];
						for (int k = 0; k < 5; ++k)
						{
							t[j][k] -= f * t[i][k];
							s[j][k] -= f * s[i][k];
						}
					}
				}

				return s;
			}

			operator glm::mat4() const
			{
				return glm::mat4
				{
					value[0].xyzw(),
					value[1].xyzw(),
					value[2].xyzw(),
					value[3].xyzw()
				};
			}
		};

		inline Mat5 transpose(const Mat5& m) { return Mat5::transpose(m); }
		inline Mat5 inverse(const Mat5& m) { return Mat5::inverse(m); }

		inline Mat5 createCamera(const glm::vec4& eye, const glm::vec4& forward, const glm::vec4& up, const glm::vec4& right, const glm::vec4& over)
		{
			Mat5 result;

			return reinterpret_cast<Mat5 & (__fastcall*)(Mat5*, const glm::vec4 & eye, const glm::vec4 & forward, const glm::vec4 & up, const glm::vec4 & right, const glm::vec4 & over)>(
				getFuncAddr((int)Func::m4::createCamera)
				)(&result, eye, forward, up, right, over);
			return result;

			/*
			Mat5 cameraD{ -right, up, forward, over, {} };
			cameraD = Mat5::transpose(cameraD);

			Mat5 cameraP{ {}, {}, {}, {}, -eye };

			return cameraD * cameraP;
			*/
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
		inline nlohmann::json vec2ToJson(const glm::vec<2, T>& v)
		{
			return nlohmann::json{ v.x, v.y };
		}
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
		inline glm::vec<2, T> vec2FromJson(const nlohmann::json& j)
		{
			return glm::vec<2, T>{ j[0].get<T>(), j[1].get<T>() };
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

		template<glm::length_t L, typename T>
		inline glm::vec<L, T> safeNormalize(const glm::vec<L, T>& v)
		{
			T len = glm::dot(v, v);
			if (len <= glm::epsilon<T>() * glm::epsilon<T>())
			{
				return glm::vec<L, T>{};
			}
			return v / glm::sqrt(len);
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
