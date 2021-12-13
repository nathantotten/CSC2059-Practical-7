#include "List.h"
#include "ListNode.h"
#include <Windows.h>
#include <time.h>

using namespace std;

void testTiming(int N)
{
	clock_t begin = clock();

	// operation being timed
	
	Sleep(1);

	clock_t end = clock();

	double elapsedTime = double(end - begin);

	cout << "Time taken with N = " << N << " is " << elapsedTime << " ms = " << elapsedTime / 1000.0 << " s " << "\n";

}

double findAvg(int* pointerI, int N)
{
	clock_t begin = clock();

	// op being timed
	int total = 0;
	for (int n = 0; n < N; n++ ) {
		total += pointerI[n];
		Sleep(1);
	}
	double avg = (double)total / (double)N;
	clock_t end = clock();

	double elapsedTime = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsedTime << " ms = " << elapsedTime / 1000.0 << " s " << "\n";
	return avg;
}

double find_countAverage(int* pi, int N)
{
	clock_t begin = clock();

	// op being timed
	double average = findAvg(pi, N);
	int count = 0;
	for (int n = 0; n < N; n++) {
		if (pi[n] > (int)average)
			count++;
		Sleep(1);
	}

	clock_t end = clock();

	double elapsedTime = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsedTime << " ms = " << elapsedTime / 1000.0 << " s " << "\n";

	return count;
}

int main()
{
	cout << "Data size N = ";
	int N;
	cin >> N;

	// allocate and populate an array
	int* pi = new int[N];
	if (!pi) return 1;

	for (int i = 0; i < N; i++)
		pi[i] = rand() % 100000;

	// (2) test find average - O(N)
	//cout << "Average = " << findAvg(pi, N) << "\n";

	// (3) test find average and count above average ~ O(2N) so O(N)
	//cout << "How many above average = " << find_countAverage(pi, N) << "\n";

	//testTiming(N);
	return 0;
}