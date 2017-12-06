#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<bitset>
#include<climits>
using namespace std;

class Solution {
public:
    unordered_map<bitset<26>,int> target_array;
    int minStickers(vector<string>& stickers, string target) {
        //store that which sticker a special letter exists in 
        vector<bitset<26>> sticker_array;
        bitset<26> target_bit(0);
        bitset<26> totoal_alphabet(0);
        bitset<26> target_alphabet(0);    
        int result = 0;
        int index = 0;
        for(auto s : stickers)
        {
            bitset<26> sticker_bit(0);
            for(auto letter : s)
            {
                int letter_index = letter - 'a';
                sticker_bit.set(letter_index,1);
                totoal_alphabet.set(letter_index,1);
            }
            sticker_array.push_back(std::move(sticker_bit));
            index++;
        }

        for(auto letter : target)
        {
            int letter_index = letter - 'a';
            target_alphabet.set(letter_index,1);
            target_bit.set(letter_index,1);
        }
        if(!(target_alphabet & ~totoal_alphabet).none())
        {
            return -1;
        }
        bitset<26> empty_item(0);
        target_array.insert({empty_item,0});
        result = Handle(target_bit,sticker_array);
        return result;
    } 
    
    //if return true, result_bit has value
    bool Match(const bitset<26>& target_bit, const bitset<26>& sticker_bit, bitset<26>& result_bit)
    {
        bool flag = false;
        for(auto i = 0; i < 26; i++)
        {
            if(target_bit.test(i))
            {
                if(target_bit[i] != sticker_bit[i])
                {
                    result_bit.set(i,1);
                }
                else
                {
                    flag = true;
                }
            }
        }
        
        return flag;
    }

    int Handle(bitset<26>& target_bit,const vector<bitset<26>>& sticker_array)
    {
        if(target_array.count(target_bit))
        {
            return target_array[target_bit];
        }
        int ans = INT_MAX;
        for(auto data: sticker_array)
        {
            bitset<26> result_bit;
            if(Match(target_bit,data,result_bit))
            {
                int temp = Handle(result_bit,sticker_array);
                if(-1 != temp)
                {
                    ans = min(ans,temp+1);
                }
            }
        }
        target_array[target_bit] = ans == INT_MAX ? -1 : ans;
        return target_array[target_bit];
    }  
};


int main(void)
{
    Solution solution;
    vector<string> stickers1 = {"notice","possible"};
    string target1 = "basicbasic";
    vector<string> stickers2 = {"with","example","science"};
    string target2 = "thehat";
    cout << solution.minStickers(stickers1,target1) << endl;
    cout << solution.minStickers(stickers2,target2) << endl;
    return 0;
}
