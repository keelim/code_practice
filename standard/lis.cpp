#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vc;
	

	int answer=0;
	vector<int> sample={10, 20, 40, 25, 20, 50, 30, 70, 85};
	for(int i=0; i<sample.size(); i++) {
		int x = sample[i];
		if(vc.empty()) {
			vc.push_back (x);
			continue;
		}
		
		if(vc.back()<x) {
			vc.push_back (x);
			answer+=1;
		} else {
			auto it=lower_bound (vc.begin (), vc.end (), x);
			*it=x;
		}
	}

	for(auto ele : vc) {
		cout << ele << ' ';
	}
	cout << '\n';

	cout << answer << '\n';
	
}