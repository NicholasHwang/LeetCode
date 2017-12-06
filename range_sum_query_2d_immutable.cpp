#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> m_sum_matrix;
    NumMatrix(vector<vector<int>> matrix) {
        int line_pos = 0;
        int column_pos = 0;
        int sum_value = 0;
        for(auto line: matrix)
        {
            sum_value = 0;
            column_pos = 0;
            m_sum_matrix.push_back(vector<int>(line.size(),0));
            for(auto data: line)
            {
                sum_value += data;
                m_sum_matrix[line_pos][column_pos++] = sum_value;
            }
            line_pos++;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int row_pos = row1;
        int sum_value = 0;
        for(; row_pos <= row2; row_pos++)
        {
            if(0 == col1)
            {
                sum_value += m_sum_matrix[row_pos][col2]; 
            }
            else
            {
                sum_value += m_sum_matrix[row_pos][col2] - m_sum_matrix[row_pos][col1-1];
            }
        }
        return sum_value;
    }
};

int main(void)
{
    vector<vector<int>> nums = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix obj(nums);
    cout << obj.sumRegion(2,1,4,3) << endl;
    cout << obj.sumRegion(1,1,2,2) << endl;
    cout << obj.sumRegion(1,2,2,4) << endl;
    cout << obj.sumRegion(0,2,2,4) << endl;
    return 0;
}
