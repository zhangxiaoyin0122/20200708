#include <iostream>
using namespace std;
class A {
public:
	void test(float a) { 
		cout << 1 << endl;
	}
};
class B : public A {
	void test(float a) {
		cout << 2 << endl;
	}
};
int main() {
	A* a = new A;
	B* b = new B;
	a = b;
	a->test(1);
	return 0;
}

//·Âº¯Êý:
struct Greater {
	bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
		if (p1.second > p2.second) {
			return true;
		}
		else if (p1.second == p2.second) {
			if (p1.first < p2.first)
				return true;
		}
		return false;
	}
};

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> m;
		for (const auto& e : words) {
			++m[e];
		}
		/*multimap<int,string,greater<int>> m2;
		for(const auto& wd : m){
			m2.insert(make_pair(wd.second,wd.first));
		}
		vector<string> v;
		int count = 0;
		for(const auto& h : m2){
			if(count < k){
				v.push_back(h.second);
				count++;
			}else
				break;
		}
		return v;*/

		priority_queue<pair<string, int>, vector<pair<string, int>>, Greater> pq;
		Greater gre;
		for (const auto& e : m) {
			if (pq.size() < k || gre(e, pq.top())) {
				pq.push(e);
			}
			if (pq.size() > k)
				pq.pop();
		}
		list<string> lst;
		while (!pq.empty()) {
			lst.push_front(pq.top().first);
			pq.pop();
		}
		vector<string> v;
		for (const auto& e : lst) {
			v.push_back(e);
		}
		return v;
	}
};