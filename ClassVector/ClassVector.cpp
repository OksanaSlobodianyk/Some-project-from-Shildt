#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <map>

using namespace System;
using namespace std;
void output(vector <char> a);
void outputList(list<char> b);
void outputList(list<int> b);
void ShowVector();
void ShowList();
void ShowMap();

int main()
{
	ShowVector();
	cout<<endl;
	ShowList();
	cout<<endl;
	ShowMap();
    

	system("pause");
    return 0;
}
 void output(vector<char> a)
 {
	 vector<char>::iterator p=a.begin();
	 while(p!=a.end()) {
		cout<< *p<<" ";
		p++;
	}
	cout<<endl;
 }
 void outputList(list<char> b) 
 {
	 list<char>::iterator p=b.begin();
	 while(p!=b.end()) {
		cout<< *p<<" ";
		p++;
	}
	cout<<endl;
 }

 void outputList(list<int> b) 
 {
	 list<int>::iterator p=b.begin();
	 while(p!=b.end()) {
		cout<< *p<<" ";
		p++;
	}
	cout<<endl;
 }

 void ShowVector() {
 vector<char> v,w, v2;
	unsigned int i;

	for(i=0; i<10; i++) v.push_back('A'+i);

	vector<char>::iterator p=v.begin();
	output(v);
	
	p+=2;
	v.insert(p, 5, '-');
	cout <<v.size()<<endl;
	output(v);
	p=v.begin()+2;
	v.erase(p, p+5);
	output(v);

	cout<<v.max_size()<<endl;
	v.pop_back();
	v.push_back('S');
	output(v);
	v.resize(12, 'i');
	output(v);

	vector<char>::iterator r;
	r=v.insert(p=v.begin()+5, '2');
	output(v);
	
	char * ch=new char[];
	ch="Hello!";
	while (*ch!='\0') {
		w.push_back(*ch);
		ch++;
	}
	w.swap(v);
	output(v);
	output(w);

	char str[]=", my dear friend";
	for(i=0;str[i];i++)
		v2.push_back(str[i]);
	p=v.begin()+5;
	vector<char>::iterator p2=v2.begin();
	vector<char>::iterator p3=v2.end();
	v.insert(p,p2,p3);
	output(v);
 }

void ShowList() {
	list<char> l, revl, l2;
	list<int> li;
	int i;
	for (i=0; i<10;i++)
		l.push_back('A'+i);
	cout<<l.size()<<endl;
	outputList(l);
	list<char>::iterator p;
	while(!l.empty()) {
		p=l.begin();
		revl.push_front(*p);
		l.pop_front();
	}
	outputList(revl);
	for(i=0;i<10;i++)
		li.push_back(rand()%100);
	outputList(li);
	li.sort();
	outputList(li);
	li.reverse();
	outputList(li);
	revl.swap(l);
	
	char str[]="Hello, world!";
	for (i=0; str[i]; i++)
		l2.push_back(str[i]);
	outputList(l2);
	l2.sort();
	l.sort();
	l.merge(l2);
	outputList(l);
	l.unique();
	outputList(l);
	p=l.begin();
	for(i=0;i<6;i++) p++;
	l.insert(p,7,'W');
	outputList(l);
	p=l.begin();
	for(i=0;i<8;i++) p++;
	list<char>::iterator r=l.end();
	for(i=0;i<8;i++) r--;

	l.erase(p, r);
	outputList(l);
	l.remove('W');
	outputList(l);
}

void ShowMap()
{
	map<int,char> m;
	int i;

	for(i=0;i<10;i++) {
		m.insert(make_pair(i,(char)('A'+i)));
	}
	int k;
	cout<<"input number:";
	cin>>k;

	map<int,char>::iterator p;
	p=m.find(k);
	if(p!=m.end())
		cout<<p->second<<endl;
	else
		cout<<"Error, the key doesn't exist!"<<endl;
	p++;
	cout<<p->second<<endl;
	m.erase(p);
	cout<<m.size()<<endl;
	cout<<m[2]<<endl;
}