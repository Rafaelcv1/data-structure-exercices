#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        
    }
    
    int getProduct(int k) {
        
    }
};

//["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
//[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
int main () {
	ProductOfNumbers* obj = new ProductOfNumbers();
	obj->add(3);
	obj->add(0);
	obj->add(2);
	obj->add(5);
	obj->add(4);
	cout << obj->getProduct(2) << " " << obj->getProduct(3) << " " << obj->getProduct(4) << endl;
	//20,40,0
	obj->add(8);
	cout << obj->getProduct(2) <<  endl;
	//32
}
