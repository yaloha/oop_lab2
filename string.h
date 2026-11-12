#pragma once
#include <cstddef>
#include <utility>
#include <ostream>

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
    explicit String(size_t o_len);
    String(const char* o_text);

    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(String other);

    size_t count_char(const char c) const;
    String& append(const char* c);
    void print(std::ostream& os) const;
    //size_t find(const char* c);
};
