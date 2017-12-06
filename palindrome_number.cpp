#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(0 > x)
        {
            return false;
        } 
        
        int div = 1;
        while(x / div >= 10)
        {
            div *= 10;
        }
        while(0 != x)
        {
            int l = x / div;
            int r = x % 10;
            if(l == r)
            {
                x = (x % div) / 10;
                div = div / 100;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution solution;
    cout << solution.isPalindrome(1) << endl;
    cout << solution.isPalindrome(-1234) << endl;
    cout << solution.isPalindrome(121) << endl;
    cout << solution.isPalindrome(40000004) << endl;
    cout << solution.isPalindrome(2147483647) << endl;
    cout << solution.isPalindrome(1234320) << endl;
    return 0;
}
