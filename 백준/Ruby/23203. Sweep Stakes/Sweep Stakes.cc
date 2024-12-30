#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define EPS 1e-15 // 무시할 수 있는 확률의 하한값

// 확률 분포를 관리하는 클래스
struct ProbabilityDistribution {
  vector<double> values; // 확률 값을 저장
  int base = 0;          // 분포의 시작 기준
  int minIndex = 0;      // 유효한 최소 인덱스

  ProbabilityDistribution() : values{1.0} {} // 초기값은 확률 1.0

  // 복사 생성자: 불필요한 값을 제거하며 복사
  ProbabilityDistribution(const ProbabilityDistribution& other) {
    base = other.base + other.minIndex;
    values.insert(values.begin(), other.values.begin() + other.minIndex, other.values.end());
  }

  // 특정 인덱스의 확률 값을 반환
  double operator[](int i) const {
    if (i < base + minIndex || i - base >= values.size()) return 0.0; // 범위를 벗어나면 0 반환
    return values[i - base];
  }

  // 확률 값을 추가하여 분포 갱신
  void addProbability(double p) {
    values.push_back(p * values.back()); // 새로운 확률 추가
    for (int i = values.size() - 2; i > minIndex; i--) {
      values[i] = (1 - p) * values[i] + p * values[i - 1]; // 분포 갱신
    }
    values[minIndex] *= (1 - p); // 최소값 갱신
    while (values[minIndex] < EPS) minIndex++; // 무시할 수 있는 확률 제거
    while (values.back() < EPS) values.pop_back(); // 끝에서 작은 확률 제거
  }
};

// 전역 변수
int rows, cols, totalMines, queryCount; // 행, 열, 전체 지뢰 수, 쿼리 수
vector<double> rowProbabilities, colProbabilities; // 행별, 열별 확률
vector<vector<pair<int, int>>> queries; // 각 쿼리에 포함된 좌표

map<pair<int, int>, vector<pair<int, int>>> mergedQueries; // 병합된 쿼리 저장

// 쿼리를 병합하는 함수
const vector<pair<int, int>>& mergeQueries(int start, int end) {
  auto& merged = mergedQueries[{start, end}];
  if (start + 1 == end) {
    merged = queries[start]; // 쿼리가 하나면 그대로 반환
  } else {
    // 재귀적으로 병합
    auto const& left = mergeQueries(start, (start + end) / 2);
    auto const& right = mergeQueries((start + end) / 2, end);
    merged = left;
    merged.insert(merged.end(), right.begin(), right.end()); // 병합
  }
  // 중복 좌표 제거
  sort(merged.begin(), merged.end());
  merged.erase(unique(merged.begin(), merged.end()), merged.end());
  return merged;
}

// 쿼리를 처리하는 함수
void processQuery(int start, int end, const ProbabilityDistribution& distribution) {
  if (start + 1 == end) {
    if (start == queryCount) return; // 마지막 쿼리는 처리하지 않음
    ProbabilityDistribution currentDistribution;
    for (auto [x, y] : queries[start]) {
      currentDistribution.addProbability(rowProbabilities[x] + colProbabilities[y]);
    }

    double total = 0.0; // 분모 계산
    for (int i = 0; i <= queries[start].size(); i++) {
      total += currentDistribution[i] * distribution[totalMines - i];
    }

    // 각 상태의 확률 출력
    for (int i = 0; i <= queries[start].size(); i++) {
      printf("%.9lf ", currentDistribution[i] * distribution[totalMines - i] / total);
    }
    printf("\n");
    return;
  }

  // 분할 정복: 왼쪽, 오른쪽 처리
  ProbabilityDistribution leftDistribution(distribution), rightDistribution(distribution);
  auto const& left = mergedQueries[{start, (start + end) / 2}];
  auto const& right = mergedQueries[{(start + end) / 2, end}];

  // 왼쪽과 오른쪽의 확률 분포 갱신
  for (int li = 0, ri = 0; li < left.size() || ri < right.size(); ) {
    if (ri == right.size() || (li < left.size() && left[li] < right[ri])) {
      rightDistribution.addProbability(rowProbabilities[left[li].first] + colProbabilities[left[li].second]);
      li++;
    } else if (li == left.size() || right[ri] < left[li]) {
      leftDistribution.addProbability(rowProbabilities[right[ri].first] + colProbabilities[right[ri].second]);
      ri++;
    } else {
      li++;
      ri++;
    }
  }

  processQuery(start, (start + end) / 2, leftDistribution);  // 왼쪽 처리
  processQuery((start + end) / 2, end, rightDistribution);   // 오른쪽 처리
}

int main() {
  while (cin >> rows >> cols >> totalMines >> queryCount) {
    rowProbabilities.resize(rows);
    colProbabilities.resize(cols);
    for (auto& p : rowProbabilities) cin >> p; // 행별 확률 입력
    for (auto& p : colProbabilities) cin >> p; // 열별 확률 입력

    queries.clear();
    queries.resize(queryCount + 1);

    for (int i = 0; i < queryCount; i++) {
      int querySize;
      cin >> querySize;
      for (int j = 0; j < querySize; j++) {
        int x, y;
        cin >> x >> y;
        queries[i].emplace_back(x - 1, y - 1); // 1-based -> 0-based
      }
    }

    // 전체 그리드 추가
    for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
        queries[queryCount].emplace_back(x, y);
      }
    }

    mergeQueries(0, queryCount + 1);         // 쿼리 병합
    processQuery(0, queryCount + 1, ProbabilityDistribution()); // 쿼리 처리
  }
}