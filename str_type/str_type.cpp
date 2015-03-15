#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace System;
using namespace std;

class str_type {
private:
	char string[80];
public:
	str_type(char *str="") {strcpy(string, str);}

	str_type operator+(str_type str);
	str_type operator+(char *str);
	str_type operator=(str_type str);
	str_type operator=(char *str);
	str_type operator-(str_type str);
	str_type operator-(char *str);
	char &operator [](int i);

	void show_str() {cout<<string;}
	friend str_type operator+(char *st, str_type str);
};

str_type str_type::operator+(str_type str) {
	str_type temp;

	strcpy(temp.string,string);
	strcat(temp.string, str.string);
	return temp;
}

str_type str_type::operator+(char *str) {
	str_type temp;

	strcpy(temp.string, string);
	strcat(temp.string, str);
	return temp;
}

str_type str_type::operator=(str_type str) {
	strcpy(string, str.string);
	return *this;
}

str_type str_type::operator=(char *str) {
	str_type temp;

	strcpy(string, str);
	strcpy(temp.string, string);
	return temp;
}

str_type operator+(char*st, str_type str) {
	str_type temp;

	strcpy(temp.string, st);
	strcat(temp.string, str.string);
	return temp;
}

str_type str_type::operator-(str_type str) {
	str_type temp;
	int k=0; 
	int j=0;
	for (int i=0;i<strlen(string)-2;i++) {
		if ((string[i]!=str.string[j])||(string[i+1]!=str.string[j+1])) {
			temp.string[k]=string[i];
			k++;
		}
		else
			j++;
		if (j==strlen(str.string)) j=0;
	}
	return temp;
}

char &str_type::operator[](int i) {
	if(i,0||i>79) {
		cout<<"\nError, Index not available";
		exit(1);
	}
	return string[i];
}

int main()
{
	str_type a("Hi "), b("to All!"), c, d, k;
	c=a+b;
	c.show_str();
	cout<<"\n";

	a="fo programing because ";

	b=c="C++ is cool ";
	c=c+a+b;
	c.show_str();
	cout<<"\n";
	
	d="Averyone should know - "+b;
	d.show_str();
	cout<<"\n";
	
	k=d-b;
	k.show_str();
	cout<<"\n";

	system("pause");
    return 0;
}
