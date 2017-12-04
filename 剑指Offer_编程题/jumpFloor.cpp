#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 3)
            return number;
        else 
            return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};

int main()
{
    Solution s1;
    cout << s1.jumpFloor(4);
}