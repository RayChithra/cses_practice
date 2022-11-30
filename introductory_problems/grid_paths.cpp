#include <iostream>
#include <vector>

using namespace std;

bool travelled[7][7];
vector<string> paths;

void initialize()
{
    for(int row = 0; row < 7; row++)
        for(int col = 0; col < 7; col++)
            travelled[row][col] = false;
}

bool check_up(int row, int col)
{
    if((row > 0) && (!travelled[row - 1][col]))
    {
        travelled[row - 1][col] = true;
        return true;
    }
    else 
        return false;
}

bool check_down(int row, int col)
{
    if((row < 6) && (!travelled[row + 1][col]))
    {
        travelled[row + 1][col] = true;
        return true;
    }
    else 
        return false;
}

bool check_left(int row, int col)
{
    if((col > 0) && (!travelled[row][col - 1]))
    {
        travelled[row][col - 1] = true;
        return true;
    }
    else 
        return false;
}

bool check_right(int row, int col)
{
    if((col < 6) && (!travelled[row][col + 1]))
    {
        travelled[row][col + 1] = true;
        return true;
    }
    else 
        return false;
}

void check_path(int row, int col, string temp_path)
{
    while(row != 6 && col != 0)
    {
        if(check_up(row,col))
        {
            temp_path += 'U';
            row--;
            check_path(row,col, temp_path);
            if(temp_path.size() == 48)
                paths.push_back(temp_path);
        }
        if(check_down(row,col))
        {
            temp_path += 'D';
            row++;
            check_path(row,col, temp_path);
            if(temp_path.size() == 48)
                paths.push_back(temp_path);
        }
        if(check_right(row,col))
        {
            temp_path += 'R';
            col++;
            check_path(row,col, temp_path);
            if(temp_path.size() == 48)
                paths.push_back(temp_path);
        }
        if(check_left(row,col))
        {
            temp_path += 'L';
            col--;
            check_path(row,col, temp_path);
            if(temp_path.size() == 48)
                paths.push_back(temp_path);
        }
        if(!check_up(row,col) && !check_down(row,col) && !check_right(row,col) && !check_left(row,col))
            temp_path += '!';
        cout << temp_path << "\n";
    }
}

int main()
{
    string str = "";
    initialize();
    check_path(0, 0, str);
    for( string s : paths)
        cout << s << "\n";
    return 0;
}