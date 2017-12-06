#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();
        if(0 == nums_size)
        {
            return 0;
        }       
        if(1 == nums_size)
        {
            return nums[0];
        }

        return max(robber(nums,0,nums_size-2),robber(nums,1,nums_size-1));
    }

    int robber(vector<int>& nums,int l,int r)
    {
        int pre = 0;
        int cur = 0;
        for(int i = l; i <= r; i++)
        {
            int temp = max(pre+nums[i],cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

int main(void)
{
    Solution solution;
    vector<int> test1 = {1,3,5,6,7};
    vector<int> test2 = {};
    vector<int> test3 = {1};
    vector<int> test4 = {1,3};
    vector<int> test5 = {1,3,5};
    vector<int> test6 = {1,3,5,6,7,4};
    vector<int> test7 = {11,3,8,6,7};
    vector<int> test8 = {1,3,5,6,7,4,1};
    vector<int> test9 = {1,3,5,6};

    cout << solution.rob(test1) << endl;
    cout << solution.rob(test2) << endl;
    cout << solution.rob(test3) << endl;
    cout << solution.rob(test4) << endl;
    cout << solution.rob(test5) << endl;
    cout << solution.rob(test6) << endl;
    cout << solution.rob(test7) << endl;
    cout << solution.rob(test8) << endl;
    cout << solution.rob(test9) << endl;
    return 0;
}
