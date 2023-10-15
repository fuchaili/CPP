#include <iostream>
using namespace std;
void Move(int n, char A, char B, char C){
   if (n == 1) {       //圆盘只有一个时，只需将其从A塔移到C塔
      cout << "move " << n << " from " << A << " to " << C << endl;
          }  
           else  {     
              Move(n - 1, A, C, B);//递归，把A塔上编号1~n-1的圆盘移到B上，以C为辅助塔
                  cout << "move " << n << " from " << A << " to " << C << endl;//把A塔上编号为n的圆盘移到C上
                    Move(n - 1, B, A, C);//递归，把B塔上编号1~n-1的圆盘移到C上，以A为辅助塔   
         }
         }
int main() { 
    int n;
        cin>>n;
            Move(n, 'A', 'B', 'C');
               return 0;
               }
