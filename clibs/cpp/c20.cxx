#include <iostream>
#include <numbers>
#include <string>



void show_num_const() { // using <numbers> header
    std::cout << std::numbers::e << std::endl;
    std::cout << std::numbers::pi << std::endl;
    std::cout << std::numbers::pi << std::endl;
    std::cout << std::numbers::phi << std::endl;
}

void common_math() { // using <cmath> header

}

// void std_format() {
//     const std::string s = "string value";
//     const double d = 3.556f;

//     std::cout << std::format("string: {} - double: {}", s, d);
// }

void cast() {
    double a = 2.13;
    double b = 3.44;

    int c = static_cast<int>(a + b);
    std::cout << c << std::endl;

    a = 10.9;
    b = 15.9;

    c = static_cast<int> (a + b); // 26
    int d = static_cast<int> (a) + static_cast<int> (b); // 25

    std::cout << c << " " << d << std::endl;
}


int main(int argc, char const *argv[])
{
    cast();
    return 0;
}