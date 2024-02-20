#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  /* Faster */
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  /* Input */
  int T;
  cin >> T;

  /* Calculate */
  for (int i = 0; i < T; i++) {
    /* Init */
    string str;
    cin >> str;
    stack<bool> s;
    bool isno = false;  // flag ����

    /* Calculate */
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(') {
        s.push(true);
      } else if (str[i] == ')') {
        if (s.empty()) {
          isno = true;
          break;
        } else {
          s.pop();
        }
      }
    }

    /* Output */
    if (!s.empty() || isno == true)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }

  /* End */
  return 0;
}

/*
'\n' �� "\n" ���� �ӵ��� ������.

����� �ڷᱸ�� : stack
Ǯ�� ����
1. '(' �� ��
        stack�� push
2. ')' �� ��
        stack�� ������� �ʴٸ� pop
        stack�� ����ִٸ� "NO"
3. �Է����� �� ���ڿ� Ȯ�� ��ģ ���
        stack�� ����ִ� ��� "YES"
        stack�� ������� ���� ��� "NO"

*/
