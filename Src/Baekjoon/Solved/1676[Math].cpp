/* Ǯ�� 1 */
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  /* Faster */
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  /* Init */
  int arr[2] = {};  // ���μ����� �� 2, 5�� ���� ����.
  int n;
  cin >> n;

  /* Calculation */
  for (int i = 1; i <= n; i++) {
    int x = i;

    while (((x % 2) == 0) || ((x % 5) == 0)) {
      if (x % 2 == 0) {  // 2�� ������ �������� ���.
        arr[0]++;
        x /= 2;
      } else if (x % 5 == 0) {  // 5�� ������ �������� ���.
        arr[1]++;
        x /= 5;
      }
    }
  }

  /* Output */
  cout << min(arr[0], arr[1]);

  /* Return */
  return 0;
}

/* Ǯ�� 2 */
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (n / 5) + (n / 25) + (n / 125);
}

/*
https://torbjorn.tistory.com/247
*/
