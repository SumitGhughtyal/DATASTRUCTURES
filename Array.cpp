#include<iostream>
#include <bits/stdc++.h>


using namespace std;

template<class T>
class Array
{
private:
    T *A;
    int size;
    int length;
    void swap(T *x, T *y);

public:
    Array(int size, int length)
    {
        if (length>size)
        {
            cout<<"Length cannot be greater than size";
            exit(0);            /* code */
        }
        this->size=size;
        this->length=length;

        A = new T[size];

        cout<<"Enter Elements of Array : "<<endl;
        for(int i=0;i<length;i++)
        {
            cout<<"Enter ["<<i<<"] elemnt : "<<flush;
            cin>>A[i];

        }
        
        
        
    }

    void Display();
    void Insert(int index, T key);
    T Delete(int index);
    T Get(int index);
    void Set(int index, T key);
    void Append(T value);
    int LinearSearch(T key);
    int BinarySearch(T key);
    T max();
    T min();
    int sum();
    float avg();
    void InsertSort(T value);
    void Reverse();
    int isSorted();
    Array<T> MergeSort(Array<T> &B);
    Array<T> Union(Array<T> &B);
    Array<T> Intersection(Array<T>& B);
    Array<T> Difference(Array<T> &B);



    ~Array()
    {
        delete[] A;
    }

};



int main()
{
    int length, size;

    cout<<"Enter size of the Array : "<<flush;
    cin>>size;
    cout<<"Enter length of the Array : "<<flush;
    cin>>length;

    Array<int> A(size,length);
    A.Display();


    return 0;
}

template<class T>
void Array<T>::Display()
{
    cout<<"Elements of list are : ";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";   
    cout<<endl; 
}
template<class T>
void Array<T>::Insert(int index, T key)
{
    if(length==size){ cout<<"Array is Full."; exit(0);}
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>=index;i--)  A[i+1]=A[i];
        A[index]=key;
        length++;        
    }
    else cout<<"Invalid Index"<<endl;
}
template<class T>
T Array<T>::Delete(int index)
{
    T x=A[index];
    for(int i=index;i<length;i++)
        A[i]=A[i+1];
    length--;
    return x;
}

template<class T>
T Array<T>::Get(int index)
{
    return A[index];
}

template<class T>
void Array<T>::Set(int index, T key)
{
    if(index>=0 && index<=length)
        A[index]=key;

    else cout<<"Invalid Index"<<endl;

}

template<class T>
void Array<T>::swap(T *x, T *y)
{
    T temp=*x;
    *x = *y;
    *y = temp;
}

template<class T>
void Array<T>::Append(T value)
{
    A[length]=value;
    length++;
}

template<class T>
int Array<T>::LinearSearch(T key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(A[i]==key)
        {
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(T key)
{
    sort(A, A+length);
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==A[mid]) return mid;
        else if(key<A[mid]) h=mid-1;
        else l=mid+1;
    }

    return -1;

}

template<class T>
T Array<T>::max(){
    T max=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]>max) max=A[i];
    }
    return max;

}

template<class T>
T Array<T>::min()
{
    T min=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]<min) min=A[i];
    }
    return min;

}

template<class T>
int Array<T>::sum()
{
    int sum=0;
    for(int i=0;i<length;i++)
    {
        sum+=(int)A[i];
    }
    return sum;

}

template<class T>
float Array<T>::avg()
{
    return sum()/length;
}

template<class T>
void Array<T>::InsertSort(T value)
{
    sort(A, A+length);
    if(length==size){ cout<<"Array is Full."; exit(0);}
    int i= length-1;
    while(i>=0 && A[i]>value)
    {
        A[i+1]=A[i];
        i--;
    }

    A[i+1]=value;
    length++;

}

template<class T>
void Array<T>::Reverse()
{
    T *B;
    B = new T[size];
    int i,j;
    for(int i=length-1,j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    }
    for(int i=0;i<length;i++)
    {
        A[i]=B[i];
    }

    delete[] B;
    
}

template<class T>
int Array<T>::isSorted()
{
    for(int i=0;i<length;i++)
    {
        if(A[i]<A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

template<class T>
Array<T> Array<T>::MergeSort(Array<T> &B)
{
    Array C(size+B.size, length+B.length);
    int i,j,k;
    i=j=k=0;

    while(i<length && j<B.length)
    {
        if(A[i]<B.Get(j))
            C.Set(k++, A[i++]);
        else {
            C.Set(k++, B.Get(j++));
        }
    }

    for(;i<length;i++)
    C.Set(k++, A[i]);
    for(;j<B.length;j++)
    C.Set(k++, B.Get(j));
    C.length=k;

    return C;
}

template<class T>
Array<T> Array<T>::Union(Array<T> &B)
{
    Array C(size+B.size, length+B.length);
    int i,j,k;
    i=j=k=0;

    while(i<length && j<B.length)
    {
        if(A[i]<B.Get(j))
            C.Set(k++, A[i++]);
        else if(A[i]>B.Get(j)){
            C.Set(k++, B.Get(j++));
        } else {
            C.Set(k++, A[i++]);
            j++;
        }
    }

    for(;i<length;i++)
    C.Set(k++, A[i]);
    for(;j<B.length;j++)
    C.Set(k++, B.Get(j));
    C.length=k;

    return C;
}

template<class T>
Array<T> Array<T>::Intersection(Array<T>& B)
{
    Array C(size+B.size, length+B.length);
    int i,j,k;
    i=j=k=0;

    while(i<length && j<B.length)
    {
        if(A[i]<B.Get(j))
            i++;
        else if(A[i]>B.Get(j)){
            j++;
        } else {
            C.Set(k++, A[i++]);
            j++;
        }
    }

    
    C.length=k;

    return C;
}

template<class T>
Array<T> Array<T>::Difference(Array<T> &B)
{
    Array C(size+B.size, length+B.length);
    int i,j,k;
    i=j=k=0;

    while(i<length && j<B.length)
    {
        if(A[i]<B.Get(j))
            C.Set(k++, A[i++]);
        else {
            i++;
            j++;
        }
    

    for(;i<length;i++)
    C.Set(k++, A[i]);
    
    C.length=k;

    return C;

}
}
