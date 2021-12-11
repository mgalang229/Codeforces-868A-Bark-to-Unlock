#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string password;
	cin >> password;
	int n;
	cin >> n;
	vector<string> word(n);
	bool checker = false;
	// check if the password is already equal to the words
	// edge case: if the word is the reverse of the password, then
	// it is also valid since repeatingly using this word will result to the password
	for (int i = 0; i < n; i++) {
		cin >> word[i];
		string s1 = word[i];
		sort(s1.begin(), s1.end());
		string s2 = password;
		sort(s2.begin(), s2.end());
		if (s1 == s2) {
			checker = true;
		}
	}
	if (checker) {
		cout << "YES" << '\n';
		return 0;
	}
	// otherwise, check if 1st character of the password can be found in one
	// of the 2nd characters in the words (end) and check if the 2nd character of
	// the password can be found in one of the 1st characters in the words (start)
	bool start = false;
	bool end = false;
	for (int i = 0; i < n; i++) {
		end |= (password[0] == word[i][1]);
		start |= (password[1] == word[i][0]);
	}
	cout << (end && start ? "YES" : "NO") << '\n';
	return 0;
}
