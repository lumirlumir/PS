#include <iostream>
#include <queue>
using namespace std;

struct cmp {
  bool operator()(const pair<int, char>& a, const pair<int, char>& b) {
    // �� ���� �ٸ��ٸ�.
    if (a.first != b.first)
      return a.first > b.first;
    // �� ���� ���ٸ�.
    else
      return a.second < b.second;
  }
};

int main(int argc, char* argv[]) {
  /* Faster */
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  /* Init */
  priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;

  /* Input */
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    /* Input */
    int x;
    cin >> x;

    /* Calculation */
    if (x == 0) {
      if (pq.empty()) {
        cout << 0 << '\n';
      } else {
        if (pq.top().second == '+')
          cout << pq.top().first << '\n';
        else
          cout << -pq.top().first << '\n';

        pq.pop();
      }
    } else {
      if (x >= 0)
        pq.push(make_pair(x, '+'));
      else
        pq.push(make_pair(-x, '-'));
    }
  }

  /* Return */
  return 0;
}

/* 1927��, 11279�� ������ ��Ʈ ���� */
