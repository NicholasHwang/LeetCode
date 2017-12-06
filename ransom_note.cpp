#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty())
        {
            return true;
        }

        if(magazine.empty())
        {
            return false;
        }
        
        int note_character[26] = {0};
        int magazine_character[26] = {0};

        for(auto c : ransomNote)
        {
            note_character[c-'a']++;
        }   

        for(auto c : magazine)
        {
            magazine_character[c-'a']++;
        }

        bool flag = true;
        for(auto i = 0; i < 26; i++)
        {
            if(note_character[i] > magazine_character[i])
            {
                flag = false;
                break;
            }
        }

        return flag;
    }
};


int main(void)
{
    Solution solution;
    string note1 = "a";
    string magazine1 = "b";
    string note2 = "aa";
    string magazine2 = "ab";
    string note3 = "aa";
    string magazine3 = "aba";
    cout << solution.canConstruct(note1,magazine1) << endl;
    cout << solution.canConstruct(note2,magazine2) << endl;
    cout << solution.canConstruct(note3,magazine3) << endl;
    return 0;
}
