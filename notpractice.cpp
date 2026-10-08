/*#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x

    int* ptr{ &x }; // ptr holds the address of x
    std::cout << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    return 0;
}*/
#include <iostream>

int main() {
    int x = 42;
    // 1. Declare a pointer and point it to x
    int* ptr = &x;          // ptr stores the address of x

    // 2. Print the address and the value
    std::cout << "x  = " << x  << "\n";
    std::cout << "&x = " << &x << "\n";   // address of x
    std::cout << "ptr= " << ptr << "\n";  // same address (ptr == &x)

    // 3. Dereference: read the value through the pointer
    std::cout << "*ptr = " << *ptr << "\n"; // 42

    // 4. Modify the value through the pointer
    *ptr = 100;
    //what will happen if i just give the variable name as ptr instead of *ptr
    std::cout << "x after *ptr = 100 → x = " << x << "\n"; // 100

    // 5. Repoint the pointer to a different variable
    int y = 7;
    ptr = &y;
    std::cout << "ptr now points to y: *ptr = " << *ptr << "\n"; // 7

    // 6. nullptr — pointer with no target
    int* p = nullptr;
    std::cout << "p is nullptr: " << (p == nullptr) << "\n"; // 1
    // *p = 5;  // ← undefined behavior, never do this

    return 0;
}   