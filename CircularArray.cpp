#include <iostream>

void print(char *a, int n, int index)
{
    for (int i = index; i < n + index; i++)
    {
        std::cout << a[i % n] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    char a[] = {'1', '2', '3', '4'};
    char *b = a;
    int n = sizeof(a) / sizeof(a[0]);
    print(b, n, 5);
    delete b;
    b = nullptr;
    return 0;
}
