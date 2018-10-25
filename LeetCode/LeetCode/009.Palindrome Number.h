#pragma once
//�ǻ��������� 1��С��0  2������0�������һλ��0��
//���������� С�ڶԱ���ʱ������ȡ�����ӵ��Ա�����
//������ ����ż�Գƻ�����Գơ����ؽ��
class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0 || (x % 10 == 0 && x != 0))
		{
			return false;
		}
			
		int reverteNumber = 0;
		while (x > reverteNumber)
		{
			reverteNumber = reverteNumber * 10 + x % 10;
			x /= 10;
		}
		return x == reverteNumber || x == reverteNumber / 10;
	}
};