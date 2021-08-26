#include <iostream>

using namespace std;

struct Node{
  int data;
  struct Node* right;
  struct Node* left;
};

//Funtion that inserts the input value of the user in the BST
//Complexity: O(n)
void insertNode(struct Node** head, int num){
  //The traverse pointer will move through the BST until it reaches NULL
  struct Node* traverse = *head;
  //newNode will be the node that will be inserted in the BST
  struct Node* newNode = new Node;
  //The last pointer will be equal to the traverse node until traverse it's NULL, when this happens the "last" pointer will be positioned in the last node of the BST
  struct Node* last = traverse;
  //Assigning values to the newNode
  newNode->data = num;
  newNode->right = NULL;
  newNode->left = NULL;
  //If the BST is empty, the head will point to the newNode and the function will finish
  if(*head == NULL){
    cout<<endl<<"The number was inserted correctly!"<<endl<<endl;
    *head = newNode;
    return;
  }
  //If it isn't empty, the traverse pointer will identify where the newNode should be inserted.
  while(traverse != NULL){
    last = traverse;
    //if the current number is bigger than the input of the user, traverse will move to the left
    if(num < traverse->data)
      traverse = traverse->left;
    //if the current number is smaller than the input of the user, traverse will move to the right
    else if(num > traverse->data)
        traverse = traverse->right;
    //if the current number is equal to the input of the user, the number can't be inseted because the BST do not accept the same value repeated
    else if(num == traverse->data){
      cout<<endl<<"The number is already in the binary search tree"<<endl<<endl;
      return;
    }

  }
  //After the last node is found, now it's time to compare if the input number is bigger or smaller than the number of last node
  //if it's smaller, the newNode will be positioned to the left of the last node
  if(num < last->data)
    last->left = newNode;
  //if it's bigger, the newNode will be positioned to the right if the last node
  else
    last->right = newNode;
  cout<<endl<<"The number was inserted correctly!"<<endl<<endl;
}

struct Node* findMinNode(struct Node *traverse){
  //this will give us the node we want to delete
  while(traverse->left != NULL)
    traverse = traverse->left;
  return traverse;
}

//there are 3 cases in this function, where the node has 2 children, when it only has 1 and when it has none
void deleteNode(struct Node** head, int num){
  struct Node* deletedNode = *head;
  struct Node *beggining = *head;
  struct Node* parentOfDeleted = deletedNode;
  if(*head == NULL){
    cout<<endl<<"There's nothing to delete"<<endl<<endl;
    return;
  }
  bool found = false;
  bool right = false;
  //first we need to find the node we want to delete
  while(!found && deletedNode != NULL){
    cout<<deletedNode->data<<endl;
    if(num != deletedNode->data)
      parentOfDeleted = deletedNode;
    if(num < deletedNode->data){
      deletedNode = deletedNode->left;
      right = false;
    }
    else if(num > deletedNode->data){
      deletedNode = deletedNode->right;
      right = true;
    }
    else if(num == deletedNode->data)
      found = true;
  }
  //if it's not found, then the program will display a message to the user
  if(!found){
    cout<<"Node not found"<<endl<<endl;
    return;
  }
  //now it's time to check which case of the 3 possible ones we have
  //first check if the node is a leaf
    //if the node that's going to be deleted is to the right of it's parent
  if(deletedNode-> right == NULL && deletedNode-> left == NULL){
    if(right)
      parentOfDeleted->right = NULL;
    //if the node that's going to be deleted is to the left of it's parent
    else
      parentOfDeleted->left = NULL;
    delete deletedNode;
  }
  //if the node that we want to delete has only one child
  //if it has a right child
  else if(deletedNode-> right != NULL && deletedNode-> left == NULL){
    if(right)
      parentOfDeleted->right = deletedNode->right;
    else
      parentOfDeleted->left = deletedNode->right;
    delete deletedNode;
  }
  //if it has a left child
  else if(deletedNode-> right == NULL && deletedNode-> left != NULL){
    if(right)
      parentOfDeleted->right = deletedNode->left;
    else
      parentOfDeleted->left = deletedNode->left;
      delete deletedNode;
  }
  //if the node we want to delete has two children
  else{
    struct Node* temp = findMinNode(deletedNode->right);
    int aux = 0;
    aux = deletedNode->data;
    deletedNode->data = temp->data;
    temp->data = aux;
    cout<<temp->data<<" temp->data"<<endl;
    cout<<deletedNode->data<<" temp->data"<<endl;
    cout<<"yes"<<endl;
    deleteNode(&beggining,num);
  }

  cout<<endl<<"The Node was deleted succesfuly!"<<endl;

}

//This function searches the n
//Complexity: O(n log n) because each time the number is compared to a node, the number of options to search are halved
void searchNode(struct Node* head, int num){
  //while the head hasn't reached to the end, the loop will continue
  while(head != NULL){
    //if the number is less than the current node, the pointer will go to the left
    if(num < head->data)
      head = head->left;
    //if the number is bigger than the current node, the pointer will go to the right
    else if (num > head->data)
      head = head->right;
    //if the number is equal than the current node, the node has been found
    else{
      cout<<"The number IS in the BST"<<endl<<endl;
      return;
    }
  }
  //if the loop finishes and it didn't found the number, it means that the number isn't in the BST
  cout<<"The number IS NOT in the BST"<<endl<<endl;
}

//Function that prints the BST in PreOrder
//Complexity: O(n) because it has to print each node, in this case, n is the number of nodes in the BST
void printPreOrder(struct Node* head){
  if(head != NULL){
    cout<<head->data<<" ";
    printPreOrder(head->left);
    printPreOrder(head->right);
  }
}

//Function that prints the BST in InOrder
//Complexity: O(n) because it has to print each node, in this case, n is the number of nodes in the BST
void printInOrder(struct Node* head){
  if(head != NULL){
    printInOrder(head->left);
    cout<<head->data<<" ";
    printInOrder(head->right);
  }
}

//Function that prints the BST in PostOrder
//Complexity: O(n) because it has to print each node, in this case, n is the number of nodes in the BST
void printPostOrder(struct Node* head){
  if(head != NULL){
    printPostOrder(head->left);
    printPostOrder(head->right);
    cout<<head->data<<" ";
  }
}

int main(){
  struct Node* head = NULL;
  int n = 0, num = 0;
  cout<<"Hi! Welcome to the Binary Search Tree (BST) program"<<endl;
  while (n != 7){
    cout<<"What would you like to do?"<<endl;
    cout<<"1)Insert a Node"<<endl;
    cout<<"2)Delete a Node"<<endl;
    cout<<"3)Find if a certain value is in the tree"<<endl;
    cout<<"4)Print pre-order "<<endl;
    cout<<"5)Print in-order"<<endl;
    cout<<"6)Print post-order"<<endl;
    cout<<"7)Exit"<<endl;
    cin>>n;

    if (n == 1) {
      cout<<endl<<"Which number would you like to insert?"<<endl;
      cin>>num;
      insertNode(&head,num);
    }
    if (n == 2) {
      cout<<"Which number would you like to delete?"<<endl;
      cin>>num;
      deleteNode(&head,num);
    }
    if (n == 3){
      cout<<endl<<"Which number would you like to look for?"<<endl;
      cin>>num;
      searchNode(head,num);
    }
    if (n == 4){
      cout<<endl<<"The elements in the BST PRE-ORDER are: "<<endl;
      printPreOrder(head);
      cout<<endl<<endl;
    }
    if (n == 5){
      cout<<endl<<"The elements in the BST IN-ORDER are: "<<endl;
      printInOrder(head);
      cout<<endl<<endl;
    }
    if (n == 6){
      cout<<endl<<"The elements in the BST POST-ORDER are: "<<endl;
      printPostOrder(head);
      cout<<endl<<endl;
    }
  }
  cout<<endl<<"Have a nice day!"<<endl<<endl;

}
