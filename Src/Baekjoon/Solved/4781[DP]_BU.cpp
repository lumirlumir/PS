#pragma warning(disable : 4996)
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  while (true) {
    /* Init */
    int table[10001] = {};
    // table�� ���������� �����ϸ�, while�� �����Խ� �ʱ�ȭ�� �ȵȴ�.

    /* Input */
    int n;
    double m;
    scanf("%d %lf", &n, &m);
    int m_int = (int)(m * 100 + 0.5);

    /* Break */
    if (n == 0 && m == 0) break;

    /* DP */
    for (int i = 0; i < n; i++) {
      int c;
      double p;
      scanf("%d %lf", &c, &p);
      int p_int = (int)(p * 100 + 0.5);

      for (int j = p_int; j <= m_int; j++)
        table[j] = max(table[j], table[j - p_int] + c);
    }

    /* Output */
    printf("%d\n", table[m_int]);
  }

  /* End */
  return 0;
}

/*
double �ڷ����� 100�� ���� ������ ��ȯ��,
�ε��Ҽ��� ������ ��Ȯ���� ���� ���� ��ȯ�� �� �����Ƿ�,
0.5������ �����־�� �Ѵ�.
*/

/*
�ϸ�ũ ����
*/
