#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000000
// How to make QuickSort quickly?
// ����� �޵�� ����Ʈ, ���� ����Ʈ ���.
int A[MAX];
int sorted[MAX];
int n;

void quick_sort(int list[], int left, int right);


int main() {

	int i, start, end, a, b;
	double sum = 0;
	printf("�迭 �ڷ� ����:");
	scanf_s("%d", &n);
	srand(time(NULL));

	for (i = 0; i < n; i++) {
		A[i] = (rand()*rand()) % MAX;
	}
	start = clock();
	quick_sort(A, 0, n - 1);
	end = clock();

	printf("���� �� �ð� : %f\n", (double)(end - start) / CLK_TCK);

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
	pivot = list[left];	// ���� ���� ����Ʈ�� ������ �ǹ� ����
	// ���� ����Ʈ�� ����ٰ� ���� ������ �ǹ��� ���ع����� ���� ������?
	do {
		// list[low]�� �ǹ����� ������ ��� low�� ����
		do {
			low++;	// low�� �������� left+1
		} while (low <= right && list[low] < pivot);
		// list[high]�� �ǹ����� ũ�� ��� high ����
		do {
			high--;
		} while (high >= left&&list[high] > pivot);
		// ���� low�� high�� �������� �ʾ����� list[low]�� list[high]�� ��ȯ
		if (low < high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low < high);
	// low-high ���� �ÿ� �ݺ��� ���� ���� list[left]�� list[right]��ȯ
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;
	// �ǹ� ��ġ�� high ��ȯ.

	return high;
}
int partition_re(int list[], int left, int right) {
	int high;
	return high;
}
void quick_sort(int list[], int left, int right) {
/* ����Ʈ�� ũ�Ⱑ 0 Ȥ�� 1�� ��� ����*/
	if (left < right) {
			/* ������ ������ 2�� �̻��� �������̸�(����Ʈ�� ũ�Ⱑ 0�̳� 1�� �ƴϸ�) */
			// partition �Լ��� ȣ���Ͽ� �ǹ��� �������� ����Ʈ�� ��յ� ���� -����(Divide)
			int q = partition(list, left, right); // q: �ǹ��� ��ġ
												  // �ǹ��� ������ 2���� �κ� ����Ʈ�� ������� ��ȯ ȣ��
			quick_sort(list, left, q - 1); // (left ~ �ǹ� �ٷ� ��) ���� �κ� ����Ʈ ���� -����(Conquer)
			quick_sort(list, q + 1, right); // (�ǹ� �ٷ� �� ~ right) ���� �κ� ����Ʈ ���� -����(Conquer)
	}
}