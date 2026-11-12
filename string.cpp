#include "string.h"
#include <cstring>
#include <utility>

String::String() : text(nullptr), len(0), capacity(0) {}

String::~String() {
    delete[] text;
}

String::String(const char* o_text, size_t o_len) {
    len = o_len;
    capacity = o_len + 1;
    text = new char[capacity];
    if (o_text != nullptr && o_len > 0) {
        std::memcpy(text, o_text, o_len);
    }
    text[len] = '\0';
}

String::String(size_t o_len)
        : text(o_len > 0 ? new char[o_len + 1]{} : nullptr),
          len(o_len),
          capacity(o_len > 0 ? o_len + 1 : 0) {}

String::String(const char* o_text) : String() {
    if (o_text == nullptr) {
        return;
    }
    len = std::strlen(o_text);
    capacity = len + 1;
    text = new char[capacity];
    std::strcpy(text, o_text);
}

String::String(const String& other) : String(other.text, other.len) {}

String::String(String&& other) noexcept
: text(std::exchange(other.text, nullptr)),
len(std::exchange(other.len, 0)),
capacity(std::exchange(other.capacity, 0)) {}

String& String::operator=(String other) {
    swap(other);
    return *this;
}

size_t String::count_char(char c) const {
    size_t cnt = 0;
    if (this->text != nullptr){
        for (size_t i = 0; i < this->len; ++i){
            if (this->text[i] == c)
                ++cnt;
        }
    }
    return cnt;
}

String *String::append(char c) {

}



