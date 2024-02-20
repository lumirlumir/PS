#pragma warning(disable : 4996)
#include <stdio.h>

int cache[11] = {0, 1, 2, 4};

int main(int argc, char* argv[]) {
  /* Input */
  int T;
  scanf("%d", &T);

  /* Calculate */
  for (int i = 0; i < T; i++) {
    /* Input */
    int n;
    scanf("%d", &n);

    /* Calculate */
    for (int i = 4; i <= n; i++)
      cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];

    /* Output */
    printf("%d\n", cache[n]);
  }

  /* End */
  return 0;
}

/* ���� ������ ��������� �ٸ� ����. ���� �ؼ� �������� ���� ���� �ٽ� Ǯ��
 * ����. */
/* Bottom Up ���� ǰ */

/*
1, 2, 3 ���ϱ� ��Ʈ������ �� 9���� ���� ������ ������ �ִ�.
�ѹ��� �ؼ� �ø���.
*/
