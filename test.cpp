#include <iostream>

int main()
{
    bool *a;
    bool b = false;
    a = &b;
    std::cout << a << " / " << b << " / " << *a << " / " << &a  << " / " << &b << std::endl;
    return 0;
}