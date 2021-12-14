#include "List.h"
#include "ListNode.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <ctime>

using namespace std;

int count1(List<int>& iL, int key)
{
	clock_t begin = clock();

	// op being timed
	int count = 0;
	for (int p = 0; p < iL.size(); p++)
		if (iL.get(p) == key)
			count++;

	clock_t end = clock();

	double elapsedTime = double(end - begin);
	cout << "Time taken with N = " << iL.size() << " is " << elapsedTime << "ms = " << elapsedTime / 1000.0 << "s" << "\n";

	return count;
}

int count2(List<int>& iL, int key)
{
	clock_t begin = clock();

	// op being timed
	iL.setp_first();
	int count = 0;
	for (int p = 0; p < iL.size(); p++)
		if (iL.get_next() == key)
			count++;


	clock_t end = clock();

	double elapsedTime = double(end - begin);
	cout << "Time taken with N = " << iL.size() << " is " << elapsedTime << "ms = " << elapsedTime / 1000.0 << "s" << "\n";


	return count;
}

int main()
{
	cout << "Data size N = ";
	int N;
	cin >> N;

	// the List
	List<int> intList;
	for (int i = 0; i < N; i++) {
		intList.insert_end(rand() % 100);
	}

	// test count1
	//cout << "Count 1 = " << count1(intList, 0) << "\n";

	// test count2
	cout << "Count 2 = " << count2(intList, 0) << "\n";

	return 0;
}