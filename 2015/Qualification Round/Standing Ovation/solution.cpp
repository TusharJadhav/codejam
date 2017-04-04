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
    int max_shyness;
    string temp;
    getline(cin, line);
    stringstream(line) >> max_shyness >> temp;
    vector<int> input;
    for (const auto& ch : temp) {
      input.push_back(ch - '0');
    }
    
    long additonal_invites{ 0 }, current_standing{ 0 }, index{ 0 };
    for(const auto& people : input) {
      if (current_standing < index) {
        additonal_invites += (index - current_standing);
        current_standing += (index - current_standing);
      }
      
      current_standing += people;
      ++index;
    }

		cout << "Case #" << i << ": " << additonal_invites << endl;
	}

	return 0;
}
