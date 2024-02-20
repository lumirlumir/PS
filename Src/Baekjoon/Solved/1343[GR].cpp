#pragma warning(disable : 4996)
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  /* Input */
  char board[51];
  scanf("%s", board);  // '\0' ����.

  /* Calculate */
  int s = 0, e = 0;       // start, end
  bool isunable = false;  // ���� �� ���� ��� üũ.
  while (true) {
    /* e�� ���� : e�� '.' Ȥ�� '\0' ��ġ�� ������.*/
    while (board[e] != '.' && board[e] != '\0') e++;

    /* X�� Ȧ������ ��� */
    if ((e - s) % 2 == 1) {
      isunable = true;
      break;
    }
    /* X�� ¦����(AAAA..AABB)�� ��� */
    else if ((e - s) % 4 == 2) {
      while (s < e - 2) board[s++] = 'A';
      while (s < e) board[s++] = 'B';
    }
    /* X�� ¦����(AAAA..AAAA)�� ��� */
    else {
      while (s < e) board[s++] = 'A';
    }

    /* �ݺ��� Ż�� ���� */
    if (board[e] == '\0') break;

    /* s, e�� ���� */
    s++;
    e++;
  }

  /* Output */
  if (isunable == true)
    printf("%d", -1);
  else
    printf("%s", board);

  /* End */
  return 0;
}

/*
���̿� Ǯ�� ���� ������.

�������� �˰��� �̿�.

[���ٹ��]
X�� ¦�����̸� A or B�� ��� ���� �� �ִ�.
X�� 4�̻��� ¦���̸�, A�� ���� �ִ��� ���� ä���, �������� B�� ä��� �ȴ�.
(�̷��� �ϸ� ���������� ���� �ռ��� ���� ��µȴ�.)
*/
