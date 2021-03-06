# Declare Constants
CC=g++
CFLAGS=-c -Wall -ggdb -I. --coverage -O0 -v
LDFLAGS=--coverage
SOURCES=bstsandbox.cpp
EXECUTABLE=bstsandbox
TESTS=BST_test.h
TESTSSOURCES=BST_test.h BST.h

OBJECTS=$(SOURCES:.cpp=.o)

FLAGS   = -Iinclude

all: $(SOURCES) $(EXECUTABLE)
	
# These next lines do a bit of magic found from http://stackoverflow.com/questions/2394609/makefile-header-dependencies
# Essentially it asks the compiler to read the .cpp files and generate the needed .h dependencies.
# This way if any .h file changes the correct .cpp files will be recompiled

depend: .depend

# file already removed with make clean
# rm -f ./.depend

.depend: $(SOURCES)
	$(CC) $(CFLAGS) -MM $^ > ./.depend;

include .depend
# End .h file magic

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
	rm -f ./.depend
	rm -rf testrunner.dsYM
	rm -f testrunner*
	rm -f labtestrunner*
	
# CXX Testing	
# Change this file path to match your directory
CXXLOCATION = cxxtest
CXXTESTGEN = $(CXXLOCATION)/bin/cxxtestgen

test: testrunner
	./testrunner
	

testrunner: testrunner.cpp 
	g++ -v --coverage -I. -ggdb -Wall -I$(CXXLOCATION)/ -o testrunner testrunner.cpp
	
testrunner.cpp: $(HEADERS) $(TESTSSOURCES) $(SOURCES)
	 $(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)
