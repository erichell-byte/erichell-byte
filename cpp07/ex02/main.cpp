﻿//
//#include <iostream>
//#include "Array.hpp"
//
//int main()
//{
//    try
//    {
//        Array<int> num(1);
//        Array<int> num2(4);
//
//        num2[0] = 2;
//        num2[1] = 132;
//        num2[2] = 12;
//        num2[3] = 100;
//
//        Array<int> copyNum(num2);
//
//        std::cout << copyNum[1] << std::endl;
//
//        num[3] = 0;
//    }
//    catch (std::exception& e)
//    {
//        std::cout << "size limit is exceeded\n";
//    }
//}
//
//

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror;//
    return 0;
}