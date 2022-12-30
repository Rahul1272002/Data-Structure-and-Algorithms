#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
pair<int, int> element(vector<int> arr)
{
    unordered_map<int, int> mejority;
    for (auto i : arr)
    {
        if (mejority.find(i) == mejority.end())
        {
            mejority.insert(make_pair(i, 1));
        }
        else
        {
            int x = mejority[i];
            mejority[i] = x + 1;
        }
    }
    auto it = mejority.begin();
    int max = it->second;
    int ans = it->first;
    for (auto i : mejority)
    {
        if (i.second >= max)
        {
            max = i.second;
            ans = i.first;
        }
    }
    
    if (max > (arr.size() / 2))
        return make_pair(ans, max);
    else
        return make_pair(-1, -1);
}
int main()
{
    vector<int> arr = {5, 1, 4, 1, 1};
    pair<int, int> res = element(arr);
    if (res.first == -1 && res.second == -1)
        cout << "No element found";
    else
        cout << res.first << " occurre " << res.second << " time";
    return 0;
}