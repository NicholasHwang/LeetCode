#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
        {
            return s.empty();
        } 
        
        if(1 == p.size() || p.at(1) != '*')
        {
            if(s.empty() || (p.at(0) != '.' && p.at(0) != s.at(0)))
            {
                return false;
            }
            else
            {
                return isMatch(s.substr(1),p.substr(1));
            }
        }

        while(!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.'))
        {
            if(isMatch(s,p.substr(2)))
            {
                return true;
            }
            s = s.substr(1);
        }

        return isMatch(s,p.substr(2));
    }
};

int main(void)
{
    Solution solution;
    cout << solution.isMatch("aa","a") << endl;
    cout << solution.isMatch("aa","aa") << endl;
    cout << solution.isMatch("aaa","aa") << endl;
    cout << solution.isMatch("aa","a*") << endl;
    cout << solution.isMatch("aa",".*") << endl;
    cout << solution.isMatch("ab",".*") << endl;
    cout << solution.isMatch("aab","c*a*b") << endl;
    return 0;
}
