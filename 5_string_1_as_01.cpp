#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

using std::cout;
using std::string;
using std::vector;

int main()
{
    int a = 2;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << a;
    cout << "Result: " << ss.str() << "\n";
}