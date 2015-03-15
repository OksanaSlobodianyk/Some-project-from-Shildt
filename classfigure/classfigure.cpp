#include "stdafx.h"
#include<iostream>
#include<cstdlib>

using namespace System;
using namespace std;

const int SIZE=5;
template <class T> class figure {
protected:
	T x,y;
public:
	figure (T i, T j) {
		x=i;
		y=j;
	}
	virtual T area()=0;
};

 template <class T> class triangle : public figure<T> {
public:
	triangle(T i, T j) : figure<T>(i,j) {}
	T area() {
				return x*0.5*y;
	}
};

template <class T> class rectangle : public figure <T> { 
public:
	rectangle(T i, T j) : figure<T>(i,j) {}
	T area() {
		return x*y;
	}
};

template <class T> class circle : public figure<T> {
public:
	circle (T i, T j=0) : figure<T>(i,j) {}
	T area() {
		return x*x*3.14;
	}
};

figure<double> * generator() {
	switch (rand()%3) {
	case 0: return new circle<double>(10.0);
	case 1: return new triangle<double>(10.0, 5.0);
	case 2: return new rectangle<double>(10.0, 6.0);
	}
	return 0;
}


int main()
{
	figure<double> *p;
	int i;
	int t=0; 
	int c=0; 
	int r=0;

	for (i=0; i<SIZE; i++) {
		p=generator();
		cout<<"The object has the type of "<< typeid(*p).name();
		cout<< ". ";
		
		if (typeid(*p)==typeid(triangle<double>)) t++;
		if (typeid(*p)==typeid(rectangle<double>)) r++;
		if (typeid(*p)==typeid(circle<double>)) t++;

		cout<<"The area is equal to "<<p->area()<< endl;
	}
	cout<<endl;
	cout<<t<<" trisngles"<<"\n"<<r<<" rectangles"<<"\n"<<c<<" circles"<<endl;

	system("pause");
    return 0;
}
