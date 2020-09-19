#include <iostream>
#include <exception>
#include <new>
#include "MyStack.h"
#include "MyStack2.h"
#include "MyString.h"

int main() {
	    int a=1;
	    int b=-1;
	    Swap(a,b);
	    std::cout << b <<'\n';

	    double da=0.5;
	    double dy=-5.5;
	    Swap(da, dy);
	    std::cout << da << '\n';

	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	std::cout << str1;



	MyStack<int, 5> S;
	S.push(4);
	S.push(10);
	std::cout << '\n' << S.pop()<<' '<< S.pop();//<<S.pop();
	//std::cout<<S[2];

	MyStack2 <int> B;
	B.push(1);
	B.push(2);
	B.push(3);
	B.push(4);
	B.push(5);
	std::cout << '\n' << B.pop() << ' ' << B.pop() << '\n';
	B.print();

	{
		MyStack2 <MyString>	ms;
		ms.push(MyString("One"));
		ms.push(MyString("Two"));
		ms.push(MyString("Three"));
		ms.print();
		std::cout <<"\nlook there!!";

		MyStack2 <MyString> ms2;
		ms2.push(MyString("Trash1")); 
		ms2.push(MyString("Trash2"));
		
		ms2 = ms;

		ms2.print();
		ms.print();
	}
	std::cout << "Test";

	return 0;
}
