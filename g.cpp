// 2021.01.09 2020 IUPC - G
// by HYOSITIVE

#include <iostream>
#include <array>
using namespace std;

int JH(int money, array<int, 14> dailyprices) {
	int cash = money;
	array<int, 14> stockprices = dailyprices;
	int stock = 0;

	// 전량 매수
	for (int i = 0; i < 14; i++) {
		while (cash > stockprices[i]) {
			cash = cash - stockprices[i];
			stock++;
		}
	}

	// 최종 자산
	int total = cash + stock * stockprices[13];
	return total;
};

int SM(int money, array<int, 14> dailyprices) {
	int cash = money;
	array<int, 14> stockprices = dailyprices;
	int stock = 0;
	
	for (int i = 0; i < 14; i++) {
		// 3일차 이후만 거래 가능?
		if (i > 1) {
			// 3일 연속 주가 상승 : 전매도
			if (stockprices[i] > stockprices[i - 1] && stockprices[i - 1] > stockprices[i - 2]) {
				cash = +stock * stockprices[i];
				stock = 0;
			}
			// 3일 연속 주가 하락 : 전매수
			else if (stockprices[i] < stockprices[i - 1] && stockprices[i - 1] < stockprices[i - 2]) {
				while (cash > stockprices[i]) {
					cash = cash - stockprices[i];
					stock++;
				}
			}
			
			// 아무 것도 아닌 경우
			else {
				while (cash > stockprices[i]) {
					cash = cash - stockprices[i];
					stock++;
				}
			}
		}
		/*
		// 1, 2일차
		else {
			while (cash > stockprices[i]) {
				cash = cash - stockprices[i];
				stock++;
			}
		}
		*/
	}

	// 최종 자산
	int total = cash + stock * stockprices[13];
	return total;
};

int main() {
	int initial;
	cin >> initial;
	array<int, 14> daily;
	for (int i = 0; i < 14; i++) {
		cin >> daily[i];
	}
	int JHtotal = JH(initial, daily);
	int SMtotal = SM(initial, daily);

	// 결과 출력
	if (JHtotal > SMtotal) cout << "BNP" << endl;
	else if (JHtotal < SMtotal) cout << "TIMING" << endl;
	else cout << "SAMESAME" << endl;
}