////////////////////////////////////////////////////////////////////////
//                                                                    //
//     Generic Programming Using Doubly circular Linkedlist           //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
//                                                                                   
// Function Name : LinkedList                                                        
// Description   : Used to Count elements and display Doubly Circular Linked list   
// Input         : Integer                                                           
// Output        : Integer                                                           
// Date          : 05/06/2022                                                        
// Author        : Thorat Swapnil Harishchandra                                      
//                                                                                   
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node     
{
  T data;
  struct node<T> *next;   
  struct node<T> *prev;
};

template<class T>
class DoublyCLL      
{
  private:      

     struct node<T>  *Head;
     struct node<T>  * Tail;
     int CountNode;          

  public:
     DoublyCLL();       

     void InsertFirst(T);   
     void InsertLast(T);
     void InsertAtPos(T ,T);

     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(T);

     int Count();
     void Display();


};

template<class T>
DoublyCLL<T>::DoublyCLL()      
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertFirst(T iNo)  
{
  struct node<T> *newn = NULL;
  newn = new node<T>;

  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

  if(CountNode == 0)    //if(head == NULL) && (Tail == NULL))  LL is empty
  {
    Head = newn;     
    Tail = newn;     
  }
  else
  {
    newn->next = Head;
    Head->prev = newn;
    Head = newn;
  }

    Head->prev = Tail;
    Tail->next = Head;
  
    CountNode++;

}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertLast(T iNo)
{
  struct node<T> *newn = NULL;
  newn = new node<T>;

  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

  if(CountNode == 0)    //if(head == NULL) && (Tail == NULL))  LL is empty
  {
    Head = newn;     
    Tail = newn;
  }

  else
  {
    Tail->next = newn;    
    newn->prev = Tail;       

    Tail = newn;
    
  }

  Head->prev = Tail;
  Tail->next = Head;
  CountNode++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCLL<T>::InsertAtPos(T iNo , T iPos)
{
   if((iPos < 1) ||(iPos >CountNode+1))
   {
     cout<<"Invalid position\n";
     return;
   }
   
   if(iPos == 1)
   {
     InsertFirst(iNo);
   }
   else if(iPos == CountNode+1)
   {  
     InsertLast(iNo); 
   }
   else
   {
      struct node<T> *newn = NULL;
      newn = new node<T>;

      newn->data = iNo;
      newn->next = NULL;
      newn->prev = NULL;

      struct node<T> *temp = Head;

      for(int i = 1; i<iPos-1; i++)       
      {
        temp = temp->next;
      }

      newn ->next = temp ->next;
      temp->next->prev = newn;
      temp->next = newn;
      newn->prev = temp;

      CountNode++;      
   }

}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
  if(CountNode == 0)
  {
     return;
  }
  else if(CountNode == 1)
  {
     delete Head;
     Head = NULL;
     Tail = NULL;
  }
  else
  {
    Head = Head ->next;
    delete Tail->next;   
  }

  Tail->next = Head;
  Head->prev = Tail;
  CountNode--;
  
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteLast()
{
  if(CountNode == 0)
  {
     return;
  }
  else if(CountNode == 1)
  {
     delete Head;
     Head = NULL;
     Tail = NULL;
  }
  else
  {
    Tail = Tail->next;
    delete Tail->prev;    
    
  }

  Tail->next = Head;
  Head->prev = Tail;
  CountNode--;
  
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteAtPos(T iPos)
{
  if((iPos < 1) ||(iPos >CountNode))
   {
     cout<<"Invalid position\n";
     return;
   }
   
   if(iPos == 1)
   {
     DeleteFirst();
   }
   else if(iPos == CountNode)
   {  
     DeleteLast(); 
   }
   else
   {
      struct node<T> *temp = Head;
      for(int i = 1; i<iPos-1; i++)       
      {
        temp = temp->next;
      }

      temp->next = temp->next ->next;
      delete temp ->next->prev;
      temp->next->prev = temp;

      CountNode--;
   }
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
void DoublyCLL<T>::Display()
{
  int i = 0;
  struct node<T> *temp = Head;   

  for(i= 1; i<= CountNode; i++)    
  {
    cout<<"|"<<temp->data<<"|->";
    temp = temp->next;
  }
  cout<<"\n";
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
int DoublyCLL<T>::Count()
{
  return CountNode;
}

int main()
{
    int iRet = 0;

    DoublyCLL<int>obj1;
    DoublyCLL<float>*obj2 = new DoublyCLL<float>;
    DoublyCLL<char>*obj3 = new DoublyCLL<char>;


    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.Display();
    iRet =obj1.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj1.InsertLast(101);
    obj1.InsertLast(111);    
    obj1.Display();
    iRet =obj1.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj1.InsertAtPos(75,4);
    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj1.DeleteAtPos(4);
    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj2->InsertFirst(51.11);
    obj2->InsertFirst(21.11);
    obj2->Display();
    iRet = obj2->Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj2->InsertLast(34.11);
    obj2->InsertLast(35.11);
    obj2->Display();
    iRet = obj2->Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj3->InsertFirst('A');
    obj3->InsertFirst('B');
    obj3->Display();
    iRet = obj3->Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    obj3->InsertLast('C');
    obj3->InsertLast('D');
    obj3->Display();
    iRet = obj3->Count();
    cout<<"Number of nodes are :"<<iRet<<endl;

    delete obj2;
    delete obj3;

    return 0;
}

//////////////////////////////////////////////////////////////////
//  OUTPUT :                                                    //
//                                                              //
//   |21|->|51|->                                               //
//   Number of nodes are :2                                     //
//                                                              //
//   |21|->|51|->|101|->|111|->                                 //
//   Number of nodes are :4                                     //
//                                                              //
//   |21|->|51|->|101|->|75|->|111|->                           //
//   Number of nodes are :5                                     //
//                                                              //
//   |21|->|51|->|101|->|111|->                                 //
//   Number of nodes are :4                                     //
//                                                              //
//   |21.11|->|51.11|->                                         //
//   Number of nodes are :2                                     //
//                                                              //
//   |21.11|->|51.11|->|34.11|->|35.11|->                       //
//   Number of nodes are :4                                     //
//                                                              //
//   |B|->|A|->                                                 //
//   Number of nodes are :2                                     //
//                                                              //
//   |B|->|A|->|C|->|D|->                                       //
//   Number of nodes are :4                                     //
//                                                              //
//////////////////////////////////////////////////////////////////