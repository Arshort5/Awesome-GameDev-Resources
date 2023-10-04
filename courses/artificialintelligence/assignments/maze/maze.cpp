#include "stack"
#include "iostream"
#include "vector"
using  namespace std;


int randVec[] = {72, 99, 56, 34, 43, 62, 31, 4, 70, 22, 6, 65, 96, 71, 29, 9, 98, 41, 90, 7, 30, 3, 97, 49, 63, 88, 47, 82, 91, 54, 74, 2, 86, 14, 58, 35, 89, 11, 10, 60, 28, 21, 52, 50, 55, 69, 76, 94, 23, 66, 15, 57, 44, 18, 67, 5, 24, 33, 77, 53, 51, 59, 20, 42, 80, 61, 1, 0, 38, 64, 45, 92, 46, 79, 93, 95, 37, 40, 83, 13, 12, 78, 75, 73, 84, 81, 8, 32, 27, 19, 87, 85, 16, 25, 17, 68, 26, 39, 48, 36};
int randIndex = 0;




int myrand() {
  int old = randIndex;
  randIndex++;
  randIndex %= 100;
  return randVec[old];
}



struct node{
  node* top = nullptr, *right= nullptr, *bottom= nullptr, *left= nullptr;
  bool top_wall = true, right_wall = true, bottom_wall = true, left_wall = true;
  int x, y;
  bool visited = false;
};

void CreateBoard(node board[], int x, int y)
{
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      node temp;
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


void DisplayBoard(const node board[], int x, int y)
{
  for (int i = 0; i < x; ++i) {
    cout << " " << "_";
  }
  cout << "  " << endl;
  for (int i = 0; i < y; ++i) {

    for (int j = 0; j < x; ++j) {
        if (board[i * x + j].left_wall) {
        cout << "|";
        } else {
        cout << " ";
        }

        if (board[i * x + j].bottom_wall) {
        cout << "_";
        } else {
        cout << " ";
        }
    }
    cout <<"| " << endl;
  }
}

vector<node> VisitableNeighbors(node inNode)
{
  vector<node> neighbors;

  if (inNode.top != nullptr && !inNode.top->visited)
  {
   neighbors.push_back(*inNode.top);
  }

  if (inNode.right != nullptr&& !inNode.right->visited)
  {
   neighbors.push_back(*inNode.right);
  }

  if (inNode.bottom != nullptr&& !inNode.bottom->visited)
  {
   neighbors.push_back(*inNode.bottom);
  }

  if (inNode.left != nullptr&& !inNode.left->visited)
  {
   neighbors.push_back(*inNode.left);

  }

  return neighbors;
}

void BreakWall(node origin, node to,node board[], int x, int y)
{
  if (origin.x < to.x)
  {
    board[origin.y * x + origin.x].right_wall = false;
    board[to.y * x + to.x].left_wall = false;
  }
  else if (origin.x > to.x)
  {
    board[origin.y * x + origin.x].left_wall = false;
    board[to.y * x + to.x].right_wall = false;
  }
  else if (origin.y < to.y)
  {
    board[origin.y * x + origin.x].bottom_wall = false;
    board[to.y * x + to.x].top_wall = false;
  }
  else if (origin.y > to.y)
  {
    board[origin.y * x + origin.x].top_wall = false;
    board[to.y * x + to.x].bottom_wall = false;

  }
}

int main()
{
  int x,y;

  cin >> x >> y >> randIndex;
  node board[x*y];
  CreateBoard(board,x,y);
 // DisplayBoard(board ,x,y);
  stack<node> stk;
  stk.push(board[0]);


while(!stk.empty())
  {
    board[stk.top().y * x + stk.top().x].visited = true;
    vector<node> visitables = VisitableNeighbors(stk.top());
    if (visitables.empty())
    {

        stk.pop();
    }
    else if (visitables.size() == 1)
    {
        BreakWall(stk.top(), visitables[0], board,x,y);
        auto n = visitables.front();
        stk.push(n);
    }
    else
    {
        int i = myrand() % visitables.size();
        BreakWall(stk.top(), visitables[i], board,x,y);
        auto n =  visitables[i];
        stk.push(n);
    }
 }

 DisplayBoard(board ,x,y);
return 0;
}
