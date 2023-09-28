#include<iostream>
#include <bits/stdc++.h>


using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

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

        A = new int[size];

        cout<<"Enter Elements of Array : "<<endl;
        for(int i=0;i<length;i++)
        {
            cout<<"Enter ["<<i<<"] elemnt : "<<flush;
            cin>>A[i];

        }
        
        
        
    }

    void Display();
    void Insert(int index, int key);
    int Delete(int index);
    int Get(int index);
    void Set(int index, int key);
    void Append(int value);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int max();
    int min();
    int sum();
    float avg();
    void InsertSort(int value);
    void Reverse();
    int isSorted();
    Array MergeSort(Array &B);
    Array Union(Array &B);
    Array Intersection(Array& B);
    Array Difference(Array &B);



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

    Array A(size,length);
    A.Display();


    return 0;
}


void Array::Display()
{
    cout<<"Elements of list are : ";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";   
    cout<<endl; 
}

void Array::Insert(int index, int key)
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

int Array::Delete(int index)
{
    int x=A[index];
    for(int i=index;i<length;i++)
        A[i]=A[i+1];
    length--;
    return x;
}

int Array::Get(int index)
{
    return A[index];
}

void Array::Set(int index, int key)
{
    if(index>=0 && index<=length)
        A[index]=key;

    else cout<<"Invalid Index"<<endl;

}

void Array::swap(int *x, int *y)
{
    int temp=*x;
    *x = *y;
    *y = temp;
}

void Array::Append(int value)
{
    A[length]=value;
    length++;
}

int Array::LinearSearch(int key)
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

int Array::BinarySearch(int key)
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

int Array::max(){
    int max=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]>max) max=A[i];
    }
    return max;

}

int Array::min()
{
    int min=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]<min) min=A[i];
    }
    return min;

}

int Array::sum()
{
    int sum=0;
    for(int i=0;i<length;i++)
    {
        sum+=A[i];
    }
    return sum;

}

float Array::avg()
{
    return sum()/length;
}

void Array::InsertSort(int value)
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

void Array::Reverse()
{
    int *B;
    B = new int[size];
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

int Array::isSorted()
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

Array Array::MergeSort(Array &B)
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

Array Array::Union(Array &B)
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

Array Array::Intersection(Array& B)
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

Array Array::Difference(Array &B)
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
