#include <iostream>
#include <vector>
using namespace std;

// 트리가 주어졌을 때, 노드 하나를 줄인다. 
// 남은 트리에서 리프 노드의 개수를 구하자.
// 부모 노드를 지우면 자식 노드가 모두 사라진다.

// 노드의 개수 N
// 0 ~ N-1 노드들의 부모
// 만약 부모가 없다면(루트 노드이면) -1이 주어진다.
// 지울 노드의 번호

int n, del, leaf = 0, root;

vector<int> tree[51];

int dfs(int node) {  // DFS - 트리를 탐색하면서 리프 노드의 개수를 센다.
  if (node == del) 
    return -1;
  if (!tree[node].size()) {  // 현재 노드가 자식이 없는 리프 노드인지 확인.
    leaf++;
    return 0;
  }

  for (int i = 0; i < tree[node].size(); i++) {  // 자식 노드가 있으면 dfs를 재귀호출
    int tmp = dfs(tree[node][i]);
    if (tmp == -1 && tree[node].size() == 1) 
      leaf++;
  }
  return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
      int parent;
      cin >> parent;
      if (parent == -1) 
        root = i;
      else  
        tree[parent].push_back(i);
    }

    cin >> del;
    dfs(root);
    cout << leaf;

    return 0;
}