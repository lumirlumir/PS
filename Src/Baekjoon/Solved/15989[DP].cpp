/* 9095�� ������ ��Ʈ���� (��Ʈ���� �� 9�� ����.) */
/* �� ������ ����1 ������ ������ (��� �ξ� ����) */
#pragma warning(disable : 4996)
#include <stdio.h>

int main(int argc, char* argv[]) {
  /* Input */
  int T;
  scanf("%d", &T);

  /* Calculate */
  for (int i = 0; i < T; i++) {
    /* Init */
    int C[10001] = {1};

    /* Input */
    int n;
    scanf("%d", &n);

    /* Calculate */
    for (int j = 1; j <= 3; j++)
      for (int k = 1; k <= n; k++)
        C[k] += (k - j >= 0 ? C[k - j] : 0);

    /* Output */
    printf("%d\n", C[n]);
  }

  /* End */
  return 0;
}
