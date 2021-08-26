//By David Zárate López
//Program designed to store numbers in a double linked list
//Last modification: 25/08/2021
#include <iostream>

using namespace std;

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node* createNewNode(int val){
  struct Node* newNode = new Node;
  newNode->prev = NULL;
  newNode->next = NULL;
  newNode->data = val;
  return newNode;
}

void insertAtBeginning(struct Node **head, struct Node **tail, int val){
  struct Node *newNode = createNewNode(val);
  struct Node *lastFirstNode = *head;
  if(*head == NULL)
    *tail = newNode;
  if(*head != NULL)
    lastFirstNode->prev = newNode;
  newNode->next = *head;
  *head = newNode;
}

void printListForward(struct Node* head){
  while(head != NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

void printListBackward(struct Node* tail){
  while(tail != NULL){
    cout<<tail->data<<" ";
    tail = tail->prev;
  }
  cout<<endl;
}

int main(){
  struct Node *head = NULL;
  struct Node *tail = NULL;
  int n = 0, num = 0;
  cout<<"Hi! Welcome to the doubly linked list program"<<endl;
  while (n != 7){
    cout<<"What would you like to do?"<<endl;
    cout<<"1)Insert at the Beggining"<<endl;
    cout<<"2)Insert at the End"<<endl;
    cout<<"3)Delete at Beggining"<<endl;
    cout<<"4)Delete at End"<<endl;
    cout<<"5)Print List Forwards"<<endl;
    cout<<"6)Print List Backwards"<<endl;
    cout<<"7)Find if a certain value is in the tree"<<endl;
    cout<<"8)Exit"<<endl;
    cin>>n;

    if (n == 1) {
      cout<<"Which number would you like to insert?"<<endl;
      cin>>num;
      insertAtBeginning(&head,&tail,num);
    }
    // if (n == 2) {
    //   cout<<"Which number would you like to insert?"<<endl;
    //   cin>>num;
    //   insertEnd(&head,num);
    // }
    // if (n == 3)
    //   deleteBeggining(&head);
    // if (n == 4)
    //   deleteEnd(&head);
    if (n == 5)
      printListForward(head);
    if (n == 6)
      printListBackward(tail);
    // if (n == 6){
    //   cout<<"Which number would you like to look for?"<<endl;
    //   cin>>num;
    //   linearSearch(head,num);
    // }
  }
  cout<<endl<<"Have a nice day!"<<endl<<endl;
}
