#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    
    // Using a traditional for loop to iterate over the array
    cout<<"using traditional for loop"<<endl;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {
        cout <<  arr[i] << endl;
    }


    cout<<"using range-based for loop"<<endl;
    for(auto numbr :arr){
        cout << numbr << endl;
    }


    return 0;
}