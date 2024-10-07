#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

class Grid
{
private: 
    bool **grid;
    int rows;
    int cols; 
public:

    // Constructor
    Grid(int r, int c) : rows(r), cols(c)
    {
        grid = new bool *[rows];
        for (int i = 0; i < rows; ++i)
        {
            grid[i] = new bool[cols];
            fill(grid[i], grid[i] + cols, false); // Initialize with zeros
        }
        generateObstacles();
    }

    // Destructor 
    ~Grid()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] grid[i];
        }
        delete[] grid;
    }
    
    void generateObstacles()
    {
        srand(time(0));                       // Seeding random number generator
        int numObstacles = rows * cols * 0.6; // Calculating number of obstacles
        for (int i = 0; i < numObstacles; ++i)
        {
            int x = rand() % rows;
            int y = rand() % cols;
            if(grid[x][y] == true)
            {
                i--;
            }
            grid[x][y] = true; // Setting obstacle 
        }
    }
    
    // Depth - First Search Main Algorithm
    bool pathExists(int startX, int startY, int endX, int endY)
    {
        if (startX < 0 || startX >= rows || startY < 0 || startY >= cols ||
            endX < 0 || endX >= rows || endY < 0 || endY >= cols ||
            grid[startX][startY] || grid[endX][endY])
        {
            cout <<"\nEither values are invalid OR starting or ending point is 1, not 0!\n";
            return false;
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        stack<pair<int, int>> s;
        s.push({startX, startY}); 
        grid[startX][startY] = true; 

        while (!s.empty())
        {
            int x = s.top().first;
            int y = s.top().second;
            s.pop();

            if (x == endX && y == endY) 
            {
                return true;
            }

            for (auto &dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !grid[newX][newY])
                {
                    s.push({newX, newY});
                    grid[newX][newY] = true; 
                }
            }
        }

        return false;
    }

    void displayGrid()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << (grid[i][j] ? "1" : "0") << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Grid grid(rows, cols);
    grid.displayGrid();
    int startX, startY, endX, endY;

    cout << "Enter starting point (x y): ";
    cin >> startX >> startY;
    cout << "Enter ending point (x y): ";
    cin >> endX >> endY;

    grid.displayGrid();
    if (grid.pathExists(startX, startY, endX, endY))
    {
        cout << "\n*** Path exists! ***" << endl;
    }
    else
    {
        cout << "\n*** No path exists! ***" << endl;
    }

    return 0;
}
