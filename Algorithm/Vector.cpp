#include <vector>
#include <iostream>
using namespace std;

/*
��� �Լ�
v.begin();		������ iterator�� ��ȯ
v.end();		���� iterator�� ��ȯ

v.size();		size��ȯ
v.max_size();	���� �� �ִ� �ִ� ������ ���� ��ȯ
v.capacity();	�޸� ũ�� ��ȯ
v.resize();		size�缳��
v.empty();		����ִ��� Ȯ��
v.reserve();	�޸� �̸��Ҵ�
v.clear();

v.assign();		�� �Ҵ�
v.at();
v.push_back();
v.pop_back();
*/
void VectorLoop(vector<int> v);
void VectorDestructor();
void PrintVector(vector<int> v);
void VectorAssign(vector<int> v);
void DynamicVector();

int main() {

	vector<int> num = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> num2(5, 1);	//{1,1,1,1,1}
	vector<int> num3(num2);	//{1,1,1,1,1}
	vector<int> num4(num.begin() + 3, num.end() - 3);	//{4,5,6,7}

//	VectorLoop(num);
//	VectorDestructor();
//	VectorAssign(num);

	return 0;
}

void DynamicVector() {
	vector<int>* dv = new vector<int>(10000, 1);
	printf("%d ", dv->at(1));
	printf("%d ", (*dv)[1]);

	delete dv;	//dv->~vector();
}

void VectorAssign(vector<int> v) {
	vector<int> v2;
	v2.assign(v.begin(), v.end());	//copy
	PrintVector(v2);

	vector<int> v3;
	v3.assign(5, 100);
	PrintVector(v3);

	vector<int> v4;
	v4.assign({ 1,2,3,4,5 });
	PrintVector(v4);
}

void VectorLoop(vector<int> v) {
	vector<int>::iterator it; //�ݺ���(iterator)
	for (it = v.begin(); it != v.end(); it++) {	//iterator�� ���� ����
		cout << *it;
	}
	cout << endl;
	
	vector<int>::reverse_iterator rit;	//���ݺ���(reverse_iterator)
	for (rit = v.rbegin(); rit != v.rend(); rit++) {
		cout << *rit;
	}
	cout << endl;
	int i;
	vector<int>::iterator it2 = v.begin();
	for (i = 0; i < v.size(); i++) {	//[]�� ���� ����
		cout << it2[i];
	}
	cout << endl;

	for (i = 0; i < v.size(); i++) {	//[]�� ���� ����
		cout << v[i];
	}
	cout << endl;
}

void VectorDestructor() {	//vector �޸�����
	vector<int> vi(5, 1);
	vi.resize(7);
	PrintVector(vi);
	cout << vi.size() << " " << vi.capacity() << endl;	//size:5 capacity:5

	vi.clear();
	cout << vi.size() << " " << vi.capacity() << endl;	//size:0 capacity:5

	vector<int>().swap(vi);	//vi.~vector();
	cout << vi.size() << " " << vi.capacity() << endl; //size:0 capacity:0

	vi.reserve(5);
	cout << vi.size() << " " << vi.capacity() << endl; //size:0 capacity:5

	//resize�� shrink_to_fit
	vi.resize(0);
	vi.shrink_to_fit();	//swap�� ����� ��ü. (c++11)
	cout << vi.size() << " " << vi.capacity() << endl; //size:0 capacity:0
	
}

void PrintVector(vector<int> v) {
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}