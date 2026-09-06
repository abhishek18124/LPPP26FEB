#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct customer {
	string name;
	int age;

	// customer(string name, int age) {
	// 	this->name = name;
	// 	this->age = age;
	// }

	customer(string name, int age) : name(name), age(age) {} // data-member(param)

};

class AgeCmp {

public:

	// return false if you want a to be given more priority than b otherwise return true

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			return false;
		} else {
			return true;
		}
	}

};

int main() {

	priority_queue<customer, vector<customer>, AgeCmp> minHeap;

	minHeap.push(customer("afzal", 20));
	minHeap.push(customer("niyati", 18));
	minHeap.push(customer("areen", 19));
	minHeap.push(customer("arpan", 21));

	while (!minHeap.empty()) {
		customer c = minHeap.top(); minHeap.pop();
		cout << c.name << " " << c.age << endl;
	}

	return 0;
}