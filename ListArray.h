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

#endif