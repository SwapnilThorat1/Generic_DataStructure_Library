//////////////////////////////////////////////////////////////////////
//                                                                  //
//     Generic Programming Using Stack                              //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Stack
// Description   : Used to Push ,Pop Count and Display
// Input         : void
// Output        : Integer
// Date          : 10/07/2022
// Author        : Thorat Swapnil Harishchandra
//
////////////////////////////////////////////////////////////////////////////////

template<class T>         //generic
struct node
{
  T data;
  struct node *next;
};

template<class T>
class Stack
{
  public:
     struct node<T> *Head;
     int Count;

     Stack();
     void Push(T);      //InsertLast
     void Pop();        //Deletefirst    T = int,char ,float  is generic
     void Display();
     int CountNode();
};

template<class T>
Stack<T>::Stack()
{
  Head = NULL;
  Count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Push
// Description   : Used to InsertFirst count and Display
// Input         : void
// Output        : Integer
// Date          : 10/07/2022
// Author        : Thorat Swapnil Harishchandra
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::Push(T no)    //InsertFirst
{
  struct node<T> *newn = NULL;
  newn = new node<T>;

  newn->data = no;
  newn->next =NULL;

  newn->next = Head;
  Head = newn;                                                                                                                                                                                                                                                                                                                                                                                                      
  Count++;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Pop
// Description   : Used to deletefirst count and Display
// Input         : void
// Output        : Integer
// Date          : 10/07/2022
// Author        : Thorat Swapnil Harishchandra
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::Pop()      //this is deletefirst logic
{
  T no;   // t cha data no;   //temp = temporary  T is int,float  +  use int no

  if(Count == 0)  //empty Q
  {
    cout<<"Stack is empty"<<endl;
    return;
  }

  if(Count == 1)  //multiple node Q
  {
    no = Head->data;     //
    delete Head;
    Head = NULL;
  }
  else
  {
    no = Head->data;
    struct node<T> *temp = Head;
    Head = Head->next;
    delete temp;
  }
  Count--;                                   //he pan common statement hote if and else madhe te baher getle
  cout<<"Removed element is :"<<no<<endl;   //he common kadle he donisathi use honar if and else madhe
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Used to  Display
// Input         : void
// Output        : Integer
// Date          : 10/07/2022
// Author        : Thorat Swapnil Harishchandra
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>::Display()
{
  cout<<"Elements from Stack are :"<<endl;
  struct node<T> *temp = Head;    //PNODE temp = Head;

  while(temp != NULL)
  {
    cout<<temp->data<<"  ";
    temp = temp->next;
  }
  cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : CountNode
// Description   : Used to CountNode
// Input         : integer
// Output        : Integer
// Date          : 10/07/2022
// Author        : Thorat Swapnil Harishchandra
//
////////////////////////////////////////////////////////////////////////////////


template<class T>
int Stack<T>::CountNode()
{
  return Count;
}

int main()
{
  Stack <int>obj1;
  
  obj1.Push(11);
  obj1.Push(21);
  obj1.Push(51);
  obj1.Push(101);

  obj1.Display();
  cout<<"Number of elements is Stack:"<<obj1.CountNode()<<endl;

  obj1.Pop();
  obj1.Pop();

  obj1.Display();
  cout<<"Number of elements is Stack :"<<obj1.CountNode()<<endl; 

  obj1.Pop();

  Stack<char>*obj2 = new Stack<char>;

  obj2->Push('A');
  obj2->Push('B');
  obj2->Push('C');
  obj2->Push('C');

  obj2->Display();

  obj2->Pop();
  obj2->Pop();

  obj2->Display();

  obj2->Push('Z');
  obj2->Pop();

  Stack<float>*obj3 = new Stack<float>;

  obj3->Push(11.11);
  obj3->Push(12.11);
  obj3->Push(13.11);
  obj3->Push(14.11);

  obj2->Display();

  obj3->Pop();
  obj3->Pop();

  obj2->Display();

  obj3->Push(15.11);
  obj3->Pop();

  delete obj2;
  delete obj3;

  return 0;
}

//////////////////////////////////////////////////////////////
//  Output :                                                //
//  Elements from Stack are :                               //
//  101  51  21  11                                         //
//  Number of elements is Stack:4                           //
//                                                          //
//  Removed element is :101                                 //
//  Removed element is :51                                  //
//  Elements from Stack are :                               //
//  21  11                                                  //
//  Number of elements is Stack :2                          //
//                                                          //
//  Removed element is :21                                  //
//  Elements from Stack are :                               //
//  C  C  B  A                                              //
//  Removed element is :C                                   //
//  Removed element is :C                                   //
//  Elements from Stack are :                               //
//  B  A                                                    //
//                                                          //
//  Removed element is :Z                                   //
//  Elements from Stack are :                               //
//  B  A                                                    //
//  Removed element is :14.11                               //
//  Removed element is :13.11                               //
//  Elements from Stack are :                               //
//  B  A                                                    //
//  Removed element is :15.11                               //
//                                                          //
//////////////////////////////////////////////////////////////
