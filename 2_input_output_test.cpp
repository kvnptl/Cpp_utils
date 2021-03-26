#include <iostream>

using std::cout;
using std::cin;


//add testing functions here

void single_input(){
    int a {0};
    cout << "Enter integer: ";
    cin >> a;
    cout << "Received: " << a << "\n";
}

void multiple_inputs(){
    int a,b;
    cout << "Enter integers(a b): ";
    cin >> a >> b;
    cout << "Received: " << a << " and " << b << "\n";
}


int main(){
    
    //single input value
    // single_input();
    
    //multiple inputs
    multiple_inputs();
 
}