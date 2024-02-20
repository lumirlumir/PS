/* Header */
#pragma warning(disable : 4996)
#include <limits.h>
#include <stdio.h>

#define MIN2(a, b) (((a) < (b)) ? (a) : (b))
#define MIN3(a, b, c) (((MIN2((a), (b))) < (c)) ? (MIN2((a), (b))) : (c))

/* Global Variable */
int C[1000000] = {};  // cache

/* Function */
int F(int n) {
  if (n == 1)
    return 0;
  else if (C[n] != 0)
    return C[n];
  else
    return C[n] = MIN3((n % 3 == 0 ? F(n / 3) + 1 : INT_MAX),
                       (n % 2 == 0 ? F(n / 2) + 1 : INT_MAX), F(n - 1) + 1);
}

/* Main */
int main(int argc, char* argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d", F(n));

  return 0;
}

/*
1. F(n-1)�� ���� ������ �����ϹǷ�, INT_MAX�� ���� min���� �Ǵ� ���� ����.
����, INT_MAX�� �����÷ο� ������ �������� �ʾƵ� �ȴ�.

2.TD ����� Stack Overflow ������ Ǯ�̰� �Ұ��ϴ�.
*/
