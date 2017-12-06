#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> table;
        int A_size = A.size();
        int B_size = B.size();
        int temp_length = 0;
        int max_length = 0;
        for(auto i = 0; i < A_size; i++)
        {
            table.push_back(vector<int>(B_size,0));
        }   
        for(auto i = 0; i < A_size; i++)
        {
            table[i][0] = A[i] == B[0] ? 1 : 0;
            max_length = table[i][0] > max_length ? table[i][0] : max_length;
        }
        for(auto j = 0; j < B_size; j++)
        {
            table[0][j] = A[0] == B[j] ? 1 : 0;
            max_length = table[0][j] > max_length ? table[0][j] : max_length;
        }
        for(auto i = 1; i < A_size; i++)
        {
            for(auto j = 1; j < B_size; j++)
            {
                if(A[i] == B[j])
                {
                    //if(A[i-1] == B[j-1])
                    {   
                        table[i][j] = table[i-1][j-1] + 1;
                    }
                    /*else*/
                    //{
                        //table[i][j] = 1;
                    /*}*/
                }
                else
                {
                    //table[i][j] = max(table[i-1][j],table[i][j-1]);
                    table[i][j] = 0;
                }
                temp_length = table[i][j];
                max_length = max_length < temp_length ? temp_length : max_length;
                //cout << "i:" << i << "  j:" << j << "  temp length:" << temp_length << "  max length:" << max_length << endl;
            }
        }
        return max_length;
    }
};

int main(void)
{
    vector<int> A1 = {1,2,3,2,1};
    vector<int> A2 = {1,2,3,2,1,4};
    vector<int> A3 = {1};
    vector<int> A4 = {1,2,3,2,1,3,2,1};
    vector<int> A5 = {1,2,4,2,1,4,7};
    vector<int> A6 = {3,0,0,0};
    vector<int> A7 = {0,1,1,1,1};
    vector<int> B1 = {3,2,1,4,7};
    vector<int> B2 = {3};
    vector<int> B3 = {3,0,0,0};
    vector<int> B4 = {1,0,1,0,1};
    Solution solution;
    cout << solution.findLength(A1,B1) << endl;
    cout << solution.findLength(A2,B1) << endl;
    cout << solution.findLength(A3,B1) << endl;
    cout << solution.findLength(A4,B1) << endl;
    cout << solution.findLength(A5,B1) << endl;
    cout << solution.findLength(A1,B2) << endl;
    cout << solution.findLength(A3,B2) << endl;
    cout << solution.findLength(A6,B3) << endl;
    cout << solution.findLength(A7,B4) << endl;
    return 0;
}
