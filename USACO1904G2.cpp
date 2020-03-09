#include <bits/stdc++.h>

using namespace std;

int m,k;

int main(){
	ifstream fin("walk.in");
	ofstream fout("walk.out");
	fin>>m>>k;
	/*
	(Ax+By) mod C
	A=C-84
	B=C-48
	=(C-84)x+(C-48)y  mod c
	=(-84x-48y) mod C
	
	C-84x-48y
	
	*/
	//2019201997
	//2019201913
	//2019201949
	//84x 48y
	//2019201997+84
	fout<<2019202081-k*84-m*48;


}
