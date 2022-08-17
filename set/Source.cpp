#include <iostream>

using namespace std;

const int n = 10;
int T[n] = { 11,13,17,23,29,31,37,41,43,47 };

void show_u() {
	cout << "U = {";
	for (int i = 0; i < n; i++)
		cout << T[i] << ' ';
	cout << '}' << endl;
}

bool is_member_of_universum(int t) {
	cout << "is_of_universum" << t << endl;
	show_u();
	for (int i = 0; i < n; i++)
		if (t == T[i])
			return true;
	return false;
}


class Set {
private:
	int shk[n];
public:
	Set() {
		for (int i = 0; i < n; i++)
			shk[i] = 0;
	}

	void add(int t) {
		for (int i = 0; i < n; i++)
			if (t == T[i])
				shk[i] = 1;
	}

	bool is_member(int t) {
		for (int i = 0; i < n; i++)
			if (t == T[i] && shk[i] == 1)
				return true;
		return false;
	}

	void del_member(int t) {
		for (int i = 0; i < n; i++)
			if (t == T[i])
				shk[i] = 0;
	}

	bool is_empty() {
		for (int i = 0; i < n; i++)
			if (shk[i] != 0)
				return 0;
		return 1;
	}

	Set operator+(Set& s) {
		Set _s;
		for (int i = 0; i < n; i++) {
			if (shk[i] == 1 || s.shk[i] == 1)
				_s.shk[i] = 1;
		}
		return _s;
	}

	Set operator*(Set& s) {
		Set _s;
		for (int i = 0; i < n; i++)
			if (shk[i] == 1 && s.shk[i] == 1) 
				_s.shk[i] = 1;
		return _s;
	}

	Set operator-(Set& s) {
		Set _s;
		for (int i = 0; i < n; i++)
			if (shk[i] == 1 && s.shk[i] != 1)
				_s.shk[i] = 1;
		return _s;
	}

	Set operator-() {
		Set _s;
		for (int i = 0; i < n; i++) {
			if (shk[i] == 1)
				_s.shk[i] = 0;
			if (shk[i] == 0)
				_s.shk[i] = 1;
		}
		return _s;
	}

	void show_in_U() {
		cout << "Elements from the U:\n";
		for (int i = 0; i < n; i++)
			if (shk[i] == 1)
				cout << T[i] << " ";
		cout << endl;
	}

	void show() {
		for (int i = 0; i < n; i++)
			cout << shk[i] << " ";
		cout << endl;
	}
};


int main() {
	Set set2;
	Set set1;

	set1.add(13);
	set2.add(41);
	set1.add(11);
	set2.add(43);

	Set s;

	show_u();

	cout << "set1: " << endl;
	set1.show();
	set1.show_in_U();
	cout << "set2: " << endl;
	set2.show();
	set2.show_in_U();

	cout << "Is empty set2? (0 - NO, 1 - YES):\nAnswer: " << set2.is_empty() << endl;

	s = set1 + set2;
	cout << "set1 + set2 = ";
	s.show();
	cout << "set1 * set2 = ";
	s = set1 * set2;
	s.show();
	cout << "s = set1 - set2 = ";
	s = set1 - set2;
	s.show();
	cout << "-s = ";
	s = -s;
	s.show();
}