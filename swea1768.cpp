#define N 4



typedef struct {

	int strike;

	int ball;

} Result;



// API

extern Result query(int guess[]);
//123~9876
bool num[9876];
bool number[5040];
bool flag = true;
int idx(0);
void init() {
	if (flag) {
		flag = false;
		for (int i = 123; i <= 9876; i++) {
			int a = i / 1000;
			int b = i % 1000 / 100;
			int c = i % 100 / 10;
			int d = i % 10;
			if (a != b && a != c && a != d && b != c && b != d && c != d) {
				number[idx] = i;
				idx++;
			}
		}
	}
	for (int i = 0; i < idx; i++) {
		num[number[i]] = true;
	}
}

Result cmp(int x, int y) {
	Result r;
	r.strike = 0;
	r.ball = 0;
	int check[10] = { 0, };
	for (int i = 0; i < N; i++) {
		if (x % 10 == y % 10)
			r.strike++;
		else {
			check[x % 10]++;
			check[y % 10]++;
		}
		if (check[x % 10] == 2)
			r.ball++;
		if (check[y % 10] == 2)
			r.ball++;
		x /= 10;
		y /= 10;
	}
	return r;
}

void doUserImplementation(int guess[]) {
	init();
	while (true)
	{
		int ans;
		for (int i = 0; i < idx; i++) {
			if (num[number[i]]) {
				ans = number[i];
				guess[0] = i / 1000;
				guess[1] = i % 1000 / 100;
				guess[2] = i % 100 / 10;
				guess[3] = i % 10;
				break;
			}
		}
		Result result = query(guess);
		if (result.strike == 4)
			break;
		else
			num[ans] = false;
		for (int i = 0; i < idx; i++) {
			if (num[number[i]]) {
				Result rslt = cmp(ans, number[i]);
				if (result.strike != rslt.strike ||
					result.ball != rslt.ball)
					num[number[i]] = false;
			}
		}
	}


}
