#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
private:
	vector<int> vet;
public:
    ProductOfNumbers() {
		vet.push_back(1);
    }
    
    void add(int num) {
		if (vet.back() == 0) {
			vet.clear();
			vet.push_back(1);
			vet.push_back(num);
		}
		else
			vet.push_back(vet.back()*num);
    }
    
    int getProduct(int k) {
		if (k >= vet.size()) return 0;
		return vet.back()/vet[vet.size()-k-1];
    }
};

int main() {
	ProductOfNumbers productOfNumbers;
	productOfNumbers.add(3);        // [3]
	productOfNumbers.add(0);        // [3,0]
	productOfNumbers.add(2);        // [3,0,2]
	productOfNumbers.add(5);        // [3,0,2,5]
	productOfNumbers.add(4);        // [3,0,2,5,4]
	cout << productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
	cout <<  " " << productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
	cout << " " << productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
	productOfNumbers.add(8);        // [3,0,2,5,4,8]
	cout << " " << productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
}
