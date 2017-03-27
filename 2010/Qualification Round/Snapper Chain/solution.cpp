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
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  string line;
  int test_cases;
  getline(cin, line);
  stringstream(line) >> test_cases;
  
  for (int i = 1; i <= test_cases; ++i) {
    int n{0}, k{0};
    
    getline(cin, line);
    stringstream(line) >> n >> k;
    
    bool flag = true;
    for(int m = 0; m < n; ++m){
      if((k & 1) != 1){
        flag = false;
        break;
      }
    
      k >>= 1;
    }
    
    string result = (flag == true) ? "ON" : "OFF";
    cout << "Case #" << i << ": " << result << endl;
  }
  
  return 0;
}
