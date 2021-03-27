#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <string>

using std::cout;
using std::string;
using std::vector;

// TODO: Read and return CPU utilization
vector<string> CpuUtilization()
{
    string line;
    string key;
    vector<string> value;
    string value1, value2, value3, value4, value5, value6, value7, value8, value9,
        value10;
    std::ifstream filestream("/proc/stat");
    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::istringstream linestream(line);
            while (linestream >> key >> value1 >> value2 >> value3 >> value4 >>
                   value5 >> value6 >> value7 >> value8 >> value9 >> value10)
            {
                if (key == "cpu")
                {
                    value.push_back(value1);
                    value.push_back(value2);
                    value.push_back(value3);
                    value.push_back(value4);
                    value.push_back(value5);
                    value.push_back(value6);
                    value.push_back(value7);
                    value.push_back(value8);
                    value.push_back(value9);
                    value.push_back(value10);
                    break;
                }
            }
        }
    }
    return value;
}

//print vector
//making generic function argument
//now it can take any data type of vector (ex. int, float, string...)
template <typename T>
void print_2d_vector(const T &vect)
{

    for (auto i : vect)
    {
        cout << i << " ";
    };
    cout << "\n";
}

int main()
{
    vector<string> s;
    s = CpuUtilization();
    print_2d_vector(s);
}
