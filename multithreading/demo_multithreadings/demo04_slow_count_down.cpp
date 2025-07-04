#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono;

using namespace std;

void CountDown(int max)
{
    
    auto id = this_thread::get_id();
    
    cout<<"[#"<<id<<"] starts"<<endl;

    while(max>=0){
        cout<<"[#"<<id<<"] counts"<<max<<endl;
        this_thread::sleep_for(1s);
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
    thread one(CountDown,20); //pass parameter as secondary argument
   

    one.join();
   

    cout<<"Main Program Ends"<<endl;
}