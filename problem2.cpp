// In a candy store, there are different types of candies available and prices[i] represent the price of  ith types of candies. You are now provided with an attractive offer.
// For every candy you buy from the store, you can get up to k other different candies for free. Find the minimum and maximum amount of money needed to buy all the candies.
// Note: In both cases, you must take the maximum number of free candies possible during each purchase.
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> minMaxCandy(vector<int>& prices, int k) {
    int N = prices.size();
    int left = 0;
    int right = N-1;
    
    int minCost = 0;
    int maxCost = 0;

    sort(prices.begin(),prices.end());

    // finding the minimum cost
    while(left<=right){
        minCost+=prices[left];
        left++;
        right-=k;
    }

    // finding the max cost
    left = 0;
    right = N-1;

    while (left<=right)
    {
        maxCost+=prices[right];
        right--;
        left += k;
    }
    return {minCost,maxCost};
}