#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0;
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int nums1_index = 0;
        int nums2_index = 0;
        bool is_odd = false;
        int total_size = nums1_size + nums2_size;
        int total_index = 0;
        if(0 != (total_size % 2))
        {
            is_odd = true;
        }
        
        int mid_index = total_size / 2;
        double sum = 0;
        int temp = 0;
        if((nums1_size == 0) && (nums2_size == 0))
        {
            result = 0.0;
        }
        else if(nums1_size == 0)
        {
            if(is_odd)
            {
                result = (double)nums2[mid_index];
            }
            else
            {
                sum = nums2[mid_index-1] + nums2[mid_index];
                result = (double)(sum / 2);
            }
        }
        else if(nums2_size == 0)
        {
            if(is_odd)
            {
                result = (double)nums1[mid_index];
            }
            else
            {
                sum = nums1[mid_index-1] + nums1[mid_index];
                result = (double)(sum / 2);
            }
        }
        else
        {
            for(;;)
            {
                if((nums1_index == -1) && (nums2_index == -1))
                {
                    break;
                }

                if(nums1_index == -1)
                {
                    temp = nums2[nums2_index];
                    if((nums2_index + 1) < nums2_size)
                    {
                        nums2_index++;
                    }
                    else
                    {
                        nums2_index = -1;
                    }
                }
                else if(nums2_index == -1)
                {
                    temp = nums1[nums1_index];
                    if((nums1_index + 1) < nums1_size)
                    {
                        nums1_index++;
                    }
                    else
                    {
                        nums1_index = -1;
                    }
                }
                else if(nums1[nums1_index] <= nums2[nums2_index])
                {
                    temp = nums1[nums1_index];
                    if((nums1_index + 1) < nums1_size)
                    {
                        nums1_index++;
                    }
                    else
                    {
                        nums1_index = -1;
                    }
                }
                else
                {
                    temp = nums2[nums2_index];
                    if((nums2_index + 1) < nums2_size)
                    {
                        nums2_index++;
                    }
                    else
                    {
                        nums2_index = -1;
                    }
                }
                
                
                
                if(is_odd)
                {
                    if(total_index == mid_index)
                    {
                        result = temp;
                        break;
                    }
                }
                else
                {
                    if(total_index == (mid_index-1))
                    {
                        sum += temp;
                    }
                    else if(total_index == mid_index)
                    {
                        sum += temp;
                        result = (double)(sum / 2);
                        break;
                    }
                }
                total_index++;      
            }
        }
        return result;   
    }
};

int main(void)
{
    std::vector<int> nums1 = {};
    std::vector<int> nums2 = {1,2};

    Solution solution;
    std::cout << solution.findMedianSortedArrays(nums1,nums2) << std::endl;
    return 0;
}
