#comment는 문제를 풀면서 느낀점에 대해 서술한 부분입니다.
-----------------------------------------------------------------------------

**병약한 윤호** - [백준14677](https://www.acmicpc.net/problem/146)
```
1. 현재의 상태에 따라 left or right 중 하나를 꺼내갈 수 있는지 Dynamic Programming을 통해 구현.
2. dp[left][right][state] = max(dp[left+1][right][state] , dp[left][right-1][state] ) + 1;
3. state -> (state+1) % 3
```

**영우와 ‘갓4’** - [백준14679](https://www.acmicpc.net/problem/14679)
```
1. Ak,Dk,Hk 계산 부분은 반복되므로 각각 최대 100,3,1000번만 계산하면 됨.
2. a^n을 계산시 이분분할 알고리즘을 이용하여 복잡도 간단하게 해결.[참조]
```

**효빈이의 과외** - [백준14680](https://www.acmicpc.net/problem/14680)
```
1. 어떨때 행렬의 곱셈이 안되는지 생각해주면됨.
2. 가능하다면 연산 진행해주면 된다.
```

**토끼가 정보섬에 올라온 이유** - [백준17130](https://www.acmicpc.net/problem/17130)
```
1. dp문제(토끼의 현재위치R을 기준으로 오른쪽 부분만 점검한다)
2. 오른쪽으로 한칸씩 움직일때 전의 dp에 대해 C이면 +1을 누적해간다.
3. 그러다 O일 경우 ans를 기존과 비교해 더 크면 저장.

```

**PLAYERJINAH’S BOTTLEGROUNDS** - [백준15803](https://www.acmicpc.net/problem/15803)
```
1. 3명의 좌표를 입력받아서 기울기가 같은지 확인하면 되는 문제
```

**저거 못 타면 지각이야!!** - [백준15804](https://www.acmicpc.net/problem/15804)
```
1. deque를 활용한 단순구현 문제.
2. 도착시간과 정차시간을 더한 시간이 현재시간(i)보다 작으면 deque에서 빼준다.
3. deque가 비어있거나 마지막 요소의 pos가 n보다 작으면 push_back (but, 현재시간(i)이 도착시간보다 크거나 같아야 한다.)
```

**트리 나라 관광 가이드** - [백준15805](https://www.acmicpc.net/problem/15805)
```
1.flag를 설정해두고 방문한 도시는 true로 바꾼다.
2.새로 방문한 도시는 바로 전의 입력이 부모도시가 된다.
```

**영우의 기숙사 청소** - 백준[15806](https://www.acmicpc.net/problem/15806)
```
1. bfs진행
2. 겹치는 부분이 queue에 들어가므로 그 부분은 조건을 추가하여 진행.
```

**참조** 
- [영우와 '갓4'](https://onsil-thegreenhouse.github.io/programming/problem/2018/03/29/problem_math_power/)
