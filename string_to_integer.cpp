#include<iostream>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int s_size = str.size();
        if(0 == s_size)
        {
            return 0;
        }
        int result = 0;
        bool minus_flag = false;
        bool flag = false;
        const char* data = str.data();
        int i = 0;
        int j = 0;
        for(i = 0; i < s_size; i++)
        {
            //first find out first non-whitespace character
            if(' ' != data[i])
            {
                break;
            }
        }

        if('-' == data[i])
        {
            minus_flag = true;
            flag = true;
        }
        else if('+' == data[i])
        {
            minus_flag = false;
            flag = true;
        }
        else if(('0' > data[i]) || ('9' < data[i]))
        {
            return 0;
        }

        if(flag)
        {
            j = i + 1;
        }
        else
        {
            j = i;
        }
        
        //ignore 0 till a non-zero digit character 
        for(; j < s_size; j++)
        {
            if('0' != data[j])
            {
                break;
            }
        }

        for(; j < s_size; j++)
        {
            if(('0' <= data[j]) && ('9' >= data[j]))
            {
                if (result >  INT_MAX / 10 || (result == INT_MAX / 10 && data[j] - '0' > 7)) 
                {
                    if (!minus_flag) return INT_MAX;
                    else return INT_MIN;
                }
                result = data[j] - '0' + result * 10;
                //cout << result <<endl;
            }
            else
            {
                break;
            }
        }

        if(minus_flag)
        {
            result = -1 * result;
        }
        return result;
    }
};

int main(void)
{
    string test1 = {"123"};
    string test2 = {"-123"};
    string test3 = {"    "};
    string test4 = {"   124"};
    string test5 = {"   -124"};
    string test6 = {"  -  125"};
    string test7 = {"    125   "};
    string test8 = {"   1 25"};
    string test9 = {"xxxxx"};
    string test10 = {"x126"};
    string test11 = {"x-126"};
    string test12 = {"1x26"};
    string test13 = {"-x126"};
    string test14 = {"-1x26"};
    string test15 = {"0127"};
    string test16 = {"-0127"};
    string test17 = {"+0127"};
    string test18 = {"0127000"};
    string test19 = {"-0127000"};
    string test20 = {"   -0128xxx128000   "};
    string test21 = {"2147483648"};
    Solution solution;
    cout << solution.myAtoi(test1) << endl;
    cout << solution.myAtoi(test2) << endl;
    cout << solution.myAtoi(test3) << endl;
    cout << solution.myAtoi(test4) << endl;
    cout << solution.myAtoi(test5) << endl;
    cout << solution.myAtoi(test6) << endl;
    cout << solution.myAtoi(test7) << endl;
    cout << solution.myAtoi(test8) << endl;
    cout << solution.myAtoi(test9) << endl;
    cout << solution.myAtoi(test10) << endl;
    cout << solution.myAtoi(test11) << endl;
    cout << solution.myAtoi(test12) << endl;
    cout << solution.myAtoi(test13) << endl;
    cout << solution.myAtoi(test14) << endl;
    cout << solution.myAtoi(test15) << endl;
    cout << solution.myAtoi(test16) << endl;
    cout << solution.myAtoi(test17) << endl;
    cout << solution.myAtoi(test18) << endl;
    cout << solution.myAtoi(test19) << endl;
    cout << solution.myAtoi(test20) << endl;
    cout << solution.myAtoi(test21) << endl;
    return 0;
}
