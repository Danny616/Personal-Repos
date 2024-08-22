#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    unordered_map<int, int> pair_dict;
    unordered_map<int, unordered_map<int, int>> pref_dict;

    // Populate pair_dict and pref_dict
    for (const auto& p : pairs) {
        pair_dict[p[0]] = p[1];
        pair_dict[p[1]] = p[0];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pref_dict[i][preferences[i][j]] = j;
        }
    }

    int unhappy_count = 0;

    // Check for unhappy friends
    for (int x = 0; x < n; ++x) {
        int y = pair_dict[x];
        for (int a = 0; a < n; ++a) {
            int b = pair_dict[a];
            if (x != a && pref_dict[x][a] < pref_dict[x][y] && pref_dict[a][x] < pref_dict[a][b]) {
                unhappy_count++;
            }
        }
    }

    return unhappy_count;
}

int main() {
    // Test cases
    vector<vector<int>> preferences1 = {{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}};
    vector<vector<int>> pairs1 = {{0, 1}, {2, 3}};
    int result1 = unhappyFriends(4, preferences1, pairs1);

    vector<vector<int>> preferences2 = {{1}, {0}};
    vector<vector<int>> pairs2 = {{1, 0}};
    int result2 = unhappyFriends(2, preferences2, pairs2);

    vector<vector<int>> preferences3 = {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}};
    vector<vector<int>> pairs3 = {{1, 3}, {0, 2}};
    int result3 = unhappyFriends(4, preferences3, pairs3);

    // Displaying results
    cout << "Test Case 1: " << result1 << endl;
    cout << "Test Case 2: " << result2 << endl;
    cout << "Test Case 3: " << result3 << endl;

    return 0;
}
