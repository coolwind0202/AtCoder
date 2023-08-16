#include <iostream>

using namespace std;

bool isAddress(string S, size_t A, size_t B)
{
  size_t i = 0;

  for (i = 0; i < A; i++)
  {
    if (!isdigit(S[i]))
      return false;
  }

  if (S[i] != '-')
    return false;

  for (i++; i < A + B + 1; i++)
  {
    if (!isdigit(S[i]))
      return false;
  }
  return true;
}

int main(void)
{
  size_t A = 0, B = 0, i = 0;
  string S;
  cin >> A >> B >> S;

  cout << (isAddress(S, A, B) ? "Yes" : "No") << endl;
  return 0;
}