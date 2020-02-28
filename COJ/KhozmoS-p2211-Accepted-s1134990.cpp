//============================================================================
// Name        : aasdasd.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;



int main() {
	int cas,n,i;
	char cad[23223];
	scanf("%d",&cas);
	while(cas--){
		scanf("%s",cad);
		n = strlen(cad);
		
			if (cad[0] == 'A' || cad[n-1] == 'A')
				puts("Alf");
			else
				puts("Gustav");
		

	}



	return 0;
}



