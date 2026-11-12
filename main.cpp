#include "string.h"
#include <iostream>
int main() {
    String s1;
    String s2("Hello");
    String s3(s2);
    String s4(std::move(s3));
    s1 = s2;
    s1.append(", World!");
    s1.print(std::cout);
    size_t cnt = s1.count_char('o');
    std::cout << cnt << std::endl; //2
    return 0;
}
