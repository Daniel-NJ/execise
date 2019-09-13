
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> maxLengthSubArrary(vector<int> arrary, int m, int n) {
		multimap<int, int> avl;
		int max, min, sub, sum = 0, start = 0;
		int maxLen = 0, maxSum = 0;
		vector<int> ret(2, 0);
		for (int i = 0; i < arrary.size(); i++ ) {
			avl.clear();
			sum = 0;
			avl.insert(make_pair(arrary[i], i));
			sum += arrary[i];
			if (i + 1 < arrary.size()) {
				avl.insert(make_pair(arrary[i + 1], i+1));
				sum += arrary[i + 1];
				
			}
			else {

				continue;
			}
 			if ((avl.rbegin()->first - avl.begin()->first) > n) {

				continue;
			}
			start = i;
			for (int j = i + 2; j < arrary.size(); j++) {
				sum += arrary[j];
				avl.insert(make_pair(arrary[j], j));
				min = avl.begin()->first;
				max = avl.rbegin()->first;
				sub = max - min;



				if (sub > n) {

					break;
				}

				if (maxLen < (j - start + 1)) {
					maxLen = j - start + 1;
					maxSum = sum;
				}
				else if (maxLen == (j - start +1) && sum > maxSum) {
					maxSum = sum;
				}


			}

		}
		ret[0] = maxLen;
		ret[1] = maxSum;
		return ret;
	}
};

int main() {
	/*
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);

		int ret = Solution().widthOfBinaryTree(root);
 		cout << ret << endl;
	}
	*/
	vector<int> arrary = { 1,2,3,4,5,6,1,2,3,1,2,3,4,5,6,7 }; int m = 0, n = 4;
	for (auto c : Solution().maxLengthSubArrary(arrary, m, n)) {
		cout << c << " ";
	}
	return 0;
}