#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numOfLIS(vector<int>& nums)
    {
         int nums_size = nums.size();
        if(0 == nums_size || 1 == nums_size)
        {
            return nums_size;
        }
        vector<int> mins(nums_size);
        vector<int> count(nums_size);
        mins[0] = 0;
        int max = 0;
        int temp = 0;
        count[0] = 1;
        count[1] = 1;
        for(auto data : nums)
        {
            int index = bs(mins,data,max);
            mins[index] = data;
            //max = max < index ? index : max;
            if(max == index)
            {
                count[index] += 1;
            }
            else if(max < index)
            {
                max = index;
                count[index] = count[index-1];
            }
            temp++;
        }
        temp = 0;
        cout << "max:" << max << endl;
        for(auto data : count)
        {
            temp = temp < data ? data : temp;
        }
        return temp;
    };
    int lengthOfLIS(vector<int>& nums) {
#if 0
        int nums_size  = nums.size();
        if(0 == nums_size || 1 == nums_size)
        {
            return nums_size;
        }

        vector<int> length_array(nums_size,1);
        int i = 0;
        int max = 1;
        for(i = 1; i < nums_size; i++)
        {
            for(auto j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    length_array[i] = (length_array[j]+1) > length_array[i] ? (length_array[j]+1) : length_array[i];
                    max = max > length_array[i] ? max : length_array[i];
                }
            }
        }
        return max;
#endif
        int nums_size = nums.size();
        if(0 == nums_size || 1 == nums_size)
        {
            return nums_size;
        }
        vector<int> mins(nums_size);
        mins[0] = 0;
        int max = 0;
        for(auto data : nums)
        {
            int index = bs(mins,data,max);
            mins[index] = data;
            max = max < index ? index : max;
        }
        return max;
    };
    int bs(vector<int>& mins, int data, int size)
    {
        int start = 0;
        while(start < size)
        {
            int mid = size - (size - start) / 2;
            if(mins[mid] < data)
            {
                start = mid;
            }
            else
            {
                size = mid - 1;
            }
        }
        return start + 1;
    }
};

int main(void)
{
    vector<int> nums = {
        10,9,2,5,3,7,101,18
    };
    vector<int> nums2 = {
        10,2,3,11,12,13,14
    };
    vector<int> nums3 = {
        1,2,3,4,5,6,7,8,0,9
    };
    vector<int> nums4 = {
        9,8,7,6,5,4,3,2,1
    };
    vector<int> nums5 = {
        10,2,3,11,12,13,4,14
    };
    vector<int> nums6 = {
        4,10,4,3,8,9
    };
    vector<int> nums7 = {4,10,4};
    vector<int> nums8 = {2,5,3};
    Solution solution;
    cout << solution.numOfLIS(nums) << endl;
    cout << solution.numOfLIS(nums7) << endl;
    /*cout << solution.lengthOfLIS(nums) << endl;*/
    //cout << solution.lengthOfLIS(nums2) << endl;
    //cout << solution.lengthOfLIS(nums3) << endl;
    //cout << solution.lengthOfLIS(nums4) << endl;
    //cout << solution.lengthOfLIS(nums5) << endl;
    /*cout << solution.lengthOfLIS(nums6) << endl;*/
    return 0;
}
