# Stock Order Execution

Created Time: Feb 17, 2021 8:11 AM
Last edited time: Feb 18, 2021 7:45 AM
Points: 1500
Pomos (25 mins): 2
Source: https://binarysearch.com/contest/Weekly-Contest-46-Wgbjnsf4qw?questionsetIndex=2
Status: waiting

You are given a two-dimensional list of integers `orders`. Each element `orders[i]` contains `[price, amount, type]` meaning that there's an order to either buy `(type = 0)` or sell `(type = 1)` `amount` number of stocks at price `price`.

A buy order can be executed if there is a sell order with a a price that is less than or equal to the price of the buy order. Similarly, a sell order can be executed if there is a corresponding buy order with a price that is greater than or equal to the price of the sell order. An order should be executed immediately if possible but if it's not possible, you should keep track of this order to be processed at a later time. You should fill the order at the best price for the user. That is, a buy order should execute at the lowest possible price while a sell order should sell at the highest possible price when the order is requested.

Return the total number of stocks that will be executed.

**Constraints**

- `0 ≤ n ≤ 200,000` where `n` is the length of `orders`

### **Example 1**

****Input****

`orders = [
    [150, 5, 0],
    [190, 1, 1],
    [200, 1, 1],
    [100, 9, 0],
    [140, 8, 1],
    [210, 4, 0]
]`

****Output****

`9`

### **Explanation**

- `price = 150`, `amount = 5`, `BUY`
- `price = 190`, `amount = 1`, `SELL`
- `price = 200`, `amount = 1`, `SELL`
- `price = 100`, `amount = 9`, `BUY`
- `price = 140`, `amount = 8`, `SELL` - We match with the `5` stocks at price `150`
- `price = 210`, `amount = 4`, `BUY` - We match with the `3` stock at price `140`, and `1` stock at price `190`

---

I am getting run time error for the below code. Need to figure out the main reason. 

```cpp
int solve(vector<vector<int>>& orders) {
    int ans = 0;
    set<pair<int, int>> buys, sells;
    for (int i = 0; i < orders.size(); i++)
    {
        cout << "test " << i << endl;
        // buy case
        if (orders[i][2] == 0)
        {
            cout << "test buy" << endl;
            int price = orders[i][0], amount = orders[i][1]; 
            while (amount and sells.size() and sells.begin()->first <= price)
            {
                pair<int, int> p = *sells.begin();
                sells.erase(sells.begin());
                ans += min(amount, p.second);
                if (amount >= p.second)
                {
                    amount -= p.second;
                }
                else
                {
                    p.second -= amount; 
                    amount = 0;
                    sells.insert(p);
                }
            }
            if (amount) buys.insert({price, amount});
            cout << "test buy complete" << endl;
        }
        else 
        {
            cout << "test sell" << endl;
            int price = orders[i][0], amount = orders[i][1]; 
            while (amount and buys.size() and prev(buys.end())->first >= price)
            {
                pair<int, int> p = *prev(buys.end());
                sells.erase(prev(buys.end()));
                ans += min(amount, p.second);
                if (amount >= p.second)
                {
                    amount -= p.second;
                }
                else
                {
                    p.second -= amount;
                    amount = 0; 
                    buys.insert(p);
                }
            }
            if (amount) sells.insert({price, amount});
            cout << "test sell complete" << endl;
        }
    }
    cout << "end " << ans << endl;
    return ans; 
}
```