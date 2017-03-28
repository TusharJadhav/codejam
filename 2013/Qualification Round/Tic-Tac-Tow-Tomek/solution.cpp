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

bool is_row_winner(const vector<vector<char>>& board, char ch, int row){
  if((board[row][0] == ch || board[row][0] == 'T') &&
     (board[row][1] == ch || board[row][1] == 'T') &&
     (board[row][2] == ch || board[row][2] == 'T') &&
     (board[row][3] == ch || board[row][3] == 'T')){
    return true;
  }
  
  return false;
}

bool is_column_winner(const vector<vector<char>>& board, char ch, int col){
  if((board[0][col] == ch || board[0][col] == 'T') &&
     (board[1][col] == ch || board[1][col] == 'T') &&
     (board[2][col] == ch || board[2][col] == 'T') &&
     (board[3][col] == ch || board[3][col] == 'T')){
    return true;
  }
  
  return false;
}

bool is_diagonal_winner(const vector<vector<char>>& board, char ch){
  if((board[0][0] == ch || board[0][0] == 'T') &&
     (board[1][1] == ch || board[1][1] == 'T') &&
     (board[2][2] == ch || board[2][2] == 'T') &&
     (board[3][3] == ch || board[3][3] == 'T')){
    return true;
  }
  
  if((board[0][3] == ch || board[0][3] == 'T') &&
     (board[1][2] == ch || board[1][2] == 'T') &&
     (board[2][1] == ch || board[2][1] == 'T') &&
     (board[3][0] == ch || board[3][0] == 'T')){
    return true;
  }
  
  return false;
}

int main()
{
//  ifstream arq(getenv("MYARQ"));
//  cin.rdbuf(arq.rdbuf());
  
  string line;
  int test_cases;
  getline(cin, line);
  stringstream(line) >> test_cases;
  
  for (int i = 1; i <= test_cases; ++i) {
    bool contains_dot{ false };
    vector<vector<char>> board(4, vector<char>(4, '.'));
    
    for(int i = 0; i < 4; ++i){
      getline(cin, line);
      stringstream ss(line);
      
      for(int j = 0; j < 4; ++j){
        ss >> board[i][j];
        if(board[i][j] == '.'){
          contains_dot = true;
        }
      }
    }
    
    getline(cin, line);
    
    bool found_result = false;
    string result;
    
    if(!found_result && is_row_winner(board, 'X', 0)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_row_winner(board, 'X', 1)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_row_winner(board, 'X', 2)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_row_winner(board, 'X', 3)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_row_winner(board, 'O', 0)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_row_winner(board, 'O', 1)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_row_winner(board, 'O', 2)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_row_winner(board, 'O', 3)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_column_winner(board, 'X', 0)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_column_winner(board, 'X', 1)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_column_winner(board, 'X', 2)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_column_winner(board, 'X', 3)){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_column_winner(board, 'O', 0)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_column_winner(board, 'O', 1)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_column_winner(board, 'O', 2)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_column_winner(board, 'O', 3)){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result && is_diagonal_winner(board, 'X')){
      found_result = true;
      result = "X won";
    }
    
    if(!found_result && is_diagonal_winner(board, 'O')){
      found_result = true;
      result = "O won";
    }
    
    if(!found_result) {
      if(contains_dot){
        result = "Game has not completed";
      }
      else {
        result = "Draw";
      }
    }
    
    cout << "Case #" << i << ": " << result << endl;
  }
  
  return 0;
}
