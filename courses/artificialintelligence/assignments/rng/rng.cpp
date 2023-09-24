#include "iostream"
using  namespace  std;

int main(){
unsigned int S,N, value;
signed int  min,max;
cin >> S;
cin >> N;
cin >> min;
cin >> max;

if (min > max)
{
  int temp = min;
  min = max;
  max = temp;
}

for (int i = 0; i < N; ++i) {
  S = S xor (S << 13);
  S = S xor (S >> 17);
  S =S xor (S << 5);
  value = min + (S % (max - min +1));
  cout << value << endl;
}

}