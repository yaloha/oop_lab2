#pragma once
#include <cstddef>
#include <utility>

class String {
    char* text;
    size_t len;
    size_t capacity;

    inline void swap(String& other) noexcept {
        std::swap(text, other.text);
        std::swap(len, other.len);
        std::swap(capacity, other.capacity);
    }

public:

    String();
    ~String();
    String(const char* o_text, size_t o_len);
    String(size_t o_len);
    String(const char* o_text);

    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(String other);

    size_t count_char(char c) const;

};
