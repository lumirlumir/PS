#pragma warning(disable : 4996)
#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

int min_idx(LL arr[], int e_idx) {  // idx '0'���� 'e_idx' �߿��� min_idx���� ã��.
  int minimum = INT_MAX;
  int idx = 0;

  for (int i = 0; i <= e_idx; i++)
    if (arr[i] < minimum) {
      minimum = arr[i];
      idx = i;
    }

  return idx;
}

/*
��� �̿��, �־��� ���(������ ���� �� ������ ���������϶�)
O(n^2)�� �ð��� �ҿ�ȴ�. (quick sort�� �־��� ���� ����)
calculate_long�� �̿��ϸ� 58���� ���´�.
*/
LL calculate_long(LL dist[], LL cost[], int e_idx) {  // e_idx = end index
  /* Exit */
  if (e_idx == 0) return 0;

  /* Init */
  LL ans = 0;                            // ���䰪.
  int pivot = min_idx(cost, e_idx - 1);  // �ð����⵵ O(n)

  /* Calculate */
  for (int i = pivot; i < e_idx; i++)
    ans += cost[pivot] * dist[i];

  /* Divide and Conquer */
  return calculate_long(dist, cost, pivot) + ans;
}

/* O(n)�� �ð����⵵ */
LL calculate_short(LL dist[], LL cost[], int e_idx) {
  /* Init */
  LL ans = 0;

  /* Calculate */
  for (int i = 0, cost_now = cost[0]; i < e_idx; i++) {
    ans += cost_now * dist[i];

    if (cost_now > cost[i + 1])
      cost_now = cost[i + 1];
  }

  return ans;
}

int main(int argc, char* argv[]) {
  /* Input */
  int N;
  scanf("%d", &N);

  LL* dist = new LL[N];
  for (int i = 0; i < N - 1; i++)
    scanf("%lld", &dist[i]);

  LL* cost = new LL[N];
  for (int i = 0; i < N; i++)
    scanf("%lld", &cost[i]);

  /* Output */
  // printf("%lld", calculate_long(dist, pric, N - 1)); //O(n^2)Ǯ��
  printf("%lld", calculate_short(dist, cost, N - 1));

  /* End */
  delete[] dist;
  delete[] cost;
  return 0;
}

/*
����, �ϸ�ũ ����.

C++ ��Ÿ�� �����Ҵ� �̿�.
�������� ������� Ǯ����.

[���ٹ��]
�⸧���� ���� �� ���󿡼� �⸧�� ���� ���� �־�� �Ѵ�.

���������� ������ 2�� ���󿡼� ���� ���� �⸧�� �־�� �Ѵ�.

[ans ����]
10^9 = 10�� ����, 10^9 * 10^9 = 10^18, 10^18 = 10��
*/
