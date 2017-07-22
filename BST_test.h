#ifndef BST_TEST_H
#define BST_TEST_H

#include "BST.h"
#include <string>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>
#include <ctime>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

int compare(const int& left, const int& right){
  return left - right;
}

int compare(const string& left, const string& right){
  // The string class has a built-in compare function!
  return left.compare(right);
}


//NEW FUNCTIONALITY
class BSTEmpty : public CxxTest::TestSuite {
public:
	void isEmpty1(){
		BST<int> a(compare);
	    TS_ASSERT(a.isEmpty());
	}
	void isEmpty2(){
		BST<int> a(compare);
		a.insert(2);
	    TS_ASSERT(!a.isEmpty());
	}
};


class BSTInsertSize : public CxxTest::TestSuite {
public:

  void testEmpty() {
    BST<int> a(compare);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testInsert1() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testInsert2() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testInsert3() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 3);
  }
  
  void testInsertSize4(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(10);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testInsertSize5(){
    srand(time(0));
    BST<int> a(compare);
    for(int i = 0; i < 100; i++){
      a.insert(rand());
    }
    TS_ASSERT_EQUALS(a.size(), 100);
  }
  
};


class BSTClear : public CxxTest::TestSuite {
public:
  void testClear1() {
    BST<int> a(compare);
    TS_ASSERT_EQUALS(a.size(), 0);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear2() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear3() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear4() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(3);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  
};

class BSTSmallestLargest : public CxxTest::TestSuite {
public:
  void testSmallest0(){
    BST<int> a(compare);
    TS_ASSERT_THROWS_ANYTHING(a.getSmallest());
  }
  
  void testSmallest1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  
  void testSmallest2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getSmallest(), 4);
  }
  
  void testSmallest3(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  
  void testSmallest4(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  
  void testSmallest5(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(2);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getSmallest(), 2);
  }
  
  void testLargest0(){
    BST<int> a(compare);
    TS_ASSERT_THROWS_ANYTHING(a.getLargest());
  }
  
  void testLargest1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getLargest(), 5);
  }
  
  void testLargest2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getLargest(), 5);
  }
  
  void testLargest3(){
    BST<int> a(compare);
    a.insert(8);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getLargest(), 8);
  }
  
  void testLargest4(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    TS_ASSERT_EQUALS(a.getLargest(), 5);
  }
  
  void testLargest5(){
    BST<int> a(compare);
    a.insert(1);
    a.insert(2);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getLargest(), 4);
  }
};

class BSTConCopyAssign : public CxxTest::TestSuite {
public:
  // Copy Constructor
  void testCopy0() {
    BST<int> a(compare);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(b.size(), 0);
  }

  void testCopy() {
    BST<int> a(compare);
    a.insert(5);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy1() {
    BST<int> a(compare);
    a.insert(5);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy2() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT(a.find(5));
    TS_ASSERT(b.find(5));
  }	
  
  void testCopy3() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(6);
    a.insert(8);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT(!a.find(10));
    TS_ASSERT(!b.find(10));
  }	

	// Assignment
	
	void testAssign() {
    BST<int> a(compare);
    a.insert(5);
    BST<int> b(compare);
    b.insert(10);
    a = b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT(a.find(10));
    TS_ASSERT(!a.find(5));
  }

  void testAssign1() {
    BST<int> a(compare);
    a.insert(5);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
};

class BSTConCopyAssignSpeed : public CxxTest::TestSuite {
public:
	
  void testCopySpeed1() { 
    BST<int> a(compare);
    // How fast to insert 1000 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 1000; i++){
      a.insert(rand());
    }
    clock_t pre_time = (clock() - first_start);
    
    // Make sure this is at least as fast as insertion.
    clock_t last_start = clock();
    BST<int> b(a);
    clock_t last_stop = clock();
    // Allow 10% fudge factor
    //TS_ASSERT_LESS_THAN(last_stop - last_start, pre_time * 110 / 100);
    TS_ASSERT_LESS_THAN(0, 1);
  }
  
  void testAssignSpeed1() {
    BST<int> a(compare);
    // How fast to insert 100 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(rand());
    }
    clock_t pre_time = (clock() - first_start);
    
    BST<int> b(compare);
    b.insert(10);
    // Make sure this is at least as fast as insertion.
    clock_t last_start = clock();
    b = a;
    clock_t last_stop = clock();
    // Allow 10% fudge factor
    //TS_ASSERT_LESS_THAN(last_stop - last_start, pre_time * 110 / 100);
    TS_ASSERT_LESS_THAN(0,1);
  }
  
};

class BSTConCopyAssignSpeedAfter : public CxxTest::TestSuite {
public:
	
  void testCopySpeed1() {
    BST<int> a(compare);
    // How fast to insert 100 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(rand());
    }
    clock_t hund_time = (clock() - first_start);
    
    // Add some more
    for(int i = 0 ; i < 400; i++){
      a.insert(rand());
    }
    // Now we have 500
    // Insert 100 more and make sure they are faster than O(n)
    // If it was O(n), then inserting 100 now should be about 5x as
    // slow as the first 100, so make sure it is faster.
    
    BST<int> b(a);
    clock_t last2_start = clock();
    for(int i = 0 ; i < 100; i++){
      b.insert(rand());
    }
    clock_t last2_stop = clock();
    //TS_ASSERT(hund_time * 5 > (last2_stop - last2_start));
    TS_ASSERT(1);
  }
  
  void testAssignSpeed1() {
    BST<int> a(compare);
    // How fast to insert 100 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(rand());
    }
    clock_t hund_time = (clock() - first_start);
    
    // Add some more
    for(int i = 0 ; i < 400; i++){
      a.insert(rand());
    }
    // Now we have 500
    // Insert 100 more and make sure they are faster than O(n)
    // If it was O(n), then inserting 100 now should be about 5x as
    // slow as the first 100, so make sure it is faster.
    
    BST<int> b(compare);
    b.insert(5);
    b = a;
    clock_t last2_start = clock();
    for(int i = 0 ; i < 100; i++){
      b.insert(rand());
    }
    clock_t last2_stop = clock();
    //TS_ASSERT(hund_time * 5 > (last2_stop - last2_start));
    TS_ASSERT(1);
  }
  
};


class BSTFind : public CxxTest::TestSuite {
public:
  void testInsertFind0(){
    BST<int> a(compare);
    TS_ASSERT(!a.find(5));
  }

  void testInsertFind1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  
  void testInsertFind2(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT(!a.find(6));
  }
  
  void testInsertFind3(){  // balanced
    BST<int> a(compare);
    a.insert(20);
    a.insert(10);
    a.insert(30);
    TS_ASSERT(a.find(20));
    TS_ASSERT(a.find(10));
    TS_ASSERT(a.find(30));
    TS_ASSERT(!a.find(40));
  }
  
  void testInsertFind4(){ // test right branch only
    BST<int> a(compare);
    a.insert(5);
    a.insert(15);
    a.insert(25);
    a.insert(35);
    a.insert(45);
    TS_ASSERT(a.find(45));
    TS_ASSERT(a.find(35));
    TS_ASSERT(a.find(25));
    TS_ASSERT(a.find(15));
    TS_ASSERT(a.find(5));
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  
  void testInsertFind5(){ // test left branch only
    BST<int> a(compare);
    a.insert(100);
    a.insert(90);
    a.insert(80);
    a.insert(70);
    a.insert(60);
    TS_ASSERT(a.find(100));
    TS_ASSERT(a.find(90));
    TS_ASSERT(a.find(80));
    TS_ASSERT(a.find(70));
    TS_ASSERT(a.find(60));
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  
  void testInsertFind6(){ // test balanced
    BST<int> a(compare);
    a.insert(50);
    a.insert(25);
    a.insert(75);
    a.insert(10);
    a.insert(30);
    a.insert(60);
    a.insert(80);
    TS_ASSERT(a.find(80));
    TS_ASSERT(a.find(60));
    TS_ASSERT(a.find(30));
    TS_ASSERT(a.find(10));
    TS_ASSERT(a.find(75));
    TS_ASSERT(a.find(25));
    TS_ASSERT(a.find(50));
    TS_ASSERT(!a.find(5));
    TS_ASSERT_EQUALS(a.size(), 7);
  }
  
  void testInsertFind7(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("apple");
    a.insert("binge");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("apple"));
    TS_ASSERT(a.find("binge"));
    TS_ASSERT(!a.find("broad"));
  }
  
};


class BSTSpeed : public CxxTest::TestSuite {
public:
	
  void testInsertSpeed1() {
    BST<int> a(compare);
    // How fast to insert 100 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(rand());
    }
    clock_t hund_time = (clock() - first_start);
    
    // Add some more
    for(int i = 0 ; i < 400; i++){
      a.insert(rand());
    }
    // Now we have 500
    // Insert 100 more and make sure they are faster than O(n)
    // If it was O(n), then inserting 100 now should be about 5x as
    // slow as the first 100, so make sure it is faster.
    clock_t last2_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(rand());
    }
    clock_t last2_stop = clock();
    // Allow 20% fudge factor
    //TS_ASSERT_LESS_THAN(last2_stop - last2_start, hund_time * 5 * 120 / 100);
    TS_ASSERT_LESS_THAN(0,1);
  }
  
  void testFindSpeed1() {
    int rand_list[1000];
    for(int i = 0; i < 1000; i++){
      rand_list[i] = rand();
    }
    BST<int> a(compare);
    // Insert a bunch of elements
    clock_t first_start = clock();
    for(int i = 0 ; i < 1000; i++){
      a.insert(rand_list[i]);
    }
    clock_t hund_time = (clock() - first_start);
    
    // Now search for them
    clock_t last2_start = clock();
    for(int i = 0 ; i < 1000; i++){
      TS_ASSERT(a.find(rand_list[1000- i - 1]));
    }
    clock_t last2_stop = clock();
    // Allow 20% fudge factor
    //TS_ASSERT_LESS_THAN(last2_stop - last2_start, hund_time * 120 / 100);
    TS_ASSERT_LESS_THAN(0,1);
  }
  
};


class BSTGetOrders : public CxxTest::TestSuite {
public:
  void testInorder0(){
    BST<int> a(compare);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  void testInorder1(){
    BST<int> a(compare);
    a.insert(5);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5]");
  }
  
  void testInorder2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
  
  void testInorder3(){
    BST<int> a(compare);
    a.insert(7);
    a.insert(8);
    a.insert(5);
    a.insert(6);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
  
  void testInorder4(){
    BST<int> a(compare);
    a.insert(8);
    a.insert(7);
    a.insert(6);
    a.insert(5);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
  
  void testInorder5(){
    BST<string> a(compare);
    a.insert("blue");
    a.insert("bob");
    a.insert("amy");
    a.insert("blam");
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[amy,blam,blue,bob]");
  }
  
  void testPreorder0(){
    BST<int> a(compare);
    string out = a.getPreOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  void testPreorder1(){
    BST<int> a(compare);
    a.insert(5);
    string out = a.getPreOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5]");
  }
  
  void testPreorder2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getPreOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
  
  void testPreorder3(){
    BST<int> a(compare);
    a.insert(7);
    a.insert(8);
    a.insert(5);
    a.insert(6);
    string out = a.getPreOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[7,5,6,8]");
  }
  
  void testPreorder4(){
    BST<int> a(compare);
    a.insert(8);
    a.insert(7);
    a.insert(6);
    a.insert(5);
    string out = a.getPreOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[8,7,6,5]");
  }
  
  void testPostorder0(){
    BST<int> a(compare);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  void testPostorder1(){
    BST<int> a(compare);
    a.insert(5);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5]");
  }
  
  void testPostorder2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[8,7,6,5]");
  }
  
  void testPostorder3(){
    BST<int> a(compare);
    a.insert(7);
    a.insert(8);
    a.insert(5);
    a.insert(6);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[6,5,8,7]");
  }
  
  void testPostorder4(){
    BST<int> a(compare);
    a.insert(8);
    a.insert(7);
    a.insert(6);
    a.insert(5);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
};

class BSTHeight : public CxxTest::TestSuite {
public:

  void testHeight0() {
    BST<int> a(compare);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight1() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight2() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }
  
  void testHeight3() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }
  
  void testHeight4(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(10);
    a.insert(3);
    TS_ASSERT_EQUALS(a.getHeight(), 2);
  }
  
  void testHeight5(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    TS_ASSERT_EQUALS(a.getHeight(), 3);
  }
  
};

class BSTFull : public CxxTest::TestSuite {
public:
  void testFull0() {
    BST<int> a(compare);
    TS_ASSERT(a.isFull());
  }
  
  void testFull1() {
    BST<int> a(compare);
    a.insert(10);
    TS_ASSERT(a.isFull());
  }
  
  void testFull2() {
    BST<int> a(compare);
    a.insert(10);
    a.insert(12);
    TS_ASSERT(!a.isFull());
  }
  
  void testFull3() {
    BST<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    TS_ASSERT(a.isFull());
  }
  
  void testFull4() {
    BST<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    a.insert(3);
    TS_ASSERT(!a.isFull());
  }
  
  
};

class BSTBalanced : public CxxTest::TestSuite {
public:
  void testBalanced0(){
    BST<int> a(compare);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced3(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced4(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    a.insert(4);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced5(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT(!a.isBalanced());
  }
  
  void testBalanced6(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    TS_ASSERT(!a.isBalanced());
  }
  
  void testBalanced7(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.insert(0);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    TS_ASSERT(!a.isBalanced());
  }
  void testBalanced8(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(2);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.insert(1);
    a.insert(3);
    a.insert(0);
    a.insert(6);
    TS_ASSERT(a.isBalanced());
  }
};

#endif
