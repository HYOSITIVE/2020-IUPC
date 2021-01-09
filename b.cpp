// 2021.01.09 2020 IUPC - B
// by HYOSITIVE

#include <iostream>
#include <string>
#include <array>
using namespace std;

class Array {
private:
	int size;
	int* myArray;

public :
	Array(int size) {
		this->size = 0;
		myArray = new int[size];
	};

	int getSize() {
		return size;
	}

/*	void addInt(int elem) {
		if (getSize() == 0) {
			myArray[0] = elem;
		}
	
		else {
			// ���Ҹ� �߰� �� ������ Ȯ���ϱ� ���� �� ĭ�� ���� �̵� : O(n)
			for (int i = 0; i < size; i++) {
				myArray[size - i] = myArray[size - i - 1];
				}
			// ���� ����
			myArray[0] = elem;

			// ���� : O(n^2)
			for (int j = 0; j < size; j++) {
				int temp;
				if (myArray[j] > myArray[j + 1]) {
					temp = myArray[j + 1];
					myArray[j + 1] = myArray[j];
					myArray[j] = temp;
				}
				else break;
			}
		}
		size++;
	}
*/

	void addInt(int elem) {
		myArray[size] = elem;
		size++;
	}

	void swap(int A, int B) {
		int temp = B;
		B = A;
		A = temp;
	}

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (myArray[i + j + 1] > myArray[j]) {
					swap(myArray[j], myArray[j + 1]);
				}
			}
		}
	}

	int findInt(int elem) {
		int index = -1;
		for (int i = 0; i < size; i++) {
			if (myArray[i] == elem) {
				index = i;
				break;
			}
		}
		return index;
	}

};
int main() {

	int N; // �迭 A�� ������ ����
	int M; // ������ ����
	cin >> N;
	Array myArr(N);
	cin >> M;

	// ���ĵ� �迭 B ����
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		myArr.addInt(a);
	}

	// ����
	for (int j = 0; j < M; j++) {
		int d;
		cin >> d;
		cout << myArr.findInt(d) << endl;
	}
}