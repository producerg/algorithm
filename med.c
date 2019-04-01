#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000000
int A[MAX];
int sorted[MAX];
int n;
void insertion(int list[], int n);
void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);
int partition(int list[], int left, int right);
void quick_sort(int list[], int left, int right);
void shell_sort();
void sorting_confirm(int start, int n);

int main() {
	int i, start, end, a, b;
	double sum = 0;
	printf("배열의 자료의개수:");
	scanf_s("%d", &n);
	srand(time(NULL));

	for (i = 0; i < n; i++)
		A[i] = rand() % MAX;
	/*for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}*/
	start = clock();
	//merge_sort(A, 0, n - 1);
	quick_sort(A, 0, n - 1);
	//insertion(A, n - 1);
	//shell_sort();
	end = clock();

	a = clock();
	//shell_sort();
	// insertion(A, n - 1);
	b = clock();

	/* printf("\n");
	sorting_confirm(0, n - 1); */
	printf("난수상태일때:%f\n", (double)(end - start) / CLK_TCK);
	printf("정렬후 정렬:%f\n", (double)(b - a) / CLK_TCK); 

	return 0;

}
void insertion(int list[], int n) {
	int temp, i, j;
	for (i = 1; i < n; i++) {
		temp = list[i];
		for (j = i - 1; j >= 0 && list[j] > temp; j--)
			list[j + 1] = list[j];
		list[j + 1] = temp;
	}
}
void shell_sort() {

	int k = n / 2;
	int i, j;
	while (k> 0) {
		for (i = k; i < n; i++) {
			int temp = A[i];
			for (j = i - k; j >= 0 && A[j] > temp; j = j - k) {
				A[j + k] = A[j];
			}
			A[j + k] = temp;
		}
		k = k / 2;
	}
}
void sorting_confirm(int start, int n) {
	int i;
	for (i = 1; i < n; i++) {
		if (A[i - 1] >A[i]) {
			printf("정렬실패!\n");
			break;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n정렬성공!\n");
}
void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	// 남아 있는 값들을 일괄 복사
	if (i>mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}
	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}
// 합병 정렬
void merge_sort(int list[], int left, int right) {
	int mid;
	if (left<right) {
		mid = (left + right) / 2;// 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
		merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
		merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
	}
}
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)
						/* low와 high가 교차할 때까지 반복(low<high) */
	do {
		/* list[low]가 피벗보다 작으면 계속 low를 증가 */
		do {
			low++; // low는 left+1 에서 시작
		} while (low <= right && list[low]<pivot);
		/* list[high]가 피벗보다 크면 계속 high를 감소 */
		do {
			high--; //high는 right 에서 시작
		} while (high >= left && list[high]>pivot);
		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
		if (low<high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low<high);
	// low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;
	// 피벗의 위치인 high를 반환
	return high;
}
// 퀵 정렬
void quick_sort(int list[], int left, int right) {
	/* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
	if (left<right) {
		// partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
		int q = partition(list, left, right); // q: 피벗의 위치
											  // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
		quick_sort(list, left, q - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
		quick_sort(list, q + 1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
	}
	else if(right-left<=50){
		
	} /* 여기다가 삽입정렬 */
}