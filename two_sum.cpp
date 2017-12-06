#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        vector<int> result;
        int nums_size = nums.size();
        for(auto i = 0; i < (nums_size - 1); i++)
        {
            for(auto j = i+1; j < nums_size; j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    };
};


int main(void)
{
    Solution solution;
    std::vector<int> nums = {-3,4,3,90};
    std::vector<int> result;
    int target = 0;
    result = solution.twoSum(nums,target);
    for(auto& itr : result)
    {
        std::cout << itr << " ";
    }
    std::cout << std::endl;
    return 0;
}
