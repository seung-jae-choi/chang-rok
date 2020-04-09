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
**참조** 
- [영우와 '갓4'](https://onsil-thegreenhouse.github.io/programming/problem/2018/03/29/problem_math_power/)
