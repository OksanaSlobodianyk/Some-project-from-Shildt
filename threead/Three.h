#ifndef THREE_H_
#define THREE_H_

#include <iostream>
#include <new>
#include <cstdlib>

class three_d {
	int x,y,z;
public:
	three_d(){x=y=z=0;}
	three_d(int i, int j, int k) {x=i; y=j; z=k;}
	~three_d() { ;}

	void chandgex(int k){x=k;}

	void *operator new(size_t size);
	void *operator new[](size_t size);
	void operator delete(void *p);
	void operator delete[](void *p);
	operator int(){return x*y*z;}

	void show();
	friend std::ostream &operator<<(std::ostream &stream, three_d obj);
	friend std::istream &operator>>(std::istream &stream, three_d *obj);
	
};

#endif