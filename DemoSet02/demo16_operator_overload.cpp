#include <iostream>
using namespace std;
#include "list.h"
#include "errors.h"

List operator*(const List &l1,  const List &l2){

    if(l1.size != l2.size){
        throw InvalidArgument {"Lists must be of same length for multiplication"};
    }

    List result;
    Node *left= l1.first;
    Node *right= l2.first;
    while(left){
        result.Append(left->data * right->data);
        left = left->next;
        right = right->next;
    }
    

    return result;
}



int main(){

    int ratesArray[]={2,11,3,9};
    int qtyArray[]={10,5,15,4};
    List rates, qty;
    for(auto i=0; i<4; i++){
        rates.Append(ratesArray[i]);
        qty.Append(qtyArray[i]);
    }

    rates.Show("Rates");
    qty.Show("Qty");

    //create a price list
    //traditional approach.
    List price= rates * qty;
    price.Show("Price");


    List list1;
    list1.Append(1).Append(2).Append(3).Append(4).Show("List 1");
    List list2;
    list2.Append(5).Append(6).Append(7).Append(8).Show("List 2");

    auto list3 = list1 + list2;
    list3.Show("List 1 + List 2");


   cout<<"end of main\n";
   return 0; 
}