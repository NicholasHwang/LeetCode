#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const char* s_data = s.data();
        const char* p_data = p.data();
        int p_pos = 0;
        int s_pos = 0;
        int p_save_pos = -1;
        int s_save_pos = -1;
        int p_size = p.size();
        int s_size = s.size();
        while(s_pos < s_size)
        {
            if(p_data[p_pos] == s_data[s_pos] || p_data[p_pos] == '?')
            {
                p_pos++;
                s_pos++;
                continue;
            }
            
            if(p_data[p_pos] == '*')
            {
                p_save_pos = p_pos;
                s_save_pos = s_pos;
                p_pos++;
                continue;
            }

            if(p_save_pos != -1)
            {
                p_pos = p_save_pos + 1;
                s_pos = ++s_save_pos;
                continue;
            }
            return false;
        }

        while(p_data[p_pos] == '*')
        {
            p_pos++;
        }

        return p_data[p_pos] == '\0' ? true : false;
    }
};

int main(void)
{
    Solution solution;
#if 1
    cout << "1 " << solution.isMatch("aaaa","***a") << "true" <<endl;
    cout << "2 " << solution.isMatch("","*") << "true" <<endl;
    cout << "3 " << solution.isMatch("aa","b") << "false" << endl;
    cout << "4 " << solution.isMatch("aa","a") << "false" <<endl;
    cout << "5 " << solution.isMatch("aa","aa") << "true" <<endl;
    cout << "6 " << solution.isMatch("aaa","aa") << "false" <<endl;
    cout << "7 " << solution.isMatch("aa","*") << "true" <<endl;
    cout << "8 " << solution.isMatch("aa","a*") << "true" <<endl;
    cout << "9 " << solution.isMatch("aa","?*") << "true" <<endl;
    cout << "10 " <<solution.isMatch("aa","c*a*b") << "false" <<endl;
    cout << "11 " << solution.isMatch("aa","??") << "true" <<endl;
    cout << "12 " << solution.isMatch("","") << "true" <<endl;
    cout << "13 " << solution.isMatch("","?") << "false" <<endl;
    cout << "14 " << solution.isMatch("","a") << "false" <<endl;
    cout << "15 " << solution.isMatch("","*") << "true" <<endl;
    cout << "16 " << solution.isMatch("caaabc","*a?c") << "true" <<endl;
    cout << "17 " << solution.isMatch("caaabc","*a*b*c") << "true" <<endl;
    cout << "18 " << solution.isMatch("abb","c*a*b") << "false" <<endl;
    cout << "19 " << solution.isMatch("aaa","c*a*b") << "false" <<endl;
    cout << "20 " << solution.isMatch("a","a*") << "true" <<endl;
    cout << "21 " << solution.isMatch("leetcode","*e*t?d*") << "false" <<endl;
    cout << "22 " << solution.isMatch("c","*?*") << "true" <<endl;
    cout << "23 " << solution.isMatch("a","aa") << "false" <<endl;
    cout << "24 " << solution.isMatch("b","?*?") << "false" <<endl;
    cout << "25 " << solution.isMatch("b","??") << "false" <<endl;
    cout << "26 " << solution.isMatch("b","*b*") << "true" <<endl;
    cout << "27 " << solution.isMatch("b","*b*?") << "false" <<endl;
    cout << "28 " << solution.isMatch("b","*?") << "true" <<endl;
    cout << "29 " << solution.isMatch("b","b") << "true" <<endl;
    cout << "30 " << solution.isMatch("aabcdedefghijkl","aabc*") << "true" <<endl;
#endif
    cout << "31 " << solution.isMatch("abbbba","a**a*?") << "false" <<endl;
    cout << "32 " << solution.isMatch("aa","a**a") << "true" <<endl;
    return 0;
}
