#include <iostream>
#include <thread>

using namespace std;

void ShowThreadInfo()
{
    auto id = this_thread::get_id();
    cout<<"Current Thread Id :"<<id<<endl;
}

int main()
{
    ShowThreadInfo();
}