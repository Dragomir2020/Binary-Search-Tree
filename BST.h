
/////////////////////////////
//FILE NAME: BST.h//
/////////////////////////////

////////////////
//Contributers//
////////////////

///////////////////////////////////////////////

// NAME                   DATE           CHANGE
// Dillon Dragomir        07-25-2017     Functions for BST
// Dillon Dragomir        07-26-2017     Added copy constructor and insert
// Dillon Dragomir        07-27-2017     Work in Lab with destructor, get smallest and largest
// Dillon Dragomir        07-28-2017     Add inOrder, postOrder and preOrder
// Dillon Dragomir        07-28-2017     Get constructor and destructor working
// Dillon Dragomir        07-29-2017     Fixed performance and checked edge cases

///////////////////////////////////////////////

////////////////
//DEPENDANCIES//
////////////////

#ifndef BST_H
#define BST_H

#include <ostream>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

// Node class holds value and left and right pointer
template <class T>
class Node{

public: Node(Node* left, Node* right, T value)
  :data(value),left(left),right(right){}
  T data;
  Node* left;
  Node* right;
  
};

template <class T>
class BST {

public:
  // CONSTRUCTOR
  BST( int (*f)(const T&, const T&) ){
    cmpfn = f;
    // Initialize root to null so other functions know tree DNE
    root = NULL;
  }
  // DESTRUCTOR
  ~BST() {
    // Use recursion to delete all nodes
    // This could also be accomplished with smart pointers and delete top node
	clear();
	delete root;
  }
  // COPY CONSTRUCTOR
  BST(const BST& other){
    // Make sure to copy over comparator function
	cmpfn = other.cmpfn;
    if(other.root == NULL){
        root = NULL;
    }
    else { 
		// Set root to copy constructor
        root = copyRecursive(other.root);
    }
  }
  // Assignment Operator	
  BST<T>& operator= (const BST& other){  
	    if(this != &other)
	    {
	       this->clear();
	       Node<T> *c = other.root;
	       preORet(c);
	    }
		return *this;
	}
  // INSERT: Inserts new value into Binary Search Tree
  void insert(T thing){
	  if (root==NULL){
	  	root = new Node<T>(NULL, NULL, thing);
	  } else {
		// Use trav fucntion to get location of top node to place new item  
        Node<T>* par = NULL;
        Node<T>* curr = trav(thing,par);
	 
        if(!curr) //no duplicates
        {
            curr= new Node<T>(NULL,NULL,thing);
      
            if(!par)
                root=curr;
            else if((*cmpfn)(thing, par->data) < 0)
                par->left=curr;
            else
                par->right=curr;
      }
 }
         
  } // end insert
  // FIND
  bool find(const T thing){
    return findR(thing, root);
  }
  // SIZE
  unsigned int size(){
    unsigned Total = sizeR(root);
    return Total;
  }
  // GETSMALLEST
  T getSmallest(){
  	// Have to verify root is not equal to NULL
  	if(root!=NULL){
       Node<T>* current = root;
       // Loop down to find leftmost leaf
       while((current->left) != NULL){
    	   current = current->left;
       }
       T min = current->data;
       return min;
    }else{
	   throw invalid_argument( "EXCEPTION: No elements stored." );
       return -1;
    }
  }
  // GETLARGEST
  T getLargest() const{
    // Have to verify root is not equal to NULL
  	if(root!=NULL){
       Node<T>* current = root;
       // Loop down to find leftmost leaf
       while((current->right) != NULL){
    	   current = current->right;
       }
       T min = current->data;
       return min;
    }else{
	   throw invalid_argument( "EXCEPTION: No elements stored." );
       return -1;
    }
  }
   // CLEAR
   void clear(){
	  // Use same as destructor
	   destroyRecursive(root);
	   root = NULL;
   }
   // GET IN ORDER
   string getInOrder(){
	  string A = "";
	  inOrder(root,A);
	  string Ns = A.substr(0,A.length()-1);
	  A = "[" + Ns + "]";
      return A;
   }
   // GET PRE ORDER
  string getPreOrder(){
	  string A = "";
	  preOrder(root,A);
	  string Ns = A.substr(0,A.length()-1);
	  A = "[" + Ns + "]";
      return A;
  }
  // GET POST ORDER
  string getPostOrder(){
	  string A = "";
	  postOrder(root,A);
	  string Ns = A.substr(0,A.length()-1);
	  A = "[" + Ns + "]";
      return A;
  }
  // GET HEIGHT OF TREE
  unsigned int getHeight() const{
	  unsigned int height;
	  if(root==NULL)
		  return 0;
	  else
		 return height = treeHeight(root);
  }
  // IS TREE FULL
  bool isFull(){
	bool Full = isFullTree(root);
    return Full;
  }
  // IS TREE BALANCED
  bool isBalanced() {
      if(checkTreeHeight(root) == -1)
      {
         return false;
      }
      else
      {
         return true;
      }
  }
   // Is EMPTY: USED TO TEST WHETHER TREE IS EMPTY
   bool isEmpty() const{
	   return (root == NULL);
   }

// Private functions for recursion
private:

  Node<T>* root;
  int (*cmpfn)(const T& left, const T& right);
  
  void destroyRecursive(Node<T>* leaf) {
  	// Delete node
  	if (leaf!=NULL){
  	    destroyRecursive(leaf->left);
  		destroyRecursive(leaf->right);
		// Must set parameters equal to null, so objects are same size
		leaf->right = NULL;
		leaf->left = NULL;
  		delete leaf;
  		//mleaf = NULL;
  	}
  }
  // Recursive size function
  T sizeR(Node<T>* u) {
        if (u == NULL) return 0;
        return (1 + sizeR(u->left) + sizeR(u->right));
  }
  // Recursive find function
  bool findR(T thing, Node<T>* u){
	 
  	if (u == NULL) 
		return 0;
	else if((*cmpfn)(u->data, thing) == 0)
		return 1;
	else if((*cmpfn)(u->data, thing) > 0)
		return findR(thing,u->left);
	else if((*cmpfn)(u->data, thing) < 0)
		return findR(thing,u->right);
	return 0;
  }
  // InOrder Recursive
  void inOrder(Node<T>* Root, string& App){
     if(Root != NULL)
     {
        inOrder(Root->left,App);
        stringstream s;
		s << Root->data << ","; 
		App = App + s.str();
        inOrder(Root->right,App);
	 }
  }
  // PreOrder Recursive
  void preOrder(Node<T>* Root, string& App){
     if(Root != NULL)
     {
        stringstream s;
		s << Root->data << ","; 
		App = App + s.str();
        preOrder(Root->left,App);
        preOrder(Root->right,App);
	 }
  }
  // PostOrder Recursive
  void postOrder(Node<T>* Root,string& App){
     if(Root != NULL)
     {
        postOrder(Root->left,App);
        postOrder(Root->right,App);
        stringstream s;
		s << Root->data << ","; 
	    App = App + s.str();
	 }
  }
  //traverse function
  Node<T>* trav(T foo, Node<T>* & par)
  {
       Node<T>* curr = root;
       par = NULL;
       while(curr )
       {
       //&& curr->data != foo
           par=curr;
           if((*cmpfn)(foo, curr->data) < 0)
               curr=curr->left;
           else
               curr=curr->right;
       }
       return curr;
  }
  // Function finds height of binary tree
  unsigned int treeHeight(Node<T>* p) const{
      if (p == NULL)
      {
         return -1;
      }

      int left = treeHeight(p->left);
      int right = treeHeight(p->right); 

      return 1 + max(left, right);
  }
  /* This function tests if a binary tree is a full binary tree. */
  bool isFullTree (Node<T>* p)
  {
      // If empty Node
      if (p == NULL)
          return true;
 
      // If leaf node
      if (p->left == NULL && p->right == NULL)
          return true;
 
      // If both left and right are not NULL, and left & right subtrees
      // are full
      if ((p->left) && (p->right))
          return (isFullTree(p->left) && isFullTree(p->right));
 
      // We reach here when none of the above if conditions work
      return false;
  }
  // 
  int checkTreeHeight(Node<T>* r)
  {
     if(r == NULL) return 0; // Height of 0.

     // Check if left is balanaced
     int leftChildHeight = checkTreeHeight(r->left);
     if(leftChildHeight == -1) return -1; // Not Balanced

     // Check if right is balanaced
     int rightChildHeight = checkTreeHeight(r->right);
     if(rightChildHeight == -1) return -1; // Not Balanced

     // Check if current node is balanced
     int heightDifference = leftChildHeight - rightChildHeight;

     if(abs(heightDifference) > 1)
        return -1; // not balanaced
     else
        return max(leftChildHeight, rightChildHeight) + 1; // Return Height
  } 
  // COPY CONSTRUCTOR RECURSIVE
  Node<T>* copyRecursive(Node<T>* sourceRoot){
  	if(sourceRoot == NULL)
    {
        return NULL;
    }
	// Recursive section copying in left, right and data
    Node<T>* copyNode = new Node<T>(copyRecursive(sourceRoot->left),copyRecursive(sourceRoot->right),sourceRoot->data);
	return copyNode;
  }
  // ASSIGNMENT OPERATOR RECURSIVE
  void preORet(Node<T>* c)
  {
      
	  this->insert(c->data);
	  // Should this be pre post or in order?
	  if(c->left != nullptr)
	      preORet(c->left);
	  
	  if(c->right != nullptr)
	      preORet(c->right);
	  // Should this be at begining or end
	  
  }
 
};

#endif
