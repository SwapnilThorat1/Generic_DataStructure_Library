///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//   Generic Programming Using  Singly Circular LinkedList                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinkedList
// Description   : Used to Count elements and display Singly Circular Linked list 
// Input         : Integer
// Output        : Integer
// Date          : 04/06/2022
// Author        : Thorat Swapnil Harishchandra
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
  T data;
  struct node *next;
};


template<class T>
class SinglyCLL
{
   private:              //characteristic

      struct node<T> *Head;       
      struct node<T> *Tail;           

   public:             //Behaviour 

      SinglyCLL();    //Defualt Constructor
      void InsertFirst(T);
      void InsertLast(T);
      void InsertAtPos(T,T);
      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(T);
      void Display();
      int Count();         

};

template<class T>
SinglyCLL<T>::SinglyCLL()    //Defualt Constructor
{
  Head = NULL;
  Tail = NULL;
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
void SinglyCLL<T>::InsertFirst(T no)
{
  struct node<T>*newn = NULL;   //initialised

  newn = new node<T>;     
  newn->data = no;     
  newn->next = NULL;    

  if((Head == NULL) && (Tail == NULL))    
  {
    Head = newn;
    Tail = newn;          
  }
  else         
  {
    newn->next = Head;
    Head = newn;
  }
  Tail->next = Head;       
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
void SinglyCLL<T>::InsertLast(T no)
{
  struct node<T> *newn = NULL;   

  newn = new node<T>;     
  newn->data = no;     
  newn->next = NULL;    

  if((Head == NULL) && (Tail == NULL))    //If LL is empty
  {
    Head = newn;
    Tail = newn;          
  }
  else         // If LL contains atleast one node
  {
    Tail->next = newn;
    Tail = newn;
  }
  Tail->next = Head;       
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
void SinglyCLL<T>::InsertAtPos(T no,T ipos)
{
  int  iSize = Count();  

  if((ipos <1) || (ipos>iSize+1))
  {
    cout<<"Invalid position\n";
    return;
  }
  if(ipos ==1)
  {
    InsertFirst(no);
  }
  else if(ipos == iSize +1)
  {
    InsertLast(no);
  }
  else
  {
     struct node<T> *newn = NULL;   

     newn = new node<T>;     

     newn->data = no;     
     newn->next = NULL;   //Initialise pointer

     struct node<T> *temp  = Head;
     int iCnt = 0;

     for(iCnt =1; iCnt<ipos-1; iCnt++)
     {
       temp = temp->next;
     }

     newn->next = temp->next;
     temp->next  = newn;
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
void SinglyCLL<T>::DeleteFirst()
{
  if(Head == NULL && Tail == NULL)     //If  LL is empty
  {
    return;
  }
  else if(Head == Tail)     //if LL contains 1 node
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else              //if LL contains more than 1 node
  {
    Head = Head ->next;
    delete Tail->next;

    Tail->next = Head;
  }
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
void SinglyCLL<T>::DeleteLast()
{
  if(Head == NULL && Tail == NULL)     //If  LL is empty
  {
    return;
  }
  else if(Head == Tail)     //if LL contains 1 node
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else              //if LL contains more than 1 node
  {
    struct node<T> *temp = Head;   

   while(temp->next != Tail)   
   {
     temp = temp->next;
   }

   delete Tail;
   Tail = temp;

   Tail->next = Head;
  }
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
void SinglyCLL<T>::DeleteAtPos(T ipos)
{
  int iSize = Count();  

  if((ipos < 1) || (ipos > iSize+1))
  {
    cout<<"Invalid position\n";
    return;
  }
  if(ipos ==1)
  {
    DeleteFirst();
  }
  else if(ipos == iSize +1)
  {
    DeleteLast();
  }
  else
  {
    struct node<T> *temp1 = Head;
    int iCnt = 0;

    for(iCnt =1; iCnt<ipos-1; iCnt++)
    {
      temp1 = temp1->next;
    }

    struct node<T> *temp2 = temp1->next;

    temp1->next =temp2->next;
    delete temp2;
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
void SinglyCLL<T>::Display()
{
   struct node<T> *temp = Head;          

   if(Head == NULL && Tail == NULL)   //fillter
   {
     return ;
   }
   
   do
   {
     cout<<"|"<<temp->data<<"|->";
     temp = temp->next;
   }while(temp != Head);              //Head =  temp->next

   cout<<endl;
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
int SinglyCLL<T>::Count()        
{
  int iCnt = 0;
  struct node<T> *temp = Head;

  if(Head == NULL && Tail == NULL)   //fillter
   {
     return 0;
   }

  do
  {
    iCnt++;
    temp = temp->next;
  }while(temp != Head);

  return iCnt;
}         

int main()
{
  int iRet = 0;
  
  SinglyCLL <int> obj1;
  SinglyCLL <float> obj2;

  obj1.InsertFirst(51);
  obj1.InsertFirst(21);
  obj1.Display();
  iRet =obj1.Count();
  cout<<"Number of nodes are :"<<iRet<<endl;

  obj1.InsertLast(111);    
  obj1.InsertLast(151);
  obj1.Display();
  iRet =obj1.Count();
  cout<<"Number of nodes are :"<<iRet<<endl;

  obj1.InsertAtPos(75,4);
  obj1.Display();
  iRet = obj1.Count();
  cout<<"Number of nodes are :"<<iRet<<endl;

  obj2.InsertFirst(51.12);
  obj2.InsertFirst(21.11);
  obj2.Display();
  iRet =obj2.Count();
  cout<<"Number of nodes are :"<<iRet<<endl;


  obj2.InsertLast(111.23);    
  obj2.InsertLast(151.34);
  obj2.Display();
  iRet =obj2.Count();
  cout<<"Number of nodes are :"<<iRet<<endl;

  return 0;
}

/////////////////////////////////////////////////////////////////////
//   OUTPUT :                                                      //
//                                                                 //
//   |21|->|51|->                                                  //
//   Number of nodes are :2                                        //
//                                                                 //
//   21|->|51|->|111|->|151|->                                     //
//   Number of nodes are :4                                        //
//                                                                 //
//   |21|->|51|->|111|->|75|->|151|->                              //
//   Number of nodes are :5                                        //
//                                                                 //
//   |21.11|->|51.12|->                                            //
//   Number of nodes are :2                                        //
//                                                                 //
//   |21.11|->|51.12|->|111.23|->|151.34|->                        //
//   Number of nodes are :4                                        // 
//                                                                 //
/////////////////////////////////////////////////////////////////////
