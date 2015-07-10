# Makefile for Bran's Linked List test code for recipe project
# Created by: Bran Amour Hagger

test: testMain.o BranLinkedList.o
	g++ -Wall -g -std=c++11 -o testBranLinkedList testMain.o BranLinkedList.o

testMain.o: test/BranLinkedListTest.cpp
	g++ -Wall -g -std=c++11 -c -o testBranLinkedList.o test/BranLinkedListTest.cpp

BranLinkedList.o: BranLinkedList.cpp BranLinkedList.h
	g++ -Wall -g -std=c++11 -c -o BranLinkedList.o BranLinkedList.cpp
