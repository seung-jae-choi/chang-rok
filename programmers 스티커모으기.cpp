#include <iostream>
#include <vector>
using namespace std;

int answer1(0),answer2(0),answer;
int dp[100001];

int solution(vector<int> sticker)
{
    if (sticker.size() == 1) return sticker.back();
    int n = sticker.size();
	//첫번째 뜯는 경우
	dp[0] = sticker[0];
	dp[1] = sticker[0];
	for (int i = 2; i < n-1; i++) {
		dp[i] = max(sticker[i] + dp[i - 2], dp[i - 1]);
	}
	answer1 = dp[n-2];
	//첫번째 안뜯음
	dp[0] = 0;
	dp[1] = sticker[1];
	for (int i = 2; i < n; i++) {
		dp[i] = max(sticker[i] + dp[i - 2], dp[i - 1]);
	}
	answer2 = dp[n - 1];
	answer = max(answer1, answer2);
    return answer;
}
