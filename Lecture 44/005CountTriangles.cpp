/*

	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	vector<pair<int, int>> points = {
		{1, 2},
		{2, 0},
		{2, 2},
		{2, 3},
		{4, 2}
	};

	// time : O(n^2)
	// space: O(1)

	int ans = 0; // to track no. of valid triangles

	for (pair<int, int> p : points) {

		// find out no. of valid triangles we can make
		// with point p as the pivot

		int x = p.first; // x-coorindate of pivot p
		int y = p.second; // y-coordinate of pivot p

		int cnt1 = 0; // to track point in the 2d plane whose x-coordinate matches pivot's x coordinate
		int cnt2 = 0; // to track point in the 2d plane whose y-coordinate matches pivot's y coordinate

		for (pair<int, int> q : points) {
			if (q.first == x) {
				cnt1++;
			}
			if (q.second == y) {
				cnt2++;
			}
		}

		cnt1--; // to avoid counting pivot
		cnt2--; // to avoid counting pivot

		ans += cnt1 * cnt2;

	}

	cout << ans << endl;

	return 0;

}