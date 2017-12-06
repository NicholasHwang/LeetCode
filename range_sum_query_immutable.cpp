#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class NumArray {
public:
    vector<int> m_int_vec;
    NumArray(vector<int> nums) {
        int sum_value = 0;
        for(auto value : nums)
        {
            sum_value += value;
            m_int_vec.push_back(sum_value);  
        }
    }

    int sumRange(int i, int j) {
        if(i == j)
        {
            return 0;
        }
        else if(i == 0)
        {
            return m_int_vec[j];
        }
        return m_int_vec[j] - m_int_vec[i-1];
    }
};

int main(void)
{
    vector<int> nums = {-2,0,5,-5,2,-1,INT_MIN};
    NumArray obj(nums);
    cout << obj.sumRange(0,2) << endl;
    cout << obj.sumRange(2,5) << endl;
    cout << obj.sumRange(0,6) << endl;
    return 0;
}
