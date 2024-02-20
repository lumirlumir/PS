#pragma warning(disable : 4996)
#include <limits.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int C[10001] = {};
int V[100] = {};

int main(int argc, char* argv[]) {
  /* Input */
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &V[i]);

  /* DP */
  // init
  for (int i = 1; i <= k; i++) C[i] = SHRT_MAX;
  // DP
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= k; j++)
      C[j] = min(((j - V[i]) >= 0 ? (C[j - V[i]] + 1) : SHRT_MAX), C[j]);

  /* Output */
  printf("%d", C[k] == SHRT_MAX ? -1 : C[k]);

  /* End */
  return 0;
}

/*
INT_MAX ��ü�� �״�� ����� ���, C[j - V[i]] + 1���� INT_MAX + 1 ����
�߻��Ͽ� �����÷ο찡 �߻��Ѵ�. ����, ���� �̻��ϰ� ��µǹǷ�
SHRT_MAX�� ���Ѵ��� ���� ������ �־���.
(������ ��ġ�� �ּڰ��� 1�̰�, k���� �ִ��� 10000�̹Ƿ�,
���� �� �ִ� ������ �ִ� ������ 10000 �̴�. ���� SHRT_MAX�� ����ص� ����
����.)
*/
