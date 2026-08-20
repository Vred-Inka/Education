#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <set>
using namespace std;

namespace aSearch
{
#define ROW 2
#define COL 4    
typedef std::pair<int, int> Point;
typedef std::pair<double, Point> sPoint;
typedef std::vector<vector<int>> Grid;

    struct Cell
    {
        int m_Parent_i{0};
        int m_Parent_j{0};

        double f{0.0}, g{0.0}, h {0.0};
    };

    inline bool isValid(const Point& point)
    {
        return (point.first >= 0) && (point.first < ROW) && (point.second >= 0) && (point.second < COL);
    }
    inline bool isValid(int row, int col)
    {
        return (row >= 0) && (row < ROW) && (col>= 0) && (col < COL);
    }    
    inline bool isBlocked(Grid& grid, const Point& point)
    {
        return grid[point.first][point.second] == 1;
    }
    inline bool isBlocked(Grid& grid, int row, int col)
    {
        return grid[row][col] == 1;
    }
    inline bool isDestination(const Point& point, const Point& dest)
    {
        return point.first == dest.first && point.second == dest.second;
    }
    inline bool isDestination(int row, int col, const Point& dest)
    {
        return row == dest.first && col == dest.second;
    }
    inline double calculateHValue(int row, int col, const Point& dest)
    {
       return (double)sqrt(row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second);
    }

    static int manhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    static void tracePath(Cell cellDetails[][COL], const Point& dest) // Cell array?
    {
        printf("\nThe Path is ");
        int row = dest.first;
        int col = dest.second;

        std::stack<Point> Path;

        while (! (cellDetails[row][col].m_Parent_i == row && cellDetails[row][col].m_Parent_j == col))
        {
            Path.push(std::make_pair(row, col));
            int tmp_row = cellDetails[row][col].m_Parent_i;
            int tmp_col = cellDetails[row][col].m_Parent_j;
            row = tmp_row;
            col = tmp_col;
        }

        Path.push(std::make_pair(row, col));
        while (!Path.empty())
        {
            Point p = Path.top();
            Path.pop();
            cout<< "[" << p.first << "," << p.second << "] ";
        }

        return;
    }
   
   /* static vector<pair<int, int>> directions = {
        {-1,-1},{0,-1} ,{1,-1},
        {-1, 0},           {1, 0},
        {-1, 1},{0, 1}, {1, 1}
    };
    */

   /* 
    vector<pair<int, int>> directions = {
               {0,1},
        {1, 0},      {0, -1},
                {-1, 0}
    };
    */


    static bool preCheck(Grid& grid, Point source,  Point dest)
    {
        if (!isValid(source))
        {
            printf("Source is invalid\n");
            return false;
        }

        if (!isValid(dest))
        {
            printf("Destination is invalid\n");
            return false;
        }

        if (isBlocked(grid, source) || isBlocked(grid, dest))
        {
            printf("Source or destination is blocked\n");
            return false;
        }

        if (isDestination(source, dest))
        {
            printf("Already on destination\n");
            return false;
        }

        return true;
    }
    
    static void aStarSearch(Grid& grid, Point source,  Point dest)
    {
        vector<pair<int, int>> directions = {
            {0,1},
     {1, 0},      {0, -1},
             {-1, 0}
        };
        
        if (!preCheck(grid, source, dest))
        {
            return;
        }        

        bool closedList[ROW][COL];
        memset(closedList, false, sizeof(closedList));

        Cell cellDetails[ROW][COL];

        int i, j;
        for (i = 0; i < ROW; i++)
        {
            for (j = 0; j < COL; j++)
            {
                cellDetails[i][j].f = FLT_MAX;
                cellDetails[i][j].g = FLT_MAX;
                cellDetails[i][j].h = FLT_MAX;
                cellDetails[i][j].m_Parent_i = -1;
                cellDetails[i][j].m_Parent_j = -1;
                std::cout << grid[i][j]<< " ";
            }

            std::cout << endl;
        }

        i = source.first;
        j = source.second;
        cellDetails[i][j].f = 0.0;
        cellDetails[i][j].g = 0.0;
        cellDetails[i][j].h = manhattanDistance(i, j, dest.first, dest.second);
        cellDetails[i][j].m_Parent_i = i;
        cellDetails[i][j].m_Parent_j = j;

        std::set<sPoint> openList;
        openList.insert(make_pair(cellDetails[i][j].h, make_pair(i,j)));

        bool foundDest = false;
        while (!openList.empty())
        {
            sPoint p = *openList.begin();
            openList.erase(openList.begin());

            i = p.second.first;
            j = p.second.second;
            closedList[i][j] = true;

            for (Point& direction :  directions)
            {
                if (foundDest)
                    continue;
                
                int nI = i + direction.first;
                int nJ = j + direction.second;

                if (!isValid(nI, nJ))
                    continue;
                
                if (isDestination(nI, nJ, dest))
                {
                    cellDetails[nI][nJ].m_Parent_i = i;
                    cellDetails[nI][nJ].m_Parent_j = j;
                    printf("The destination call is found\n");
                    tracePath(cellDetails, dest);
                    foundDest = true;
                }
                else if (!closedList[nI][nJ] && !isBlocked(grid, nI, nJ))
                {
                    int cellCost = grid[nI][nJ] == 0 ? 1 : 5;
                    int gNew = cellCost + p.first;
                    //double hNew = calculateHValue(in, jn, dest);
                    double hNew = manhattanDistance(nI, nJ, dest.first, dest.second);
                    double fNew = gNew + hNew;

                    //if (cellDetails[nI][nJ].f == FLT_MAX || cellDetails[nI][nJ].f > fNew)
                    {
                        openList.insert(make_pair(fNew, make_pair(nI, nJ)));

                        cellDetails[nI][nJ].f = fNew;
                        cellDetails[nI][nJ].g = gNew;
                        cellDetails[nI][nJ].h = hNew;
                        cellDetails[nI][nJ].m_Parent_i = i;
                        cellDetails[nI][nJ].m_Parent_j = j;
                    }
                }
            }
        }

        if (foundDest == false)
            printf("Failed to find the Destination Cell\n");

        return;     
    }
    
    static int pathSearchAStar()
    {
        vector<vector<int>> grid = {
         {0,2,0,1},
         {0,0,2,0}};   

        Point source =  make_pair(1, 0);
        Point dest =  make_pair(1, 3);

        aStarSearch(grid, source, dest);
    
        // Read and parse inputs
        // Call solution and handle output
        return 0;
    }
}//namespace aSEarch

 

/*
Input:
grid = [[0,2,0,1],[0,0,2,0]], start = [0,1], goal = [3,1]
›
Output:
[6,[[0,1],[1,1],[2,1],[3,1]],[[0,1],[1,1],[2,1],[3,1]]]
*/



