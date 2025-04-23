#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define DEBUG			0
#define MAX_DIR			4
#define ALPHA_COUNT		('Z' - 'A') + 1

using namespace std;

static int R, C;
static vector<vector<char>> board;

static vector<int> dx = {-1, 1, 0, 0};
static vector<int> dy = {0, 0, -1, 1};

static vector<bool> visited_alpha;

static int max_count;

void check_max(int depth)
{
	if(depth > max_count)
	{
		max_count = depth;
	}
}

void dfs(int sx, int sy, int depth)
{
	int nx, ny;

	check_max(depth);

	for(int i = 0; i < MAX_DIR; i ++)
	{
		nx = dx[i] + sx;
		ny = dy[i] + sy;
		
#if(DEBUG)
		cout << "nx, ny: " << nx << ny << endl;
#endif

		if((nx < 0) || (nx >= C) || (ny < 0) || (ny >= R))
		{
			continue;
		}

		if(visited_alpha[board[ny][nx] - 'A'] == true)
		{
			continue;
		}
		visited_alpha[board[ny][nx] - 'A'] = true;
		dfs(nx, ny, (depth + 1));
		visited_alpha[board[ny][nx] - 'A'] = false;
	}
}

int main(void)
{
	string line;
	char temp;
	
	cin >> R >> C;

	cin.ignore();

	board.resize(R);
	visited_alpha.resize(ALPHA_COUNT);

	for(int i = 0; i < R; i ++)
	{
		getline(cin, line);
		istringstream iss(line);

		while(iss >> temp)
		{
			board[i].push_back(temp);
		}
	}

#if(0)
	for(int q = 0; q < R; q ++)
	{
		for(int p = 0; p < C; p ++)
		{
			cout << board[q][p];
		}
		cout << endl;
	}
#endif
	max_count = 1;
	visited_alpha[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << max_count << endl;

	return 0;
}
