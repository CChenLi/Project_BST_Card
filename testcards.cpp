// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "cards.h"

using namespace std;

void test_getSHelper(card c, char s, string message){
	if(c.getS()==s){
		cout << "PASSED" << endl;
	} else {
		cout << "	FAILED" << message << endl;
	}
}

void test_getNHelper(card c, char s, string message){
	if(c.getN()==s){
		cout << "PASSED" << endl;
	} else {
		cout << "	FAILED" << message << endl;
	}
}

void test_getS(){
	card c1('h', '3');
	card c2('h', '3');
	card c3('c', 'a');
	card c4('c', '3');
	card c5('h', '9');
	card c6('s', 'a');
	cout <<"--------getS()---------" << endl;
	test_getSHelper(c1, 'h', "case for c1");
	test_getSHelper(c2, 'h', "case for c2");
	test_getSHelper(c3, 'c', "case for c3");
	test_getSHelper(c4, 'c', "case for c4");
	test_getSHelper(c5, 'h', "case for c5");
	test_getSHelper(c6, 's', "case for c6");	
}

void test_getN(){
	card c1('h', '3');
	card c2('h', '3');
	card c3('c', 'a');
	card c4('c', '3');
	card c5('h', '9');
	card c6('s', 'a');
	cout <<"--------getN()---------" << endl;
	test_getNHelper(c1, '3', "case for c1");
	test_getNHelper(c2, '3', "case for c2");
	test_getNHelper(c3, 'a', "case for c3");
	test_getNHelper(c4, '3', "case for c4");
	test_getNHelper(c5, '9', "case for c5");
	test_getNHelper(c6, 'a', "case for c6");
}

void assert_equal(bool b, string message){
	if(b){
		cout << "PASSED" << endl;
	} else {
		cout << "	FAILED " << message << endl;
	}
}

void test_equal(){
	card c1('h', '3');
	card c2('h', '3');
	card c3('c', 'a');
	card c4('c', '3');
	card c5('h', '9');
	card c6('h', '9');
	cout <<"--------equal---------" << endl;

	assert_equal(c1==c2, "c1==c2");
	assert_equal(!(c3==c4), "!(c3==c4)");
	assert_equal(c5==c6, "c5==c6");
}

void test_Cards(){
	test_getS();
	test_getN();
	test_equal();
}

void test_removeCard(){
	cout << "------removeCard------" << endl;
	card c1('h', '3');
	card c2('s', '2');
	card c3('c', 'a');
	card c4('c', '3');
	card c5('h', '9');
	card c6('s', 'a');

	card c7('c', '2');
	card c8('s', 'a');
	card c9('d', 'j');
	card c0('h', '9');
	card c11('c', '3');

	Player p1("Alice");
	Player p2("Bob");

	p1.insert(c1);
	p1.insert(c2);
	p1.insert(c3);
	p1.insert(c4);
	p1.insert(c5);
	p1.insert(c6);

	p2.insert(c7);
	p2.insert(c8);
	p2.insert(c9);
	p2.insert(c0);
	p2.insert(c11);

	p1.removeCard(2);
	p1.removeCard(2);
	p1.removeCard(2);
	p2.removeCard(2);
	p2.removeCard(2);
	p2.removeCard(2);

	assert_equal(!p1.search(&c2), "p1.search(&c2)");
	assert_equal(!p1.search(&c3), "p1.search(&c3)");
	assert_equal(!p1.search(&c4), "p1.search(&c4)");
	assert_equal(!p2.search(&c8), "p1.search(&c8)");
	assert_equal(!p2.search(&c9), "p1.search(&c9)");
	assert_equal(!p2.search(&c0), "p1.search(&c0)");
}



void test_search(){
	card c1('h', '3');
	card c2('s', '2');
	card c3('c', 'a');
	card c4('c', '3');
	card c5('h', '9');
	card c6('s', 'a');

	card c7('c', '2');
	card c8('s', 'a');
	card c9('d', 'j');
	card c0('h', '9');
	card c11('c', '3');

	Player p1("Alice");
	Player p2("Bob");

	p1.insert(c1);
	p1.insert(c2);
	p1.insert(c3);
	p1.insert(c4);
	p1.insert(c5);
	p1.insert(c6);

	p2.insert(c7);
	p2.insert(c8);
	p2.insert(c9);
	p2.insert(c0);
	p2.insert(c11);

	cout <<"--------search()---------" << endl;

	assert_equal(p1.search(&c1), "p1.search(&c1)");
	assert_equal(p1.search(&c3), "p1.search(&c3)");
	assert_equal(!(p1.search(&c9)), "!(p1.search(&c9))");
	assert_equal(p2.search(&c7), "p2.search(&c7)");
	assert_equal(p2.search(&c8), "p2.search(&c8)");
	assert_equal(p2.search(&c9), "p2.search(&c9)");
}

void test_Myturn(){
	cout <<"--------Myturn()---------" << endl;
	card c1('h', '3');
	card c2('s', '2');
	card c3('c', 'a');
	card c4('c', '3');
	card c5('h', '9');
	card c6('s', 'a');

	card c7('c', '2');
	card c8('s', 'a');
	card c9('d', 'j');
	card c0('h', '9');
	card c11('c', '3');

	Player p1("Alice");
	Player p2("Bob");

	p1.insert(c1);
	p1.insert(c2);
	p1.insert(c3);
	p1.insert(c4);
	p1.insert(c5);
	p1.insert(c6);

	p2.insert(c7);
	p2.insert(c8);
	p2.insert(c9);
	p2.insert(c0);
	p2.insert(c11);

	assert(p1.Myturn(p2));
	assert(p2.Myturn(p1));
	assert(p1.Myturn(p2));
	assert(!(p2.Myturn(p1)));
	cout << "\n-----Myturn() PASSED--------\n with expected output:\nAlice picked matching card c 3\nBob picked matching card s a\nAlice picked matching card h 9\n";
}

void test_Player(){
	test_removeCard();
	test_search();
	test_Myturn();
}

int main(int argv, char** argc){
	test_Cards();
	test_Player();

	cout << endl << "-----------ALL TESTS ARE PASSED-----------" << endl;

	



 	return 0;
}
