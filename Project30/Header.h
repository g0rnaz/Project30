#include<iostream>
using namespace std;

template<class T>
class Myvector
{
    T* ptr;
    int size;
public:
    Myvector()
    {
        ptr = nullptr;
        size = 0;
    }
    Myvector(int s)
    {
        size = s;
        ptr = new T[size]{};
    }
    int getsize()
    {
        return size;
    }
    Myvector& setsize(int size, int grow=1) {
        if (this->size < size) {
            T* temp = new T[size + grow + 1];
            for (int i = 0; i < this->size; i++)
            {
                temp[i] = ptr[i];
            }
            for (int i = this->size; i < this->size + grow; i++)
            {
                temp[i] = 0;
            }
            this->size += grow;
            delete[]ptr;
            ptr = new T[this->size + 1];
            for (int i = 0; i < this->size; i++) {
                ptr[i] = temp[i];
            }
            return *this;
        }
    }
    int GetUpperBound() {
        if (ptr != nullptr) {
            for (int i = 0; i < size; i++)
            {
                if (ptr[i] == 0)
                {
                    return i - 1;
                }
            }
        }
        return -1;
    }
    bool isempty() {
        if(ptr == nullptr) {
            return true;
        }
        return false;
    }
    Myvector& freextra() {
        int j = 0;
        int s = 0;
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] != 0)
            {
                s++;
            }
        }
        T* temp = new T[s+ 1];
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] != 0)
            {
                temp[j] = ptr[i];
                j++;
            }
        }
        delete[]ptr;
        ptr = new T[s + 1];
        for (int i = 0; i < s; i++) {
            ptr[i] = temp[i];
            
        }
        size = s;
        return *this;
    }
    void removeall() {
        delete[] ptr;
        size = 0;
    }
    T getat(int i) {
        if (i <= size)
        {
            return ptr[i];
        }
        return 0;
    }
    void setat(T a, int i) {
        if (i <= size)
        {
            ptr[i] = a;
        }
    }
    Myvector& append(Myvector& obj) {
        int j = 0;
        T* temp = new T[size + obj.size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }
        for (int i = size; i < size + obj.size; i++)
        {
            temp[i] = obj.ptr[j];
            j++;
        }
        size += obj.size;
        delete[]ptr;
        ptr = new T[size + 1];
        for (int i = 0; i < size; i++) {
            ptr[i] = temp[i];
        }
        return *this;
    }
    T* getdata() {
        return &ptr[0];
    }
    Myvector& insertat(T a,int ii) {
        T* temp = new T[size + 2];
        for (int i = 0; i < ii; i++)
        {
            temp[i] = ptr[i];
        }
        temp[ii] = a;
        for (int i = ii+1; i < size+1; i++)
        {
            temp[i] = ptr[i-1];
        }
        size++;
        delete[]ptr;
        ptr = new T[size + 1];
        for (int i = 0; i < size; i++) {
            ptr[i] = temp[i];
        }
        return *this;
    }
    Myvector& deleteat(int ii) {
        T* temp = new T[size];
        for (int i = 0; i < ii; i++)
        {
            temp[i] = ptr[i];
        }
        for (int i = ii + 1; i < size + 1; i++)
        {
            temp[i] = ptr[i - 1];
        }
        size--;
        delete[]ptr;
        ptr = new T[size + 1];
        for (int i = 0; i < size; i++) {
            ptr[i] = temp[i];
        }
        return *this;
    }
    Myvector& add(T a, int i)
    {
        if (i >= 0)
        {
            while (i+1 > size)
            {
                setsize(i+1);
            }
            ptr[i] = a;
        }
        return *this;
    }
    Myvector& operator = (Myvector& obj) {
        if (ptr != nullptr) {
            delete[]ptr;
        }
        size = obj.size;
        delete[]ptr;
        ptr = new T[size + 1];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
        return *this;
    }
    T operator[](int i) {
        if (i >= 0 && i <= size) {
            return ptr[i];
        }
        return -1;
    }
    void Init()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand() % 100;
        }
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << "\t";
        }
        cout << endl;

    }
    ~Myvector()
    {
        delete[]ptr;
    }

    void AddBack(T a)
    {
        T* temp = new T[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }
        temp[size] = a;
        delete[]ptr;
        ptr = temp;
        size++;
    }

};
