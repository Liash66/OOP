#include <string>
#include "Text.h"

int main()
{
    std::string str = "HELLO WORLD";

    text::Text text1(str, 1, text::Color::WHITE, { 46, 0 });
    text::Text text5(str, 5, text::Color::BLUE, { 14, 2 });
    text::Text text7(str, 7, text::Color::RED, { 0, 8 });

    text1.Print();
    text5.Print();
    text7.Print();
}