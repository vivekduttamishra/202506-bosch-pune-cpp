#include <iostream>
#include <thread>

using namespace std;

void CountDown(int max)
{
    
    auto id = this_thread::get_id();
    
    cout<<"[#"<<id<<"] starts"<<endl;

    while(max>=0){
        cout<<"[#"<<id<<"] counts"<<max<<endl;
        max--;
    }

    cout<<"[#"<<id<<"] ends"<<endl;
    
}

struct Counter{
    int max;

    void operator()(){
        CountDown(max);
    }
};

int main()
{
    thread one(CountDown,200); //pass parameter as secondary argument
    thread two(Counter{150});  //pass functor
    thread three([](){ CountDown(300);} ); //use lambda function

    one.join();
    two.join();
    three.join();

    cout<<"Main Program Ends"<<endl;
}