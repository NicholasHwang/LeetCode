#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> result;
        int nums_size = nums.size();
        if(0 == nums_size)
        {
            return 0;
        }
        if(1 == nums_size)
        {
            return nums[0];
        }
        result.push_back(nums[0]);
        if(nums[1] > nums[0])
        {
            result.push_back(nums[1]);
        }
        else
        {
            result.push_back(nums[0]);
        }
        for(auto i = 2; i < nums_size; i++)
        {
            int temp = result[i-2] + nums[i];
            if(temp > result[i-1])
            {
                result.push_back(temp);
            }
            else
            {
                result.push_back(result[i-1]);
            }
        }
        return result[nums_size-1];     
    }
};

int main(void)
{
    Solution solution;
    vector<int> test1 = {};
    vector<int> test2 = {10};
    vector<int> test3 = {10,5};
    vector<int> test4 = {10,17,5};
    vector<int> test5 = {10,15,5};
    vector<int> test6 = {10,15,7};
    vector<int> test7 = {10,15,7,3};
    vector<int> test8 = {10,15,7,3,6};//1,3,5
    vector<int> test9 = {10,9,7,20,6};//1,4
    vector<int> test10 = {10,15,7,20,6};//2,4
    vector<int> test11 = {10,20,7,2,6};//2,5
    cout << solution.rob(test1) << endl;
    cout << solution.rob(test2) << endl;
    cout << solution.rob(test3) << endl;
    cout << solution.rob(test4) << endl;
    cout << solution.rob(test5) << endl;
    cout << solution.rob(test6) << endl;
    cout << solution.rob(test7) << endl;
    cout << solution.rob(test8) << endl;
    cout << solution.rob(test9) << endl;
    cout << solution.rob(test10) << endl;
    cout << solution.rob(test11) << endl;
    return 0;
}
