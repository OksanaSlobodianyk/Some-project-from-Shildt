#include "stdafx.h"
#include "Three.h"
#include <iostream>
#include <new>
#include <cstdlib>
#include <fstream>
#include <string>


using namespace System;
using namespace std;

std::ostream &operator<<(std::ostream &stream, three_d obj);
std::istream &operator>>(std::istream &stream, three_d *obj);

int main()
{
	three_d *p1, *p2;
	three_d *p3;

	try{
		p1=new three_d[3];
		p2=new three_d(5,6,7);
		p3=new three_d();
	}
	catch (bad_alloc ba) {
		cout<< "Error";
		return 1;
	}

	ofstream out("three.txt");
	ifstream in;
	in.open("threed.txt");

	if (!in) {
		cout<<"File Not Opened";
		return 1;
	}
	
	in>>p3;

	p2->chandgex(9);
	p1[1].chandgex(5);
	
	out<<*p2<<endl;
	out<<p1[1]<<endl;
	out<<*p3<<endl;

	char *Num=new char [];
	itoa(*p2+100, Num, 10);
	while (*Num) out.put(*Num++);

	out.close();
	in.close();
	
	delete [] p1;
	delete p2;
		    
	system("pause");
    return 0;
}
