#pragma warning(disable : 4996)
#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;

class Multitap {
 private:
  int* socket;
  int len;
  int pocnt;  // plug out count

 public:
  /* Constructer & Destructor */
  Multitap(int len) {
    socket = new int[len]{};  // 0=false�� �ʱ�ȭ.
    this->len = len;
    pocnt = 0;
  }
  ~Multitap() { delete[] socket; }
  /* Func */
  void plugin(
      int plug) {  // ��Ƽ���� �� ������ idx�� ���� �������� �÷��׸� �ȴ´�.
    for (int idx = 0; idx < len; idx++)
      if (socket[idx] == 0) {
        socket[idx] = plug;
        break;
      }
  }
  void plugout(int plug) {
    for (int idx = 0; idx < len; idx++)
      if (socket[idx] == plug) {
        socket[idx] = 0;
        break;
      }
    pocnt++;
  }
  bool isplug(int plug) const {  // ��Ƽ�ǿ� plug�� plug�� �����ֳ� ���� Ȯ��
    for (int idx = 0; idx < len; idx++)
      if (socket[idx] == plug) return true;
    return false;
  }
  bool isfull(
      void) const {  // ��Ƽ���� �ϳ��� ��������� false, �� �������� true
    for (int i = 0; i < len; i++)
      if (socket[i] == false) return false;
    return true;
  }
  int getpocnt(void) const { return pocnt; }
  int opt(int job_q[], int len, int idx) const {
    /* Init */
    int maxidx = 0;

    /* OPT */
    for (int i = 0, max = 0; i < this->len; i++) {  // i��° socket
      int tmp = INT_MAX;

      for (int j = idx + 1; j < len; j++)
        if (socket[i] == job_q[j]) {
          tmp = j - idx;
          break;
        }

      if (max < tmp) {
        max = tmp;
        maxidx = socket[i];
      }
    }

    /* End */
    return maxidx;
  }
  /* Debug */
  void getstatus(void) const {
    printf("\nMul ");
    for (int i = 0; i < this->len; i++) printf("%d ", i);
    printf("\nPlu ");
    for (int i = 0; i < this->len; i++) printf("%d ", socket[i]);
    printf("\n\n");
  }
};

int main(int argc, char* argv[]) {
  /* Input */
  int N, K;
  scanf("%d %d", &N, &K);

  Multitap multitap(N);
  int* job_q = new int[K]{};  // 0���� �ʱ�ȭ.

  for (int i = 0; i < K; i++) scanf("%d", &job_q[i]);

  ///* Debug */
  // for (int i = 0; i < K; i++)
  //	printf("%2d ", i);
  // printf("\n");
  // for (int i = 0; i < K; i++)
  //	printf("%2d ", job_q[i]);
  // printf("\n\n");

  /* Scheduling */
  for (int i = 0; i < K; i++) {
    /* ��Ƽ�ǿ� job_q[i]�� �ش��ϴ� �÷��װ� �������� ���� ��� */
    if (!multitap.isplug(job_q[i])) {
      /* plugout */
      if (multitap.isfull())  // ��Ƽ���� �� ���ִ� ��쿡�� plugout
        multitap.plugout(multitap.opt(job_q, K, i));

      /* plugin */
      multitap.plugin(job_q[i]);
    }

    ///* debug */
    // printf("queue : %d, pocnt : %d", job_q[i], multitap.getpocnt());
    // multitap.getstatus();
  }

  /* OUtput */
  printf("%d", multitap.getpocnt());

  /* End */
  delete[] job_q;
  return 0;
}

/*
OS�� locality�� ���� ����.
OS�� ������ ��ü �˰���.
(�� �� ���� �̻����� �˰����� OPT �˰����� �����ϴ� ���̴�.)
pocnt���� �ᱹ page fault�� �߻� Ƚ���̴�.

�ݷ�
[INPUT]
2 18
1 2 3 4 3 4 3 4 3 4 1 2 1 2 1 2 1 2

[OUTPUT]
4
*/
