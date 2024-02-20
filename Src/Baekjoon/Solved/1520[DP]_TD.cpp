/* Header */
#pragma warning(disable : 4996)
#include <stdio.h>

/* Global */
int M[502][502] = {};      // �Է°� ���� �迭
int C_arr[502][502] = {};  // Cache (-1�� �ʱ�ȭ)
//'0���� �ʱ�ȭ' �� 'idx 0, 501 Ȱ���� ���� ũ�⸦ 502�� ����'

/* Function */
void init(void) {
  for (int i = 0; i < 502; i++)
    for (int j = 0; j < 502; j++) C_arr[i][j] = -1;
}

int C_func(int m, int n) {
  /* Base Case */
  if (m == 1 && n == 1) return 1;
  /* Memoization */
  else if (C_arr[m][n] != -1)
    return C_arr[m][n];
  // �ڿ����� C[3][5]�� ���� 0 �� �ǹǷ�, Cache �迭�� 0���� �ʱ�ȭ�ϸ� �ȵȴ�.
  /* Inductive Step */
  else
    return C_arr[m][n] = (M[m][n] < M[m - 1][n] ? C_func(m - 1, n) : 0) +
                         (M[m][n] < M[m + 1][n] ? C_func(m + 1, n) : 0) +
                         (M[m][n] < M[m][n - 1] ? C_func(m, n - 1) : 0) +
                         (M[m][n] < M[m][n + 1] ? C_func(m, n + 1) : 0);
}

/* Main */
int main(int argc, char* argv[]) {
  /* Init */
  init();

  /* Input */
  int M, N;
  scanf("%d %d", &M, &N);
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= N; j++) scanf("%d", &M[i][j]);

  /* Debug */
  // printf("\n");
  // for (int i = 0; i <= M + 1; i++) {
  //	for (int j = 0; j <= N + 1; j++)
  //		printf("%3d", V[i][j]);
  //	printf("\n");
  // }
  // printf("\n");

  /* Output */
  printf("%d", C_func(M, N));

  /* End */
  return 0;
}

/*
�����¿��� ��� �������� ���� �̵��� �� �־�(���ǿ��� �´´ٸ�)
BU ����� �̿��ϱ⿡�� �δ��� ������.
*/
