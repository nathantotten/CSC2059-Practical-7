#include "List.h"
#include "ListNode.h"
#include <Windows.h>
#include <time.h>

using namespace std;

// (1)
void testTiming(int N)
{
	clock_t begin = clock();

	// operation being timed
	
	Sleep(1);

	clock_t end = clock();

	double elapsedTime = double(end - begin);

	cout << "Time taken with N = " << N << " is " << elapsedTime << " ms = " << elapsedTime / 1000.0 << " s " << "\n";

}

// (2)
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

// (3)
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

// (4)
int findFurthest(int* pi, int N)
{
	clock_t begin = clock();

	// op being timed
	int* temp = new int[N];

	// Find for each value pi[i] the closest other value
	for (int i = 0; i < N; i++) {
		int minDistance = MAXINT;
		for (int j = 0; j < N; j++) {
			Sleep(1);
			if (j != i)
				if (abs(pi[i] - pi[j]) < minDistance)
					minDistance = abs(pi[i] - pi[j]);
		}
		temp[i] = minDistance;
	}

	// find the value with the furthest closest other value
	int maxDistance = temp[0];
	int furthest = pi[0];
	for (int i = 0; i < N; i++) {
		if (temp[i] > maxDistance) {
			Sleep(1);
			maxDistance = temp[i];
			furthest = pi[i];
		}
	}
	delete[] temp;
	clock_t end = clock();

	double elapsedTime = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsedTime << "ms = " << elapsedTime / 1000.0 << "s" << "\n";
	return furthest;
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

	// (4) test findFurthest ~ O(N^2) + O(N) so O(N^2) overall (Always take the complexity of the worst part of the funciton)
	cout << findFurthest(pi, N) << endl;

	delete[] pi;

	//testTiming(N);
	return 0;
}