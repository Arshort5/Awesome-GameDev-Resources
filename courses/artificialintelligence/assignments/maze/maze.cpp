#include "stack"
#include "iostream"

using  namespace std;


//int randVec[] = {72, 99, 56, 34, 43, 62, 31, 4, 70, 22, 6, 65, 96, 71, 29, 9, 98, 41, 90, 7, 30, 3, 97, 49, 63, 88, 47, 82, 91, 54, 74, 2, 86, 14, 58, 35, 89, 11, 10, 60, 28, 21, 52, 50, 55, 69, 76, 94, 23, 66, 15, 57, 44, 18, 67, 5, 24, 33, 77, 53, 51, 59, 20, 42, 80, 61, 1, 0, 38, 64, 45, 92, 46, 79, 93, 95, 37, 40, 83, 13, 12, 78, 75, 73, 84, 81, 8, 32, 27, 19, 87, 85, 16, 25, 17, 68, 26, 39, 48, 36};
//int randIndex = 0;

struct Node{
  Node* top, *right, *bottom, *left;
  bool top_wall = true, right_wall = true, bottom_wall = true, left_wall = true;
  int x, y;
};

/*
int myrand() {
  int old = randIndex;
  randIndex++;
  randIndex %= 100;
  return randVec[old];
}
*/

/*
void CreateBoard(Node board[], int x, int y)
{
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      Node temp;
      temp.x  = i;
      temp.y  = j;
      board [j * x + i] = temp;
    }
  }

  for (int i = 0; i < x; ++i)
  {
    for (int j = 0; j < y; ++j)
    {
      if ((j-1) * x + (i) >=0)
      {
        board[j* x +i].top = &board[(j-1) * x + (i)];
      }
      if ((j+1) * x + (i) < x*y)
      {
        board[j* x +i].bottom = &board[(j+1) * x + (i)];
      }
      if ((j) * x +(i+1) < x*y && i+1 < x)
      {
        board[j* x +i].right = &board[(j) * x + (i+1)];
      }
      if ((j) * x + (i-1) >=0 && i -1 >=0)
        {
        board[j* x +i].left = &board[(j) * x + (i-1)];

        }


    }
  }
}
*/

int main()
{
  int x,y,index;
  cin >> x >> y >> index;
cout << x << y << index;

  stack<Node> stk;
  stk.emplace();

  while(!stk.empty())
  {



  }

return 0;
}




// to navigate and chose which neighbor to visit in the visitables vector, you have to follow something like this:
// breakWall breaks the wall between 2 points
// stk is stack data structure
// boardlimits is the limits for the size of the board
// getVisitableNeightbors gives me a vector of directions that can be visted. up, down, left, right
// getNeighbor gets the neighbor in that direction
/*void MyLoop() {
stack<Node> stk;
stk.emplace(0,0); // bootstrap case
  while (!stk.empty()) {
    // visit the top
    board[stk.top().y][stk.top().x].visited = true;
    auto visitables = getVisitableNeightbors(stk.top(), boardlimits);
    if (visitables.empty())
      stk.pop();  // backtrack
    else if (visitables.size() == 1) {
      // no need to call rand for visitables.
      breakWall(stk.top(), visitables[0]);
      auto n = getNeighbor(stk.top(), visitables[0]);
      stk.push(n);
    } else {
      // get the rand to get the random one to break the wall
      int i = myrand() % visitables.size();
      breakWall(stk.top(), visitables[i]);
      auto n = getNeighbor(stk.top(), visitables[i]);
      stk.push(n);
    }
  }
}
 */