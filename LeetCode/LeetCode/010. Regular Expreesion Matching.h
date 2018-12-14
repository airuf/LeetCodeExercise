#pragma once
#include "includes.h"

//PASS

//	https://www.cnblogs.com/willaty/p/8134672.html

class Solution
{
public:
	bool cmatch(char s, char p)
	{
		return p == '*' || p == '.' || s == p;
	}


	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		bool* arr = new bool[n + 1]();
		arr[0] = 1;

		for (int i = 2; i <= n; ++i)
			if (p[i - 1] == '*' && arr[i - 2] == true) arr[i] = true;

		int j2 = arr[0];
		int j1 = arr[1];
		int sa = arr[2];

		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j <= n; ++j)
				if (j == 0) {
					j2 = arr[0];
					arr[0] = false;
				}
				else if (j == 1) {
					j1 = arr[1];
					arr[1] = i == 1 && cmatch(s[0], p[0]);
				}
				else {
					sa = arr[j];
					if (p[j - 1] == '*')
						arr[j] = cmatch(s[i - 1], p[j - 2]) && (arr[j] || arr[j - 1] || j1 || j2 || arr[j - 2]) ? true : arr[j - 2];
					else
						arr[j] = cmatch(s[i - 1], p[j - 1]) ? j1 : false;
					j2 = j1;
					j1 = sa;
				}
		}
		return arr[n];
	}
};


//https://www.cnblogs.com/jkn1234/p/8967415.html
//error
class Solution2
{
public:
	bool isMatch(string s, string p)
	{
		//match[i][j]==true ��ʾs��ǰiλ��p��ǰjλ��ƥ��ġ�
		vector<vector<bool>>match(s.length() + 3, vector<bool>(p.length() + 3, false));

		//�߽�����Ϊi=0. j=0 j=1
		// j=0ʱpΪ�մ���ֻ��ƥ��մ�������Ĭ��Ϊfalse
		match[0][0] = true;
		// j=1ʱpֻ��һ���ַ���ֻ��ƥ��һ���ַ�������ȫ��Ϊfalse
		match[1][1] = s[0] == p[0] || p[0] == '.';
		// i=0ʱsΪ�մ���pֻ������a*b*c*d*��������ʽ�ſ��Գɹ�ƥ��
		for (int j = 2; j < p.length() + 1; j += 2)
		{
			match[0][j] = match[0][j - 2] && p[j - 1] == '*';
		}

		// i��ʾs��ǰiλ��j��ʾp��ǰjΪ
		for (int i = 1; i < s.length() + 1; i++)
		{
			for (int j = 2; j < p.length() + 1; j++)
			{
				if (p[j - 1] != '*')
				{
					//??? ǰi-1λ��ǰj-1λ��ƥ��ģ��ҵ�iλ�͵�jλ��ƥ���
					match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
				else
				{
					//???��p[j-1]����0��ʱ��ǰiλ��ǰj-2λ��ƥ���
					//???��p[j-1]����1�λ���ʱ����iλһ��ƥ���j-1λ����ǰi-1λһ����ǰjλ��ƥ��ġ�
					match[i][j] = match[i][j - 2] || match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
				}
			}
		}
		return match[s.length()][p.length()];
	}
};

