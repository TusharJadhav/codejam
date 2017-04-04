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
    unsigned long n { 0 }, result { 0 };
    bool insomnia { false };
    bitset<10> data;
    unordered_set<unsigned long> dict;
    
    getline(cin, line);
    
    stringstream(line) >> n;
    
    while(!data.all()){
      result += n;
      
      if(dict.find(result) != dict.end()){
        insomnia = true;
        break;
      }
      
      dict.insert(result);
      
      string str_result = to_string(result);
      
      for(const auto& ch_num : str_result){
        int num = (ch_num - '0');
        data.set(num);
      }
    }
    
    cout << "Case #" << i << ": " ;
    if(insomnia)
      cout << "insomnia";
    else
      cout << result;
    
    cout << endl;
  }
  
  return 0;
}
