#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
#if 1
        if(0 == n || 1 == n)
        {
            return n;
        }
        int i = 1;
        vector<int> squares_array;
        for(;;i++)
        {
            int temp = i * i;
            if(temp > n)
            {
                break;
            }
            squares_array.push_back(temp);
        }
        int squares_array_size = squares_array.size();
        //BFS
        queue<pair<int,int>> q;//first is left value,second is depth
        unordered_map<int,bool> ump;
        q.push(make_pair(n,1));
        int diff = 0;
        int depth = 0;
        while(!q.empty())
        {
            diff = q.front().first;
            depth = q.front().second;
            q.pop();
            for(auto i = squares_array_size-1; i >= 0; i--)
            {
                if(diff == squares_array[i])
                {
                    return depth;
                }
                else if(diff > squares_array[i])
                {
                    if(ump.find(diff-squares_array[i]) == ump.end())
                    {
                        q.push(make_pair(diff-squares_array[i],depth+1));
                        ump[diff-squares_array[i]] = true;
                    }
                }
            }
        }
        return depth;
        /*for(auto i = squares_array_size-1; i >= 0; i--)*/
        //{
            //length = 1;
            //sum_operation(n-squares_array[i],squares_array,squares_array_size,i,length);
            //cout << "!!!!" << length << endl;
            //min = length < min ? length : min;
        /*}*/
#else
        vector<int> res(n+1, INT_MAX);
        res[0] = 0;
        for (int i=0;i<=n; i++){
            for (int j=1; j*j <= i; j++){
                res[i] = min(res[i-j*j]+1, res[i]);
                cout << i << " " << i-j*j << " " << res[i-j*j] << " " << res[i] << endl;
            }
        }
        return res[n];
#endif
    }
};

/*    int sum_operation(int diff,vector<int>& squares_array,int squares_array_size,int j,int& length)*/
    //{
        //if(0 == diff)
        //{
            //return 0;
        //}
        //int result = -1;
        //for(auto i = squares_array_size-1; i >= 0; i--)
        //{
            ////cout << i << " " << squares_array[i] << " " << diff << endl;
            //if(squares_array[i] <= diff)
            //{
                //result = sum_operation(diff-squares_array[i],squares_array,squares_array_size,i,length);
                //if(-1 == result)
                //{
                    //length--;
                    ////cout << "result is -1    " << i << " " << squares_array[i] << " " << length << endl;
                    //return -1;
                //}
                //else
                //{
                    //length++;
                    ////cout << "result is 0    " << i << " " << squares_array[i] << " " << length << endl;
                    //return 0;
                //}
            //}
        //}
        //return -1;
    //}
/*};*/

int main(void)
{
    Solution solution;
    /*cout << solution.numSquares(12) << endl;*/
    //cout << solution.numSquares(1) << endl;
    //cout << solution.numSquares(0) << endl;
    //cout << solution.numSquares(13) << endl;
    //cout << solution.numSquares(2) << endl;
    /*cout << solution.numSquares(43) << endl;*/
    cout << solution.numSquares(48) << endl;
    return 0;
}
