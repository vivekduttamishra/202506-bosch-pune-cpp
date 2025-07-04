#include <iostream>
#include <thread>

using namespace std;

void CountDown()
{
    int max=200;
    auto id = this_thread::get_id();
    
    cout<<"[#"<<id<<"] starts"<<endl;

    while(max>=0){
        cout<<"[#"<<id<<"] counts"<<max<<endl;
        max--;
    }

    cout<<"[#"<<id<<"] ends"<<endl;
    
}

int main()
{
    thread one(CountDown); //run this function on a separate thread
    thread two(CountDown); //run this function on a separate thread
    thread three(CountDown); //run this function on a separate thread

    one.join();
    two.join();
    three.join();

    cout<<"Main Program Ends"<<endl;
}