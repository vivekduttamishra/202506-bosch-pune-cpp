#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;


struct Basket
{
   long items=0;
   mutex _mutex;

   void AddItem()
   {
      //_mutex.lock(); //accessed mutually exclusive
      lock_guard guard(_mutex); //automatically calls lock

      auto i=items;
      i+=1;
      items=i;
      //_mutex.unlock();

      //when guard destructor is called, mutex is automatically unlocked
   }
};


void worker(long itemsToAdd, Basket* basket)
{
   for(int i=0; i<itemsToAdd; i++)
   {
      basket->AddItem();
   }
}

void simulateWork(long workerCount, long itemsToAdd, bool useSameBasket=false,string label="")
{
   Basket* theBasket=new Basket;
   vector<thread> workers;
   vector<Basket*> baskets;
   
   for(int i=0; i<workerCount; i++)
   {
      Basket *basket;
      
      if( useSameBasket)
         basket= theBasket ;
      else
         basket= new Basket();

      workers.push_back(thread(worker, itemsToAdd, basket));

      if (!useSameBasket)
         baskets.push_back(basket);
      
   }

   for(int i=0; i<workerCount; i++)
      workers[i].join();

   long totalWorkDone=0;
   if(useSameBasket)
      totalWorkDone=theBasket->items;
   else
      for(auto basket : baskets)
         totalWorkDone+=basket->items;

   cout<<label<<endl;
   cout<<"Total Work done by "<<workerCount<<" workers is "<<totalWorkDone<<endl;

}


int main()
{
  simulateWork(1000,1000, false,"using different baskets");

   simulateWork(1000,1000, true,"using the same basket");

   return 0;
}

  

