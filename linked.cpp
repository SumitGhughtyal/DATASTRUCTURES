#include<iostream>

using namespace std;


class Node
{
public:
    int Data;
    Node* next;

};

class LinkedList
{
private:
    Node* first;
    Node* third;
public:
    LinkedList(){first=NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    void append(int x);
    void sortInsert(int x);
    int Length();
    int Delete(int index);
    int max();
    int min();
    int sum();
    int Search(int key);
    bool isSorted();
    void RemoveD();
    void Reverse();
    void concatenate(LinkedList l1);   
    LinkedList merge(LinkedList l1);

    

};

LinkedList LinkedList::merge(LinkedList l1)
{
    LinkedList mergedList;
    Node *p=first;
    Node *q=l1.first;

    while (p && q) {
            if (p->Data < q->Data) {
                mergedList.append(p->Data);
                p = p->next;
            } else {
                mergedList.append(q->Data);
                q = q->next;
            }
        }
    while (p) {
            mergedList.append(p->Data);
            p = p->next;
        }

    while (q) {
            mergedList.append(q->Data);
            q = q->next;
        }

    return mergedList;

}



void LinkedList::concatenate(LinkedList l1)
{
    Node *p=first;
    while(p->next!=NULL) p=p->next;

    p->next=l1.first;
    l1.first=NULL;
}

void LinkedList::Reverse()
{
    Node *r=NULL, *q=NULL, *p=first;

    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }

    first=q;
}

void LinkedList::RemoveD()
{
    Node *p, *q;
    p=first;
    q=p->next;

    while(q)
    {
        if(p->Data!=q->Data)
        {
            p=q;
            q=q->next;
        } 
        else{
            p->next=q->next;
            delete(q);
            q=p->next;

        }
        
    }
}

bool LinkedList::isSorted()
{
    int x=INT32_MIN;
    Node *p=first;

    while(p)
    {
        if(p->Data<x) return true;
        x=p->Data;
        p=p->next;
    }
    return false;
}

void LinkedList::sortInsert(int x)
{
    Node *p, *q, *temp;
    temp = new Node;
    q=NULL;
    p=first;
    temp->Data=x;
    temp->next=NULL;
    
    if(first==NULL)
    {
        first=temp;
    } else{
        while(p->Data<x && p)
        {
            q=p;
            p=p->next;

        }
        
        if(p==first)
        {
            temp->next=first;
            first=temp;
        } else{
            temp->next=q->next;
            q->next=temp;
        }
        
    }
}

void LinkedList::append(int x)
{
    Node *p, *t;
    p=first;
    t = new Node;
    t->Data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }
    else{
        while(p->next!=NULL) p=p->next;
        p->next=t;
    }
}

int LinkedList::Search(int key)
{
    Node *p=first;
    int i=1;
    while(p)
    {
        if(key==p->Data) return i;
        i++;p=p->next;
    }
    return -1;

}

int LinkedList::sum()
{
    int s=0;
    Node *p=first;
    while(p)
    {
        s+=p->Data;
        p=p->next;
    }
    return s;
}

int LinkedList::min()
{
    int m=INT32_MAX;
    Node *p=first;
    while(p)
    {
        if(m<p->Data) m =p->Data;
        p=p->next;
    }
    return m;
}

int LinkedList::max()
{
    int m=INT32_MIN;
    Node *p=first;
    while(p)
    {
        if(m>p->Data) m=p->Data;
        p=p->next;
    }
    return m;
}

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *temp;
    int i=0;

    first = new Node;
    first->Data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        temp = new Node;
        temp->Data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;

    }


}

LinkedList::~LinkedList()
{
    Node* p =first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList::Display()
{
    Node *p = first;

    while(p)
    {
        cout<<p->Data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int LinkedList::Length()
{
    Node *current=first;
    int count=0;
    while(current)
    {
        count++;
        current=current->next;
    }
    return count;
}

void LinkedList::Insert(int index, int x)
{
    Node *q, *p=first;

    if(index<0 || index>Length()){cout<<"Invalid Index."<<endl;return;}
    q = new Node;
    q->Data=x;
    q->next=NULL;

    if(index==0)
    {
        q->next=first;
        first=q;
    } else{
        for(int i=1;i<index-1;i++) p=p->next;
        q->next=p->next;
        p->next=q;
                
    }
}

int LinkedList::Delete(int index)
{
    Node *p, *q=NULL;
    int x=-1;

    if(index<0 || index>Length()) {cout<<"Invalid Index."<<endl; return x;}
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->Data;
        delete(p);
    } else {
        p=first;
        for(int i=0;i<index-1;i++) {q=p;p=p->next;}
        q->next=p->next;
        x=p->Data;
        delete(p);
    }
    return x;

}

int main()
{
    int A[]={1,2,3,4,5};
    int B[]={2,3,4,5,6};
    
    LinkedList l(A,5);
    LinkedList l2(B,5);
    LinkedList l3 = l.merge(l2);

    

    
    l3.Display();
    

    return 0;

}
