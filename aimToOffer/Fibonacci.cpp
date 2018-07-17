#include <iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    int temp = 0, fib_0 = 0, fib_1 = 1;
    while (--n)
    {
        temp = fib_1;
        fib_1 += fib_0;
        fib_0 = temp;
    }
    return fib_1;
        
    }
};

int main()
{
    Solution s1;
    cout << s1.Fibonacci(2);
}