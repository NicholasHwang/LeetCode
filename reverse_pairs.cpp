#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int nums_size = nums.size();
        if(0 == nums_size)
        {
            return 0;
        }    
        return mergeSort(nums,0,nums_size-1);
    }

    int mergeSort(vector<int>& nums, int l,int r)
    {
        if(l >= r)
        {
            return 0;
        }

        int mid = l + (r - l) / 2;
        int count = mergeSort(nums,l,mid) + mergeSort(nums,mid+1,r);
        for(auto i = l, j = mid+1; i <= mid; i++)
        {
            while((j <= r) && (nums[i]/2.0 > nums[j])) j++;
            count += j - (mid + 1);
        }
        std::sort(nums.begin()+l,nums.begin()+r+1);
        return count;
    }
};


int main(void)
{
    std::vector<int> nums = {2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647};
    Solution solution;
    std::cout << solution.reversePairs(nums) << std::endl;
    return 0;
}
