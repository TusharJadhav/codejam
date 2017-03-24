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
  
  string line;
  int length, no_of_words, test_cases;
  getline(cin, line);
  stringstream(line) >> length >> no_of_words >> test_cases;
  
  vector<string> words;
  for (int i = 1; i <= no_of_words; ++i) {
    getline(cin, line);
    string word;
    stringstream(line) >> word;
    
    words.push_back(word);
  }
  
  for (int i = 1; i <= test_cases; ++i) {
    vector<vector<bool>> pattern(length, vector<bool>(26, false));
    getline(cin, line);
    size_t index = 0;
    bool found_brace = false;
    
    for(const auto& ch : line){
      if(ch == '('){
        found_brace = true;
      }
      else
        if(ch == ')'){
          found_brace = false;
          ++index;
        }
        else{
          if(found_brace){
            pattern[index][ch - 'a'] = true;
          }
          else{
            pattern[index++][ch - 'a'] = true;
          }
        }
    }
    
    int result = 0;
    
    for(const auto& word : words){
      index = 0;
      bool ok = true;
      
      for(const auto& ch : word){
        if(!pattern[index++][ch - 'a']){
          ok = false;
          break;
        }
      }
      
      if(ok)
        ++result;
    }
    
    cout << "Case #" << i << ": " << result << endl;
  }
  
  return 0;
}
