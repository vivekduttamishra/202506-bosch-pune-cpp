#include <iostream>
#include <vector>
#include <memory>
#include "generic-list.h"
#include "algorithm-v2.h"
using namespace std;


int main(){

    int values[5];
    vector<int> valueVector;
    List<int> valueList;

    for(auto i=0;i<5;i++){
        values[i]=i+1;
        valueVector.push_back(i+1);
        valueList.Append(i+1);
    }

    //we can calculate average for all of them using my algorithm

    cout<<"array average:" << average(values, values+5)<<endl;
    cout<<"vector average:" << average(valueVector.begin(), valueVector.end()) <<endl;
    cout<<"list average:" <<    average(valueList.begin(), valueList.end()) <<endl;

    return 0;
}