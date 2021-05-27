/**
 *
 * @brief Fractional Knapsack: A greedy approach
 * Given with a container / knapsack with limited capacity and some objects
 * with finite weight and profit value, Task is to fill the container
 * or knapsack in such a way that the price of knapsack is maximum
 *
 * price of knapsack is the sum of profits of all the objects that it
 * contains.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

// given with   objects: 
//              profit :
//              weights:
//
//              constraint is limited knapsack capacity 
//
//              objective is to maximize profit

int main() {
  // n: number of objects
  // m: capacity of knapsack
  int n, m;
  std::cin >> n >> m;

  std::vector<float> objects(n, 0);
  std::vector<float> profit(n, 0);

  for(auto &obj: objects)
    std::cin >> obj;

  for(auto &x: profit)
    std::cin >> x;

  std::map<float, std::pair<float, float>, std::greater<float>> profitByWeight
    = [=] () {
      std::map<float, std::pair<float, float>, std::greater<float>> temp;
      for(int i = 0; i < n; i++) {
        temp[profit[i] / objects[i]] = std::make_pair(profit[i], objects[i]);
      }
      return temp;
    }();

  float gain = 0.0f;
  for(auto x: profitByWeight) {
    // if there is space in knapsack
    if (m > 0) {
      // object can be taken completely
      if (m >= x.second.second) {
        gain += x.second.first;
        m -= x.second.second;
      }
      // or can be taken in fraction
      else {
        gain += m * x.first;
        break;
      }
    }
  }
  std::cout << "Max Profit: " << gain << "\n";
  return 0;
}
