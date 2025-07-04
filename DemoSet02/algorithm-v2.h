#pragma once
#include "generic-list.h"



template<typename Ptr,typename Data, typename Matcher>
List<Data>* findAll( Ptr start, Ptr end, Matcher matcher){
    
    auto result=new List<Data>;
    auto ptr=start;
    while(ptr!=end){
        auto v=(Data)*ptr;
        if(matcher(v))
            result->Append(v);
        ++ptr;
    }

    return result;
}

template<typename Ptr, typename Matcher>
auto searchAll( Ptr start, Ptr end, Matcher matcher){

    auto data=*start;
    auto result=new List<decltype(data)>;
    auto ptr=start;
    while(ptr!=end){
        auto v=*ptr;
        if(matcher(v))
            result->Append(v);
        ++ptr;
    }

    return result;
}




template<typename Ptr>
List<int>* searchEvens( Ptr start, Ptr end){
    List<int> * result=new List<int>;
    auto ptr=start;
    while(ptr!=end){
        auto v=*ptr;
        if(v%2==0)
            result->Append(v);
        ++ptr;
    }

    return result;
}
template<typename Ptr>
List<int>* searchRange( Ptr start, Ptr end, int min, int max){
    List<int> * result=new List<int>;
    auto ptr=start;
    while(ptr!=end){
        auto v= *ptr;
        if(v>=min && v<=max)
            result->Append(v);
        ++ptr;
    }

    return result;
}

template<typename Ptr>
void show(const char * prompt, Ptr start, Ptr end){
    cout<< prompt <<":\t";
    
    for(auto ptr=start; ptr!=end; ptr++){
        cout<<(*ptr)<<"\t";
    }
    cout<<endl;
}
template<typename Ptr>
void println(const char * prompt, Ptr start, Ptr end){
    cout<< prompt <<"\n";
    
    for(auto ptr=start; ptr!=end; ptr++){
        cout<<(*ptr)<<endl;
    }
    cout<<"---------"<<endl<<endl;
}

template<typename Container>
void appendValues(Container&container, int count, int fillValue=0){
    for(auto i=0;i<count;i++){
        container.Append(fillValue);
    }
}

template<typename Ptr, typename T>
void setValues(Ptr begin, Ptr end, T fillValue){
    for(auto ptr=begin; ptr!=end; ++ptr)
        *ptr=fillValue;
}


template<typename Ptr>
double average(Ptr start, Ptr end){
    double sum=0;
    int count=0;
    for(auto ptr=start; ptr!=end; ++ptr){
        sum+=*ptr;
        count++;
    }

    return sum/count;
}

