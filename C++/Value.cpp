//https://dydtjr1128.github.io/cpp/2019/06/10/Cpp-values.html

#include <iostream>
using namespace std;

/*
			   expression
		glvalue			 rvalue
	lvalue		 xvalue		  prvalue

lvalue : identity�� �����鼭 move�� �� ���� ǥ���ĵ�
xvalue : identity�� �����鼭 move�� �� �ִ� ǥ���ĵ�(std::move())
prvalue : identity�� ���������� �����鼭 move�� �� �ִ� ǥ���ĵ�
glvalue : identity�� �������ִ� ǥ���ĵ�(lvalue + xvlaue)
rvalue : move�� �� �ִ� ǥ���ĵ�(prvalue + xvalue)
x : identity�� ������ ���� �����鼭 move�� �� ���°͵�
*/

int& ref(int&);
int ref2(int&);

int main() {

	int a = 10; //���� ���ͷ� -> Prvalue
	char b = 'a'; //���� ���ͷ� -> Prvalue

	enum Color { Red, Green, Blue };
	Color color;
	color = Red;	//��� ������ -> Rrvalue

	int c = a + 1;	//���� �������� ��� -> Pralue

	int *p;
	p = &a;	//���� ������ &�� �ǿ����� -> Lvalue, Return �� -> Rvalue

	int d = *p;	//���� ������ *�� Return �� -> Lvalue
	*p = 11;
	cout << a << endl;
	*(p + 0) = 12;	//�ǿ����ڷ� Rvalue�� ����
	cout << a << endl;

	++a;	//���� �������� ��� -> Lvalue;
	a++;	//���� �������� ��� -> Rvalue;

	int s = 5;
	int k = 10;
	ref(s) *= 5;	//�Լ��� ReturnŸ���� ���۷����� ��� -> Lvalue
	cout << ref2(s) << endl;	//�ܴ̿� -> Rvalue
	cout << s << endl;

	const char *str = "Hello World";
	const char *str2 = "Hello World";
	cout << &str << endl;
	cout << &str2 << endl;
	return 0;
}

int& ref(int& a) {
	a = a + 5;
	return a;
}

int ref2(int& a) {
	a = a + 5;
	return a;
}
