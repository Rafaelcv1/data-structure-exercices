#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long number_of_books;
	long long time;
	long long maxBooks = 0;
	cin >>  number_of_books >> time;
	vector<long long> vector;
	for (long long i = 0; i < number_of_books; i++) {
		int x;
		cin >> x;
		vector.push_back(x);
	}

	long long actualTime = 0;
	long long left = 0;
	long long booksCounter = 0;
	for (long long right = 0; right < number_of_books; right++) {
		actualTime += vector[right];
		booksCounter++;
		while (actualTime > time) {
			actualTime -= vector[left];
			booksCounter--;
			left++;
		}
		if (booksCounter > maxBooks) maxBooks = booksCounter;
	}
	cout << maxBooks << endl;
}
