#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};


///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and doubly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure of Stack

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct NodeStack
{
    T data;
    struct NodeStack *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure of Queue

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct NodeQueue
{
    T data;
    struct NodeQueue *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure of Binary Search Tree

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct BinarySearchTree
{
    struct BinarySearchTree *lchild;
    T data;
    struct BinarySearchTree *rchild;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Singly Linear Linked List

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    private:
        struct NodeS<T> * First;
        int iCount;

    public:
        SinglyLL();
        ~SinglyLL();

        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurrence(T);
        int SearchLastOccurrence(T);
        T Addition(); 
        T Average();  
        T Maximum();
        T Minimum();

        void DisplayPrime();
        void DisplayPerfect();
        int AdditionEven();
        void DigitsSum();
        T SecondMaximum();

        int Frequency(T);
        
        int Reverse();
        void DisplayPalindromeNumber(); 
        void DisplayDigitsProduct();
        void DisplaySmallDigit();
        void DisplayLargeDigit();
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
SinglyLL<T> :: ~SinglyLL()
{
    NodeS<T> *temp = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    NodeS<T> *temp = First;

    cout<<"\nThe Elements of the Singly Linear Linked List are :\n";

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL \n\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        newn->next = First;
        First = newn;
    }

    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        NodeS<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }

    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }

    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *newn = new NodeS<T>;
        newn->data = No;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        NodeS<T> *temp = First;

        First = First->next;
        delete temp;
    }

    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        NodeS<T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iLength)
    {
        DeleteLast();
    }

    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *tempX = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

template<class T>
T SinglyLL<T> :: Average()
{
    T Sum = 0;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return (Sum/iCount);
}

template<class T>
int SinglyLL<T> :: Frequency(T Search)
{
    int iFreq = 0;
    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == Search)
        {
            iFreq++;
        }
    }

    return iFreq;
}

template<class T>
int SinglyLL<T>:: SearchFirstOccurrence(T No)
{
    int iIndex = -1;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
            break;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
int SinglyLL<T>:: SearchLastOccurrence(T No)
{
    int iIndex = -1;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
T SinglyLL<T> :: Addition()
{
    NodeS<T> *temp = First;

    T Sum = 0;

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template<class T>
T SinglyLL<T> :: Maximum()
{
    NodeS<T> *temp = First;

    T Max = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < (temp->data))
        {
            Max = temp->data;
        }

        temp = temp->next;
    }

    return Max;
}

template<class T>
T SinglyLL<T> :: Minimum()
{
    NodeS<T> *temp = First;

    T Min = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > (temp->data))
        {
            Min = temp->data;
        }

        temp = temp->next;
    }

    return Min;
}

template<class T>
int SinglyLL<T> :: AdditionEven()
{
    NodeS<T> *temp = First;

    int SumEven = 0;

    while(temp != NULL)
    {
        if(((temp->data) % 2) == 0)
        {
            SumEven = SumEven + temp->data;
        }

        temp = temp->next;
    }

    return SumEven;
}

template<class T>
void SinglyLL<T> :: DigitsSum()
{
    int iDigit = 0;
    int iSum = 0;
    
    NodeS<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iSum = iSum + iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Sum is :"<<iSum<<"\n";
        iSum = 0;
    }
}

template<class T>
T SinglyLL<T> :: SecondMaximum()
{
    NodeS<T> *temp = First;

    T MaxFirst = temp->data;
    T MaxSecond;

    while(temp != NULL)
    {
        if(((temp->data) > MaxFirst))
        {
            MaxSecond = MaxFirst;
            MaxFirst = temp->data;
        }

        else if((temp->data) > MaxSecond)
        {
            MaxSecond = temp->data;
        }

        temp = temp->next;
    }

    return MaxSecond;
}

template<class T>
void SinglyLL<T> :: DisplayPerfect()
{
    int iSum = 0;
    int iCnt1 = 0;
    int iCnt2 = 0;

    NodeS<T> *temp = First;

    for(iCnt1 = 1; iCnt1 <= iCount; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= (temp->data)/2; iCnt2++)
        {
            if(((temp->data) % iCnt2) == 0)
            {
                iSum = iSum + iCnt2;
            }
        }

        if(iSum == (temp->data))
        {
            cout<<temp->data<<" is a perfect number\n";
        }

        temp = temp->next;
        iSum = 0;
    }

}

template<class T>
void SinglyLL<T> ::DisplayPrime()
{
    NodeS<T> *temp = First;

    int iCount1 = 0;

    while(temp != NULL)
    {
        for(int iCnt = 1; iCnt <= (temp->data); iCnt++)
        {
            if(((temp->data) % iCnt) == 0)
            {
                iCount1++;
            }
        }

        if(iCount1 == 2)
        {
            cout<<temp->data<<" is a prime number\n";
        }

        temp = temp->next;
        iCount1 = 0;
    }
}

template<class T>
int SinglyLL<T> :: Reverse()
{
    int iReverse = 0;
    int iDigit = 0;
    NodeS<T> *temp = First;

    cout<<"After reversing elements :\n";

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            (temp->data) = (temp->data) / 10;
        }

        cout<<"| "<<iReverse<<" | -> ";
        temp = temp->next;
        iReverse = 0;
    }

    cout<<" NULL \n";
}

template<class T>
void SinglyLL<T> :: DisplayPalindromeNumber()
{
    int iReverse = 0;
    int itemp = 0;
    int iDigit = 0;

    NodeS<T> *temp = First;

    cout<<"Palindrome numbers are :\n";

    while(temp != NULL)
    {
        itemp = temp->data;

        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            temp->data = (temp->data) / 10;
        }

        if(iReverse == itemp)
        {
            cout<<"|"<<itemp<<"| "<<"\t";
        }

        temp = temp->next;
        iReverse = 0;
    }
}

template<class T>
void SinglyLL<T> :: DisplayDigitsProduct()
{
    int iMult = 1;
    int iDigit = 0;

    NodeS<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;

            if(iDigit == 0)
            {
                iDigit = 1;
            }

            iMult = iMult * iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Product is :"<<iMult<<"\n";
        iMult = 1;
    }

}

template<class T>
void SinglyLL<T> :: DisplaySmallDigit()
{
    int iSmallDigit = 9;
    int iDigit = 0;

    NodeS<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 0)
            {
                iSmallDigit = iDigit;
                break;
            }

            if(iSmallDigit > iDigit)
            {
                iSmallDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Smallest digit is :"<<iSmallDigit<<"\n";
        iSmallDigit = 9;
    }
}

template<class T>
void SinglyLL<T> :: DisplayLargeDigit()
{
    int iLargeDigit = 0;
    int iDigit = 0;

    NodeS<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 9)
            {
                iLargeDigit = iDigit;
                break;
            }

            if(iLargeDigit < iDigit)
            {
                iLargeDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Largest digit is :"<<iLargeDigit<<"\n";
        iLargeDigit = 0;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Singly Circular Linked List

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    private:
        struct NodeS<T> * First;
        struct NodeS<T> * Last;
        int iCount;

    public:
        SinglyCL();
        ~SinglyCL();

        void Display();
        int Count();
    
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
    
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurrence(T);
        int SearchLastOccurrence(T);
        T Addition(); 
        T Average();  
        T Maximum();
        T Minimum();
        int Frequency(T);

        void DisplayPrime();
        void DisplayPerfect();
        int AdditionEven();
        void DigitsSum();
        T SecondMaximum();
        
        int Reverse();
        void DisplayPalindromeNumber(); 
        void DisplayDigitsProduct();
        void DisplaySmallDigit();
        void DisplayLargeDigit();
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
SinglyCL<T> :: ~SinglyCL()
{
    NodeS<T> *temp = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeS<T> *temp = First;

    cout<<"\nThe Elements of Singly Circular Linked List are :\n";

    if((First != NULL) && (Last != NULL))
    {
        do
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp->next;
        }while(temp != (Last->next));

        cout<<"\n";
    }

    else
    {
        cout<<"Singly Circular Linked List is empty\n";
    }
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }

    else
    {
        newn->next = First;
        First = newn;
    }

    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }

    else
    {
        Last->next = newn;
        Last = newn;
    }

    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }

    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }

    else
    {
        NodeS<T> *newn = new NodeS<T>;
        NodeS<T> *temp = First;

        newn->data = No;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    else if(First == Last)
    {
        delete First;

        First = NULL;
        Last = NULL;
    }

    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    else if(First == Last)
    {
        delete First;

        First = NULL;
        Last = NULL;
    }

    else
    {
        NodeS<T> *temp = First;

        while(temp->next->next != First)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = First;
        Last = temp;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iLength)
    {
        DeleteLast();
    }

    else
    {
        
        NodeS<T> *temp = First;
        NodeS<T> *tempX = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

template<class T>
int SinglyCL<T> :: Frequency(T Search)
{
    int iFreq = 0;
    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == Search)
        {
            iFreq++;
        }
    }

    return iFreq;
}

template<class T>
T SinglyCL<T> :: Average()
{
    T Sum = 0;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return (Sum/iCount);
}

template<class T>
int SinglyCL<T>:: SearchFirstOccurrence(T No)
{
    int iIndex = -1;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
            break;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
int SinglyCL<T>:: SearchLastOccurrence(T No)
{
    int iIndex = -1;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
T SinglyCL<T> :: Addition()
{
    NodeS<T> *temp = First;

    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template<class T>
T SinglyCL<T> :: Maximum()
{
    NodeS<T> *temp = First;

    T Max = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < (temp->data))
        {
            Max = temp->data;
        }

        temp = temp->next;
    }

    return Max;
}

template<class T>
T SinglyCL<T> :: Minimum()
{
    NodeS<T> *temp = First;

    T Min = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > (temp->data))
        {
            Min = temp->data;
        }

        temp = temp->next;
    }

    return Min;
}

template<class T>
int SinglyCL<T> :: AdditionEven()
{
    NodeS<T> *temp = First;

    int SumEven = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(((temp->data) % 2) == 0)
        {
            SumEven = SumEven + temp->data;
        }

        temp = temp->next;
    }

    return SumEven;
}

template<class T>
void SinglyCL<T> :: DigitsSum()
{
    int iDigit = 0;
    int iSum = 0;
    
    NodeS<T> *temp = First;

    cout<<"The sum of the digits are :\n";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iSum = iSum + iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Sum is :"<<iSum<<"\n";
        iSum = 0;
    }
}

template<class T>
T SinglyCL<T> :: SecondMaximum()
{
    NodeS<T> *temp = First;

    T MaxFirst = temp->data;
    T MaxSecond = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) >= MaxFirst)
        {
            MaxSecond = MaxFirst;
            MaxFirst = temp->data;
        }

        temp = temp->next;
    }

    return MaxSecond;
}

template<class T>
void SinglyCL<T> :: DisplayPerfect()
{
    int iSum = 0;
    int iCnt2 = 0;

    cout<<"The perfect numbers are : \n";

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        for(iCnt2 = 1; iCnt2 <= (temp->data)/2; iCnt2++)
        {
            if(((temp->data) % iCnt2) == 0)
            {
                iSum = iSum + iCnt2;
            }
        }

        if(iSum == (temp->data))
        {
            cout<<temp->data<<" is a perfect number\n";
        }

        temp = temp->next;
        iSum = 0;
    }

}

template<class T>
void SinglyCL<T> ::DisplayPrime()
{
    NodeS<T> *temp = First;

    int iCount1 = 0;

    cout<<"The prime numbers are : \n";

    for(int iCnt1 = 1; iCnt1 <= iCount; iCnt1++)
    {
        for(int iCnt = 1; iCnt <= (temp->data); iCnt++)
        {
            if(((temp->data) % iCnt) == 0)
            {
                iCount1++;
            }
        }

        if(iCount1 == 2)
        {
            cout<<temp->data<<" is a prime number\n";
        }

        temp = temp->next;
        iCount1 = 0;
    }
}

template<class T>
int SinglyCL<T> :: Reverse()
{
    int iReverse = 0;
    int iDigit = 0;
    NodeS<T> *temp = First;

    cout<<"After reversing elements :\n";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            (temp->data) = (temp->data) / 10;
        }

        cout<<"| "<<iReverse<<" | -> ";
        temp = temp->next;
        iReverse = 0;
    }
}

template<class T>
void SinglyCL<T> :: DisplayPalindromeNumber()
{
    int iReverse = 0;
    int itemp = 0;
    int iDigit = 0;

    NodeS<T> *temp = First;

    cout<<"Palindrome numbers are :\n";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        itemp = temp->data;

        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            temp->data = (temp->data) / 10;
        }

        if(iReverse == itemp)
        {
            cout<<"|"<<itemp<<"| \t";
        }

        temp = temp->next;
        iReverse = 0;
    }
}

template<class T>
void SinglyCL<T> :: DisplayDigitsProduct()
{
    int iMult = 1;
    int iDigit = 0;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;

            if(iDigit == 0)
            {
                iDigit = 1;
            }

            iMult = iMult * iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Product is :"<<iMult<<"\n";
        iMult = 1;
    }

}

template<class T>
void SinglyCL<T> :: DisplaySmallDigit()
{
    int iSmallDigit = 9;
    int iDigit = 0;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 0)
            {
                iSmallDigit = iDigit;
                break;
            }

            if(iSmallDigit > iDigit)
            {
                iSmallDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Smallest digit is :"<<iSmallDigit<<"\n";
        iSmallDigit = 9;
    }
}

template<class T>
void SinglyCL<T> :: DisplayLargeDigit()
{
    int iLargeDigit = 0;
    int iDigit = 0;

    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 9)
            {
                iLargeDigit = iDigit;
                break;
            }

            if(iLargeDigit < iDigit)
            {
                iLargeDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Largest digit is :"<<iLargeDigit<<"\n";
        iLargeDigit = 0;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly Linear Linked List

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    private:
        struct NodeD<T> * First;
        int iCount;

    public:
        DoublyLL();
        ~DoublyLL();

        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int); 

        int SearchFirstOccurrence(T);
        int SearchLastOccurrence(T); 
        T Addition();
        T Average();
        T Maximum();   
        T Minimum();
        int Frequency(T);

        void DisplayPrime();
        void DisplayPerfect();
        int AdditionEven();
        int DigitsSum();
        T SecondMaximum(); 

        int Reverse();
        void DisplayPalindromeNumber(); 
        void DisplayDigitsProduct();
        void DisplaySmallDigit();
        void DisplayLargeDigit();
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
DoublyLL<T> :: ~DoublyLL()
{
    NodeD<T> *temp = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"The Elements of Doubly Linear Linked List are :\n";

    NodeD<T> *temp = First;

    cout<<"NULL <-> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <-> ";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        newn->next = First;
        First = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        NodeD<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }

    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }

    else
    {
        NodeD<T> *temp = First;
        NodeD<T> *newn = new NodeD<T>;

        newn->data = No;
        newn->prev = NULL;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    else if((First->next == NULL) && (First->prev) == NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        First = First->next;
        delete (First->prev);
        First->prev = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    else if((First->next == NULL) && (First->prev) == NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        NodeD<T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iLength)
    {
        DeleteLast();
    }

    else
    {
        NodeD<T> *temp = First;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

template<class T>
int DoublyLL<T> :: Frequency(T Search)
{
    int iFreq = 0;
    NodeS<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == Search)
        {
            iFreq++;
        }
    }

    return iFreq;
}

template<class T>
T DoublyLL<T> :: Average()
{
    T Sum = 0;

    NodeD<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return (Sum/iCount);
}

template<class T>
int DoublyLL<T>:: SearchFirstOccurrence(T No)
{
    NodeD<T> *temp = First;
    int iIndex = -1;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
            break;
        }
        
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
int DoublyLL<T>:: SearchLastOccurrence(T No)
{
    NodeD<T> *temp = First;
    int iIndex = -1;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
        }
        
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
T DoublyLL<T>:: Maximum()
{
    NodeD<T> *temp = First;

    T Max = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < (temp->data))
        {
            Max = temp->data;
        }

        temp = temp->next;
    }

    return Max;
}

template<class T>
T DoublyLL<T> :: Addition()
{
    NodeD<T> *temp = First;

    T Sum = 0;

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template<class T>
T DoublyLL<T> :: Minimum()
{
    NodeD<T> *temp = First;

    T Min = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > (temp->data))
        {
            Min = temp->data;
        }

        temp = temp->next;
    }

    return Min;
}

template<class T>
int DoublyLL<T> :: AdditionEven()
{
    NodeD<T> *temp = First;

    int SumEven = 0;

    while(temp != NULL)
    {
        if(((temp->data) % 2) == 0)
        {
            SumEven = SumEven + temp->data;
        }

        temp = temp->next;
    }

    return SumEven;
}

template<class T>
int DoublyLL<T> :: DigitsSum()
{
    int iDigit = 0;
    int iSum = 0;
    
    NodeD<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iSum = iSum + iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Sum is :"<<iSum<<"\n";
        iSum = 0;
    }
}

template<class T>
T DoublyLL<T> :: SecondMaximum()
{
    NodeD<T> *temp = First;

    T MaxFirst = temp->data;
    T MaxSecond;

    while(temp != NULL)
    {
        if(((temp->data) > MaxFirst))
        {
            MaxSecond = MaxFirst;
            MaxFirst = temp->data;
        }

        else if((temp->data) > MaxSecond)
        {
            MaxSecond = temp->data;
        }

        temp = temp->next;
    }

    return MaxSecond;
}

template<class T>
void DoublyLL<T> :: DisplayPerfect()
{
    int iSum = 0;
    int iCnt1 = 0;
    int iCnt2 = 0;

    NodeD<T> *temp = First;

    for(iCnt1 = 1; iCnt1 <= iCount; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= (temp->data)/2; iCnt2++)
        {
            if(((temp->data) % iCnt2) == 0)
            {
                iSum = iSum + iCnt2;
            }
        }

        if(iSum == (temp->data))
        {
            cout<<temp->data<<" is a perfect number\n";
        }

        temp = temp->next;
        iSum = 0;
    }

}

template<class T>
void DoublyLL<T> ::DisplayPrime()
{
    NodeD<T> *temp = First;

    int iCount1 = 0;

    while(temp != NULL)
    {
        for(int iCnt = 1; iCnt <= (temp->data); iCnt++)
        {
            if(((temp->data) % iCnt) == 0)
            {
                iCount1++;
            }
        }

        if(iCount1 == 2)
        {
            cout<<temp->data<<" is a prime number\n";
        }

        temp = temp->next;
        iCount1 = 0;
    }
}

template<class T>
int DoublyLL<T> :: Reverse()
{
    int iReverse = 0;
    int iDigit = 0;
    NodeD<T> *temp = First;

    cout<<"After reversing elements :\n";

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            (temp->data) = (temp->data) / 10;
        }

        cout<<"| "<<iReverse<<" | -> ";
        temp = temp->next;
        iReverse = 0;
    }

    cout<<" NULL \n";
}

template<class T>
void DoublyLL<T> :: DisplayPalindromeNumber()
{
    int iReverse = 0;
    int itemp = 0;
    int iDigit = 0;

    NodeD<T> *temp = First;

    cout<<"Palindrome numbers are :\n";

    while(temp != NULL)
    {
        itemp = temp->data;

        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            temp->data = (temp->data) / 10;
        }

        if(iReverse == itemp)
        {
            cout<<"|"<<itemp<<"| "<<"\t";
        }

        temp = temp->next;
        iReverse = 0;
    }
}

template<class T>
void DoublyLL<T> :: DisplayDigitsProduct()
{
    int iMult = 1;
    int iDigit = 0;

    NodeD<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;

            if(iDigit == 0)
            {
                iDigit = 1;
            }

            iMult = iMult * iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Product is :"<<iMult<<"\n";
        iMult = 1;
    }

}

template<class T>
void DoublyLL<T> :: DisplaySmallDigit()
{
    int iSmallDigit = 9;
    int iDigit = 0;

    NodeD<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 0)
            {
                iSmallDigit = iDigit;
                break;
            }

            if(iSmallDigit > iDigit)
            {
                iSmallDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Smallest digit is :"<<iSmallDigit<<"\n";
        iSmallDigit = 9;
    }
}

template<class T>
void DoublyLL<T> :: DisplayLargeDigit()
{
    int iLargeDigit = 0;
    int iDigit = 0;

    NodeD<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 9)
            {
                iLargeDigit = iDigit;
                break;
            }

            if(iLargeDigit < iDigit)
            {
                iLargeDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Largest digit is :"<<iLargeDigit<<"\n";
        iLargeDigit = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly cicular Linked List

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    private:
        struct NodeD<T> * First;
        struct NodeD<T> * Last;
        int iCount;

    public:
        DoublyCL();
        ~DoublyCL();

        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurrence(T);
        int SearchLastOccurrence(T); 
        T Addition();
        T Average();
        T Maximum();   
        T Minimum();
        int Frequency(T);

        void DisplayPrime();
        void DisplayPerfect();
        int AdditionEven();
        int DigitsSum();
        T SecondMaximum(); 

        int Reverse();
        void DisplayPalindromeNumber(); 
        void DisplayDigitsProduct();
        void DisplaySmallDigit();
        void DisplayLargeDigit();

        void BubbleSort(T [],int);
        void EfficientBubbleSort(T [], int);
        void SelectionSort(T [],int);
        void InsertionSort(T [],int);
        void QuickSort(T [],int);
        void MergeSort(T [],int);

        bool LinearSearch(T [],int,T);
        bool BidirectionalSearch(T [],int,T);
        bool BinarySearch(T [],int,T);
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
DoublyCL<T> :: ~DoublyCL()
{
    NodeD<T> *temp = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> *temp = First;

    if((First != NULL) && (Last != NULL))
    {
        cout<<"The Elements of Doubly Circular Linked List are :\n";
        cout<<" <-> ";
        do
        {
            cout<<"| "<<temp->data<<" | <-> ";
            temp = temp->next;
        }while(temp != (Last->next));

        cout<<"\n";
    }

    else
    {
        cout<<"Doubly Circular Linked List is empty\n";
    }
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->prev = NULL;
    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }

    else
    {
        newn->next = First;
        newn->prev = Last;
        
        First = newn;
    }

    First->prev = Last;
    Last->next = First;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->prev = NULL;
    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }

    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }

    First->prev = Last;
    Last->next = First;
    
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }

    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }

    else
    {
        NodeD<T> *newn = new NodeD<T>;
        NodeD<T> *temp = First;

        newn->prev = NULL;
        newn->data = No;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next->prev = newn;
        newn->next = temp->next;

        newn->prev = temp;
        temp->next = newn;

        First->prev = Last;
        Last->next = First;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    else if(First == Last)
    {
        delete First;

        First = NULL;
        Last = NULL;
    }

    else
    {
        First = First->next;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }

    else if(First == Last)
    {
        delete First;

        First = NULL;
        Last = NULL;
    }

    else
    {
        Last = Last->prev;
        delete Last->next;

        Last->next = First;
        First->prev = Last;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    int iLength = Count();

    if((iPos < 1) || (iPos > iLength))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iLength)
    {
        DeleteLast();
    }

    else
    {
        NodeD<T> *temp = First;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

template<class T>
int DoublyCL<T> :: Frequency(T Search)
{
    int iFreq = 0;
    NodeD<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == Search)
        {
            iFreq++;
        }
    }

    return iFreq;
}

template<class T>
T DoublyCL<T> :: Average()
{
    T Sum = 0;

    NodeD<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return (Sum/iCount);
}

template<class T>
int DoublyCL<T>:: SearchFirstOccurrence(T No)
{
    NodeD<T> *temp = First;
    int iIndex = -1;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
            break;
        }
        
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
int DoublyCL<T>:: SearchLastOccurrence(T No)
{
    NodeD<T> *temp = First;
    int iIndex = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
        }
        
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
T DoublyCL<T>:: Maximum()
{
    NodeD<T> *temp = First;

    T Max = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < (temp->data))
        {
            Max = temp->data;
        }

        temp = temp->next;
    }

    return Max;
}

template<class T>
T DoublyCL<T> :: Addition()
{
    NodeD<T> *temp = First;

    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template<class T>
T DoublyCL<T> :: Minimum()
{
    NodeD<T> *temp = First;

    T Min = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > (temp->data))
        {
            Min = temp->data;
        }

        temp = temp->next;
    }

    return Min;
}

template<class T>
int DoublyCL<T> :: AdditionEven()
{
    NodeD<T> *temp = First;

    int SumEven = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(((temp->data) % 2) == 0)
        {
            SumEven = SumEven + temp->data;
        }

        temp = temp->next;
    }

    return SumEven;
}

template<class T>
int DoublyCL<T> :: DigitsSum()
{
    int iDigit = 0;
    int iSum = 0;
    
    NodeD<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iSum = iSum + iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Sum is :"<<iSum<<"\n";
        iSum = 0;
    }
}

template<class T>
T DoublyCL<T> :: SecondMaximum()
{
    NodeD<T> *temp = First;

    T MaxFirst = temp->data;
    T MaxSecond;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(((temp->data) > MaxFirst))
        {
            MaxSecond = MaxFirst;
            MaxFirst = temp->data;
        }

        else if((temp->data) > MaxSecond)
        {
            MaxSecond = temp->data;
        }

        temp = temp->next;
    }

    return MaxSecond;
}

template<class T>
void DoublyCL<T> :: DisplayPerfect()
{
    int iSum = 0;
    int iCnt1 = 0;
    int iCnt2 = 0;

    NodeD<T> *temp = First;

    for(iCnt1 = 1; iCnt1 <= iCount; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= (temp->data)/2; iCnt2++)
        {
            if(((temp->data) % iCnt2) == 0)
            {
                iSum = iSum + iCnt2;
            }
        }

        if(iSum == (temp->data))
        {
            cout<<temp->data<<" is a perfect number\n";
        }

        temp = temp->next;
        iSum = 0;
    }

}

template<class T>
void DoublyCL<T> ::DisplayPrime()
{
    NodeD<T> *temp = First;

    int iCount1 = 0;

    for(int iCnt1 = 1; iCnt1 <= iCount; iCnt1++)
    {
        for(int iCnt = 1; iCnt <= (temp->data); iCnt++)
        {
            if(((temp->data) % iCnt) == 0)
            {
                iCount1++;
            }
        }

        if(iCount1 == 2)
        {
            cout<<temp->data<<" is a prime number\n";
        }

        temp = temp->next;
        iCount1 = 0;
    }
}

template<class T>
int DoublyCL<T> :: Reverse()
{
    int iReverse = 0;
    int iDigit = 0;
    NodeD<T> *temp = First;

    cout<<"After reversing the elements are : \n <->";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            (temp->data) = (temp->data) / 10;
        }

        cout<<" | "<<iReverse<<" | <->";
        temp = temp->next;
        iReverse = 0;
    }

}

template<class T>
void DoublyCL<T> :: DisplayPalindromeNumber()
{
    int iReverse = 0;
    int itemp = 0;
    int iDigit = 0;

    NodeD<T> *temp = First;

    cout<<"Palindrome numbers are :\n";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        itemp = temp->data;

        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            temp->data = (temp->data) / 10;
        }

        if(iReverse == itemp)
        {
            cout<<"|"<<itemp<<"| "<<"\t";
        }

        temp = temp->next;
        iReverse = 0;
    }
}

template<class T>
void DoublyCL<T> :: DisplayDigitsProduct()
{
    int iMult = 1;
    int iDigit = 0;

    NodeD<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;

            if(iDigit == 0)
            {
                iDigit = 1;
            }

            iMult = iMult * iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Product is :"<<iMult<<"\n";
        iMult = 1;
    }

}

template<class T>
void DoublyCL<T> :: DisplaySmallDigit()
{
    int iSmallDigit = 9;
    int iDigit = 0;

    NodeD<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 0)
            {
                iSmallDigit = iDigit;
                break;
            }

            if(iSmallDigit > iDigit)
            {
                iSmallDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Smallest digit is :"<<iSmallDigit<<"\n";
        iSmallDigit = 9;
    }
}

template<class T>
void DoublyCL<T> :: DisplayLargeDigit()
{
    int iLargeDigit = 0;
    int iDigit = 0;

    NodeD<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 9)
            {
                iLargeDigit = iDigit;
                break;
            }

            if(iLargeDigit < iDigit)
            {
                iLargeDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Largest digit is :"<<iLargeDigit<<"\n";
        iLargeDigit = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    private:
        struct NodeStack<T> *First;
        int iCount;

    public:
        
        Stack();
        ~Stack();

        void Push(T);
        void Pop();
        void Display();
        int Count();

        int SearchFirstOccurrence(T);
        int SearchLastOccurrence(T);
        T Addition(); 
        T Average();  
        T Maximum();
        T Minimum();
        int Frequency(T);

        void DisplayPrime();
        void DisplayPerfect();
        int AdditionEven();
        void DigitsSum();
        T SecondMaximum();
        
        int Reverse();
        void DisplayPalindromeNumber(); 
        void DisplayDigitsProduct();
        void DisplaySmallDigit();
        void DisplayLargeDigit();
};

template<class T>
Stack<T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
Stack<T> :: ~Stack()
{
    NodeStack<T> *temp = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template<class T>
void Stack<T> :: Push(T No)
{
    NodeStack<T> *newn = new NodeStack<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
       NodeStack<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template<class T>
void Stack<T> :: Pop()
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
    }

    else if(iCount == 1)
    {
        Value = First->data;
        delete First;
        First = NULL;
    }

    else
    {
        NodeStack<T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;  
}

template<class T>
void Stack<T> :: Display()
{
    NodeStack<T> *temp = First;

    cout<<"The Elements in the Stack are :\n";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp = temp->next;
    }
}

template<class T>
int Stack<T> :: Count()
{
    return iCount;
}

template<class T>
int Stack<T> :: Frequency(T Search)
{
    int iFreq = 0;
    NodeStack<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == Search)
        {
            iFreq++;
        }
    }

    return iFreq;
}

template<class T>
T Stack<T> :: Average()
{
    T Sum = 0;

    NodeStack<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return (Sum/iCount);
}

template<class T>
int Stack<T>:: SearchFirstOccurrence(T No)
{
    int iIndex = -1;

    NodeStack<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
            break;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
int Stack<T>:: SearchLastOccurrence(T No)
{
    int iIndex = -1;

    NodeStack<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
T Stack<T> :: Addition()
{
    NodeStack<T> *temp = First;

    T Sum = 0;

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template<class T>
T Stack<T> :: Maximum()
{
    NodeStack<T> *temp = First;

    T Max = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < (temp->data))
        {
            Max = temp->data;
        }

        temp = temp->next;
    }

    return Max;
}

template<class T>
T Stack<T> :: Minimum()
{
    NodeStack<T> *temp = First;

    T Min = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > (temp->data))
        {
            Min = temp->data;
        }

        temp = temp->next;
    }

    return Min;
}

template<class T>
int Stack<T> :: AdditionEven()
{
    NodeStack<T> *temp = First;

    int SumEven = 0;

    while(temp != NULL)
    {
        if(((temp->data) % 2) == 0)
        {
            SumEven = SumEven + temp->data;
        }

        temp = temp->next;
    }

    return SumEven;
}

template<class T>
void Stack<T> :: DigitsSum()
{
    int iDigit = 0;
    int iSum = 0;
    
    NodeStack<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iSum = iSum + iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Sum is :"<<iSum<<"\n";
        iSum = 0;
    }
}

template<class T>
T Stack<T> :: SecondMaximum()
{
    NodeStack<T> *temp = First;

    T MaxFirst = temp->data;
    T MaxSecond;

    while(temp != NULL)
    {
        if(((temp->data) > MaxFirst))
        {
            MaxSecond = MaxFirst;
            MaxFirst = temp->data;
        }

        else if((temp->data) > MaxSecond)
        {
            MaxSecond = temp->data;
        }

        temp = temp->next;
    }

    return MaxSecond;
}

template<class T>
void Stack<T> :: DisplayPerfect()
{
    int iSum = 0;
    int iCnt1 = 0;
    int iCnt2 = 0;

    NodeStack<T> *temp = First;

    for(iCnt1 = 1; iCnt1 <= iCount; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= (temp->data)/2; iCnt2++)
        {
            if(((temp->data) % iCnt2) == 0)
            {
                iSum = iSum + iCnt2;
            }
        }

        if(iSum == (temp->data))
        {
            cout<<temp->data<<" is a perfect number\n";
        }

        temp = temp->next;
        iSum = 0;
    }

}

template<class T>
void Stack<T> ::DisplayPrime()
{
    NodeStack<T> *temp = First;

    int iCount1 = 0;

    while(temp != NULL)
    {
        for(int iCnt = 1; iCnt <= (temp->data); iCnt++)
        {
            if(((temp->data) % iCnt) == 0)
            {
                iCount1++;
            }
        }

        if(iCount1 == 2)
        {
            cout<<temp->data<<" is a prime number\n";
        }

        temp = temp->next;
        iCount1 = 0;
    }
}

template<class T>
int Stack<T> :: Reverse()
{
    int iReverse = 0;
    int iDigit = 0;
    NodeStack<T> *temp = First;

    cout<<"After reversing elements :\n";

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            (temp->data) = (temp->data) / 10;
        }

        cout<<"| "<<iReverse<<" |\n";
        temp = temp->next;
        iReverse = 0;
    }

}

template<class T>
void Stack<T> :: DisplayPalindromeNumber()
{
    int iReverse = 0;
    int itemp = 0;
    int iDigit = 0;

    NodeStack<T> *temp = First;

    cout<<"Palindrome numbers are :\n";

    while(temp != NULL)
    {
        itemp = temp->data;

        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            temp->data = (temp->data) / 10;
        }

        if(iReverse == itemp)
        {
            cout<<"|"<<itemp<<"| "<<"\t";
        }

        temp = temp->next;
        iReverse = 0;
    }
}

template<class T>
void Stack<T> :: DisplayDigitsProduct()
{
    int iMult = 1;
    int iDigit = 0;

    NodeStack<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;

            if(iDigit == 0)
            {
                iDigit = 1;
            }

            iMult = iMult * iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Product is :"<<iMult<<"\n";
        iMult = 1;
    }

}

template<class T>
void Stack<T> :: DisplaySmallDigit()
{
    int iSmallDigit = 9;
    int iDigit = 0;

    NodeStack<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 0)
            {
                iSmallDigit = iDigit;
                break;
            }

            if(iSmallDigit > iDigit)
            {
                iSmallDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Smallest digit is :"<<iSmallDigit<<"\n";
        iSmallDigit = 9;
    }
}

template<class T>
void Stack<T> :: DisplayLargeDigit()
{
    int iLargeDigit = 0;
    int iDigit = 0;

    NodeStack<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 9)
            {
                iLargeDigit = iDigit;
                break;
            }

            if(iLargeDigit < iDigit)
            {
                iLargeDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Largest digit is :"<<iLargeDigit<<"\n";
        iLargeDigit = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

// Class of Queue

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    private:
        struct NodeQueue<T> *First;
        int iCount;

    public:
        
        Queue();
        ~Queue();

        void Enqueue(T);
        void Dequeue();
        void Display();
        int Count();

        int SearchFirstOccurrence(T);
        int SearchLastOccurrence(T);
        T Addition();
        T Average();   
        T Maximum();
        T Minimum();
        int Frequency(T);

        void DisplayPrime();
        void DisplayPerfect();
        int AdditionEven();
        void DigitsSum();
        T SecondMaximum();
        
        int Reverse();
        void DisplayPalindromeNumber(); 
        void DisplayDigitsProduct();
        void DisplaySmallDigit();
        void DisplayLargeDigit();
};

template<class T>
Queue<T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
Queue<T> :: ~Queue()
{
    NodeQueue<T> *temp = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template<class T>
void Queue<T>:: Enqueue(T No)
{
    NodeQueue<T> *newn = new NodeQueue<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        NodeQueue<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template<class T>
void Queue<T>:: Dequeue()
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
    }

    else if(iCount == 1)
    {
        Value = First->data;
        delete First;
        First = NULL;
    }

    else
    {
        NodeQueue<T> *temp = First;

        First = First->next;
        delete temp;
    }

    iCount--;
}

template<class T>
void Queue<T>:: Display()
{
    NodeQueue<T> *temp = First;

    cout<<"The Elements in the Queue are :\n";

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp = temp->next;
    }
}

template<class T>
int Queue<T>:: Count()
{
    return iCount;
}

template<class T>
int Queue<T> :: Frequency(T Search)
{
    int iFreq = 0;
    NodeQueue<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == Search)
        {
            iFreq++;
        }
    }

    return iFreq;
}

template<class T>
T Queue<T> :: Average()
{
    T Sum = 0;

    NodeQueue<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return (Sum/iCount);
}

template<class T>
int Queue<T>:: SearchFirstOccurrence(T No)
{
    int iIndex = -1;

    NodeQueue<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
            break;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
int Queue<T>:: SearchLastOccurrence(T No)
{
    int iIndex = -1;

    NodeQueue<T> *temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if((temp->data) == No)
        {
            iIndex = iCnt;
        }
        temp = temp->next;
    }

    return iIndex;
}

template<class T>
T Queue<T> :: Addition()
{
    NodeQueue<T> *temp = First;

    T Sum = 0;

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template<class T>
T Queue<T> :: Maximum()
{
    NodeQueue<T> *temp = First;

    T Max = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < (temp->data))
        {
            Max = temp->data;
        }

        temp = temp->next;
    }

    return Max;
}

template<class T>
T Queue<T> :: Minimum()
{
    NodeQueue<T> *temp = First;

    T Min = temp->data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > (temp->data))
        {
            Min = temp->data;
        }

        temp = temp->next;
    }

    return Min;
}

template<class T>
int Queue<T> :: AdditionEven()
{
    NodeQueue<T> *temp = First;

    int SumEven = 0;

    while(temp != NULL)
    {
        if(((temp->data) % 2) == 0)
        {
            SumEven = SumEven + temp->data;
        }

        temp = temp->next;
    }

    return SumEven;
}

template<class T>
void Queue<T> :: DigitsSum()
{
    int iDigit = 0;
    int iSum = 0;
    
    NodeQueue<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iSum = iSum + iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Sum is :"<<iSum<<"\n";
        iSum = 0;
    }
}

template<class T>
T Queue<T> :: SecondMaximum()
{
    NodeQueue<T> *temp = First;

    T MaxFirst = temp->data;
    T MaxSecond;

    while(temp != NULL)
    {
        if(((temp->data) > MaxFirst))
        {
            MaxSecond = MaxFirst;
            MaxFirst = temp->data;
        }

        else if((temp->data) > MaxSecond)
        {
            MaxSecond = temp->data;
        }

        temp = temp->next;
    }

    return MaxSecond;
}

template<class T>
void Queue<T> :: DisplayPerfect()
{
    int iSum = 0;
    int iCnt1 = 0;
    int iCnt2 = 0;

    NodeQueue<T> *temp = First;

    for(iCnt1 = 1; iCnt1 <= iCount; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= (temp->data)/2; iCnt2++)
        {
            if(((temp->data) % iCnt2) == 0)
            {
                iSum = iSum + iCnt2;
            }
        }

        if(iSum == (temp->data))
        {
            cout<<temp->data<<" is a perfect number\n";
        }

        temp = temp->next;
        iSum = 0;
    }

}

template<class T>
void Queue<T> ::DisplayPrime()
{
    NodeQueue<T> *temp = First;

    int iCount1 = 0;

    while(temp != NULL)
    {
        for(int iCnt = 1; iCnt <= (temp->data); iCnt++)
        {
            if(((temp->data) % iCnt) == 0)
            {
                iCount1++;
            }
        }

        if(iCount1 == 2)
        {
            cout<<temp->data<<" is a prime number\n";
        }

        temp = temp->next;
        iCount1 = 0;
    }
}

template<class T>
int Queue<T> :: Reverse()
{
    int iReverse = 0;
    int iDigit = 0;
    NodeQueue<T> *temp = First;

    cout<<"After reversing elements :\n";

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            (temp->data) = (temp->data) / 10;
        }

        cout<<"| "<<iReverse<<" |\n";
        temp = temp->next;
        iReverse = 0;
    }

}

template<class T>
void Queue<T> :: DisplayPalindromeNumber()
{
    int iReverse = 0;
    int itemp = 0;
    int iDigit = 0;

    NodeQueue<T> *temp = First;

    cout<<"Palindrome numbers are :\n";

    while(temp != NULL)
    {
        itemp = temp->data;

        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            iReverse = (iReverse * 10) + iDigit;
            temp->data = (temp->data) / 10;
        }

        if(iReverse == itemp)
        {
            cout<<"|"<<itemp<<"| "<<"\t";
        }

        temp = temp->next;
        iReverse = 0;
    }
}

template<class T>
void Queue<T> :: DisplayDigitsProduct()
{
    int iMult = 1;
    int iDigit = 0;

    NodeQueue<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;

            if(iDigit == 0)
            {
                iDigit = 1;
            }

            iMult = iMult * iDigit;
            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Product is :"<<iMult<<"\n";
        iMult = 1;
    }

}

template<class T>
void Queue<T> :: DisplaySmallDigit()
{
    int iSmallDigit = 9;
    int iDigit = 0;

    NodeQueue<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 0)
            {
                iSmallDigit = iDigit;
                break;
            }

            if(iSmallDigit > iDigit)
            {
                iSmallDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Smallest digit is :"<<iSmallDigit<<"\n";
        iSmallDigit = 9;
    }
}

template<class T>
void Queue<T> :: DisplayLargeDigit()
{
    int iLargeDigit = 0;
    int iDigit = 0;

    NodeQueue<T> *temp = First;

    while(temp != NULL)
    {
        while(temp->data != 0)
        {
            iDigit = (temp->data) % 10;
            
            if(iDigit == 9)
            {
                iLargeDigit = iDigit;
                break;
            }

            if(iLargeDigit < iDigit)
            {
                iLargeDigit = iDigit;
            }

            temp->data = (temp->data) / 10;
        }

        temp = temp->next;
        cout<<"Largest digit is :"<<iLargeDigit<<"\n";
        iLargeDigit = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Binary Search Tree

///////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class Binary
{
    private:
        struct BinarySearchTree<T> *First;
        int iCount;

    public:

        Binary();

        void Insert(T);
        int Count();
        
        void Preorder(struct BinarySearchTree<T> *);
        void DisplayPreorder();

        void Postorder(struct BinarySearchTree<T> *);
        void DisplayPostorder();
        
        void Inorder(struct BinarySearchTree<T> *);
        void DisplayInorder();

        bool Search(T);
        
        int CountNodesMain(struct BinarySearchTree<T> *);
        int CountNodes();
        
        int CountLeafNodesMain(struct BinarySearchTree<T> *);
        int CountLeafNodes();

        int CountParentNodesMain(struct BinarySearchTree<T> *);
        int CountParentNodes();
};

template<class T>
Binary<T> :: Binary()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Binary<T> :: Insert(T No)
{
    BinarySearchTree<T> *newn = new BinarySearchTree<T>;

    newn->lchild = NULL;
    newn->data = No;
    newn->rchild = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        BinarySearchTree<T> *temp = First;

        while(1)
        {
            if(No == temp->data)
            {
                cout<<"Duplicate element : Unable to insert\n";
                delete(newn);
                break;
            }

            else if(No > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }

                temp = temp->rchild;
            }

            else if(No < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }

                temp = temp->lchild;
            }
        }
    }

    iCount++;
}

template<class T>
int Binary<T> :: Count()
{
    return iCount;
}

template<class T>
void Binary<T> :: Preorder(struct BinarySearchTree<T> *Head)
{
    if(Head != NULL)
    {
        cout<<Head->data<<"\t";
        Preorder(Head->lchild);
        Preorder(Head->rchild);      
    }
}

template<class T>
void Binary<T> :: DisplayPreorder()
{
    Preorder(First);  
}


template<class T>
void Binary<T> :: Inorder(struct BinarySearchTree<T> *Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        cout<<Head->data<<"\t";
        Inorder(Head->rchild);
    }
}

template<class T>
void Binary<T> :: DisplayInorder()
{
    Inorder(First);  
}

template<class T>
void Binary<T> :: Postorder(struct BinarySearchTree<T> *Head)
{
    if(Head != NULL)
    {
        Postorder(Head->lchild);
        Postorder(Head->rchild);
        cout<<Head->data<<"\t";        
    }
}

template<class T>
void Binary<T> :: DisplayPostorder()
{
    Postorder(First);
}

template<class T>
bool Binary<T> :: Search(T No)
{
    bool bFlag = false;

    BinarySearchTree<T> *temp = First;

    if(temp == NULL)
    {
        cout<<"There is no element in BST\n";
        return bFlag;
    }

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            bFlag = true;
            break;
        }

        else if(temp->data > No)
        {
            temp = temp->lchild;
        }

        else if(temp->data < No)
        {
            temp = temp->rchild;
        }
    }

    return bFlag;
}

template<class T>
int Binary<T> :: CountNodesMain(struct BinarySearchTree<T> *Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        iCnt++;
        CountNodesMain(Head->lchild);
        CountNodesMain(Head->rchild);
    }

    return iCnt;
}

template<class T>
int Binary<T> :: CountNodes()
{
    return CountNodesMain(First);
}

template<class T>
int Binary<T> :: CountParentNodesMain(struct BinarySearchTree<T> *Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild != NULL || Head->rchild != NULL))
        {
            iCnt++;
        }

        CountParentNodesMain(Head->lchild);
        CountParentNodesMain(Head->rchild);
    }

    return iCnt;
}

template<class T>
int Binary<T> :: CountParentNodes()
{
    return CountParentNodesMain(First);
}

template<class T>
int Binary<T> :: CountLeafNodesMain(struct BinarySearchTree<T> *Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            iCnt++;
        }

        CountLeafNodesMain(Head->lchild);
        CountLeafNodesMain(Head->rchild);
    }

    return iCnt;
}

template<class T>
int Binary<T> :: CountLeafNodes()
{
    return CountLeafNodesMain(First);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// All Searching and Sorting Algorithm
// Searching : Linear Search, Bidirectional Search, Binary Search
// Sorting : Bubble sort, Efficient Bubble sort, Selection sort, Insertion sort, Quick sort, Merge sort

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool LinearSearch(T Arr[], int iSize, T No)
{
    bool bFlag = false;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template<class T>
bool BidirectionalSearch(T Arr[], int iSize, T No)
{
    bool bFlag = false;
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            bFlag = true;
            break;
        }

        iStart++;
        iEnd--;
    }

    return bFlag;
}

template<class T>
bool BinarySearch(T Arr[], int iSize, T No)
{
    bool bFlag = false;
    int iStart = 0;
    int iMid = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;

        if((Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            bFlag = true;
            break;
        }

        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }

        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

template<class T>
void BubbleSort(T Arr[], int iSize)
{
    for(int i = 0; i < iSize; i++)
    {
        for(int j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                T temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

template<class T>
void EfficientBubbleSort(T Arr[], int iSize)
{
    bool bFlag = false;

    for(int i = 0; i < iSize; i++)
    {
        bFlag = false;

        for(int j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                T temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                bFlag = true;
            }
        }

        if(bFlag == false)
        {
            break;
        }
    }
}

template<class T>
void SelectionSort(T Arr[], int iSize)
{
    for(int i = 0; i < iSize - 1; i++)
    {
        T min_index = i;

        for(int j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        T temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template<class T>
void InsertionSort(T Arr[], int iSize)
{
    T selected;
    int i = 0, j = 0;
    
    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1,selected = Arr[i]; ((j >= 0) && (Arr[j] > selected)); j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}

template<class T>
int Partition(T Arr[], int iLow, int iHigh)
{
    T iPivot = Arr[iLow];
    int i = iLow;
    int j = iHigh;

    while(i < j)
    {
        while(Arr[i] <= iPivot && i <= iHigh - 1)
        {
            i++;
        }

        while(Arr[j] > iPivot && j >= iLow + 1)
        {
            j--;
        }

        if(i < j)
        {
            swap(Arr[i],Arr[j]);
        }
    }

    swap(Arr[iLow],Arr[j]);
    return j;
}

template<class T>
void Quick(T Arr[], int iLow, int iHigh)
{
    if(iLow < iHigh)
    {
        int iPartition_Index = Partition(Arr,iLow,iHigh);
        Quick(Arr, iLow, iPartition_Index - 1);
        Quick(Arr, iPartition_Index + 1,  iHigh);
    }
}

template<class T>
void QuickSort(T Arr[], int iSize)
{
    Quick(Arr, 0, iSize-1);
}

template<class T>
void Conquer(T Arr[], int iLow, int iMid, int iHigh)
{
    int iSize = iHigh - iLow + 1;
    T Temp[iSize];

    int iLeft = iLow;
    int iRight = iMid + 1;
    int i = 0;

    while(iLeft <= iMid && iRight <= iHigh)
    {
        if(Arr[iLeft] <= Arr[iRight])
        {
            Temp[i++] = Arr[iLeft++];
        }

        else 
        {
            Temp[i++] = Arr[iRight++];
        }
    }

    while(iLeft <= iMid)
    {
        Temp[i++] = Arr[iLeft++];    
    }

    while(iRight <= iHigh)
    {
        Temp[i++] = Arr[iRight++];
    }

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        Arr[iLow + iCnt] = Temp[iCnt];
    }
}

template<class T>
void Divide(T Arr[], int iLow, int iHigh)
{
    if(iLow >= iHigh)
    {
        return;
    }

    int iMid = iLow + (iHigh - iLow) / 2;
    Divide(Arr, iLow, iMid);
    Divide(Arr, iMid + 1, iHigh);
    Conquer(Arr, iLow, iMid, iHigh);
}

template<class T>
void MergeSort(T Arr[], int iSize)
{
    Divide(Arr,0, iSize - 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL<char> obj1;    

    SinglyCL <int>obj2;
    
    DoublyLL <int>obj3;
    
    DoublyCL <float>obj4;

    Stack <int>obj5;

    Queue <char>obj6;

    Binary<int> bobj;

    bobj.Insert(21);
    bobj.Insert(23);
    bobj.Insert(15);
    bobj.Insert(78);
    bobj.Insert(45);
    bobj.Insert(10);
    bobj.Insert(90);
    bobj.Insert(18);
    bobj.Insert(22);
    bobj.Insert(7);

    return 0;
}