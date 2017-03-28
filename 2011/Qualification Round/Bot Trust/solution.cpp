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
//  ifstream arg(getenv("MYARQ"));
//  cin.rdbuf(arg.rdbuf());
  
  string line;
  int test_cases;
  getline(cin, line);
  stringstream(line) >> test_cases;
  
  for (int i = 1; i <= test_cases; ++i) {
    int N { 0 }, orange_pos { 1 }, blue_pos { 1 }, orange_time { 0 }, blue_time { 0 }, total_time { 0 };
    
    getline(cin, line);
    stringstream ss(line);
    
    ss >> N;
    
    for (int index = 0; index < N; ++index) {
      char type;
      int target;
      
      ss >> type >> target;
      
      if (type == 'O') {
        orange_time += abs(orange_pos - target);
        orange_time = total_time = max(total_time, orange_time) + 1;
        orange_pos = target;
      }
      else {
        blue_time += abs(blue_pos - target);
        blue_time = total_time = max(total_time, blue_time) + 1;
        blue_pos = target;
      }
    }
    
    cout << "Case #" << i << ": " << total_time << endl;
  }
  
  return 0;
}
