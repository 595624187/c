#include <iostream>
using namespace std;
class A
{
public:
	A() { cout << "A���� "; foo(); }        // �����������ζ���A::foo()�����ã�
	~A() { cout << "A���� "; foo(); }       // ͬ��,������ζ���A::foo()�����ã�
	virtual void foo() { cout << "A foo \n"; };
};
class B : public A
{
public:
	virtual void foo() { cout << "B foo \n"; };
	B() { cout << "B���� "; foo(); }
	~B() { cout << "B���� "; foo(); }
};
int main()
{
	A * p = new B;
	delete p;
}
