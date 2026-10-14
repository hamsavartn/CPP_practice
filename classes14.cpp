#include <bits/stdc++.h>
#include <iostream>
#include<string_view>
struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};
struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};
struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};
int main()
{
    constexpr Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";
    return 0;
}