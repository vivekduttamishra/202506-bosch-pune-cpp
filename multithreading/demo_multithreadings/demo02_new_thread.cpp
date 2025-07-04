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
    thread newThread(ShowThreadInfo); //run this function on a separate thread

    ShowThreadInfo(); //runs the same function on current thread.

    //wait for the other threads to finish and join
    newThread.join(); 
    cout<<"Main Program Ends"<<endl;
}