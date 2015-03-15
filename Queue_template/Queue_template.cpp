#include "stdafx.h"
#include<iostream>
#include <cstdlib>

using namespace System;
using namespace std;

template <class QT, int t> class queue{
	QT q[t];
	int sloc, rloc;
public:
	queue() { sloc=rloc=0; }
	~queue() { ;}
	void qput (QT i);
	QT qget();
};

template <class QT, int t>
void queue<QT, t>::qput(QT i)
{
	if(sloc==t) {
		cout<< "The queue is filled up\n";
		return;
	}
	sloc++;
	q[sloc]=i;
}

template <class QT, int t>
QT queue<QT,t>::qget()
{
	if (rloc==sloc) {
		cout << "The queue is empty\n";
		return 0;
	}
	rloc++;
	return q[rloc];
}

int main()
{
	queue<int, 10> a, b;
	a.qput(12);
	cout<<a.qget()<<"\n";

	system ("pause");
    return 0;
}
