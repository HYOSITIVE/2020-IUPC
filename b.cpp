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
			// 원소를 추가 할 공간을 확보하기 위해 한 칸씩 원소 이동 : O(n)
			for (int i = 0; i < size; i++) {
				myArray[size - i] = myArray[size - i - 1];
				}
			// 원소 삽입
			myArray[0] = elem;

			// 정렬 : O(n^2)
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

	int N; // 배열 A의 원소의 개수
	int M; // 질문의 개수
	cin >> N;
	Array myArr(N);
	cin >> M;

	// 정렬된 배열 B 생성
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		myArr.addInt(a);
	}

	// 질문
	for (int j = 0; j < M; j++) {
		int d;
		cin >> d;
		cout << myArr.findInt(d) << endl;
	}
}