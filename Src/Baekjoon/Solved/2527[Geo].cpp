#pragma warning(disable : 4996)
#include <cstdio>
using namespace std;

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point ld;  // Left Down
  Point ru;  // Right Up
} Square;

int main(int argc, char* argv[]) {
  for (int i = 0; i < 4; i++) {
    /* Input */
    Square s1, s2;
    scanf("%d %d %d %d %d %d %d %d", &s1.ld.x, &s1.ld.y, &s1.ru.x, &s1.ru.y,
          &s2.ld.x, &s2.ld.y, &s2.ru.x, &s2.ru.y);

    /* Calculate */
    if ((s1.ru.x > s2.ld.x && s1.ru.y > s2.ld.y) &&
        (s1.ld.x < s2.ru.x && s1.ld.y < s2.ru.y))
      printf("a\n");
    else if ((s1.ru.x == s2.ld.x && s1.ru.y > s2.ld.y &&
              s1.ld.y < s2.ru.y) ||  // �����ʸ�
             (s1.ru.y == s2.ld.y && s1.ru.x > s2.ld.x &&
              s1.ld.x < s2.ru.x) ||  // ���ʸ�
             (s1.ld.x == s2.ru.x && s1.ld.y < s2.ru.y &&
              s1.ru.y > s2.ld.y) ||  // ���ʸ�
             (s1.ld.y == s2.ru.y && s1.ld.x < s2.ru.x &&
              s1.ru.x > s2.ld.x))  // �Ʒ��ʸ�
      printf("b\n");
    else if ((s1.ru.x == s2.ld.x && s1.ru.y == s2.ld.y) ||  // UR
             (s1.ru.x == s2.ld.x && s1.ld.y == s2.ru.y) ||  // DR
             (s1.ld.x == s2.ru.x && s1.ld.y == s2.ru.y) ||  // DL
             (s1.ld.x == s2.ru.x && s1.ru.y == s2.ld.y))    // UL
      printf("c\n");
    else
      printf("d\n");
  }

  return 0;
}

/*
���̿� Ǯ�� ������.
����->�ܺη� ���� Ǯ�̴� ���ǹ��� �� ����������
�ܺ�->���η� ���� Ǯ�̴� ���ǹ��� �ܼ��ϴ�.
�� ���� �ϸ�ũ ����.
*/
