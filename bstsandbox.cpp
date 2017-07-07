
/////////////////////////////
//FILE NAME: BST.h//
/////////////////////////////

////////////////
//Contributers//
////////////////

///////////////////////////////////////////////

// NAME                   DATE           CHANGE
// Dillon Dragomir        07-25-2017     Initialize
// Dillon Dragomir        07-26-2017     Test copy and insert
// Dillon Dragomir        07-27-2017     Test Destructor, insert and largest
// Dillon Dragomir        07-28-2017     Test inOrder, postOrder and preOrder

///////////////////////////////////////////////

////////////////
//DEPENDANCIES//
////////////////

#include <string>
#include <iostream>

#include "BST.h"

using namespace std;

// Returns a negative number if right is greater than right, 0 if equal
// and a positive number if left is greater than right.
int compare(const int& left, const int& right){
  return left - right;
}

int compare(const string& left, const string& right){
  // The string class has a built-in compare function!
  return left.compare(right);
}


int main(int argc, char* argv[]){
  // Pass in comparator function
  // Test all of the functionality
  BST<int> a(compare);
  BST<string> c(compare);
  c.insert("bob");
  c.insert("apple");
  c.insert("binge");
  cout<< "find bob: " << c.find("bob") << endl;
#if 1
  a.insert(5);
  a.insert(2); 
  a.insert(-10);
  a.insert(-10); 
  a.insert(534);
  a.insert(-232); 
  a.insert(51);
  a.insert(51);  
  a.insert(15);
  cout << "Smallest: " << a.getSmallest() << endl;
  cout << "Largest: " << a.getLargest() << endl;
  cout << "Size: " << a.size() << endl;
  cout << "Exists(-10): " << a.find(-10) << endl;
  cout << "Exists(3): " << a.find(3) << endl;
  cout << "Height: " << a.getHeight() << endl;
  cout << "Is Full: " << a.isFull() << endl;
  cout << "Is Balanced: " << a.isBalanced() << endl;
  cout << "In Order: " << endl << a.getInOrder() << endl;
  cout << "Pre Order: " << endl << a.getPreOrder() << endl;
  cout << "Post Order: " << endl << a.getPostOrder() << endl;
  BST<int> b(compare);
  cout << "Seting b equal to a" << endl;
  b = a;
  cout << "Smallest(b): " << b.getSmallest() << endl;
  cout << "Largest(b): " << b.getLargest() << endl;
  b.insert(-500);
  cout << "Inserted -500 into b: " << endl;
  cout << "Smallest(b): " << b.getSmallest() << endl;
  a.clear();
  cout << "Cleared Tree: " << endl;
  cout << "List Empty: " << a.isEmpty() << endl;
  // Error Handling
  try{
	  a.getSmallest();
  } catch (invalid_argument& e){
	  cout << e.what() << endl;
  }
  /*& e
  cout << "Largest: " << a.getLargest() << endl;
  cout << "Size: " << a.size() << endl;
  cout << "Exists(-10): " << a.find(-10) << endl;
  cout << "Exists(3): " << a.find(3) << endl;
  cout << "Height: " << a.getHeight() << endl;
  cout << "Is Full: " << a.isFull() << endl;
  cout << "Is Balanced: " << a.isBalanced() << endl;
  cout << "In Order: " << endl << a.getInOrder() << endl;
  cout << "Pre Order: " << endl << a.getPreOrder() << endl;
  cout << "Post Order: " << endl << a.getPostOrder() << endl;
  */
#endif

}
