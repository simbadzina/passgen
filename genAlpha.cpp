//============================================================================
// Name        : genAlpha.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include "mt.h"
#define MY_CUSTOM_CONSTANT 0
using namespace std;

int main(int argc, char** argv) {
	vector<char> myChars;
	vector<char> myOrderedChars;
	int initSeed = atoi(argv[1] + MY_CUSTOM_CONSTANT);
	int orderingSeed = atoi(argv[2]);
	int passwordSeed= atoi(argv[3]);
	int length= atoi(argv[4]);
	//cin >> orderingSeed >> passwordSeed >> length;

	MersenneTwister mt;
	mt.init_genrand(initSeed);
	mt.init_genrand(orderingSeed+mt.genrand_int32());
	//add numbers o myChars;
	for(char i = '1'; i<='9';i++){
		myChars.push_back(i);
	}

	for(char i = 'a'; i <='z'; i++){
		myChars.push_back(i);
	}

	int pos;
	while(myChars.size() > 0){
		pos = mt.genrand_int32()%myChars.size();

		myOrderedChars.push_back(myChars[pos]);
		myChars.erase(myChars.begin()+pos);
	}

	MersenneTwister mt2;
	mt2.init_genrand(passwordSeed);

	cout << endl;
	for(int i =0; i< length ; i++){
		cout << myOrderedChars[mt2.genrand_int32()%myOrderedChars.size()];
		if(((i+1)%32)==0){
			cout << endl;
		}
		else if(((i+1)%4)==0){
			//cout << " ";
		}
	}
	cout << endl;
cout << endl;
	return 0;

}
