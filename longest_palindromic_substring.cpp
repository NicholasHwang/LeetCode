#include <iostream>
#include <string>
    
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int s_size = s.size();
        if((0 == s_size) || (1 == s_size))
        {
            return s;
        }
        bool pal[1000][1000] = {{false}};
        int max_len = 0;
        const char* data = s.data();
        int start = 0, end = 0;
        for(int i = 0; i < s_size; i++)
        {
            int j = i;
            while(j >= 0)
            {
                if((data[i] == data[j]) && ((i - j < 2) || pal[j+1][i-1]))
                {
                    pal[j][i] = true;
                    int diff = i - j + 1;
                    if(max_len < diff)
                    {
                        max_len = diff;
                        start = j;
                        end = i;
                    }
                }
                j--;
            }
        }
        return s.substr(start,(end-start+1));
    }
};

int main(void)
{
    string test1 = {"babad"};
    string test2 = {"cbbd"};
    string test3 = {""};
    string test4 = {"a"};
    string test5 = {"bbbbd"};
    string test6 = {"abcda"};
    Solution solution;
    cout << solution.longestPalindrome(test1) << endl;
    cout << solution.longestPalindrome(test2) << endl;
    cout << solution.longestPalindrome(test3) << endl;
    cout << solution.longestPalindrome(test4) << endl;
    cout << solution.longestPalindrome(test5) << endl;
    cout << solution.longestPalindrome(test6) << endl;
    return 0;
}
