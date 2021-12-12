//
//  utils.h
//  cpp
//
//  Created by Vlada Vlada on 21.11.2021.
//

#ifndef utils_h
#define utils_h

#include <iostream>
#include <unordered_map>
#include <tuple>

#endif /* utils_h */

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail() || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter number (" << min << "-" << max <<") again:";
    }
    return x;
    
}
