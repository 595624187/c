#include <iostream>
using namespace std;
class A
{
public:
	A() { cout << "A构造 "; foo(); }        // 在这里，无论如何都是A::foo()被调用！
	~A() { cout << "A析构 "; foo(); }       // 同上,无论如何都是A::foo()被调用！
	virtual void foo() { cout << "A foo \n"; };
};
class B : public A
{
public:
	virtual void foo() { cout << "B foo \n"; };
	B() { cout << "B构造 "; foo(); }
	~B() { cout << "B析构 "; foo(); }
};
int main()
{
	A * p = new B;
	delete p;
}
