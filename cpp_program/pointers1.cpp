#include <iostream>
#include <string>

int main() {
    // 1. Create the regular string variable
    std::string name = "John Smith"; 

    // 2. Create the pointer and assign it the address of the variable
    std::string* name_ptr = &name; // Exactly like int* name = &n;

    // To print the memory address:
    std::cout << "Memory Address: " << name_ptr << std::endl;

    // To print the actual text "John Smith" (Dereferencing):
    std::cout << "Text Value: " << *name_ptr << std::endl;

    return 0;
}
