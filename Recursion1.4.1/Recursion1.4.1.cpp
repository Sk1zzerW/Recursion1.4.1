#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int minSumPosition(int arr[], int size, int pos = 0, int minPos = 0, int minSum = INT_MAX) {
    if (pos + 10 > size) return minPos;

    int currentSum = 0;
    for (int i = pos; i < pos + 10; i++) {
        currentSum += arr[i];
    }

    if (currentSum < minSum) {
        minSum = currentSum;
        minPos = pos;
    }

    return minSumPosition(arr, size, pos + 1, minPos, minSum);
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100;
    }

    int pos = minSumPosition(arr, 100);
    cout << "минимальная сумма : " << pos << endl;
    return 0;
}