#pragma warning(disable : 4996)
#include <stdio.h>

long C[10001] = {0, 1};

int fibonacci(int P, int Q) {
  if (Q == 1)  // Q�� 1�϶� ���������� ������ ��.... �̰� ���ϸ� 100%���� ����
    return 0;

  for (int i = 2; i <= P; i++)
    C[i] = (C[i - 2] + C[i - 1]) % Q;

  return C[P];
}
/*
C[i] = ((C[i - 1] % Q) + (C[i - 2] % Q)) % Q;
���� ���� ����ϸ� �ð��ʰ��� ��. ����Ƚ���� �ٿ��� �Ѵ�.

�� �κ� ���� ���� ����. (�˰��� ���ڿ� ���ǿ� ���� ����.)
*/

int main(int argc, char* argv[]) {
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    int P, Q;
    scanf("%d %d", &P, &Q);
    printf("Case #%d: %d\n", i + 1, fibonacci(P, Q));
  }

  return 0;
}
