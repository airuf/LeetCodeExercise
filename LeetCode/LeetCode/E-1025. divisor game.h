#pragma once
#include "includes.h"

class solution{
public:
	bool divisorGame(int N) {
		return (N % 2) == 0;
	}

	bool divisorGame2(int N) {
		vector<int> f(N + 5, false);
		f[1] = false;
		f[2] = true;
		for (int i = 3; i <= N; ++i) {
			for (int j = 1; j < i; ++j) {// 为最终的N做前置运算
				if(i%j == 0 && !f[i-j])//首先满足条件，然后开始验算
				f[i] = true;
				break;
			}
		}
		return f[N];
	}
}