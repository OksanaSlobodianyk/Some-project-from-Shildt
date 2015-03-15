#include "stdafx.h"
#include "Three.h"
#include <iostream>
#include <new>
#include <cstdlib>
#include <fstream>
#include <string>


using namespace std;

void *three_d::operator new(size_t size) 
{
	void *p;
	p=malloc(size);
	if (!p) {
		bad_alloc ba;
		throw ba;
	}
	return p;
}
void *three_d::operator new[](size_t size) 
{
	void *p;
	p=malloc(size);
	if (!p) {
		bad_alloc ba;
		throw ba;
	}
	return p;
}

void three_d::operator delete(void *p)
{
	free(p);
}

void three_d::show()
{
	cout<<x<<", "<<y<<", "<<z<<"\n";
}


void three_d::operator delete[](void *p)
{
	free(p);
}

std::ostream &operator<<(std::ostream &stream, three_d obj)
{
	stream<<obj.x<<", ";
	stream<<obj.y<<", ";
	stream<<obj.z<<"\n";
	return stream;
}
std::istream &operator>>(std::istream &stream, three_d *obj)
{
	char *p=new char[80];
	stream.getline(p, 80, ',');
	obj->x=atoi(p);
	stream.getline(p, 80, ',');
	obj->y=atoi(p);
	stream.getline(p, 80, '\n');
	obj->z=atoi(p);
	delete p;
	return stream;
}