#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty())
        {
            return s;
        }

        if(1 == numRows)
        {
            return s;
        }
        int s_size = s.size();
        char* buff = new char[s_size+1];
        buff[s_size+1] = '\0';
        int buff_pos = 0;
        int param1 = 2 * numRows - 2;
        const char* data = s.data();
        int temp_index = 0;
        int temp_index2 = 0;
        //int start_number = s_size / numRows;
        for(auto i = 0; i < numRows; i++)
        {
            if(i == 0 || i == numRows-1)
            {
                for(auto j = 0;;j++)
                {
                    temp_index = i + j * param1;
                    if(temp_index >= s_size)
                    {
                        break;
                    }
                    buff[buff_pos++] = data[temp_index];
                    //cout << "1 temp index:" << temp_index << "  buff pos:" << buff_pos - 1 << "  buff value:" << buff[buff_pos-1] << endl;
                }
            }
            else
            {
                for(auto j = 0;;j++)
                {
                    if(0 == (j % 2))
                    {
                        temp_index = i + (j / 2) * param1;
                        if(temp_index >= s_size)
                        {
                            break;
                        }   
                        buff[buff_pos++] = data[temp_index];
                        //cout << "2 temp index:" << temp_index << "  buff pos:" << buff_pos - 1 << "  buff value:" << buff[buff_pos-1] << endl;
                    }
                    else
                    {
                        temp_index2 = param1 * (j / 2) + 2 * numRows - i - 2;
                        if(temp_index2 >= s_size)
                        {
                            break;
                        }   
                        buff[buff_pos++] = data[temp_index2];
                        //cout << "3 temp index:" << temp_index2 << "  buff pos:" << buff_pos - 1 << "  buff value:" << buff[buff_pos-1] << endl;
                    }
                }
            }
        }
        return buff;
    }
};

const static string test1 = {"PAYPALISHIRING"};
const static string test2 = {"PAYP"};
const static string test3 = {"wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"};
int main(void)
{
    Solution solution;
    cout << solution.convert(test1,4) << endl;
    cout << "******************************" << endl;
    cout << solution.convert(test2,3) << endl;
    cout << "******************************" << endl;
    cout << solution.convert(test3,61) << endl;
    return 0;
}
