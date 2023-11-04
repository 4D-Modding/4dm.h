#pragma once

#include "4dm.h"

struct uuid
{
private:
    template <typename CharIterator>
    typename std::iterator_traits<CharIterator>::value_type
        get_next_char(CharIterator& begin, CharIterator end) const {
        if (begin == end) {
            std::runtime_error("invalid uuid string");
        }
        return *begin++;
    }

    unsigned char get_value(char c) const {
        static char const digits_begin[] = "0123456789abcdefABCDEF";
        static size_t digits_len = (sizeof(digits_begin) / sizeof(char)) - 1;
        static char const* const digits_end = digits_begin + digits_len;

        static unsigned char const values[] =
        { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,10,11,12,13,14,15 };

        size_t pos = std::find(digits_begin, digits_end, c) - digits_begin;
        if (pos >= digits_len) {
            std::runtime_error("invalid uuid string");
        }
        return values[pos];
    }

    unsigned char get_value(wchar_t c) const {
        static wchar_t const digits_begin[] = L"0123456789abcdefABCDEF";
        static size_t digits_len = (sizeof(digits_begin) / sizeof(wchar_t)) - 1;
        static wchar_t const* const digits_end = digits_begin + digits_len;

        static unsigned char const values[] =
        { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,10,11,12,13,14,15 };

        size_t pos = std::find(digits_begin, digits_end, c) - digits_begin;
        if (pos >= digits_len) {
            std::runtime_error("invalid uuid string");
        }
        return values[pos];
    }

    bool is_dash(char c) const {
        return c == '-';
    }

    bool is_dash(wchar_t c) const {
        return c == L'-';
    }

    // return closing brace
    bool is_open_brace(char c) const {
        return (c == '{');
    }

    bool is_open_brace(wchar_t c) const {
        return (c == L'{');
    }

    void check_close_brace(char c, char open_brace) const {
        if (open_brace == '{' && c == '}') {
            //great
        }
        else {
            std::runtime_error("invalid uuid string");
        }
    }

    void check_close_brace(wchar_t c, wchar_t open_brace) const {
        if (open_brace == L'{' && c == L'}') {
            // great
        }
        else {
            std::runtime_error("invalid uuid string");
        }
    }
public:
	uint8_t data[16];

    typedef uint8_t* iterator;
    typedef uint8_t const* const_iterator;

    iterator begin() noexcept { return data; }
    const_iterator begin() const noexcept { return data; }
    iterator end() noexcept { return data + 16; }
    const_iterator end() const noexcept { return data + 16; }

    inline static char to_char(size_t i) {
        if (i <= 9) {
            return static_cast<char>('0' + i);
        }
        else {
            return static_cast<char>('a' + (i - 10));
        }
    }

    template<class OutputIterator>
    OutputIterator static to_chars(uuid const& u, OutputIterator out)
    {
        std::size_t i = 0;
        for (uuid::const_iterator it_data = u.begin(); it_data != u.end(); ++it_data, ++i) {
            const size_t hi = ((*it_data) >> 4) & 0x0F;
            *out++ = to_char(hi);

            const size_t lo = (*it_data) & 0x0F;
            *out++ = to_char(lo);

            if (i == 3 || i == 5 || i == 7 || i == 9) {
                *out++ = '-';
            }
        }
        return out;
    }

    inline static bool to_chars(uuid const& u, char* first, char* last)
    {
        if (last - first < 36) {
            return false;
        }
        to_chars(u, first);
        return true;
    }

    inline static std::string to_string(uuid const& u)
    {
        std::string result(36, char());
        to_chars(u, &result[0]);
        return result;
    }
    inline static std::string to_string_raw(uuid const& u)
    {
        std::string result(u.begin(), u.end());
        return result;
    }

    template <typename ch, typename char_traits, typename alloc>
    uuid operator()(std::basic_string<ch, char_traits, alloc> const& s) const {
        return operator()(s.begin(), s.end());
    }

    uuid operator()(char const* const s) const {
        return operator()(s, s + std::strlen(s));
    }

    uuid operator()(wchar_t const* const s) const {
        return operator()(s, s + std::wcslen(s));
    }

    template <typename CharIterator>
    uuid operator()(CharIterator begin, CharIterator end) const
    {
        typedef typename std::iterator_traits<CharIterator>::value_type char_type;

        // check open brace
        char_type c = get_next_char(begin, end);
        bool has_open_brace = is_open_brace(c);
        char_type open_brace_char = c;
        if (has_open_brace) {
            c = get_next_char(begin, end);
        }

        bool has_dashes = false;

        uuid u;
        int i = 0;
        for (uuid::iterator it_byte = u.begin(); it_byte != u.end(); ++it_byte, ++i) {
            if (it_byte != u.begin()) {
                c = get_next_char(begin, end);
            }

            if (i == 4) {
                has_dashes = is_dash(c);
                if (has_dashes) {
                    c = get_next_char(begin, end);
                }
            }

            // if there are dashes, they must be in every slot
            else if (i == 6 || i == 8 || i == 10) {
                if (has_dashes == true) {
                    if (is_dash(c)) {
                        c = get_next_char(begin, end);
                    }
                    else {
                        std::runtime_error("invalid uuid string");
                    }
                }
            }


            *it_byte = get_value(c);

            c = get_next_char(begin, end);
            *it_byte <<= 4;
            *it_byte |= get_value(c);
        }

        // check close brace
        if (has_open_brace) {
            c = get_next_char(begin, end);
            check_close_brace(c, open_brace_char);
        }

        // check end of string - any additional data is an invalid uuid
        if (begin != end) {
            std::runtime_error("invalid uuid string");
        }

        return u;
    }

    inline static std::size_t hash_value(const uuid & u) noexcept
    {
        std::size_t seed = 0;
        for (uuid::const_iterator i = u.begin(); i != u.end(); ++i)
        {
            seed ^= static_cast<std::size_t>(*i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }

        return seed;
    }

    inline bool operator== (uuid const& rhs) const noexcept
    {
        return std::equal(this->begin(), this->end(), rhs.begin(), rhs.end());
    }
    inline bool operator!=(uuid const& rhs) const noexcept
    {
        return !(*this == rhs);
    }
};
namespace std
{
    template<>
    struct hash<uuid>
    {
        std::size_t operator () (const uuid& value) const noexcept
        {
            return uuid::hash_value(value);
        }
    };
}