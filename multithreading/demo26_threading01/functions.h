#pragma once

namespace conceptarchitect::data
{
    template<typename Data, typename Selector>
    LinkedList<Data> findAll(LinkedList<Data> list, Selector selector)
    {
        LinkedList<Data> result;
        for (auto item : list)
            if(selector(item))
                result<<item;

        return result;
    }


    template<typename List, typename Action>
    void ForEach(List list, Action action)
    {
        for(auto item : list)
        {
            action(item);
        }
    }

}