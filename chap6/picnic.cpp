#include <iostream>

using namespace std;
bool isFriend[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
int N, M;
int Finding_friend_pair(bool taken[10])
{
  int pivot = -1;
  for (int i = 0; i < N; i++)
  {
    if (taken[i] == false)
    {
      pivot = i;
      break;
    }
  }
  if (pivot == -1)
  {
    return 1;
  }
  int repet = 0;
  for (int j = pivot + 1; j < N; j++)
  {
    if (taken[j] == true)
      continue;
    if (!taken[j] && isFriend[pivot][j] == true)
    {
      taken[j] = taken[pivot] = true;
      repet += Finding_friend_pair(taken);
      taken[pivot] = taken[j] = false;
    }
  }

  cout << repet << endl;
  return repet;
}
int main()
{

  int testcase;
  cin >> testcase;
  cin >> N >> M;
  bool isTaken[10] = {
      false,
  };
  int rst = Finding_friend_pair(isTaken);
  cout << rst << endl;

  return 0;
}