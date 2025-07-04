#pragma once
#include "list.h"
#include "utils.h"
using namespace conceptarchitect::data;
using namespace conceptarchitect::utils;

LinkedList<int> findPrimes(LinkedList<int> values){
   
   LinkedList<int> result;
   for(auto value :values){
      if(isPrime(value)){
         result.Add(value);
      }

   }

   return result;
}


LinkedList<int> findEvens(LinkedList<int> values){
   LinkedList<int> result;
   for(auto value :values){
      if(value%2==0){
         result.Add(value);
      }
   }
   return result;
}
