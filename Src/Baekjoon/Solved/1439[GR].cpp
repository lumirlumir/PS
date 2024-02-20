#pragma warning(disable : 4996)
#include <cstdio>
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

char S[1000000] = {};  //'\0'����.
int count[2] = {};  // count[0] : 0 -> 1 �� Ƚ��. count[1] : 1 -> 0�� Ƚ��.

int main(int argc, char* argv[]) {
  /* Input */
  scanf("%s", S);

  /* Calculate */
  for (int i = 0; S[i] != '\0'; i++)  // O(n)�� �ð����⵵.
    if (S[i] != S[i + 1]) count[(S[i] == '0' ? 0 : 1)]++;

  printf("%d", min(count[0], count[1]));

  /* End */
  return 0;
}

/*
[���ٹ��]
�� 0 -> 1�� Ƚ�� ����.
�� 1 -> 0�� Ƚ�� ����.

0 or 1 -> null(='\0')���� ���� ����� Ƚ���� ���������.

��� ���� �ּڰ� ã��.
*/
