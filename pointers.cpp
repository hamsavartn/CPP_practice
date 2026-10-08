#include <iostream>
using namespace std;

int main() {

    // === SECTION 1: & and * ===
    cout << "=== SECTION 1: & and * ===\n";

    int x = 42;
    int* ptr = &x;

    cout << "x      = " << x   << "\n";
    cout << "&x     = " << &x  << "\n";
    cout << "ptr    = " << ptr << "\n";
    cout << "*ptr   = " << *ptr << "\n";

    x = 99;
    cout << "\nAfter x = 99:\n";
    cout << "*ptr = " << *ptr << "\n";

    *ptr = 200;
    cout << "x    = " << x << "\n";

    // === SECTION 2: Repointing ===
    cout << "\n=== SECTION 2: Repointing ===\n";

    int a = 10, b = 20;
    int* p1 = &a;
    cout << "p1 points to a → *p1 = " << *p1 << "\n";

    p1 = &b;
    cout << "p1 repointed to b → *p1 = " << *p1 << "\n";

    // === SECTION 3: Pointer Arithmetic ===
    cout << "\n=== SECTION 3: Pointer Arithmetic ===\n";

    int arr[5] = {10, 20, 30, 40, 50};
    int* p2 = arr;

    cout << "arr[0] = " << *p2 << "\n";
    cout << "arr[1] = " << *(p2 + 1) << "\n";
    cout << "arr[2] = " << *(p2 + 2) << "\n";

    cout << "Walking: ";
    for (int i = 0; i < 5; i++) {
        cout << *(p2 + i) << " ";
    }
    cout << "\n";

    cout << "(p2+1) - p2 = " << (p2 + 1) - p2 << "\n";

    // === SECTION 4: Pointer to Pointer ===
    cout << "\n=== SECTION 4: Pointer to Pointer ===\n";

    int val = 5;
    int*  pp1 = &val;
    int** pp2 = &pp1;

    cout << "val  = " << val   << "\n";
    cout << "*pp1 = " << *pp1  << "\n";
    cout << "**pp2= " << **pp2 << "\n";

    **pp2 = 99;
    cout << "After **pp2 = 99 → val = " << val << "\n";
    cout << "After **pp2 = 99 ->val = " << *pp1<< "\n";
    // === SECTION 5: Pointers in Functions ===
    cout << "\n=== SECTION 5: Pointers in Functions ===\n";

    auto doubleIt = [](int* p) { *p *= 2; };

    int n = 5;
    cout << "Before: n = " << n << "\n";
    doubleIt(&n);
    cout << "After:  n = " << n << "\n";

    // === SECTION 6: nullptr ===
    cout << "\n=== SECTION 6: nullptr ===\n";

    int* safe = nullptr;
    cout << "safe == nullptr: " << (safe == nullptr) << "\n";

    if (safe != nullptr) {
        cout << "*safe = " << *safe << "\n";
    } else {
        cout << "safe is null, skipping dereference.\n";
    }

    // === SECTION 7: Pointer vs Reference ===
    cout << "\n=== SECTION 7: Pointer vs Reference ===\n";

    int target = 100;
    int*  p3  = &target;
    int&  ref = target;

    cout << "target = " << target << "\n";
    cout << "*p3    = " << *p3    << "\n";
    cout << "ref    = " << ref    << "\n";

    int other = 999;
    p3 = &other;
    // Now MODIFY through the reference:
    ref = 777;

    cout << "After ref = 777:\n";
    cout << "target = " << target << "\n";  // 777!
    cout << "ref    = " << ref    << "\n";  // 777
    cout << "*p3    = " << *p3    << "\n";  // 999 (p3 points to other, not target)   
    cout << "\nAfter p3 = &other:\n";
    cout << "*p3    = " << *p3    << "\n";
    cout << "ref    = " << ref    << "\n";
    cout << "target = " << target << "\n";

    cout << "\nDone. Now go break things!\n";
    return 0;
}   