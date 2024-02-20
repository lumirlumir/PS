#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  /* Faster */
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  /* Init */
  deque<int> dq;
  int count = 0;

  /* Input */
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)  // deque���� 1���� N������ �ڿ����� ������� ��.
    dq.push_back(i);

  /* Calculation */
  while (m--) {
    /* Init */
    int lr = 0;  // 2������(���� �̵�, Left Rotation)�� Ƚ��
    int a;
    cin >> a;

    /* Calculation */
    while (true) {
      if (dq.front() == a) {
        dq.pop_front();
        break;
      } else {
        dq.push_back(dq.front());
        dq.pop_front();
        lr++;
      }
    }
    count += min(lr, (int)dq.size() + 1 - lr);
  }

  /* Output */
  cout << count;

  /* Return */
  return 0;
}
