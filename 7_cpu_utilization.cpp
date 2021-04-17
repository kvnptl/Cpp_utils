#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <string>
#include <unistd.h>
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

// TODO: Return the aggregate CPU utilization
float Utilization()
{
    vector<string> cpuString;

    int total_jiffies_1{0}, work_jiffies_1{0};
    int total_jiffies_2{0}, work_jiffies_2{0};

    int work_over_period{0}, total_over_period{0};
    float cpuUsage{0.0};
    int i = 0;

    // time t1
    cpuString = CpuUtilization();
    for (auto c : cpuString)
    {
        total_jiffies_1 += std::stoi(c);
        if (i < 3)
        {
            work_jiffies_1 += std::stoi(c);
        }
        i++;
    }

    // time t2
    unsigned int microsecond = 1000000;
    usleep(3 * microsecond); // sleeps for 3 second
    cpuString = CpuUtilization();
    i = 0;
    for (auto c : cpuString)
    {
        total_jiffies_2 += std::stoi(c);
        if (i < 3)
        {
            work_jiffies_2 += std::stoi(c);
        }
        i++;
    }

    work_over_period = work_jiffies_2 - work_jiffies_1;
    total_over_period = total_jiffies_2 - total_jiffies_1;

    cpuUsage = (work_over_period / float(total_over_period)) * 100.0;

    return cpuUsage;
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
    float c = Utilization();
    cout << "Toal usage: " << c << "\n";
}
