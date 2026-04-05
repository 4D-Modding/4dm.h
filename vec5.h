#pragma once

#include <stdexcept>
#include <cstdint>
#include <cstdlib>
#include "glm/glm.hpp"
#include "json.hpp"

namespace fdm
{
	namespace m4
	{
		template<typename T = float>
		struct Tvec5
		{
			inline static constexpr size_t size = 5;

			union { T x{}; };
			union { T y{}; };
			union { T z{}; };
			union { T w{}; };
			union { T v{}; };

			Tvec5() {}
			template<typename T2 = T>
			Tvec5(T2 v)
				: x((T)v), y((T)v), z((T)v), w((T)v), v((T)v) {
			}
			template<typename T2 = T>
			Tvec5(T2 x, T2 y, T2 z, T2 w, T2 v)
				: x((T)x), y((T)y), z((T)z), w((T)w), v((T)v) {
			}
			template<typename T2 = T>
			Tvec5(const glm::vec<4, T2>& xyzw, T2 v = {})
				: x((T)xyzw.x), y((T)xyzw.y), z((T)xyzw.z), w((T)xyzw.w), v((T)v) {
			}

			template<typename T2 = T>
			Tvec5(const Tvec5<T2>& other)
				: x((T)other.x), y((T)other.y), z((T)other.z), w((T)other.w), v((T)other.v) {
			}
			template<typename T2 = T>
			Tvec5(Tvec5<T2>&& other) noexcept
				: x((T)other.x), y((T)other.y), z((T)other.z), w((T)other.w), v((T)other.v)
			{
				other.x = {};
				other.y = {};
				other.z = {};
				other.w = {};
				other.v = {};
			}
			template<typename T2 = T>
			Tvec5<T>& operator=(const Tvec5<T2>& other)
			{
				this->x = (T)other.x;
				this->y = (T)other.y;
				this->z = (T)other.z;
				this->w = (T)other.w;
				this->v = (T)other.v;

				return *this;
			}
			template<typename T2 = T>
			Tvec5<T>& operator=(Tvec5<T2>&& other) noexcept
			{
				if (this != &other)
				{
					this->x = (T)other.x;
					this->y = (T)other.y;
					this->z = (T)other.z;
					this->w = (T)other.w;
					this->v = (T)other.v;
					other.x = {};
					other.y = {};
					other.z = {};
					other.w = {};
					other.v = {};
				}

				return *this;
			}

			T& operator[](size_t i)
			{
				assert(i < size);
				return (&x)[i];
			}
			const T& operator[](size_t i) const
			{
				assert(i < size);
				return (&x)[i];
			}

			template<typename T2 = T>
			Tvec5<T> operator+(const Tvec5<T2>& other) const
			{
				return Tvec5<T>
				{
					this->x + (T)other.x,
					this->y + (T)other.y,
					this->z + (T)other.z,
					this->w + (T)other.w,
					this->v + (T)other.v,
				};
			}
			template<typename T2 = T>
			Tvec5<T> operator+(T2 v) const
			{
				return Tvec5<T>
				{
					this->x + (T)v,
					this->y + (T)v,
					this->z + (T)v,
					this->w + (T)v,
					this->v + (T)v,
				};
			}
			template<typename T2 = T>
			Tvec5<T> operator-(const Tvec5<T2>& other) const
			{
				return Tvec5<T>
				{
					this->x - (T)other.x,
					this->y - (T)other.y,
					this->z - (T)other.z,
					this->w - (T)other.w,
					this->v - (T)other.v,
				};
			}
			template<typename T2 = T>
			Tvec5<T> operator-(T2 v) const
			{
				return Tvec5<T>
				{
					this->x - (T)v,
					this->y - (T)v,
					this->z - (T)v,
					this->w - (T)v,
					this->v - (T)v,
				};
			}
			Tvec5<T> operator-() const
			{
				return Tvec5<T>
				{
					-this->x,
					-this->y,
					-this->z,
					-this->w,
					-this->v,
				};
			}
			template<typename T2 = T>
			Tvec5<T> operator*(const Tvec5<T2>& other) const
			{
				return Tvec5<T>
				{
					this->x * (T)other.x,
					this->y * (T)other.y,
					this->z * (T)other.z,
					this->w * (T)other.w,
					this->v * (T)other.v,
				};
			}
			template<typename T2 = T>
			Tvec5<T> operator*(T2 v) const
			{
				return Tvec5<T>
				{
					this->x * (T)v,
					this->y * (T)v,
					this->z * (T)v,
					this->w * (T)v,
					this->v * (T)v,
				};
			}
			template<typename T2 = T>
			Tvec5<T> operator/(const Tvec5<T2>& other) const
			{
				return Tvec5<T>
				{
					this->x / (T)other.x,
					this->y / (T)other.y,
					this->z / (T)other.z,
					this->w / (T)other.w,
					this->v / (T)other.v,
				};
			}
			template<typename T2 = T>
			Tvec5<T> operator/(T2 v) const
			{
				double invV = 1.0 / v;
				return Tvec5<T>
				{
					this->x * invV,
					this->y * invV,
					this->z * invV,
					this->w * invV,
					this->v * invV,
				};
			}

			template<typename T2 = T>
			Tvec5<T>& operator+=(const Tvec5<T2>& other)
			{
				return *this = *this + other;
			}
			template<typename T2 = T>
			Tvec5<T>& operator+=(T2 v)
			{
				return *this = *this + v;
			}
			template<typename T2 = T>
			Tvec5<T>& operator-=(const Tvec5<T2>& other)
			{
				return *this = *this - other;
			}
			template<typename T2 = T>
			Tvec5<T>& operator-=(T2 v)
			{
				return *this = *this - v;
			}
			template<typename T2 = T>
			Tvec5<T>& operator*=(const Tvec5<T>& other)
			{
				return *this = *this * other;
			}
			template<typename T2 = T>
			Tvec5<T>& operator*=(T2 v)
			{
				return *this = *this * v;
			}
			template<typename T2 = T>
			Tvec5<T>& operator/=(const Tvec5<T2>& other)
			{
				return *this = *this / other;
			}
			template<typename T2 = T>
			Tvec5<T>& operator/=(T2 v)
			{
				return *this = *this / v;
			}

			template<typename T2 = T>
			bool operator==(const Tvec5<T2>& other) const
			{
				return this->x == (T)other.x && this->y == (T)other.y && this->z == (T)other.z && this->w == (T)other.w && this->v == (T)other.v;
			}

			template<typename T2 = T>
			T dot(const Tvec5<T2>& other) const
			{
				return x * (T)other.x + y * (T)other.y + z * (T)other.z + w * (T)other.w + v * (T)other.v;
			}
			T length2() const
			{
				return dot(*this);
			}
			T length() const
			{
				return glm::sqrt(length2());
			}
			Tvec5<T>& normalize()
			{
				float len = length2();
				if (len <= glm::epsilon<T>() * glm::epsilon<T>())
				{
					return *this;
				}
				return *this /= glm::sqrt(len);
			}
			Tvec5<T> normalized() const
			{
				Tvec5<T> v = *this;
				v.normalize();
				return v;
			}

			glm::vec<4, T>& xyzw()
			{
				return *(glm::vec<4, T>*)&x;
			}
			const glm::vec<4, T>& xyzw() const
			{
				return *(const glm::vec<4, T>*)&x;
			}

			Tvec5(const nlohmann::json& j)
				: Tvec5(j.at(0).get<T>(), j.at(1).get<T>(), j.at(2).get<T>(), j.at(3).get<T>(), j.at(4).get<T>()) {
			}
			nlohmann::json toJson() const
			{
				return { x, y, z, w, v };
			}
		};

		using vec5 = Tvec5<float>;
		using i8vec5 = Tvec5<int8_t>;
		using i16vec5 = Tvec5<int16_t>;
		using i32vec5 = Tvec5<int32_t>;
		using ivec5 = i32vec5;
		using i64vec5 = Tvec5<int64_t>;
		using u8vec5 = Tvec5<uint8_t>;
		using u16vec5 = Tvec5<uint16_t>;
		using u32vec5 = Tvec5<uint32_t>;
		using uvec5 = u32vec5;
		using u64vec5 = Tvec5<uint64_t>;
		using bvec5 = Tvec5<bool>;
		using quadvec5 = vec5;

		inline float dot(const vec5& a, const vec5& b) { return a.dot(b); }
		inline vec5 normalize(const vec5& v) { return v.normalized(); }
		inline float length(const vec5& v) { return v.length(); }
		inline float length2(const vec5& v) { return v.length2(); }
		inline float distance(const vec5& a, const vec5& b) { return (b - a).length(); }
		inline float distance2(const vec5& a, const vec5& b) { return (b - a).length2(); }
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> min(const Tvec5<T>& a, const Tvec5<T2>& b)
		{
			return Tvec5<T>
			{
				glm::min(a.x, (T)b.x),
				glm::min(a.y, (T)b.y),
				glm::min(a.z, (T)b.z),
				glm::min(a.w, (T)b.w),
				glm::min(a.v, (T)b.v),
			};
		}
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> max(const Tvec5<T>& a, const Tvec5<T2>& b)
		{
			return Tvec5<T>
			{
				glm::max(a.x, (T)b.x),
				glm::max(a.y, (T)b.y),
				glm::max(a.z, (T)b.z),
				glm::max(a.w, (T)b.w),
				glm::max(a.v, (T)b.v),
			};
		}
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> mix(const Tvec5<T>& a, const Tvec5<T2>& b, float t)
		{
			return Tvec5<T>
			{
				glm::mix(a.x, (T)b.x, t),
				glm::mix(a.y, (T)b.y, t),
				glm::mix(a.z, (T)b.z, t),
				glm::mix(a.w, (T)b.w, t),
				glm::mix(a.v, (T)b.v, t),
			};
		}
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> mix(const Tvec5<T>& a, const Tvec5<T2>& b, const bvec5& t)
		{
			return Tvec5<T>
			{
				glm::mix(a.x, (T)b.x, t.x),
				glm::mix(a.y, (T)b.y, t.y),
				glm::mix(a.z, (T)b.z, t.z),
				glm::mix(a.w, (T)b.w, t.w),
				glm::mix(a.v, (T)b.v, t.v),
			};
		}
		template<typename T = float, typename T2 = T>
		inline bvec5 lessThan(const Tvec5<T>& a, const Tvec5<T2>& b)
		{
			return bvec5
			{
				a.x < (T)b.x,
				a.y < (T)b.y,
				a.z < (T)b.z,
				a.w < (T)b.w,
				a.v < (T)b.v,
			};
		}
		template<typename T = float, typename T2 = T>
		inline bvec5 lessThanEqual(const Tvec5<T>& a, const Tvec5<T2>& b)
		{
			return bvec5
			{
				a.x <= (T)b.x,
				a.y <= (T)b.y,
				a.z <= (T)b.z,
				a.w <= (T)b.w,
				a.v <= (T)b.v,
			};
		}
		template<typename T = float, typename T2 = T>
		inline bvec5 greaterThan(const Tvec5<T>& a, const Tvec5<T2>& b)
		{
			return bvec5
			{
				a.x > (T)b.x,
				a.y > (T)b.y,
				a.z > (T)b.z,
				a.w > (T)b.w,
				a.v > (T)b.v,
			};
		}
		template<typename T = float, typename T2 = T>
		inline bvec5 greaterThanEqual(const Tvec5<T>& a, const Tvec5<T2>& b)
		{
			return bvec5
			{
				a.x >= (T)b.x,
				a.y >= (T)b.y,
				a.z >= (T)b.z,
				a.w >= (T)b.w,
				a.v >= (T)b.v,
			};
		}
		template<typename T = float, typename T2 = T, typename T3 = T>
		inline Tvec5<T> clamp(const Tvec5<T>& v, const Tvec5<T2>& min, const Tvec5<T3>& max)
		{
			return m4::min(m4::max(v, min), max);
		}
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> abs(const Tvec5<T>& v)
		{
			return Tvec5<T>
			{
				glm::abs(v.x),
				glm::abs(v.y),
				glm::abs(v.z),
				glm::abs(v.w),
				glm::abs(v.v),
			};
		}
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> floor(const Tvec5<T>& v)
		{
			return Tvec5<T>
			{
				glm::floor(v.x),
				glm::floor(v.y),
				glm::floor(v.z),
				glm::floor(v.w),
				glm::floor(v.v),
			};
		}
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> fract(const Tvec5<T>& v)
		{
			return Tvec5<T>
			{
				glm::fract(v.x),
				glm::fract(v.y),
				glm::fract(v.z),
				glm::fract(v.w),
				glm::fract(v.v),
			};
		}
		template<typename T = float, typename T2 = T>
		inline Tvec5<T> sign(const Tvec5<T>& v)
		{
			return Tvec5<T>
			{
				glm::sign(v.x),
				glm::sign(v.y),
				glm::sign(v.z),
				glm::sign(v.w),
				glm::sign(v.v),
			};
		}
		inline bool any(const bvec5& v)
		{
			return v.x || v.y || v.z || v.w || v.v;
		}
		inline bool all(const bvec5& v)
		{
			return v.x && v.y && v.z && v.w && v.v;
		}
	}
}
