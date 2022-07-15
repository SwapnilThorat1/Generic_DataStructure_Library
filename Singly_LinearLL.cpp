///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//     Generic Programming Using  Singly Linear LinkedList                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////////
//
// Function Name : LikedList
// Description   : Used to Count elements and display Singly Linear Linked list 
// Input         : Integer
// Output        : Integer
// Date          : 30/05/2022
// Author        : Thorat Swapnil Harishchandra
//
////////////////////////////////////////////////////////////////////////////////

#define TRUE 1
#define FALSE 0


template<class T>
struct node       //structure Defination
{
    T Data;
    struct node *Next;
};


template<class T>
class Singly_linkedList
{
    private:
      
      struct node<T> *Head;

    public:
      Singly_linkedList();
      ~Singly_linkedList();
      int  InsertFirst(T);
      int InsertLast(T);
      int  InsertAtPosition(T,T);
      inline void Display();
      inline int Count();
      int DeleteFirst();
      int  DeleteLast();
      int DeleteAtPosition(T);
     
};

template<class T>
Singly_linkedList<T>:: Singly_linkedList()
{
    Head = NULL;
}

template<class T>
Singly_linkedList<T>::~Singly_linkedList()
{
    struct node<T> *Temp,*Navigate;

    if(Head != NULL)
    {
        Navigate = Head;
            while(Navigate != NULL)
            {
                Temp = Navigate->Next;
                delete Navigate;
                Navigate = Temp;
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
int  Singly_linkedList<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;     //Allocate memory

    if(newn == NULL)
    {
        return FALSE;
    }

    newn->Next = NULL;   //Initialise pointer
    newn->Data = no;     //Initialise data

    if(Head == NULL)    //Linkedlist is empty
    {
        Head = newn;
    }
    else                //LL Contains atleast one node
    {
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
int  Singly_linkedList<T>::InsertLast(T no)
{
    struct node<T>  *newn = NULL, *temp = Head;

    newn = new node<T>;   //Allocate memory

    if(newn == NULL)
    {
        return FALSE;
    }
    newn->Next = NULL;  //Initialise data 
    newn->Data = no;    //Initialise pointer

    if(Head == NULL)    //Linkedlist is empty
    {
        Head = newn;
    }
    else                //LL contains atleast one node
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
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
int  Singly_linkedList<T>::InsertAtPosition(T pos,T no)
{
    if((Head == NULL)  || (pos > Count()+1 ) || (pos <= 0))
    {
        return FALSE;
    }

    if(pos == 1)
    {
        return(InsertFirst(no));
    }
    else if(pos == (Count()) +1)
    {
        return(InsertLast(no));
    }
    else
    {
        struct node<T> *newn = NULL, *temp = Head;

        newn = new node<T>;
        if(newn == NULL)
        {
            return FALSE;
        }
        newn->Next = NULL;
        newn->Data = no;

        for(int i = 1; i<= (pos-2); i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
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
int  Singly_linkedList<T>::DeleteFirst()
{
    struct node<T> *temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head->Next;
        delete(temp);
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
int  Singly_linkedList<T>::DeleteLast()
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
        struct node<T> *temp1 = Head,*temp2 = NULL;

        while(temp1-> Next-> Next != NULL)
        {
            temp1 = temp1-> Next;
        }

        temp2 = temp1->Next;
        temp1->Next = NULL;
        delete(temp2);
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
int  Singly_linkedList<T>::DeleteAtPosition(T pos)
{
    if((Head == NULL) || (pos > Count()) ||(pos <= 0))
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
        struct node<T> *temp1 = *Head,*temp2 = NULL;

        for(int i = 1;i<= (pos-2); i++)
        {
            temp1 = temp1-> Next;
            ++i;
        }

        temp2 = temp1->Next;
        temp1->Next = temp2->Next;

        delete temp2;
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
void Singly_linkedList<T> ::Display()
{
    struct node<T> *Temp = Head;

    while(Temp != NULL)
    {
        cout<<Temp->Data<<"-> ";
        Temp = Temp->Next;
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
int Singly_linkedList<T> ::Count()
{
    struct node<T> *Temp = Head;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp->Next;
    }
    return iCnt;
}

int main()
{
    Singly_linkedList<int> obj1;
    Singly_linkedList<float> *obj2 = new Singly_linkedList<float>();
    Singly_linkedList<char> *obj3= new Singly_linkedList<char>();

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.Display();
    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

   
    obj1.InsertAtPosition(75,4);
    obj1.Display();

    obj1.DeleteFirst();
    obj1.Display();
    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";


    obj2->InsertFirst(501.11);
    obj2->InsertFirst(511.12);
    obj2->Display();
    cout<<"\nNumber of nodes : "<<obj2->Count()<<"\n";


    obj2->InsertLast(551.13);
    obj2->InsertAtPosition(601.5,3);
    obj2->Display();
    cout<<"\nNumber of nodes :"<<obj2->Count()<<"\n";

    obj3->InsertFirst('A');
    obj3->InsertFirst('B');
    obj3->Display();

    obj3->InsertLast('D');
    obj3->InsertLast('E');
    obj3->Display();
    cout<<"\nNumber of nodes :"<<obj3->Count()<<"\n";

    delete obj2;

    return 0;
}

//////////////////////////////////////////////////////////////////////
//   OUTPUT :                                                       //
//                                                                  //
//  11-> 21-> 51-> NULL                                             //
//                                                                  //
//  Number of nodes : 3                                             //
//  11-> 21-> 51-> NULL                                             //
//  21-> 51-> NULL                                                  //
//                                                                  //
//  Number of nodes : 2                                             //
//  511.12-> 501.11-> NULL                                          //
//                                                                  //
//  Number of nodes : 2                                             //
//  511.12-> 501.11-> 551.13-> NULL                                 //
//                                                                  //
//  Number of nodes :3                                              //
//  B-> A-> NULL                                                    //
//  B-> A-> D-> E-> NULL                                            //
//                                                                  //
//  Number of nodes :4                                              //                                              
//////////////////////////////////////////////////////////////////////




