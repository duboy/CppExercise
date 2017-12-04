#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         if (n > 0)
         {
             bitset<32> b(n);
             return b.count();
         }
         else
         {
             bitset<32> b(-n);
             int temp = (b.flip()).to_ulong() + 1;
             bitset<32> b2(temp);
             return b2.count();
         }             
     }
};

int main()
{
    Solution s1;
    cout << s1.NumberOf1(-1);
}