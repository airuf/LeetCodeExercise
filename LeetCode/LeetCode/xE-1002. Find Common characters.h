#pragma once
#include "includes.h"
#include <vector>
#include <unordered_map>

class Solution {
	vector<string> commonChars(vector<string>& A) {
		vector<string> out;
		int num[100][26] = { 0 };                  //����һ����ά���飬������г��ֵ���ĸ����
		for (int i = 0; i<A.size(); i++)
			for (int j = 0; j<A[i].size(); j++)
				num[i][(A[i][j] - 'a')]++;

		for (int j = 0; j<26; j++)                  //�������е���Сֵ�浽��һ��
			for (int i = 1; i<A.size(); i++)
				num[0][j] = min(num[0][j], num[i][j]);

		string str;                           //���յ�һ�б���Ĵ��������Ӧ��ĸ
		for (int i = 0; i<26; i++) {
			while (num[0][i]--)
			{
				str.clear();
				str.push_back((char)('a' + i));
				out.push_back(str);
			}
		}
		return out;
	}
};



