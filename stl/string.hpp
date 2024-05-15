#pragma once

#include <cstdint>
#include <array>
#include <cstring>
#include <string>
#include <string_view>
#include <compare>
#include <filesystem>
#include <memory>

// some stuff based on https://github.com/geode-sdk/geode/blob/main/loader/include/Geode/c%2B%2Bstl/string.hpp
// other stuff based on Redjard's (dj=t) msvc_string.h
// other other stuff made by me (tr1ngle)
namespace fdm::stl
{
    template<class T>
    class basic_string
    {
    public:
        inline static constexpr size_t npos = -1;
        inline static constexpr size_t bufSize = 16 / sizeof(T) < 1 ? 1 : 16 / sizeof(T);
        inline static constexpr size_t allocMask = sizeof(T) <= 1 ? 15
            : sizeof(T) <= 2 ? 7
            : sizeof(T) <= 4 ? 3
            : sizeof(T) <= 8 ? 1
            : 0;
        inline static constexpr size_t ssCapacity = bufSize - 1;

        using iterator = T*;
        using const_iterator = const T*;
    private:
        union 
        {
			std::array<T, bufSize> m_smallStorage;
			T* m_bigStorage;
		};

		size_t m_size;
		size_t m_capacity;

        void _setEmpty()
        {
            m_size = 0;
            m_capacity = ssCapacity;
            m_smallStorage[0] = NULL;
        }
        void _free()
        {
            if(m_capacity > ssCapacity)
                delete m_bigStorage;
        }
        T* _getStorage()
        {
            return m_capacity <= ssCapacity ? m_smallStorage.data() : m_bigStorage;
        }
        const T* _getStorage() const
        {
            return m_capacity <= ssCapacity ? m_smallStorage.data() : m_bigStorage;
        }
        void _setStorage(const std::basic_string_view<T> str)
        {
            m_size = m_capacity = str.size();

            if(str.size() <= ssCapacity)
                m_capacity = ssCapacity;
            else
                m_bigStorage = static_cast<T*>(operator new(str.size() + 1));

            std::memcpy(_getStorage(), str.data(), str.size());
            _getStorage()[str.size()] = NULL; 
        }

    public:
        constexpr iterator begin() { return data(); }
        constexpr iterator end() { return data() + size(); }
        constexpr const_iterator begin() const { return data(); }
        constexpr const_iterator end() const { return data() + size(); }

        operator std::basic_string<T>() const { return std::basic_string<T>(data(), size()); }
        operator std::basic_string_view<T>() const { return std::basic_string_view<T>(data(), size()); }
        operator std::filesystem::path() const { return std::filesystem::path((std::basic_string<T>)*this); }

        basic_string()
        {
            _setEmpty();
        }
        basic_string(const basic_string<T>& str)
        {
            _setStorage(str);
        }
        basic_string(basic_string<T>&& other)
        {
            _setStorage(other);
            other._free();
            other._setEmpty();
        }
        basic_string(const basic_string<T>& str, size_t pos, size_t len = npos)
        {
            _setStorage(std::basic_string<T>((std::basic_string<T>)str, pos, len));
        }
        basic_string(const T* s)
        {
            _setStorage(s);
        }
        basic_string(const T* s, size_t n)
        {
            _setStorage(std::basic_string_view<T>(s, n));
        }
        basic_string(size_t n, char c)
        {
            _setStorage(std::basic_string<T>(n, c));
        }
        basic_string(const std::basic_string<T>& stdStr)
        {
            _setStorage(stdStr);
        }
        template <class InputIterator>
        basic_string(InputIterator first, InputIterator last)
        {
            _setStorage(std::basic_string<T>(first, last));
        }
        ~basic_string()
        {
            clear();
        }

        constexpr basic_string<T>& operator=(const basic_string<T>& other)
        {
            if (this != &other) 
            {
                _free();
                _setStorage(other);
            }
            return *this;
        }
        basic_string<T>& operator=(basic_string<T>&& other)
        {
            _free();
            _setStorage(other);
            other._free();
            other._setEmpty();
            return *this;
        }
        basic_string<T>& operator=(const T* other)
        {
            _free();
            _setStorage(other);
            return *this;
        }
        basic_string<T>& operator=(const std::basic_string<T>& other)
        {
            _free();
            _setStorage(other);
            return *this;
        }

        constexpr size_t size() const noexcept { return m_size; }
        constexpr size_t length() const noexcept { return m_size; }
        constexpr size_t max_size() const noexcept { return 0x7fffffffffffffff; }
        constexpr size_t capacity() const noexcept { return m_capacity; }
        void resize(size_t n, char c = 0) 
        { 
            std::basic_string<T> a = (std::basic_string<T>)*this;
            a.resize(n, c);
            *this = a;
        }
        constexpr void reserve(size_t n = 0)
        {
            if (n <= capacity())
                return;
            resize(n);
        }
        constexpr void shrink_to_fit() { reserve(size()); }
        void clear() noexcept
        {
            _free();
            _setEmpty();
        }
        constexpr bool empty() const noexcept { return size() == 0; }
        
        T& at(size_t pos)
        {
            if (pos >= size())
                throw std::out_of_range("fdm::stl::basic_string::at");
            return _getStorage()[pos];
        }
        const T& at(size_t pos) const
        {
            if (pos >= size())
                throw std::out_of_range("fdm::stl::basic_string::at");
            return _getStorage()[pos];
        }

        T& operator[](size_t pos) { return at(pos); }
        const T& operator[](size_t pos) const { return at(pos); }

        T& back() { return at(0); }
        const T& back() const { return at(0); }
        T& front() { return at(size() - 1); }
        const T& front() const { return at(size() - 1); }

        const T* data() const noexcept { return _getStorage(); }
        T* data() noexcept { return _getStorage(); }
        const T* c_str() const noexcept { return data(); }

        constexpr bool operator==(const basic_string<T>& other) const { return std::basic_string_view<T>(*this) == std::basic_string_view<T>(other); }
        constexpr bool operator==(const std::basic_string_view<T> other) const { return std::basic_string_view<T>(*this) == other; }
        constexpr bool operator==(const T* other) const { return std::basic_string_view<T>(*this) == std::basic_string_view<T>(other); }
        constexpr bool operator==(const std::basic_string<T>& other) const { return std::basic_string_view<T>(*this) == std::basic_string_view<T>(other); }

        constexpr int compare(const basic_string<T>& other) const
        {
            return std::basic_string_view<T>(*this).compare(std::basic_string_view<T>(other));
        }
        constexpr int compare(const std::basic_string_view<T> other) const
        {
            return std::basic_string_view<T>(*this).compare(other);
        }
        constexpr int compare(const T* other) const
        {
            return std::basic_string_view<T>(*this).compare(other);
        }
        constexpr int compare(const std::basic_string<T>& other) const
        {
            return std::basic_string_view<T>(*this).compare(other);
        }

        constexpr std::strong_ordering operator<=>(const basic_string<T>& other) const
        { 
            return static_cast<std::strong_ordering>(compare(other) <=> 0);
        }
        constexpr std::strong_ordering operator<=>(const std::basic_string_view<T> other) const
        {
            return static_cast<std::strong_ordering>(compare(other) <=> 0);
        }
        constexpr std::strong_ordering operator<=>(const T* other) const
        {
            return static_cast<std::strong_ordering>(compare(other) <=> 0);
        }
        constexpr std::strong_ordering operator<=>(const std::basic_string<T>& other) const
        {
            return static_cast<std::strong_ordering>(compare(other) <=> 0);
        }

        basic_string<T> operator+(const basic_string<T>& other)
        {
            std::basic_string<T> a = (std::basic_string<T>)(*this) + (std::basic_string<T>)(other);
            return a;
        }
        basic_string<T> operator+(const std::basic_string_view<T> other)
        {
            std::basic_string<T> a = (std::basic_string<T>)(*this) + (std::basic_string<T>)(other);
            return a;
        }
        basic_string<T> operator+(const T* other)
        {
            std::basic_string<T> a = (std::basic_string<T>)(*this) + (std::basic_string<T>)(other);
            return a;
        }
        basic_string<T> operator+(const std::basic_string<T>& other)
        {
            std::basic_string<T> a = (std::basic_string<T>)(*this) + other;
            return a;
        }

        basic_string<T>& operator+=(const basic_string<T>& other)
        {
            return *this = *this + other;
        }
        basic_string<T>& operator+=(const std::basic_string_view<T> other)
        {
            return *this = *this + other;
        }
        basic_string<T>& operator+=(const T* other)
        {
            return *this = *this + other;
        }
        basic_string<T>& operator+=(const std::basic_string<T>& other)
        {
            return *this = *this + other;
        }

        basic_string<T> substr(size_t pos = 0, size_t len = npos) const
        {
            return ((std::basic_string<T>)*this).substr(pos, len);
        }
        size_t find(const basic_string<T>& str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find(std::basic_string<T>(str), pos);
        }
        size_t find(const std::basic_string<T>& str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find(str, pos);
        }
        size_t find(const T* str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find(str, pos);
        }
        size_t find(const T* str, size_t pos, size_t n) const
        {
            return ((std::basic_string<T>)*this).find(str, pos, n);
        }
        size_t find(T c, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find(c, pos);
        }
        size_t find_first_not_of(const basic_string<T>& str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_not_of(std::basic_string<T>(str), pos);
        }
        size_t find_first_not_of(const std::string& str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_not_of(str, pos);
        }
        size_t find_first_not_of(const T* str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_not_of(str, pos);
        }
        size_t find_first_not_of(const T* str, size_t pos, size_t n) const
        {
            return ((std::basic_string<T>)*this).find_first_not_of(str, pos, n);
        }
        size_t find_first_not_of(T c, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_not_of(c, pos);
        }
        size_t find_first_of(const basic_string<T>& str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_of(std::basic_string<T>(str), pos);
        }
        size_t find_first_of(const std::basic_string<T>& str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_of(str, pos);
        }
        size_t find_first_of(const T* str, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_of(str, pos);
        }
        size_t find_first_of(const T* str, size_t pos, size_t n) const
        {
            return ((std::basic_string<T>)*this).find_first_of(str, pos, n);
        }
        size_t find_first_of(T c, size_t pos = 0) const
        {
            return ((std::basic_string<T>)*this).find_first_of(c, pos);
        }
        size_t find_last_of(const basic_string<T>& str, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_of(std::basic_string<T>(str), pos);
        }
        size_t find_last_of(const std::basic_string<T>& str, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_of(str, pos);
        }
        size_t find_last_of(const T* str, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_of(str, pos);
        }
        size_t find_last_of(const T* str, size_t pos, size_t n) const
        {
            return ((std::basic_string<T>)*this).find_last_of(str, pos, n);
        }
        size_t find_last_of(T c, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_of(c, pos);
        }
        size_t find_last_not_of(const basic_string<T>& str, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_not_of(std::basic_string<T>(str), pos);
        }
        size_t find_last_not_of(const std::basic_string<T>& str, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_not_of(str, pos);
        }
        size_t find_last_not_of(const T* str, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_not_of(str, pos);
        }
        size_t find_last_not_of(const T* str, size_t pos, size_t n) const
        {
            return ((std::basic_string<T>)*this).find_last_not_of(str, pos, n);
        }
        size_t find_last_not_of(T c, size_t pos = npos) const
        {
            return ((std::basic_string<T>)*this).find_last_not_of(c, pos);
        }
    };

    using string = basic_string<char>;
    using wstring = basic_string<wchar_t>;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const fdm::stl::basic_string<T>& str)
{
    return os << str.data();
}
template<class T>
std::istream& operator>>(std::istream& is, fdm::stl::basic_string<T>& str)
{
    std::string s;
    is >> s;
    str = s;
    return is;
}
template<class T>
struct std::hash<fdm::stl::basic_string<T>>
{
    size_t operator()(const fdm::stl::basic_string<T>& s) const noexcept
    {
        return std::hash<std::string>{}(s);
    }
};