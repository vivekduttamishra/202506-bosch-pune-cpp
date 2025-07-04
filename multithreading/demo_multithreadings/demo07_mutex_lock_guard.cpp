#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std::chrono;

using namespace std;

template<typename Lock>
struct LockGuard
{
    Lock & lock;
    LockGuard(Lock &lock): lock(lock)
    {   
        lock.lock();
    }
    ~LockGuard()
    {
        lock.unlock();
    }
};

struct Basket
{
    long items=0;
    mutex lock;
    void AddItem()
    {
        //lock.lock(); //take ownership or wait

        LockGuard<mutex> guard(lock);

        auto n =rand()%100;
        
        auto i= items;
        i+=1;
        items=i;
        if(n<10)
            return;
        
        
        //lock.unlock(); //release ownership.
    }
};

void Worker( Basket *basket, int itemsToAdd)
{
    for( int i=0; i<itemsToAdd;i++)
        basket->AddItem();
}


void DemoWorkerBasket( int workerCount, int itemsToAdd, bool useSameBasket=false)
{
    cout<< workerCount << " worker will add " << itemsToAdd << (useSameBasket?" same ":" different ") << "basket"<<endl;

    vector<thread*> workers;
    vector<Basket*> baskets;
    Basket *commonBasket=new Basket;

    for( int i=0; i<workerCount; i++)  
    {
        auto basket =commonBasket;
        if(!useSameBasket) 
        {
            basket=new Basket();
            baskets.push_back(basket);
        }

        thread *t= new thread([basket,itemsToAdd](){ Worker(basket,itemsToAdd);});
        workers.push_back(t);

    }

    cout<<"All workers sent work. waiting for workers to finish..."<<endl;
    for(auto worker: workers)
        worker->join();


    cout<<"Calculating total items added "<<endl;

    long totalItems=0;

    if(useSameBasket) 
        totalItems=commonBasket->items;
    else
        for_each(baskets.begin(), baskets.end(),[&totalItems](Basket*b){ totalItems+=b->items;});


    cout<<"Total Items Added by all workers: "<<totalItems<<endl;
    cout<<endl<<endl;

}




int main()
{
   DemoWorkerBasket(1000,10000,false); //unshared resource
   
   
   DemoWorkerBasket(1000,10000,true); //shared resource. all workers using same basket.
    

    cout<<"Main Program Ends"<<endl;
}