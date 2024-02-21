#pragma warning(disable : 4996)
#include <stdio.h>

int main(int argc, char* argv[]) {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n - 1; i++) {  // n에서 n-1로 값 변경.

    /* 공백 찍기 */
    for (int j = 1; j <= n - i; j++) {
      printf(" ");
    }

    /* 별 찍기 */
    for (int j = 1; j <= (2 * i) - 1; j++) {
      printf("*");
    }

    /* 개행 */
    printf("\n");
  }

  for (int i = n; i >= 1; i--) {  // 여기의 n을 n-1로 변경해도 됨.

    /* 공백 찍기 */
    for (int j = 1; j <= n - i; j++) {
      printf(" ");
    }

    /* 별 찍기 */
    for (int j = 1; j <= (2 * i) - 1; j++) {
      printf("*");
    }

    /* 개행 */
    printf("\n");
  }

  return 0;
}
