#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace System;
using namespace std;

bool isvowel(char ch);
int xform(int i) {
	return i*i;
}
void counting();
void reversing();
void transforming();


int main()
{
	counting();
	cout<<endl;
	reversing();
	cout<<endl;
	transforming();

    system("pause");
    return 0;
}

bool isvowel(char ch)
{
	ch=tolower(ch);
	if(ch=='a'||ch=='e'||ch=='y'||ch=='u'||ch=='i'||ch=='o'||ch=='j') return true;
	return false;
}
void counting()
{
	char str[]="STL--it is cool! Forever!";
	vector<char> v, v2(30);
	unsigned int i;

	for (i=0; str[i]; i++) v.push_back(str[i]);
	cout<<"The sequence: ";
	for (i=0; i<v.size(); i++) cout<<v[i];
	cout<<endl;

	int n;
	n=count(v.begin(), v.end(), 'r');
	cout<<n<<" letters of 'r'"<<endl;

	n=count_if(v.begin(), v.end(), isvowel);
	cout<<n<<" letters of vowel"<<endl;

	remove_copy(v.begin(), v.end(), v2.begin(),'e');
	for (i=0; i<v2[i]; i++) cout<<v2[i];
	cout<<endl;

	replace_copy(v.begin(), v.end(), v2.begin(),'i', 'W');
	for (i=0; i<v2[i]; i++) cout<<v2[i];
	cout<<endl;
}

void reversing()
{
	vector<int> v;
	unsigned int i;

	for (i=0; i<10; i++) v.push_back(i);
	cout<<"The sequence: ";
	for (i=0; i<v.size(); i++) cout<<v[i];
	cout<<endl;

	reverse(v.begin(),v.end());
	for (i=0; i<v.size(); i++) cout<<v[i];
	cout<<endl;
}

void transforming()
{
	list<int> x1;
	int i;

	for (i=0; i<10; i++) x1.push_back(i);
	list<int>::iterator p=x1.begin();
	while(p!=x1.end()) {
		cout<<*p<<" ";
		p++;
	}
	cout<<endl;

	p=transform(x1.begin(), x1.end(), x1.begin(), xform);
	p=x1.begin();
	while(p!=x1.end()) {
		cout<<*p<<" ";
		p++;
	}
	cout<<endl;
}
