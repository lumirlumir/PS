/*Counting Sort ����*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(int A[], int k, int n) {  // k�� �Է� �迭�� �ִ�.
  /*1�ܰ�*/
  int* count = (int*)calloc(k + 1, sizeof(int));

  for (int i = 0; i < n; i++) count[A[i]]++;

  // for (int i = 0; i < k + 1; i++)//Test
  // printf("%d ", count[i]);
  // printf("\n");

  for (int i = 1; i < k + 1; i++) count[i] += count[i - 1];

  // for (int i = 0; i < k + 1; i++)//Test
  // printf("%d ", count[i]);
  // printf("\n");

  /*2�ܰ�*/
  int* Atmp = (int*)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) Atmp[(count[A[i]]--) - 1] = A[i];

  // for (int i = 0; i < n; i++)//Test
  // printf("%d ", Atmp[i]);

  memcpy(A, Atmp, sizeof(int) * n);

  free(Atmp);
  free(count);
}  // �� ���������� �̰� �Ⱦ�.

int main(void) {
  int k = 10000;
  int n;
  scanf("%d", &n);

  int tmp = 0;
  int* count = (int*)calloc(k + 1, sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    count[tmp]++;
  }

  // for (int i = 0; i < k + 1; i++)//Test
  //	printf("%d ", count[i]);
  // printf("\n");

  for (int i = 0; i < k + 1; i++) {
    for (int j = 0; j < count[i]; j++) printf("%d\n", i);
  }

  free(count);
  return 0;
}
