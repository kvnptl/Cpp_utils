#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>

using std::cout;
using std::string;
using std::vector;

std::string exec(const char *cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    return result;
}

int main()
{
    // unsigned int microsecond = 1000000;
    // usleep(3 * microsecond); //sleeps for 3 second
    string s1;
    s1 = exec("bash ./test.sh");
    // cout << s1;
    float value = std::stof(s1);
    cout << value;
}
