#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <array>
#include <forward_list>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <limits>
#include <memory>
#include <tuple>
#include <initializer_list>
#include <utility>
#include <iterator>
#include <bitset>

using namespace std;

int main()
{
  /*ifstream arq(getenv("MYARQ"));
	cin.rdbuf(arq.rdbuf());*/

	string line;
	int test_cases;
	getline(cin, line);
	stringstream(line) >> test_cases;

	for (int i = 1; i <= test_cases; ++i) {
    int choice1, choice2;
    getline(cin, line);

    stringstream(line) >> choice1;
    vector<int> row1;

    for (int i = 1; i <= 4; ++i) {
      getline(cin, line);
      if (i == choice1) {
        stringstream ss(line);
        for (int j = 0; j < 4; ++j) {
          int num;
          ss >> num;
          row1.push_back(num);
        }
      }
    }

    getline(cin, line);

    stringstream(line) >> choice2;
    vector<int> row2;

    for (int i = 1; i <= 4; ++i) {
      getline(cin, line);
      if (i == choice2) {
        stringstream ss(line);
        for (int j = 0; j < 4; ++j) {
          int num;
          ss >> num;
          row2.push_back(num);
        }
      }
    }

    sort(row1.begin(), row1.end());
    sort(row2.begin(), row2.end());

    vector<int> matches;
    auto itr1 = row1.begin();
    auto itr2 = row2.begin();

    while (true) {
      if (itr1 == row1.end() || itr2 == row2.end()) {
        break;
      }

      if (*itr1 == *itr2) {
        matches.push_back(*itr2);
        ++itr1;
        ++itr2;
        continue;
      }

      if (*itr1 < *itr2) {
        ++itr1;
      }
      else {
        ++itr2;
      }
    }

    string result;
    if(matches.size() == 1){
      result = to_string(*matches.begin());
    }
    else
      if (matches.size() > 1) {
        result = "Bad magician!";
      }
      else
      {
        result = "Volunteer cheated!";
      }

		cout << "Case #" << i << ": " << result << endl;
	}

	return 0;
}
