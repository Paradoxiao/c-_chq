#include <cstdio>
#define NULLELEM -1
struct Sq_BiTree {
  int *base;
  int length;
  int capacity;
};
int GetLeaf(Sq_BiTree T, int root) {
  if (T.base == NULL || root >= T.length || T.base[root] == NULLELEM)
    return 0;
  int left = 2 * root + 1;
  int right = 2 * root + 2;
  if ((left >= T.length || T.base[left] == NULLELEM) &&
      (right >= T.length || T.base[right] == NULLELEM))
    return 1;
  int cnt = 0;
  if (left < T.length)
    cnt += GetLeaf(T, left);
  if (right < T.length)
    cnt += GetLeaf(T, right);
  return cnt;
}
int main() {

  return 0;
}
