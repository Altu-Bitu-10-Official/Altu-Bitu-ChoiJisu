### 📚 Binary Search(이분 탐색)

#### 1. 개념

이분 탐색(Binary Search)은 **정렬된 데이터에서 원하는 값을 빠르게 찾는 탐색 알고리즘**이다.
탐색 범위를 절반씩 줄여가며 탐색하므로 시간 복잡도는 **O(log N)** 이다.

#### 2. 동작 원리

1. 탐색 구간의 중앙값(`mid`)을 선택한다.
2. 찾고자 하는 값(`target`)과 비교한다.
3. `target < mid` 이면 왼쪽 구간 탐색
4. `target > mid` 이면 오른쪽 구간 탐색
5. 값을 찾거나 탐색 범위가 없어질 때까지 반복한다.

```cpp
while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] == target) return true;
    else if (arr[mid] > target)
        right = mid - 1;
    else
        left = mid + 1;
}
```

> `1920_binarySearch.cpp`, `10815.cpp`(`binary_search()` STL 활용)에서 직접 구현해봄.

#### 3. 이분 탐색의 전제 조건

* 탐색 대상이 **정렬(Sorted)** 되어 있어야 한다.
* 배열, 벡터 등 인덱스 접근이 가능한 자료구조에서 주로 사용한다.

#### 4. Lower Bound와 Upper Bound

중복된 값이 존재할 때 특정 값의 개수를 구하기 위해 사용한다.

* **Lower Bound** : target 이상이 처음 나타나는 위치
* **Upper Bound** : target 초과가 처음 나타나는 위치

```cpp
개수 = upperBound(target) - lowerBound(target);
```

> `10816_lowerupperBound.cpp`(숫자 카드2)에서 직접 구현해봄. C++ STL에도 동일한 기능의 `lower_bound()`, `upper_bound()`가 존재한다.

#### 5. Parametric Search(매개변수 탐색)

정답 자체를 이분 탐색하는 방법이다.

* 조건을 만족하는지 검사하는 함수(`check`)를 만든다.
* 가능한 답의 범위를 이분 탐색한다.
* "가능/불가능"이 단조성을 가질 때 사용할 수 있다.

예시:

* 가로등 높이의 최솟값 구하기 (`17266.cpp`, 어두운 굴다리)
* 공유기 사이 거리의 최댓값 구하기 (`2110_cntRouters.cpp`, 공유기 설치)

```cpp
if (check(mid))
    right = mid - 1; // 더 작은 값 탐색
else
    left = mid + 1;  // 더 큰 값 탐색
```

찾는 목적(최솟값 vs 최댓값)에 따라 조건 만족 시 어느 방향으로 줄여나갈지가 반대가 된다는 점이 헷갈렸던 부분이다.

* 최솟값을 구할 때: 조건 만족 시 `right = mid - 1` (더 작은 값도 가능한지 확인)
* 최댓값을 구할 때: 조건 만족 시 `left = mid + 1` (더 큰 값도 가능한지 확인)

#### 6. 느낀 점

이분 탐색은 단순히 값을 찾는 알고리즘이 아니라, **정답의 범위를 탐색하는 Parametric Search 형태로도 활용 가능**하다는 점을 학습했다. 특히 시간 복잡도를 `O(N)`에서 `O(log N)` 수준으로 줄일 수 있어 대규모 데이터 처리에 매우 효과적이었다.
