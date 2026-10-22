#ifdef LISTARRAY_H
#define LISTARRAY_H
#include "List.h"

template <typename T>
class ListArray : public List<T> {
    private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;
    void resize(int new_size);

    public:
    ListArray();
    ~ListArray() override;
    void insert(int pos, const T& e) override;
    void append(const T& e) override;
    void prepend(const T& e) override;
    T remove(int pos) override;
    T& get(int pos) override;
    int search(const T& e) const override;
    bool empty() const override;
    int size() const override;
    T operator[](int pos) const;
};
template <typename T>
ListArray<T> :: ListArray() {
    arr = new T[MINSIZE];
    max = MINSIZE;
    n = 0;
}
template<typename T>
void ListArray <T> :: resize(int new_size){
    T* new_arr = new T[new_size];
    for(int i=0; i<n; i++){
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    max = new_size;
}
template<typename T>
void ListArray<T> :: insert(int pos, const T& e){
    if(pos<0 || pos>n){
        throw std::out_out_of_range("Posicion invalida");
    }
    if (n==max){
        resize(max * 2),
    }
    for(int i = n; i>pos;i--){
        arr[i] = arr[i-1]; 
    }
    arr[pos] = e;
    n++;
}
template<typename T>
void ListArray<T> :: append(const T&, e){
    insert(n,e);
}
template<typename T>
void ListArray<T> :: prepend(const T&, e){
    insert(0,e);
}
template<typename T>
T ListArray<T> :: remove(int pos){
    if(pos<0 || pos>=n){
        throw std::out_of_range("Posicion invalida");
    }
    T element = arr[pos];
    for(int i =pos;i<n-1;i++){
        arr[i] = arr[i + 1];
    }
    n--;
    return element;
}
template<typename T>
T& ListArray<T> :: get(int pos){
    if(pos<0 || pos>=n){
        throw std::out_of_range("Posicion invalida");
    }
    return arr[pos];
}
template<typename T>
int ListArray<T> :: search(const T& e) const {
    for(int i = 0; i<n; i++){
        if(arr[i]== e){
            return i;
        }
    }
    return -1;
}
template<typename T>
bool ListArray<T> :: empty() const{
    return n==0;
}
template<typename T>
int ListArray<T> :: size() const{
    return n;
}
template<typename T>
T ListArray<T>::operator[](int pos) const{
    if(pos<0 || pos>=n){
        throw std::out_of_range("Posicion invalida");
    }
    return arr[pos];
}
template<typename U>
std::ostream& operator<<(std::ostream& os, const ListArray<U>& list){
    os<<"[";
    for(int i=0; i<list.n; i++){
        if(i>0){
            os<<",";
        }
        os<<list.arr[i];
    }
    os<<"]";
    return os;
}

#endif
