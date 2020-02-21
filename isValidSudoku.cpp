#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {        
        for (int i = 0; i < 9; i++) {
            set<char> row, col;
            for (int j = 0; j < 9; j++) {
                // already exist -> cannot insert
                if ( board[i][j] != '.' && !row.insert(board[i][j]).second )
                    return false;
                if ( board[j][i] != '.' && !col.insert(board[j][i]).second )
                    return false;
            }
        }
        
        for (int p = 0; p < 3; p++) 
            for (int q = 0; q < 3; q++) {
            set<char> square;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j <3; j++) 
                    if ( board[p*3 + i][q*3 + j] != '.' && !square.insert(board[p*3 + i][q*3 + j]).second )
                        return false;
        }
        return true;
    }
};

int main()
{
    Solution S;
    // need 9*9 input 
    //cout << S.isValidSudoku(a) << endl;
    return 0;
}