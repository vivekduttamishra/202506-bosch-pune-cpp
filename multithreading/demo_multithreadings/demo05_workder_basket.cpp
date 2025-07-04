#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std::chrono;

using namespace std;

struct Basket
{
    long items=0;
    void AddItem()
    {
        auto i= items;
        i+=1;
        items=i;
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