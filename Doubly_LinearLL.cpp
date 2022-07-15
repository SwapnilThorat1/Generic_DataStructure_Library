/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//   Generic Programming  Using Doubly Linear Likedlist                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinkedList
// Description   : Used to Count elements and display Doubly Linear Linked list 
// Input         : Integer
// Output        : Integer
// Date          : 08/06/2022
// Author        : Thorat Swapnil Harishchandra
//
//////////////////////////////////////////////////////////////////////////////////

#define TRUE 1;
#define FALSE 0;

template<class T>
struct  node
{
    T Data;
    node *Next;
    node *Prev;
};

template<class T>
class Doubly_linkedList
{
    private:
    struct node<T> *Head;

    public:
    Doubly_linkedList();
    ~Doubly_linkedList();
    int InsertFirst (T);
    int InsertLast(T);
    int InsertAtPosition(T,T);
    inline void Display();
    inline int Count();
    int DeleteFirst();
    int DeleteAtPosition(T);
    int DeleteLast();
};

template<class T>
Doubly_linkedList<T> :: Doubly_linkedList()
{
    Head = NULL;
}

template<class T>
Doubly_linkedList<T> :: ~Doubly_linkedList()
{
    struct node<T> *Temp = Head;

    if(Head != NULL)
    {
        while(Head !=NULL)
        {
            Head = Head->Next;
            delete Temp;
            Temp = Head;
        }
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Doubly_linkedList<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;
    if(newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;
    newn->Prev = NULL;
    newn->Data = no;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        Head->Prev = newn;
        newn->Next = Head;
        Head = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int Doubly_linkedList<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL, *temp = Head;
    newn = new node<T>;

    if(newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;
    newn->Prev = NULL;
    newn->Data =- no;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }

        temp->Next = newn;
        newn->Prev = temp;
    }
    return TRUE;
    
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  int 
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Doubly_linkedList<T>::InsertAtPosition(T no ,T pos)
{
    if((Head == NULL) || (pos > Count()+1) || (pos <= 0))
    {
        return FALSE;
    }

    if(pos == 1)
    {
        return(InsertFirst(no));
    }
    else if(pos == (Count()) + 1)
    {
        return(InsertLast(no));
    }
    else
    {
        struct node<T> *newn = NULL,*temp = Head;

        newn = new node<T>;
        if(newn == NULL)
        {
            return FALSE;
        }

        newn->Next = NULL;
        newn->Prev = NULL;
        newn->Data = no;

        for(int i = 1; i<=(pos-2); i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next->Prev = newn;

        newn->Prev = temp;
        temp->Next = newn;
    }

    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Doubly_linkedList<T>::DeleteFirst()
{
    struct node<T> *temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head -> Next;
        Head->Prev = NULL;

        delete temp;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Doubly_linkedList<T>:: DeleteLast()
{
    if(Head == NULL)
    {
        return FALSE;
    }
    else if(Head->Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp = Head;

        while((temp->Next) != NULL)
        {
            temp = temp->Next;
        }

        temp->Prev->Next = NULL;
        delete temp;
    }

    return TRUE;
    
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Doubly_linkedList<T>::DeleteAtPosition(T pos)
{
    if((Head == NULL) || (pos > Count()) || (pos <= 0))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;

        for(int i = 1; i<= (pos-2); i++)
        {
            temp = temp ->Next;
        }

        temp->Next = temp->Next->Next;
        delete temp->Next->Prev;
        temp->Next->Prev = temp;

    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Display
//  Description   :  Used to display elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Doubly_linkedList<T>:: Display()
{
    struct node<T> *Temp = Head;

    while(Temp != NULL)
    {
        cout<<Temp->Data<<"-> ";
        Temp = Temp -> Next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Count
//  Description   :  Used to Count elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Doubly_linkedList<T>::Count()
{
    struct node<T> *Temp = Head;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp -> Next;
    }
    return iCnt;
}

int main()
{
    Doubly_linkedList<int> obj1;
    Doubly_linkedList<float> *obj2 = new Doubly_linkedList<float>();
    Doubly_linkedList<char> *obj3 = new Doubly_linkedList<char>();

    obj1.InsertFirst(21);
    obj1.InsertLast(11);
    obj1.Display();
    cout<<"\nNUmber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertAtPosition(75.12,4);
    obj1.Display();
    cout<<"\nNUmber of nodes :"<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();
    cout<<"\nNUmber of nodes :"<<obj1.Count()<<"\n";

    obj2->InsertFirst(501.23);
    obj2->InsertFirst(511.22);
    obj2->InsertLast(505.33);
    obj2->Display();
    cout<<"\nNumber of nodes : "<<obj2->Count()<<"\n";

    obj3->InsertFirst('A');
    obj3->InsertFirst('B');
    obj3->Display();
    cout<<"\nNumber of nodes :"<<obj3->Count()<<"\n";



    delete obj2;
    delete obj3;

    return 0;
}

//////////////////////////////////////////////////////////////
//  OUTPUT :                                                //
//  11-> 21-> NULL                                          //
//                                                          //
//  NUmber of nodes : 2                                     //
//   101-> 11-> 21-> -75-> NULL                             //
//                                                          //
//  NUmber of nodes :4                                      //
//  11-> 21-> -75-> NULL                                    //
//  11-> 21-> NULL                                          //
//  11-> NULL                                               //
//                                                          //
// Number of nodes : 3                                      //
//////////////////////////////////////////////////////////////