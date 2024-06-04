#include<iostream>
#include<string>

using namespace std;

bool cells_in(string cells[4], string a)
{
    for(int i=0;i<4;i++)
    {
        if(cells[i]==a)
            return false;
    }
    return true;
}


string num_to_cell(int row, int col) {
    char colChar = 'A' + col;
    row++;
    string cell = "";
    cell += colChar;
    cell += to_string(row);

    return cell;
}

 void def(string cells[4], int table[2][2], int rows) {
  int z=0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      if (table[i][j] == 3 || table[i][j] == 4) continue;
      if (i - 1 >= 0 && cells_in(cells, num_to_cell(i - 1, j)) && table[i - 1][j] != 3 && table[i - 1][j] != 4) {
        table[i][j] += 1;
        table[i - 1][j] += 1;
      }
      if (i + 1 < rows && cells_in(cells, num_to_cell(i + 1, j)) && table[i + 1][j] != 3 && table[i + 1][j] != 4) {
        table[i][j] += 1;
        table[i + 1][j] += 1;
      }
      if (j - 1 >= 0 && cells_in(cells, num_to_cell(i, j-1))&& table[i][j - 1] != 3 && table[i][j - 1] != 4) {
        table[i][j] += 1;
        table[i][j - 1] += 1;
      }
      if (j + 1 < rows && cells_in(cells, num_to_cell(i, j+1))&& table[i][j + 1] != 3 && table[i][j + 1] != 4) {
        table[i][j] += 1;
        table[i][j + 1] += 1;
      }
      cells[z]=num_to_cell(i, j);
      z++;
  }
  cells[4] = {' ',' ',' ',' '};
}
}

int main()
{
    int table[2][2];
    string cells[4]={" "," "," "," "};
    def(cells, table, 2);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<table[i][j];
        }
        cout<<endl;
    }
    return 0;
}
