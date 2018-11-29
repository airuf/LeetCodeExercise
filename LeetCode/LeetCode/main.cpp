#include "includes.h"
#include "M-636. Exclusive Time of Function.h"

int main()
{

	Solution A;
	string sttt[] = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
	vector<string> bbb(sttt, sttt + 4);
	A.exclusiveTime(2, bbb);
	system("pause");
	return 0;
}
