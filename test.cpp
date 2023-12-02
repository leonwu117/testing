# include <iostream>

using namespace std;

const int N = 51, M = 1010;

int n, L, S, ans;
bool b[N][N];
pair<int, int> one_location[M];

int find(int a, int b) {
	for (int i = 0; i < n; i++) {
		if (a == one_location[i].first && b == one_location[i].second) {
			return 1;
		}
	}
	return 0;
}

int main(void) {
	cin >> n >> L >> S;

	for (int i = 0; i < n; i++)
		cin >> one_location[i].first >> one_location[i].second;

	for (int i = S; i >= 0; i--)
		for (int j = 0; j <= S; j++)
			cin >> b[i][j];

	for (int i = 0; i < n; i++) {
		if (one_location[i].first > L - S || one_location[i].second > L - S)continue;
		bool flag = true;
		for (int x = 0; x <= S; x++) {
			for (int y = 0; y <= S; y++) {
				if (x == 0 && y == 0)continue;

				int findx = find(one_location[i].first + x, one_location[i].second + y);
				if (findx != b[x][y]) {
					flag = false;
					break;
				}

			}

			if (!flag)break;
		}

		if (flag)ans++;
	}

	cout << ans << endl;
	return 0;
}