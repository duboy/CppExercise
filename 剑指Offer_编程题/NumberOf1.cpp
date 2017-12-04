#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {    
         bitset<32> b(n);
         return b.count();
     }
};

int main()
{
    Solution s1;
    cout << s1.NumberOf1(-1);
}