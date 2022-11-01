#include "ProblemHeader.h"

namespace {
	int N;

	vector<vector<int>> board;

	bool IsInRange(int x, int y) {
		if (0 <= x && x < N && 0 <= y && y < N) {
			return true;
		}

		return false;
	}
}

void P16173() {
	cin >> N;

	board = vector<vector<int>>(N, vector<int>(N, 0));

	std::pair<int, int> src, dst;
	src = { 0,0 };

	queue<std::pair<int, int>> q;

	for (auto i = 0; i < N; ++i)
		for (auto j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		
			if (board[i][j] == -1) dst = { i,j };
		}

	q.push(src);
	
	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		auto [x, y] = now;
		auto jump = board[x][y];

		if (now == dst) {
			cout << "HaruHaru";
			return;
		}

		if (jump == 0) continue;

		if(IsInRange(x + jump, y))
			q.push({x+jump, y});

		if (IsInRange(x, y+ jump))
			q.push({x, y+jump});
	}

	cout << "Hing";
	return;

}