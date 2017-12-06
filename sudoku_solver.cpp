#include <iostream>
#include <vector>
#include <tuple>
#include <sys/time.h>
using namespace std;

class Solution
{
    public:
        const static int N = 81;
        const static int NEIGHBOR = 20;
        char m_board[N];
        int m_neighbors[N][NEIGHBOR];
        int m_spaces[N];
        int m_nspaces;
        int m_arities[N];
        bool m_available[N][10];
        void solveSudoku(vector<vector<char>>& board)
        {
            int i = 0;
            m_nspaces = 0;
            for(auto& line : board)
            {
                for(auto& data : line)
                {
                    if('.' == data)
                    {
                        m_board[i] = '.';
                        m_spaces[m_nspaces++] = i;
                    }
                    else
                    {
                        m_board[i] = data - '0';
                    }
                    i++;
                }
            }
            CreateNeighbor();
            FillArityInformation();           
            Update();
            i = 0;
            for(auto& line : board)
            {
                for(auto& data : line)
                {
                    data = m_board[i++] + '0';
                }
            }
        }

        int Update()
        {
            int ret = 0;
            int temp = 0;
            bool flag = false;
            if(m_nspaces > 0)
            { 
                auto result = FindMinArity();
                auto min_index = std::get<0>(result);
                auto min_space = std::get<1>(result);
                if(-2 == min_index)
                {
                    return 0;
                }
                else if(-1 == min_index)
                {
                    return -1;
                }
                
                for(auto k = 1; k < 10; k++)
                {
                    if(m_available[min_index][k])
                    {
                        flag = true;
                        m_board[min_index] = k;
                        m_available[min_index][k] = false;
                        m_arities[min_index]--;
                        temp = m_spaces[min_space];
                        m_spaces[min_space] = m_spaces[m_nspaces-1];
                        m_spaces[m_nspaces-1] = 0;
                        m_nspaces--;
                        int temp_array[NEIGHBOR];
                        int temp_count = 0;
                        auto result = UpdateNeighbor(min_index,k,temp_array,temp_count);
                        if(-1 == result)
                        {
                            flag = false;
                            m_board[min_index] = '.';
                            m_available[min_index][k] = true;
                            m_arities[min_index]++;    
                            m_spaces[m_nspaces] = m_spaces[min_space];
                            m_spaces[min_space] = temp;
                            m_nspaces++;
                            for(auto i = 0; i < temp_count; i++)
                            {
                                //cout << temp_array[i] << "  ";
                                m_available[temp_array[i]][k] = true;
                                m_arities[temp_array[i]]++;
                            }
                        }
                        else
                        {
                            ret = Update();
                            if(0 != ret)
                            {
                                flag = false;
                                m_board[min_index] = '.';
                                m_available[min_index][k] = true;
                                m_spaces[m_nspaces] = m_spaces[min_space];
                                m_spaces[min_space] = temp;
                                m_nspaces++;
                                m_arities[min_index]++;
                                for(auto i = 0; i < temp_count; i++)
                                {
                                    m_available[temp_array[i]][k] = true;
                                    m_arities[temp_array[i]]++;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                if(!flag)
                {
                    return -1;
                } 
            }
            return 0;
        }

        std::tuple<int,int> FindMinArity()
        {
            int min_index = -2;
            int min_arity = 9;
            int min_space = 0;
            for(auto i = 0; i < m_nspaces; i++)
            {
                if(0 == m_arities[m_spaces[i]])
                {
                    min_index = -1;
                    break;
                }
                if(min_arity > m_arities[m_spaces[i]])
                {
                    min_index = m_spaces[i];
                    min_space = i;
                    min_arity = m_arities[m_spaces[i]];
                }
            }
            return std::make_tuple(min_index,min_space);
        }

        int UpdateNeighbor(int index,int value,int* temp,int& temp_count)
        {
            bool flag = false;
            for(auto i = 0; i < NEIGHBOR; i++)
            {
                int neighbor_index = m_neighbors[index][i];
                if('.' == m_board[neighbor_index])
                {
                    if(m_available[neighbor_index][value])
                    {
                        m_arities[neighbor_index]--;
                        temp[temp_count++] = neighbor_index;
                        if(0 == m_arities[neighbor_index])
                        {
                            flag = true;
                            break;
                        }
                        m_available[neighbor_index][value] = false;
                    }
                }
            }
            return flag ? -1 : 0;
        }

        void FillArityInformation()
        {
            for(auto m = 0; m < N; m++)
            {
                m_available[m][0] = false;
                for(auto n = 1; n < 10 ; n++)
                {
                    m_available[m][n] = true;
                }

                if('.' != m_board[m])
                {
                    m_arities[m] = 0;
                }
                else
                {
                    m_arities[m] = 9;
                    for(auto l = 0; l < NEIGHBOR; l++)
                    {
                        //cout << "m:" << m << "  l:" << l << "  neighbor index:" << m_neighbors[m][l] << endl;
                        int value = m_board[m_neighbors[m][l]];
                        if('.' != value)
                        {
                            //int temp = value - '1' + 1;                           
                            if(m_available[m][value])
                            {
                                m_arities[m]--;   
                                m_available[m][value] = false;
                            }
                        }
                    }
                }
            }
        }

        void CreateNeighbor()
        {
            for(auto m = 0 ; m < N; m++)
            {
                auto x = m / 9;
                auto y = m % 9;
                auto x_begin = (x / 3) * 3;
                auto x_end = x_begin + 2;
                auto y_begin = (y / 3) * 3;
                auto y_end = y_begin + 2;
                int diff_x = 0;
                int diff_y = 0;
                for(auto n = 0; n < NEIGHBOR; n++)
                {
                    if(n <= 7)
                    {
                        if(diff_y == y)
                        {
                            diff_y++;
                        }

                        //std::cout << "m:" << m << " n:" << n << " diff_y:" << diff_y << " x:" << x;
                        m_neighbors[m][n] = x * 9 + diff_y;
                        //cout << "  neighbor index:" << m_neighbors[m][n] << endl;
                        diff_y++;
                    }
                    else if(n <= 15)
                    {
                        if(diff_x == x)
                        {
                            diff_x++;
                        }

                        //std::cout << "m:" << m << " n:" << n << " diff_x:" << diff_x << " y:" << y;
                        m_neighbors[m][n] = diff_x * 9 + y;
                        //cout << "  neighbor index:" << m_neighbors[m][n] << endl;
                        diff_x++;
                    }
                    else
                    {
                        if(y_begin == y)
                        {
                            if(y_begin < y_end)
                            {
                                y_begin++;
                            }
                            else
                            {
                                x_begin++;
                                y_begin -= 2;
                            }
                        }

                        if(x_begin == x)
                        {
                            if(x_begin < x_end)
                            {
                                x_begin++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        //std::cout << "m:" << m << " n:" << n << " x begin:" << x_begin << " y begin:" << y_begin;
                        m_neighbors[m][n] = x_begin * 9 + y_begin;
                        //cout << "  neighbor index:" << m_neighbors[m][n] << endl;
                        y_begin++;
                        if(y_begin > y_end)
                        {
                            x_begin++;
                            y_begin -= 3;
                        }

                    }
                }
            }
        }
};

#define N '.'
int main(void)
{
    vector<vector<char>> board = {
        {'5','3',N,N,'7',N,N,N,N},
        {'6',N,N,'1','9','5',N,N,N},
        {N,'9','8',N,N,N,N,'6',N},
        {'8',N,N,N,'6',N,N,N,'3'},
        {'4',N,N,'8',N,'3',N,N,'1'},
        {'7',N,N,N,'2',N,N,N,'6'},
        {N,'6',N,N,N,N,'2','8',N},
        {N,N,N,'4','1','9',N,N,'5'},
        {N,N,N,N,'8',N,N,'7','9'}
    };
    vector<vector<char>> board4 = {
        {N,N,'9','7','4','8',N,N,N},
        {'7',N,N,N,N,N,N,N,N},
        {N,'2',N,'1',N,'9',N,N,N},
        {N,N,'7',N,N,N,'2','4',N},
        {N,'6','4',N,'1',N,'5','9',N},
        {N,'9','8',N,N,N,'3',N,N},
        {N,N,N,'8',N,'3',N,'2',N},
        {N,N,N,N,N,N,N,N,'6'},
        {N,N,N,'2','7','5','9',N,N}
    };
#if 1
    vector<vector<char>> board2 = {
        {N,N,N,N,N,2,N,5,N},
        {N,7,8,N,N,N,3,N,N},
        {N,N,N,N,N,4,N,N,N},
        {5,N,N,N,N,N,N,N,N},
        {N,N,N,N,N,N,1,N,N},
        {N,N,N,N,3,N,7,N,8},
        {2,N,N,N,N,N,N,4,N},
        {N,N,N,N,N,5,N,9,N},
        {N,1,N,N,7,N,N,N,N}
    };

    vector<vector<char>> board3 = {
        {7,2,3,N,N,N,1,5,9},
        {6,N,N,3,N,2,N,N,8},
        {8,N,N,N,1,N,N,N,2},
        {N,7,N,6,5,4,N,2,N},
        {N,N,4,2,N,7,3,N,N},
        {N,5,N,9,3,1,N,4,N},
        {5,N,N,N,7,N,N,N,3},
        {4,N,N,1,N,3,N,N,6},
        {9,3,2,N,N,N,7,1,4}
    };
#endif
    Solution solution;
    //struct timeval begin, end;
    //gettimeofday(&begin,nullptr);
    solution.solveSudoku(board4);
    int count = 0;
    for(auto& line : board4)
    {
        for(auto& data : line)
        {
            cout << (int)data << " ";
            count++;
            if((count % 9) == 0)
            {
                cout << endl;
            }
        }
    }
    cout << "********************" << endl;
    //solution.solveSoduku(board2);
    cout << "********************" << endl;
    //solution.solveSoduku(board3);
    //gettimeofday(&end,nullptr);
    //int cost_time = 0;
    //if(end.tv_usec < begin.tv_usec)
    //{
        //cost_time = 1000000 + end.tv_usec - begin.tv_usec;
    //}
    //else
    //{
        //cost_time = end.tv_usec - begin.tv_usec;
    //}
    //cout << "cost time:" << cost_time << endl;
    return 0;
}

