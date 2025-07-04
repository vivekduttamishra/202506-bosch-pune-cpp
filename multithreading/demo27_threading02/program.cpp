#include <iostream>
#include <thread>
using namespace std;

void longRunningTask(int delay)
{
   auto id= this_thread::get_id();
   cout<<"Thread "<<id<<" started"<<endl;
   this_thread::sleep_for(chrono::milliseconds(delay));
   cout<<"Thread "<<id<<" finished"<<endl;
}


int main()
{
   thread t2(longRunningTask, 5000);
   thread t3(longRunningTask, 4000);
  
   t2.join();
   t3.join();


   return 0;
}

  

