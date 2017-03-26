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
  //ifstream arq(getenv("MYARQ"));
  //cin.rdbuf(arq.rdbuf());
  
  int test_cases{0};
  string line;
  getline(cin, line);
  stringstream(line) >> test_cases;
  
  for (int i = 1; i <= test_cases; ++i) {
    int s{0};
    getline(cin, line);
    stringstream(line) >> s;
    unordered_set<string> search_engines;
    
    for(int j = 0; j < s; ++j){
      getline(cin, line);
      search_engines.insert(line);
    }
    
    int result{0};
    unordered_set<string> engines = search_engines;
    
    int q{0};
    getline(cin, line);
    stringstream(line) >> q;
    
    for(int k = 0; k < q; ++k){
      getline(cin, line);
    
      auto found = engines.find(line);
      if(found == engines.end()){
        continue;
      }
      
      if(engines.size() == 1){
        ++result;
        engines.clear();
        engines = search_engines;
        found = engines.find(line);
      }
      
      engines.erase(found);
    }
    
    cout << "Case #" << i << ": " << result << endl;
  }
  
  return 0;
}
