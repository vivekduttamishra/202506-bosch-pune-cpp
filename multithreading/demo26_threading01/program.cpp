#include <iostream>
#include <thread>
using namespace std;

void print_thread_info()
{
   cout << "current thread is " << this_thread::get_id() << endl;
}

void demo01()
{
    auto t1= thread(print_thread_info); //runs this function on a separate thread
   
   print_thread_info(); //call the same function on the main thread

   t1.join(); // main thread waits for t1 to finish.

}

void count_down(int max)
{
   auto id= this_thread::get_id();
   cout<<"[Thread#" << id << "] starts from " << max << endl;
   while (max){
      cout<<"[Thread#" << id << "] " << max << endl;
      max--;
      
   }

   cout<<"[Thread#" << id << "] ends" << endl;
}


int main()
{
   thread t2(count_down, 200);
   thread t3(count_down, 2000);
   thread t4(count_down, 300);

   cout<<"main thread waiting"<<endl;

   t2.join();
   t3.detach(); //if application ends, kill it. I DONT CARE!
   t4.join();

   cout<<"main thread ends" << endl;

  
   return 0;
}

  

