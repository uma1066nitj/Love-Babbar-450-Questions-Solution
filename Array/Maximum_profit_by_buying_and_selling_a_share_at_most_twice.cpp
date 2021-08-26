/* Question :- Maximum profit by buying and selling a share at most twice
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

Examples: 

Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80

Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
Output:  100
Trader earns 100 as sum of 28 and 72
Buy at price 2, sell at 30, buy at 8 and sell at 80

Input:   price[] = {100, 30, 15, 10, 8, 25, 80};
Output:  72
Buy at price 8 and sell at 80.

Input:   price[] = {90, 80, 70, 60, 50}
Output:  0
Not possible to earn.
*/


//code with O(N) complexity
#include <iostream>
#include<string>
using namespace std;

int profitMax(int price[], int n){
    int* profit = new int[n];
    for(int i=0;i<n;i++){
        profit[i] = 0;
    }
    int maxPrice = price[n-1];
    for(int i=n-2;i>=0;i--){
        if(price[i] > maxPrice){
            maxPrice = price[i];
        }
        
        profit[i] = max(profit[i+1], maxPrice - price[i]);
    }
    int minPrice = price[0];
    for(int i =1;i<n;i++){
        if(profit[i] < minPrice){
            minPrice = profit[i];
        }
        profit[i] = max(profit[i-1], profit[i]+(price[i] - minPrice));
    }
    int result = profit[n-1];
    delete[] profit;
    return result;
}
int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price) / sizeof(price[0]);
    
    cout<<"Maximum Profit: "<<profitMax(price,n);
    return 0;
}