/*
Name: Candace Hazelwood
CRN: CS-251
Assignment: Lab 2
Sources: cplusplus.com
*/


#include<iostream>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
using namespace std;

int residue(int a, int n, int modulus);
void tobinary( int n, int binary[]);

int main()

{
int a, n, modulus;

//to calculate the residue of an integer of the form a^n and loop 4 times
for(int i = 0; i <4; i++){
	cout << endl << endl << "please enter a, n, and modulus in this format:a n modulus " << endl;
	cin >> a >> n >> modulus;
	cin.ignore(100, '\n');
	cout <<	endl << residue(a, n, modulus) << " is the residue" << endl << endl;
}
}

//function to compute residue 
int residue(int a, int n, int modulus){

	
	int res;
	int k;
	int largestBit;
	vector<int> powers;
	vector<long long> intermediaryRes;
	int place = 128;
	long long holder;
	int binary[8];
	tobinary(n, binary);
	
		for(int i = 0; i <8; i++){
			if (binary[i] == 1)
				powers.push_back(place);
			//else powers.push_back(0);
			place = place / 2;
		}
	
		largestBit = powers[0];	//cycle through for a^(2^i) to find largest mod in powers
		holder = (a % modulus);
		intermediaryRes.push_back(holder);
		for (int i = 0; i < log2(largestBit); i++){
			holder = fmod((pow(holder, 2)),modulus);
			intermediaryRes.push_back(holder);
			}
		reverse(intermediaryRes.begin(), intermediaryRes.end());

		holder = 1; //reusing holder for final math steps
		k = 8- intermediaryRes.size();	
		for(int i = 0; i < intermediaryRes.size(); i ++){
			if (binary[k] == 1)
				holder = holder * intermediaryRes[i];
			k++;
		}
	res = fmod(holder,modulus);
	//}
	return res;
} 

void tobinary(int n, int binary[]){
	int i = 7;
	while (n > 0){
		binary[i] =n%2;
		i--;
		n = n/2;
	}
	
	while (i >= 0){
		binary[i] = 0;
		i--;
	}
}
