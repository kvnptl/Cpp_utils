#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::string;

//print vector
//making generic function argument
//now it can take any data type of vector (ex. int, float, string...)
template <typename T>
void print_2d_vector(const T &vect){

    for (auto i:vect) {cout << i << " ";};
    cout << "\n";
}

//static function argument data type
void sort_vector_w_index(vector<int> &inp_vect){
    vector<int> V (inp_vect.size());
    std::iota(V.begin(), V.end(), 0);
    sort(V.begin(), V.end(), [&](int i, int j){ return inp_vect[i] < inp_vect[j]; } );
    print_2d_vector(V);
}

//sort vector in ascending order
//making generic function argument
//now it can take any data type vector (ex. int, float, string...)
template <typename T>
void sort_vector_w_index_generic(T &inp_vect){
    vector<int> V (inp_vect.size());
    std::iota(V.begin(), V.end(), 0);

    //ascending order
    sort(V.begin(), V.end(), [&](int i, int j){ return inp_vect[i] < inp_vect[j]; });
    
    //descending order
    // sort(V.begin(), V.end(), [&](int i, int j){ return inp_vect[i] > inp_vect[j]; });

    cout << "Sorted: ";
    print_2d_vector<vector<int>>(V);
    T temp_vect = inp_vect;
    for (int i=0, j=0; i<inp_vect.size() && j<inp_vect.size(); i++, j++){
         
         inp_vect[i] = temp_vect[V[j]];
    }
    print_2d_vector<vector<float>>(inp_vect);
}


int main(){
    vector<float> A {22.5, 91.1, 5.0};
    print_2d_vector<vector<float>>(A);
    sort_vector_w_index_generic<vector<float>>(A);


}