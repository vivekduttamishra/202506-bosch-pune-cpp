#include <iostream>
using namespace std;


template <typename T>
class Value{
private:
    T value;
public:
    Value()  {
        cout << "Default Value created: " << value << endl;
    }
    Value(T value) : value(value) {
        cout << "Value created: " << value << endl;
    }
    Value(const Value<T> &source) : value(source.value) {
        cout << "Value copied: " << value << endl;
    }

    Value<T> &operator=(const Value<T> &source) {
        if (this != &source) {
            value = source.value;
        }
        cout << "Value assigned: " << value << endl;
        return *this;
    }
};


template <typename K, typename V>
class KeyValuePair{
    Value<K> key;
    Value<V> value;

    public:
    KeyValuePair(Value<K> &key, Value<V> &value): key(key) {
        this->value=value;        
    }
};

int main(){

    Value<int> v1=10;
    Value<int> v2(20);
    
    cout<<"Now craeting KeyValuePair"<<endl;
    KeyValuePair<int, int> kvp(v1, v2);

    return 0;

}