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
  while (true) {
    /* Init */
    string str;
    getline(cin, str);
    if (str == ".") break;

    stack<char> s;

    bool isno = false;  // flag ����

    /* Calculate */
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(' || str[i] == '[') {
        s.push(str[i]);
      } else if (str[i] == ')' || str[i] == ']') {
        if (s.empty() || str[i] == ')' && s.top() == '[' ||
            str[i] == ']' && s.top() == '(') {
          isno = true;
          break;
        } else {
          s.pop();
        }
      }
    }

    /* Output */
    if (!s.empty() || isno == true)
      cout << "no" << '\n';
    else
      cout << "yes" << '\n';
  }

  /* End */
  return 0;
}

/*

9012���� ����� Ǯ��

'('�� ')'�� �ƽ�Ű�ڵ� ���� ���̿�, '['�� ']'�� �ƽ�Ű�ڵ� ���� ���̰� ��������
�ʾ�, str[i] == ')' && s.top() == '[' || str[i] == ']' && s.top() == '(' �� ����
�ڵ带 �ۼ��� �� �ۿ� ����.

[�ݷ�]
input : [)]
output : no

�ϸ�ũ ��������.

*/
