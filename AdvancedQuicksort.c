#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000000
// How to make QuickSort quickly?
// 방법은 메디안 퀵소트, 삽입 퀵소트 사용.
int A[MAX];
int sorted[MAX];
int n;

void quick_sort(int list[], int left, int right);


int main() {

	int i, start, end, a, b;
	double sum = 0;
	printf("배열 자료 개수:");
	scanf_s("%d", &n);
	srand(time(NULL));

	for (i = 0; i < n; i++) {
		A[i] = (rand()*rand()) % MAX;
	}
	start = clock();
	quick_sort(A, 0, n - 1);
	end = clock();

	printf("정렬 후 시간 : %f\n", (double)(end - start) / CLK_TCK);

	return 0;

}
int pivotset(int list[]) {
	int pivot = 0;
	if (list[0] < list[1]) {
		
	}
	else
	return pivot;
}
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];	// 가장 왼쪽 리스트를 임의의 피벗 설정
	// 향상된 퀵소트는 여기다가 새로 설정한 피벗을 정해버리면 되지 않을까?
	do {
		// list[low]가 피벗보다 작으면 계속 low를 증가
		do {
			low++;	// low의 시작점은 left+1
		} while (low <= right && list[low] < pivot);
		// list[high]가 피벗보다 크면 계속 high 감소
		do {
			high--;
		} while (high >= left&&list[high] > pivot);
		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high]와 교환
		if (low < high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low < high);
	// low-high 교차 시에 반복문 빠져 나와 list[left]와 list[right]교환
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;
	// 피벗 위치인 high 반환.

	return high;
}
int partition_re(int list[], int left, int right) {
	int high;
	return high;
}
void quick_sort(int list[], int left, int right) {
/* 리스트의 크기가 0 혹은 1인 경우 제함*/
	if (left < right) {
			/* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
			// partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
			int q = partition(list, left, right); // q: 피벗의 위치
												  // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
			quick_sort(list, left, q - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
			quick_sort(list, q + 1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
	}
}