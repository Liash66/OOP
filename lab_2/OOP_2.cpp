#include <iostream>
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");

    const int h = 2;
    const int w = 3;
    const int d = 4;

    mt::Array3d<int> arr = mt::Array3d<int>::CreateFill(h, w, d);
    std::cout << "CreteFill:" << std::endl;
    arr.print();

    int x = 0;
    std::cout << "getValue0 (" << x << "): " << std::endl;
    for (size_t i = 0; i < arr.getValues0(x).size(); i++)
    {
        std::cout << arr.getValues0(x)[i];
    }
    std::cout << std::endl << std::endl;

    std::cout << "getValue1 (" << x << "): " << std::endl;
    for (size_t i = 0; i < arr.getValues1(x).size(); i++)
    {
        std::cout << arr.getValues1(x)[i];
    }
    std::cout << std::endl << std::endl;

    std::cout << "getValue2 (" << x << "): " << std::endl;
    for (size_t i = 0; i < arr.getValues2(x).size(); i++)
    {
        std::cout << arr.getValues2(x)[i];
    }
    std::cout << std::endl << std::endl;

    int y = 0;
    std::cout << "getValue01 (" << x << ", " << y << "): " << std::endl;
    for (size_t i = 0; i < arr.getValues01(x, y).size(); i++)
    {
        std::cout << arr.getValues01(x, y)[i];
    }
    std::cout << std::endl << std::endl;

    std::cout << "getValue02 (" << x << ", " << y << "): " << std::endl;
    for (size_t i = 0; i < arr.getValues02(x, y).size(); i++)
    {
        std::cout << arr.getValues02(x, y)[i];
    }
    std::cout << std::endl << std::endl;

    std::cout << "getValue12 (" << x << ", " << y << "): " << std::endl;
    for (size_t i = 0; i < arr.getValues12(x, y).size(); i++)
    {
        std::cout << arr.getValues12(x, y)[i];
    }
    std::cout << std::endl << std::endl;

    std::cout << "setValue0 (" << x << "): " << std::endl;
    arr.setValues0(x, 0);
    arr.print();

    std::cout << "setValue1 (" << x << "): " << std::endl;
    arr.setValues1(x, 1);
    arr.print();

    std::cout << "setValue2 (" << x << "): " << std::endl;
    arr.setValues2(x, 2);
    arr.print();

    std::cout << "setValue01 (" << x << ", " << y << "): " << std::endl;
    arr.setValues01(x, y, 3);
    arr.print();

    std::cout << "setValue02 (" << x << ", " << y << "): " << std::endl;
    arr.setValues02(x, y, 4);
    arr.print();

    std::cout << "setValue12 (" << x << ", " << y << "): " << std::endl;
    arr.setValues12(x, y, 5);
    arr.print();

    return 0;
}