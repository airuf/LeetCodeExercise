#include "includes.h"
//#include "E-557.Reverse Words in a String III.h"
//#include "E-1021. Remove Outermost Parentheses.h"
//untreate
//that mean havnt finished ;please use find in proj to accomplish these problem;

//void InitLinkedList(ListNode *lst, const vector<int> *a)
//{
//	ListNode *cp1 = lst;
//	vector<int> _data = *a;
//	ListNode *p;
//	cp1->val = _data[0];
//	for (int _dataLen = _data.size(), i = 1; i < _dataLen; i++)
//	{
//		p = (ListNode*)malloc(sizeof(ListNode));
//		cp1->next = p;
//		cp1 = cp1->next;
//		p->val = _data[i];
//		p->next = NULL;
//	}
//}
#include "E-1047. Remove all adjacent duplicates in string.h"


int main()
{

	Solution S;
	string bbb = S.removeDuplicates("abbcs");
	std::cout<< bbb;


	//for (int i = 0; i <res.size(); i++)
	//{
	//	cout << res[i] << endl;
	//}

	//S.swapPairs(&l1);

	system("pause");
	return 0;
}

//
//#include<vector>
//#include<iostream>
//
//using namespace std;
//
//vector<long> ChangePeople(long roomNums, long roomEnds, vector<long> roomPeopleNums)
//{
//	int min, index, a, b;
//	b = roomEnds - 1;
//	min = roomPeopleNums[roomEnds];
//	for (int i = roomEnds; i < roomNums; i++) {
//		if (min >= roomPeopleNums[i]) {
//			min = roomPeopleNums[i];
//			index = i;
//		}
//	}
//	for (int i = 1; i < roomEnds; i++) {
//		if (min >= roomPeopleNums[i]) {
//			min = roomPeopleNums[i];
//			index = i;
//		}
//	}
//
//	for (int i = 0; i < roomNums; i++) {
//		if (i != index)
//			roomPeopleNums[i] = roomPeopleNums[i] - roomPeopleNums[index];
//	}
//	roomPeopleNums[index] = roomPeopleNums[index] + roomPeopleNums[index] * (roomNums - 1);
//
//	if (index > b) {
//		a = roomNums - 1 - index + roomEnds;
//		roomPeopleNums[index] = roomPeopleNums[index] + a;
//		for (int i = index + 1; i < roomNums; i++)
//			roomPeopleNums[i] = roomPeopleNums[i] - 1;
//		for (int i = 0; i < roomEnds; i++)
//			roomPeopleNums[i] = roomPeopleNums[i] - 1;
//	}
//	else {
//		roomPeopleNums[index] = roomPeopleNums[index] + roomEnds - 1 - index;
//		if (index == b)
//			roomPeopleNums[index] = roomPeopleNums[index];
//		for (int i = index + 1; i < roomEnds; i++) {
//			roomPeopleNums[i] = roomPeopleNums[i] - 1;
//		}
//	}
//	return roomPeopleNums;
//
//}
//
//int main()
//{
//	long roomNums;
//	long roomEnds;
//	int temps;
//	vector<long> roomPeopleNums;
//	vector<long> result;
//	cin >> roomNums >> roomEnds;
//	for (int i = 0; i < roomNums; i++) {
//		cin >> temps;
//		roomPeopleNums.push_back(temps);
//	}
//	result = ChangePeople(roomNums, roomEnds, roomPeopleNums);
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << ' ';
//	}
//	return 0;
//}

