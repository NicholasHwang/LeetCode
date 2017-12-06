#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        map<string,int> dict;
        int words_size = words.size();
        int s_size = s.size();
        if(0 == words_size || 0 == s_size)
        {
            return result;
        }
        int word_length = words[0].length();
        int words_length = word_length * words_size;
        int end_position = s.size() - words_length;
        for(auto i = 0; i < words_size; i++)
        {
            dict[words[i]]++;
        }
        map<string,int> cnt;
        for(auto j = 0; j <= end_position; j++)
        {
            cnt.clear();
            for(auto k = 0; k < words_size; k++)
            {
                string cur = s.substr(j + k*word_length, word_length);
                if(dict.find(cur) == dict.end() || ++cnt[cur] > dict[cur])
                {
                    goto next;
                }
            }
            result.push_back(j);
            next:;
        }
        return result;
    }
    
    int kmp_matcher(string s, string word)
    {
        int match_count = 0;
        int s_size = s.size();
        int word_size = word.size();
        vector<int> prefix_array(word_size,0);
        kmp_compute_prefix(prefix_array,word);
        /*for(auto data : prefix_array)*/
        //{
            //cout << data << " ";
        //}
        /*cout << endl;*/
        int i = 0;
        int j = 0;
        for(; i < s_size; i++)
        {
            //cout << s[i] << " " << word[j];
            while((j > 0) && (s[i] != word[j]))
            {
                j = prefix_array[j-1];
            }

            if(word[j] == s[i])
            {
                j++;
            }
            
            if(j == word_size)
            {
                match_count++;
                j = prefix_array[j];
            }
            //cout << " " << j << endl;
        }

        return match_count;
    }
        
    void kmp_compute_prefix(vector<int>& prefix_array,string word)
    {
        int word_size = word.size();
        int i = 1;
        int j = 0;
        prefix_array.push_back(0);
        for(;i < word_size; i++)
        {
            //cout << word[i] << " " << word[j];
            while((j > 0) && (word[j] != word[i]))
            {
                j = prefix_array[j-1];
            }

            if(word[j] == word[i])
            {
                j++;
            }
            prefix_array[i] = j;
            //cout << " " << prefix_array[i] << endl;
        }
    }
};

int main(void)
{
    Solution solution;
    vector<string> words1 = {"foo","bar"};
    string s1 = "barfoothefoobarman";
    vector<int> result1;
    result1 = solution.findSubstring(s1,words1);
    for(auto data: result1)
    {
        cout << data << " ";
    }
    cout << endl;
    return 0;
}
