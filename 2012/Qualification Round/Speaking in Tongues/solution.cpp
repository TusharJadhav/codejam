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
  string line;
  int test_cases;
  getline(cin, line);
  stringstream(line) >> test_cases;
  unordered_map<char, char> dict{{'q','z'}, {'g','v'}, {'u','j'}, {'o','k'}, {'f','c'}, {'w','f'}, {'t','w'}, {'b','h'}, {'i','d'}, {'r','t'}, {'a','y'}, {'n','b'}, {'v','p'}, {'x','m'}, {'d','s'}, {'k','i'}, {'c','e'}, {'s','n'}, {'h','x'}, {'y','a'}, {'m','l'}, {'l','g'}, {'p','r'}, {'j','u'}, {'e','o'}, {'z', 'q'}};
  
  for (int i = 1; i <= test_cases; ++i) {
    cout << "Case #" << i << ": ";
    
    getline(cin, line);
    
    for(const auto& ch : line){
      if(ch == ' '){
        cout << ' ';
        continue;
      }
      
      cout << dict[ch];
    }
    
    cout << endl;
  }
  
  return 0;
}
