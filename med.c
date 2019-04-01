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
	printf("�迭�� �ڷ��ǰ���:");
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
	printf("���������϶�:%f\n", (double)(end - start) / CLK_TCK);
	printf("������ ����:%f\n", (double)(b - a) / CLK_TCK); 

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
			printf("���Ľ���!\n");
			break;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n���ļ���!\n");
}
void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	// ���� �ִ� ������ �ϰ� ����
	if (i>mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	// ���� �ִ� ������ �ϰ� ����
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}
	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}
// �պ� ����
void merge_sort(int list[], int left, int right) {
	int mid;
	if (left<right) {
		mid = (left + right) / 2;// �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge_sort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
	}
}
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left]; // ������ ����Ʈ�� ���� ���� �����͸� �ǹ����� ����(������ ���� �ǹ����� ����)
						/* low�� high�� ������ ������ �ݺ�(low<high) */
	do {
		/* list[low]�� �ǹ����� ������ ��� low�� ���� */
		do {
			low++; // low�� left+1 ���� ����
		} while (low <= right && list[low]<pivot);
		/* list[high]�� �ǹ����� ũ�� ��� high�� ���� */
		do {
			high--; //high�� right ���� ����
		} while (high >= left && list[high]>pivot);
		// ���� low�� high�� �������� �ʾ����� list[low]�� list[high] ��ȯ
		if (low<high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low<high);
	// low�� high�� ���������� �ݺ����� �������� list[left]�� list[high]�� ��ȯ
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;
	// �ǹ��� ��ġ�� high�� ��ȯ
	return high;
}
// �� ����
void quick_sort(int list[], int left, int right) {
	/* ������ ������ 2�� �̻��� �������̸�(����Ʈ�� ũ�Ⱑ 0�̳� 1�� �ƴϸ�) */
	if (left<right) {
		// partition �Լ��� ȣ���Ͽ� �ǹ��� �������� ����Ʈ�� ��յ� ���� -����(Divide)
		int q = partition(list, left, right); // q: �ǹ��� ��ġ
											  // �ǹ��� ������ 2���� �κ� ����Ʈ�� ������� ��ȯ ȣ��
		quick_sort(list, left, q - 1); // (left ~ �ǹ� �ٷ� ��) ���� �κ� ����Ʈ ���� -����(Conquer)
		quick_sort(list, q + 1, right); // (�ǹ� �ٷ� �� ~ right) ���� �κ� ����Ʈ ���� -����(Conquer)
	}
	else if(right-left<=50){
		
	} /* ����ٰ� �������� */
}