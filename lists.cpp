//By David Zárate López
//Program designed to store numbers in linked list
//Last modification: 05/07/2021
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

// Complexity: O(1). This function will insert the input number given by the user at the beggining of the list
void insertBeggining(struct Node **head, int num){
  //First create a new Node, because **head is a double pointer and we need to be able to change the value of the original head pointer
  struct Node* newNode = new Node;
  //Then assign the value given by the user to the struct
  newNode->data = num;
  //Also, all the nodes next to the head are given to the newNode, because it's inseted at the beggining
  newNode->next = (*head);
  //Finally, the head now points to the newNode, to be correctly inserted at the beggining
  (*head) = newNode;
  cout<<endl<<"The number was inserted correctly!"<<endl<<endl;
}

//Complexity: O(n). This function will insert the input number given by the user at the end of the list
void insertEnd(struct Node **head, int num){
  //First create a new Node, because **head is a double pointer and we need to be able to change the value of the original head pointer
  struct Node* newNode = new Node;
  //Then assign the value given by the user to the struct
  newNode->data = num;
  //Now, instead of giving the value at which the head is pointing, the next (pointer) will be NULL, because it's the last node of the list
  newNode->next = NULL;
  //if the list is empty, the head will point at the newNode
  if (*head == NULL)
    *head = newNode;
  //if not, the list will need to be traversed
  else{
    //It's important to create a new struct Node pointer, in order to traverse to the end of the list and then insert the new Node.
    //The double pointer parameter isn't able to do that
    struct Node* lastNode = *head;
    //The next while indicates that it will stop when next (pointer) is equal to NULL, meaning that the lastNode pointer is at the last node of the list
    while (lastNode->next != NULL)
      lastNode = lastNode->next;
    //Finally, the newNode is attached to the list
    lastNode->next = newNode;
  }
  cout<<endl<<"The number was inserted correctly!"<<endl<<endl;
}

//Complexity: O(n). This function will delete the element at the beggining of the list
void deleteBeggining(struct Node **head){
  //Firstly, two Node pointers are created, both pointing to the same node as the head, one will be the new first node and the other one the node that is going to be deleted
  struct Node* newFirst = *head;
  struct Node* deleted = *head;
  //if the list is empty, there's nothing to delete
  if (*head == NULL)
    cout<<endl<<"There's nothing to delete"<<endl<<endl;
  //if it isn't empty the first node will be deleted
  else{
    //the new first will be the second node
    newFirst = deleted->next;
    //and the head will point to the new first node
    *head = newFirst;
    //the node that was located at the beggining is now deleted
    delete deleted;
    cout<<endl<<"The number was deleted correctly!"<<endl<<endl;
  }
}

//This function will delete the element at the end of the list
void deleteEnd(struct Node **head){
  //create a new Node pointer in order to traverse the linked list and find the last node
  struct Node* traverse = *head;
  //if the list is empty, there's nothing to delete
  if (*head == NULL){
    cout<<endl<<"There's nothing to delete"<<endl<<endl;
    return;
  }
  if (traverse->next == NULL){
    *head = NULL;
    delete traverse;
    cout<<endl<<"The number was insert deleted correctly!"<<endl<<endl;
    return;
  }
    //if it isn't empty, the pointer created will traverse the list until it reaches the node before the final node
    while (traverse->next->next != NULL)
      traverse->next;
    //the last node is deleted
    delete (traverse->next);
    //the new last node now points to NULL
    traverse->next = NULL;

}

//Prints the elements in the list
void printList(struct Node *head){
  //if the list is empty, the program notifies the user
  if (head == NULL){
    cout<<endl<<"The linked list is empty"<<endl<<endl;
    return;
  }
  else{
    //if it isn't empty, it prints all the elements inside the list
    cout<<endl<<"The elements in the linked list are: ";
    while(head != NULL){
      cout<<head->data<<" ";
      head = head->next;
    }
  }
  cout<<endl<<endl;
}

void linearSearch(struct Node *head, int num){
  //declare a boolean that will determine if the num is found or not
  bool found = false;
  //if the list is empty, the program notifies the user
  if (head == NULL){
    cout<<endl<<"The linked list is empty"<<endl<<endl;
    return;
  }
  //if it isn't empty, the list will be traversed
  while(head != NULL){
    //if the number is found, the boolean will be true
    if (head->data == num)
      found = true;
    head = head->next;
  }
  if (found)
    cout<<endl<<"The number IS in the list!"<<endl<<endl;
  else
    cout<<endl<<"The number is NOT in the list!"<<endl<<endl;
}


int main(){
 struct Node * head = NULL;
 int n = 0, num = 0;
 cout<<"Hi! Welcome to the linked list program"<<endl;
 while (n != 7){
   cout<<"What would you like to do?"<<endl;
   cout<<"1)Insert at the Beggining"<<endl;
   cout<<"2)Insert at the End"<<endl;
   cout<<"3)Delete at Beggining"<<endl;
   cout<<"4)Delete at End"<<endl;
   cout<<"5)Print List"<<endl;
   cout<<"6)Linear Search"<<endl;
   cout<<"7)Exit"<<endl;
   cin>>n;

   if (n == 1) {
     cout<<"Which number would you like to insert?"<<endl;
     cin>>num;
     insertBeggining(&head,num);
   }
   if (n == 2) {
     cout<<"Which number would you like to insert?"<<endl;
     cin>>num;
     insertEnd(&head,num);
   }
   if (n == 3)
     deleteBeggining(&head);
   if (n == 4)
     deleteEnd(&head);
   if (n == 5)
     printList(head);
   if (n == 6){
     cout<<"Which number would you like to look for?"<<endl;
     cin>>num;
     linearSearch(head,num);
   }
 }
 cout<<endl<<"Have a nice day!"<<endl<<endl;

}
