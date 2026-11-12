#include "string.h"
#include <cstring>
#include <utility>
#include <iostream>

String::String() : text(new char[2]{}), len(0), capacity(1) {}

String::~String() {
    delete[] text;
}

String::String(const char* o_text, size_t o_len) {
    len = o_len;
    capacity = (o_len > 0) ? o_len : 1;
    text = new char[capacity + 1];
    if (o_text != nullptr && o_len > 0) {
        std::memcpy(text, o_text, o_len);
    }
    text[len] = '\0';
}

String::String(size_t o_len)
        : text(new char[(o_len > 0 ? o_len : 1) + 1]{}),
          len(o_len),
          capacity(o_len > 0 ? o_len + 1 : 0) {}

String::String(const char* o_text) : String() {
    if (o_text == nullptr) {
        return;
    }
    delete[] text;
    len = std::strlen(o_text);
    capacity = len;
    text = new char[capacity + 1];
    std::memcpy(text, o_text, len + 1);
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

size_t String::count_char(const char c) const {
    size_t cnt = 0;
    if (this->text != nullptr){
        for (size_t i = 0; i < this->len; ++i){
            if (this->text[i] == c)
                ++cnt;
        }
    }
    return cnt;
}

String &String::append(const char* c) {
    if (c == nullptr || *c == '\0') {
        return *this;
    }
    
    size_t add_len = std::strlen(c);
    size_t new_len = this->len + add_len;

    if (new_len <= this->capacity) {
        std::memmove(this->text + this->len, c, add_len + 1);
    }else{
        size_t new_capacity = this->capacity;
        while (new_capacity < new_len) {
            new_capacity *= 2;
        }
        char* temp = new char[new_capacity + 1];

        if (this->text != nullptr && this->len > 0) {
            std::memcpy(temp, this->text, this->len);
        }
        std::memcpy(temp + this->len, c, add_len + 1);

        delete[] this->text;
        this->text = temp;
        this->capacity = new_capacity;
    }
    this->len = new_len;
    return *this;
}

void String::print(std::ostream& os) const{
    if (this->text != nullptr)
        os << this->text << "\n";
}

//size_t String::find(const char *c) {
//
//}



