#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> B;

struct Node
{
	Node() : left(false), right(false), up(false), down(false) {}
    
	bool left;
	bool right;
	bool up;
	bool down;
};

struct Point
{
	Point() : y(0), x(0) {}
	int y;
	int x;

	void operator=(Point a)
	{
		this->y = a.y;
		this->x = a.x;
	}
};

struct Pointset
{
	Point p1; //(n, n)과 상대적으로 가까운 것
	Point p2; //(n, n)과 상대적으로 먼 것
};

struct Path
{
	//최소값을 구하기 위한 값을 지정한다.
	int mcount;
	Pointset pos;
};

//왼쪽, 오른쪽, 위쪽, 아래쪽 각각 이동이 가능한지 판단
bool moveleft(Pointset pos, int n)
{
	if (0 <= pos.p2.x - 1 && B[pos.p1.y][pos.p1.x - 1] == 0 && B[pos.p2.y][pos.p2.x - 1] == 0)
		return true;
	return false;
}
bool moveright(Pointset pos, int n)
{
	if (pos.p1.x + 1 < n && B[pos.p1.y][pos.p1.x + 1] == 0 && B[pos.p2.y][pos.p2.x + 1] == 0)
		return true;
	return false;
}
bool moveup(Pointset pos, int n)
{
	if (0 <= pos.p2.y - 1 && B[pos.p1.y - 1][pos.p1.x] == 0 && B[pos.p2.y - 1][pos.p2.x] == 0)
		return true;
	return false;
}
bool movedown(Pointset pos, int n)
{
	if (pos.p1.y + 1 < n && B[pos.p1.y + 1][pos.p1.x] == 0 && B[pos.p2.y + 1][pos.p2.x] == 0)
		return true;
	return false;
}

bool rotate_p1_clockwise(Pointset pos, int n, int state)
{
	if (state == 0)
	{
		if (0 <= pos.p1.y - 1 && B[pos.p2.y - 1][pos.p2.x] == 0 && B[pos.p1.y - 1][pos.p1.x] == 0)
			return true;
	}
	else
	{
		//p1, p2 스왑
		if (pos.p1.x + 1 < n && B[pos.p2.y][pos.p2.x + 1] == 0 && B[pos.p1.y][pos.p1.x + 1] == 0)
			return true;
	}
	return false;
}
bool rotate_p1_counterclockwise(Pointset pos, int n, int state)
{
	if (state == 0)
	{
		//p1, p2 스왑
		if (pos.p1.y + 1 < n && B[pos.p2.y + 1][pos.p2.x] == 0 && B[pos.p1.y + 1][pos.p1.x] == 0)
			return true;
	}
	else
	{
		if (0 <= pos.p1.x - 1 && B[pos.p2.y][pos.p2.x - 1] == 0 && B[pos.p1.y][pos.p1.x - 1] == 0)
			return true;
	}
	return false;
}
bool rotate_p2_clockwise(Pointset pos, int n, int state)
{
	if (state == 0)
	{
		if (pos.p2.y + 1 < n && B[pos.p1.y + 1][pos.p1.x] == 0 && B[pos.p2.y + 1][pos.p2.x] == 0)
			return true;
	}
	else
	{
		//p1, p2 스왑
		if (0 <= pos.p2.x - 1 && B[pos.p1.y][pos.p1.x - 1] == 0 && B[pos.p2.y][pos.p2.x - 1] == 0)
			return true;
	}
	return false;
}
bool rotate_p2_counterclockwise(Pointset pos, int n, int state)
{
	if (state == 0)
	{
		//p1, p2 스왑
		if (0 <= pos.p2.y - 1 && B[pos.p1.y - 1][pos.p1.x] == 0 && B[pos.p2.y - 1][pos.p2.x] == 0)
			return true;
	}
	else
	{
		if (pos.p2.x + 1 < n && B[pos.p1.y][pos.p1.x + 1] == 0 && B[pos.p2.y][pos.p2.x + 1] == 0)
			return true;
	}

	return false;
}

void Swap(Point& a, Point& b)
{
	Point tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int solution(vector<vector<int>> board)
{
	int n = board.size();
	vector<vector<Node>> visit(n, vector<Node>(n));
	B = board;
	
	queue<Path> q;

	Pointset pos;
	pos.p1.x = 1;
	Path path;
	path.mcount = 0;
	path.pos = pos;

	q.push(path);
	int cnt = 0;

	while (!q.empty())
	{
		pos = q.front().pos;
		cnt = q.front().mcount;
		q.pop();

		if (pos.p1.x == (n - 1) && pos.p1.y == (n - 1))
		{
			return cnt;
		}

		int state = -1;

		if (pos.p1.y == pos.p2.y)
		{
			if (visit[pos.p1.y][pos.p1.x].left && visit[pos.p2.y][pos.p2.x].right)
			{
				continue;
			}
			visit[pos.p1.y][pos.p1.x].left = true;
			visit[pos.p2.y][pos.p2.x].right = true;

			state = 0;
		}
		else
		{
			if (visit[pos.p1.y][pos.p1.x].up && visit[pos.p2.y][pos.p2.x].down)
			{
				continue;
			}
			visit[pos.p1.y][pos.p1.x].up = true;
			visit[pos.p2.y][pos.p2.x].down = true;

			state = 1;
		}

		if (moveleft(pos, n))
		{
			path.pos = pos;
			path.pos.p1.x--;
			path.pos.p2.x--;
			path.mcount = cnt + 1;
			q.push(path);
		}
		if (moveright(pos, n))
		{
			path.pos = pos;
			path.pos.p1.x++;
			path.pos.p2.x++;
			path.mcount = cnt + 1;
			q.push(path);
		}
		if (moveup(pos, n))
		{
			path.pos = pos;
			path.pos.p1.y--;
			path.pos.p2.y--;
			path.mcount = cnt + 1;
			q.push(path);
		}
		if (movedown(pos, n))
		{
			path.pos = pos;
			path.pos.p1.y++;
			path.pos.p2.y++;
			path.mcount = cnt + 1;
			q.push(path);
		}

		if (rotate_p1_clockwise(pos, n, state))
		{
			if (state == 0)
			{
				path.pos = pos;
				path.pos.p2.y--;
				path.pos.p2.x++;
				path.mcount = cnt + 1;
				q.push(path);
			}
			else
			{
				//p1, p2 스왑
				path.pos = pos;
				path.pos.p2.y++;
				path.pos.p2.x++;
				Swap(path.pos.p1, path.pos.p2);
				path.mcount = cnt + 1;
				q.push(path);
			}
		}

		if (rotate_p1_counterclockwise(pos, n, state))
		{
			if (state == 0)
			{
				//p1, p2 스왑
				path.pos = pos;
				path.pos.p2.y++;
				path.pos.p2.x++;
				Swap(path.pos.p1, path.pos.p2);
				path.mcount = cnt + 1;
				q.push(path);
			}
			else
			{
				path.pos = pos;
				path.pos.p2.y++;
				path.pos.p2.x--;
				path.mcount = cnt + 1;
				q.push(path);
			}
		}

		if (rotate_p2_clockwise(pos, n, state))
		{
			if (state == 0)
			{
				path.pos = pos;
				path.pos.p1.y++;
				path.pos.p1.x--;
				path.mcount = cnt + 1;
				q.push(path);
			}
			else
			{
				//p1, p2 스왑
				path.pos = pos;
				path.pos.p1.y--;
				path.pos.p1.x--;
				Swap(path.pos.p1, path.pos.p2);
				path.mcount = cnt + 1;
				q.push(path);
			}
		}

		if (rotate_p2_counterclockwise(pos, n, state))
		{
			if (state == 0)
			{
				//p1, p2가 스왑
				path.pos = pos;
				path.pos.p1.y--;
				path.pos.p1.x--;
				Swap(path.pos.p1, path.pos.p2);
				path.mcount = cnt + 1;
				q.push(path);
			}
			else
			{
				path.pos = pos;
				path.pos.p1.y--;
				path.pos.p1.x++;
				path.mcount = cnt + 1;
				q.push(path);
			}
		}
	}
	return 0;
}
