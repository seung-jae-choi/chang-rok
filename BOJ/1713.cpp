#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Student {
public:
	
	Student(int num, int vote, int time)
		:num(num),vote(vote),time(time) {};
	int num,vote,time;
};

bool operator < (Student s1, Student s2) {
	//투표 적은 순, 동일하면 먼저 들어온 순으로
	if (s1.vote == s2.vote)  
		return s1.time > s2.time;
	else
		return s1.vote > s2.vote;
}

int N;
int totalcnt;
int stu_num;
vector<bool> recommend(101,false);
vector<Student> stu;
vector<int> ans;
priority_queue<Student> pq;

void clear() {
	while (!pq.empty()) {
		pq.pop();
	}
}
int main()
{
	cin >> N >> totalcnt;
	for (int i = 0; i < totalcnt; i++) {
		cin >> stu_num;
		if (recommend[stu_num]) { // 추천받았다면
			for (int i = 0; i < stu.size(); i++) {
				if (stu[i].num == stu_num) {
					stu[i].vote++;
					break;
				}
			}
			continue;
		}
		recommend[stu_num] = true;
		if (stu.size() < N) { //사진틀에 여유가 있으면
			stu.push_back(Student(stu_num, 1, i));
			continue;
		}
		for (int i = 0; i < stu.size(); i++) {
			pq.push(stu[i]);
		}
		Student s = pq.top();
		for (int j = 0; j < stu.size(); j++) {
			if (stu[j].num == s.num) {
				recommend[s.num] = false;
				stu[j].num = stu_num;
				stu[j].vote = 1;
				stu[j].time = i;
				clear();
				break;
			}
		}
	}
	for (int i = 0; i < stu.size(); i++) {
		ans.push_back(stu[i].num);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
