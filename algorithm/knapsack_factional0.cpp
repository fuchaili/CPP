/**************************************************************** 
 * Description: C++ program to solve fractional Knapsack Problem 实现部分背包问题
 * Author: Alex Li
 * Date: 2022-04-23 19:34:18
 * LastEditTime: 2023-06-15 17:04:45
****************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct article{
    float weight;
    int value;
    float ratio;
};

bool compare( article a, article b){	
	if(a.ratio > b.ratio)
		return true;
	else 
		return false;
}

int main(){
    int knapsack_weight,article_number;
    float result=0;
    cout<<"please input knapsack weight and article number: ";
    cin>>knapsack_weight>>article_number;
    struct article *p;
    p=new article[article_number]; 
    cout<<"please input "<<article_number<<" weight and "<<article_number<<" value of items: ";
    for (int i = 0; i < article_number; i++){
        cin>>p[i].weight>>p[i].value;
        p[i].ratio=p[i].value/p[i].weight;
    }

    sort(p,p+article_number,compare);

    for (int i = 0; i < article_number; i++){
        if(p[i].weight<=knapsack_weight){
           knapsack_weight=knapsack_weight-p[i].weight;
           result=result+p[i].value;
        }
        else{
            result=result+knapsack_weight*p[i].ratio;
            break;
        }
    }
    cout<<result;
}