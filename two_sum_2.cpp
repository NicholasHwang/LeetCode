#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int numbers_size = numbers.size();
        auto forward_index = 0;
        auto backforward_index = numbers_size - 1;
        std::vector<int> result;
        for(; (backforward_index > 0) && (forward_index < numbers_size); )
        {
            if(backforward_index <= forward_index)
            {
                break;
            }
            int sum = numbers[forward_index] + numbers[backforward_index];
            if(sum > target)
            {
                backforward_index--;
                continue;
            }
            else if(sum < target)
            {
                forward_index++;
                continue;
            }
            if(sum == target)
            {
                result.push_back(forward_index+1);
                result.push_back(backforward_index+1);
                break;
            }
        }
        return result;       
    }
};


int main(void)
{
    Solution solution;
    std::vector<int> numbers = {2,3,4};
    int target = 6;
    std::vector<int> result;
    result = solution.twoSum(numbers,target);
    for(auto& itr : result)
    {
        std::cout << itr << " ";
    }
    std::cout << std::endl;
    return 0;
}
