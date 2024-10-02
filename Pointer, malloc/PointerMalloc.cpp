#include <iostream>
#include <cstdlib> // for std::exit

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int* arr, int size)
{
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end)
    {
        swap(start, end);
        start++;
        end--;
    }
}

int main()
{
    // 1. Pointer Basics
    int x = 10;
    int* ptr = &x;

    std::cout << "Pointer Basics:" << std::endl;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Pointer ptr pointing to x: " << ptr << std::endl;
    std::cout << "Value at the address pointed by ptr: " << *ptr << std::endl << std::endl;

    // 2. Dynamic Array Allocation with Error Checking
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new(std::nothrow) int[size]; // Dynamic allocation of array with error checking

    if (!arr)
    {
        std::cerr << "Memory allocation failed. Exiting program." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Enter " << size << " elements of the array:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Elements of the array are:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << *(arr + i) << " "; // Pointer arithmetic to access array elements
    }
    std::cout << std::endl << std::endl;

    // 3. Swapping Values using Pointers
    int a = 5, b = 10;
    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl << std::endl;

    // 4. Reverse Array using Pointers
    std::cout << "Reversing the array:" << std::endl;
    reverseArray(arr, size);

    std::cout << "Elements of the reversed array are:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << *(arr + i) << " "; // Pointer arithmetic to access array elements
    }
    std::cout << std::endl << std::endl;

    // 5. Pointer Arithmetic
    std::cout << "Traversing array using pointer arithmetic:" << std::endl;
    for (int* p = arr; p < arr + size; ++p)
    {
        std::cout << *p << " "; // Pointer arithmetic to traverse the array
    }
    std::cout << std::endl;

    // Deallocate the dynamically allocated array
    delete[] arr;

    return 0;
}
