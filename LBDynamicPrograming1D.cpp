#include <bits/stdc++.h>
using namespace std;
#define int long long int

int fibTtoD(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;

    // step 3
    if (dp[n] != -1)
        return dp[n];

    // strp 2
    dp[n] = fibTtoD(n - 1, dp) + fibTtoD(n - 2, dp);
    return dp[n];
}

int fibDtoT(int n, vector<int> &dp)
{
    // dp[0]=0;
    // dp[1]=1;

    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i]=dp[i-1]+dp[i-2];
    // }

    // return dp[n];

    int pre1 = 1;
    int pre2 = 0;

    if (n == 0)
        return pre2;

    for (int i = 2; i <= n; i++)
    {
        int curr = pre1 + pre2;
        pre2 = pre1;
        pre1 = curr;
    }

    return pre1;
}

int fibonacciSeries(int n)
{
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    return fibTtoD(n, dp);
}

int solve(int nStairs, int i)
{
    // base case
    if (i == nStairs)
        return 1;

    if (i > nStairs)
        return 0;

    return (solve(nStairs, i + 1) + solve(nStairs, i + 2));
}

int countDistinctWaysToClimbStairs(int nStairs)
{
    int ans = solve(nStairs, 0);
    return ans;
}

// int ans(vector<int> &cost, int n)
// {
//     // base case
//     if (n == 0)
//         return cost[0];
//     if (n == 1)
//         return cost[1];

//     int answer = cost[n] + min(ans(cost, n - 1), ans(cost, n - 2));
//     return answer;
// }

// int minCostClimbingStairs(vector<int> &cost)
// {
//     int n = cost.size();

//     // int ans=min(ans(cost,n-1),ans(cost,n-2));   //doubt
// }

int solve2(vector<int> &cost, int n, vector<int> &dp)
{
    // base case
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];

    // int ans=cost[n]+min(solve2(cost,n-1),solve(cost,n-2));
    // return ans;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    return dp[n];
}

int solve3(vector<int> &cost, int n)
{
    // step 1: creating dp array
    vector<int> dp(n + 1);

    // step 2: base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    // step 3:
    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}

int solve4(vector<int> &cost, int n)
{
    int pre2 = cost[0];
    int pre1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(pre1, pre2);
        pre2 = pre1;
        pre1 = curr;
    }
    return min(pre1, pre2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    // int n=cost.size();
    // int ans=min(solve2(cost,n-1),solve2(cost,n-2));
    // return ans;

    // int n=cost.size();
    // vector<int>dp(n+1,-1);
    // int ans=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    // return ans;

    // int n = cost.size();
    // return solve3(cost, n);

    int n = cost.size();
    return solve4(cost, n);
}

int solveMin(vector<int> &num, int x)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return LLONG_MAX;

    int mini = LLONG_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveMin(num, x - num[i]);
        if (ans != LLONG_MAX)
        {
            int ans = min(mini, ans + 1);
        }
    }
    return mini;
}

int solveMin2(vector<int> &num, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return LLONG_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = LLONG_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveMin(num, x - num[i]);
        if (ans != LLONG_MAX)
        {
            int ans = min(mini, ans + 1);
        }
    }
    dp[x] = mini;

    return mini;
}

int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }
    if (dp[x] == INT_MAX)
        return -1;

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // int ans = solveMin(num, x);
    // if (ans != LLONG_MAX)
    // {
    //     return -1;
    // }
    // else
    //     return ans;

    // vector<int> dp(x+1,-1);
    // int ans = solveMin2(num, x,dp);
    // if (ans != LLONG_MAX)
    // {
    //     return -1;
    // }
    // else
    //     return ans;

    solveTab(num, x);
}

int maxadj(vector<int> &nums, int n)
{
    // base case
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    int incl = maxadj(nums, n - 2) + nums[n];
    int excl = maxadj(nums, n - 1) + 0;

    return max(incl, excl);
}

int maxadj2(vector<int> &nums, int n, vector<int> &dp)
{
    // base case
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int incl = maxadj2(nums, n - 2, dp) + nums[n];
    int excl = maxadj2(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);
}

int maxadjTab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1] + 0;
        dp[i] = max(incl, excl);
    }
}

int solveMe(vector<int> &nums, int n)
{
    if (n > nums.size() - 1)
        return 0;

    if (n == nums.size() - 1)
        return nums[nums.size() - 1];

    int incl = solveMe(nums, n + 2) + nums[n];
    int excl = solveMe(nums, n + 1);

    return max(incl, excl);
}

int solveMe2(vector<int> &nums, int n, vector<int> &dp)
{
    if (n > nums.size() - 1)
        return 0;

    if (n == nums.size() - 1)
        return nums[nums.size() - 1];

    if (dp[n] != -1)
        return dp[n];

    int incl = solveMe2(nums, n + 2, dp) + nums[n];
    int excl = solveMe2(nums, n + 1, dp);

    dp[n] = max(incl, excl);

    return dp[n];
}

int solveMe3(vector<int> &nums)
{
    int n = nums.size();

    int pre2 = 0;
    int pre1 = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        int incl = pre2 + nums[i];
        int excl = pre1;

        int ans = max(incl, excl);
        pre2 = pre1;
        pre1 = ans;
    }
    return pre1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // int n=nums.size();
    // int ans=maxadj(nums,n-1);
    // return ans;

    // int n=nums.size();
    // vector<int>dp(n,-1);
    // return maxadj2(nums,n-1,dp);

    // return maxadjTab(nums);

    // My Approch
    //  int n=nums.size();
    //  int ans=solveMe(nums,0);
    //  return ans;

    // int n=nums.size();
    // vector<int>dp(n,-1);
    // int ans=solveMe2(nums,0,dp);
    // return ans;

    return solveMe3(nums);
}

int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            first.push_back(valueInHouse[i]);
        if (i != 0)
            second.push_back(valueInHouse[i]);
    }

    return max(solveMe3(first), solveMe3(second));
}

int solved(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    int a = solved(n - x, x, y, z) + 1;
    int b = solved(n - y, x, y, z) + 1;
    int c = solved(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

int solved2(int n, int x, int y, int z, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    if (dp[n] != -1)
        return dp[n];

    int a = solved2(n - x, x, y, z, dp) + 1;
    int b = solved2(n - y, x, y, z, dp) + 1;
    int c = solved2(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int solved3(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0 && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0 && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0 && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    if (dp[n] < 0)
        return 0;
    else
        return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // int ans=solved(n,x,y,z);
    // if(ans<0)
    // return 0;
    // return ans;

    vector<int> dp(n + 1, -1);
    int ans = solved2(n, x, y, z, dp);
    for (int i = 0; i < n + 1; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    if (ans < 0)
        return 0;
    return ans;
}

int counting(int n, vector<int> &dp)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (n - 1) * (counting(n - 1, dp) + counting(n - 2, dp));

    return dp[n];
}

int counting2(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

int counting3(int n)
{
    int pre2 = 0;
    int pre1 = 1;

    for (int i = 3; i <= n; i++)
    {
        int ans = (i - 1) * (pre1 + pre2);
        pre2 = pre1;
        pre1 = ans;
    }
    return pre1;
}

int countDerangement(int n)
{
    // //base case
    // if(n==1)
    // return 0;
    // if(n==2)
    // return 1;

    // int ans=(n-1)*(countDerangement(n-1)+countDerangement(n-2));

    // return ans;

    vector<int> dp(n + 1, -1);
    return counting(n, dp);
}

int finding(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return k + (k * (k - 1));

    int ans = (finding(n - 2, k) * k - 1) + (finding(n - 1, k) * k - 1);

    return ans;
}
int finding2(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return k + (k * (k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (finding2(n - 2, k, dp) * k - 1) + (finding2(n - 1, k, dp) * k - 1);
    return dp[n];

    return dp[n];
}
int finding3(int n, int k)
{

    // vector<int> dp(n+1,-1);
    // dp[1]=k;
    // dp[2]=k+(k*(k-1));

    // for (int i = 3; i <= n; i++)
    // {
    //     dp[i]=dp[i-2]*k-1 + dp[i-1]*k-1;
    // }

    // return dp[n];

    int pre2 = k;
    int pre1 = k + (k * (k - 1));

    for (int i = 3; i <= n; i++)
    {
        int ans = pre2 * k - 1 + pre1 * k - 1;
        pre2 = pre1;
        pre1 = ans;
    }
    return pre1;
}

int numberOdWays(int n, int k)
{
    // return finding(n,k);

    // vector<int> dp(n+1,-1);
    // return finding2(n,k,dp);
}
int solveCom(vector<int> &num, int tar)
{
    // base case
    if (tar < 0)
        return 0;

    if (tar == 0)
        return 1;

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveCom(num, tar - num[i]);
    }

    return ans;
}

int solveCom2(vector<int> &num, int tar, vector<int> &dp)
{
    // base case
    if (tar < 0)
        return 0;

    if (tar == 0)
        return 1;

    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveCom(num, tar - num[i]);
    }
    dp[tar] = ans;

    return dp[tar];
}

int solveCom3(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    // traversing from 1 to tar
    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[tar];
}

int solveMS(int n)
{
    if (n == 0)
        return 0;

    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, 1 + solveMS(n - i * i));
    }
    return ans;
}

int solveMS2(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, 1 + solveMS2(n - i * i, dp));
    }
    dp[n] = ans;

    return dp[n];
}

int solveMS3(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j * j >= 0)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}

int MinSquares(int n)
{
    // return solveMS(n);

    vector<int> dp(n + 1, -1);
    return solveMS2(n, dp);

    vector<int> dp(n + 1, INT_MAX);
}

int findWays(vector<int> &num, int tar)
{
    // return solveCom(num,tar);

    // vector<int> dp(tar + 1, -1);
    // return solveCom2(num, tar, dp);

    // return solveCom3 (num);
}

int func(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
        return 0;

    // 1 day pass
    int opt1 = cost[0] + func(n, days, cost, index + 1);

    int i;
    // 7 day pass
    for (int i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int opt2 = cost[i] + func(n, days, cost, i);

    // 30 day pass
    for (int i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int opt3 = cost[i] + func(n, days, cost, i);

    return min(opt1, min(opt2, opt3));
}

int func2(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    // 1 day pass
    int opt1 = cost[0] + func2(n, days, cost, index + 1, dp);

    int i;
    // 7 day pass
    for (int i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int opt2 = cost[i] + func2(n, days, cost, i, dp);

    // 30 day pass
    for (int i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int opt3 = cost[i] + func2(n, days, cost, i, dp);

    dp[index] = min(opt1, min(opt2, opt3));

    return dp[index];
}

int func3(int n, vector<int> &days, vector<int> &cost, int index)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k++)
    {
        // 1 day pass
        int opt1 = cost[0] + dp[k + 1];

        int i;
        // 7 day pass
        for (int i = k; i < n && dp[k] + 7; i++)
            ;

        int opt2 = cost[i] + dp[i];

        // 30 day pass
        for (int i = k; i < n && dp[k] + 30; i++)
            ;

        int opt3 = cost[i] + dp[i];

        dp[index] = min(opt1, min(opt2, opt3));
    }
    return dp[0];
}

int func3(int n, vector<int> &days, vector<int> &cost, int index)
{
    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days)
    {
        // step 1: remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();

            while(!week.empty() && week.front().first+7<=day)
            week.pop();

        //step 2: add cost for current day
            week.push({day,ans+cost[1]});
            month.push({day,ans+cost[2]});

        //step 3: ans update
            ans=min(ans+cost[0],min(week.front().second,month.front().second));



    }
    return ans;
}

int minimumCost(int n, vector<int> days, vector<int> cost)
{
    // return func(n, days, cost, 0);

    // vector<int> dp(n + 1, -1);
    return (n, days, cost, 0);
}

int32_t main()
{
    // vector<int>dp(5,0);
    // dp[0]=1;
    // cout<<dp[-1]<<endl;

    // vector<int> nums = {9, 9, 8, 2};
    // cout << maximumNonAdjacentSum(nums) << endl;
    // vector<int> nums = {1, 3, 2, 1};
    // cout << houseRobber(nums) << endl;

    cout << cutSegments(7, 5, 2, 2) << endl;

    return 0;
}