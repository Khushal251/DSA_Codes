#include <bits/stdc++.h>
using namespace std;
#define int long long int

int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    // base case
    // if only 1 item to steal,then just compare its weight with knapsak capacity
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int exclude = solve(weight, value, index - 1, capacity);

    int ans = max(exclude, include);
    return ans;
}
int solve2(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    // if only 1 item to steal,then just compare its weight with knapsak capacity
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != 1)
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int exclude = solve(weight, value, index - 1, capacity);

    dp[index][capacity] = max(exclude, include);
    return dp[index][capacity];
}

int solve3(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step 1;
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    // step 2:
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w < capacity; w++)
        {
            int include = 0;

            if (weight[index] <= 0)
                include = value[index] + dp[index - 1][w - weight[index]];

            int exclude = 0 + dp[index - 1][w];

            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n - 1][capacity];
}

int solve4(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step 1;
    vector<int> pre(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // step 2: analysis of base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            pre[w] = value[0];
        else
            pre[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + pre[w - weight[index]];

            int exclude = 0 + pre[w];

            curr[w] = max(exclude, include);
        }
        pre = curr;
    }
    return pre[capacity];
}

int solve5(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step 1;
    vector<int> pre(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // step 2: analysis of base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + curr[w - weight[index]];

            int exclude = 0 + pre[w];

            curr[w] = max(exclude, include);
        }
        pre = curr;
    }
    return pre[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxweight)
{
    // return solve(weight,value,n-1,maxweight);

    vector<vector<int>> dp(n, vector<int>(maxweight + 1, -1));
    return solve2(weight, value, n - 1, maxweight, dp);
}

int solveSqu(vector<vector<int>> mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    int right = solveSqu(mat, i, j + 1, maxi);
    int digonal = solveSqu(mat, i + 1, j + 1, maxi);
    int down = solveSqu(mat, i + 1, j, maxi);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(digonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

int solveSqu2(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solveSqu2(mat, i, j + 1, maxi, dp);
    int digonal = solveSqu2(mat, i + 1, j + 1, maxi, dp);
    int down = solveSqu2(mat, i + 1, j, maxi, dp);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(digonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}

int solveSqu3(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int digonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(digonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];

    // If you want to iterate from start to end then

    // int row = mat.size();
    // int col = mat[0].size();

    // vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    // for (int i = 0; i <= row - 1; i++)
    // {
    //     for (int j = 0; j <= col-1; j++)
    //     {
    //         int left,digonal,up;
    //         if(i-1==-1 || j-1==-1)
    //         {
    //            left = 0;
    //            digonal = 0;
    //            up = 0;
    //         }

    //         else{
    //            left = dp[i][j-1];
    //            digonal = dp[i-1][j-1];
    //            up = dp[i-1][j];
    //         }

    //         if (mat[i][j] == 1)
    //         {
    //             dp[i][j] = 1 + min(left, min(digonal, up));
    //             maxi = max(maxi, dp[i][j]);
    //         }
    //         else
    //         {
    //             dp[i][j] = 0;
    //         }
    //     }
    // }
    // return dp[row-1][col-1];
}

int solveSqu4(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<int> curr(col + 1, 0);
    vector<int> next(col + 1, 0);

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = curr[j + 1];
            int digonal = next[j + 1];
            int down = next[j];

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(digonal, down));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return next[0];
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // int maxi=0;
    // solveSqu(mat,0,0,maxi);
    // return maxi;

    // int maxi = 0;
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // solveSqu2(mat, 0, 0, maxi, dp);
    // return maxi;

    // int maxi=0;
    // solveSqu3(mat, maxi);
    // return maxi;

    int maxi = 0;
    solveSqu4(mat, maxi);
    return maxi;
}

int solveTri(vector<int> &v, int i, int j)
{
    // base case
    if (i + 1 == j)
        return 0;

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, v[i] * v[j] * v[k] + solveTri(v, i, k) + solveTri(v, k, j));
    }
    return ans;
}

int solveTri2(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i + 1 == j)
        return 0;

    if (dp[i][j] != -1)
        return -1;

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, v[i] * v[j] * v[k] + solveTri2(v, i, k, dp) + solveTri2(v, k, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveTri3(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j];
        }
    }
    return dp[0][n - 1];
}

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    // return solveTri(values,0,n-1);

    vector<vector<int>> dp(n, vector<int>(n, -1));
}

int solveSide(vector<int> &obsticles, int currlane, int currpos)
{
    // base case
    int n = obsticles.size() - 1;
    if (currpos == n)
        return 0;

    if (obsticles[currpos + 1] != currlane)
    {
        return solveSide(obsticles, currlane, currpos + 1);
    }
    else
    {
        // sideways jump
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && obsticles[currpos] != i)
                ans = min(ans, 1 + solveSide(obsticles, i, currpos));
        }
        return ans;
    }
}

int solveSide2(vector<int> &obsticles, int currlane, int currpos, vector<vector<int>> dp)
{
    // base case
    int n = obsticles.size() - 1;
    if (currpos == n)
        return 0;

    if (dp[currlane][currpos] != -1)
        return dp[currlane][currpos];

    if (obsticles[currpos + 1] != currlane)
    {
        return solveSide2(obsticles, currlane, currpos + 1, dp);
    }

    else
    {
        // sideways jump
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && obsticles[currpos] != i)
                ans = min(ans, 1 + solveSide2(obsticles, i, currpos, dp));
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}

int solveSide3(vector<int> &obsticles)
{
    int n = obsticles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(obsticles.size(), 1e9));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos++)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (obsticles[currpos + 1] != currlane)
            {
                dp[currlane][currpos] = dp[currlane][currpos + 1];
            }
            else
            {
                // sideways jump
                // int ans = INT_MAX;
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currlane != i && obsticles[currpos] != i)
                        ans = min(ans, 1 + dp[i][currpos + 1]); // IMPORTANT
                }
                dp[currlane][currpos] = ans;
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

int solveSide4(vector<int> &obsticles)
{
    int n = obsticles.size() - 1;

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos++)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (obsticles[currpos + 1] != currlane)
            {
                curr[currlane] = next[currlane];
            }
            else
            {
                // sideways jump
                // int ans = INT_MAX;
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currlane != i && obsticles[currpos] != i)
                        ans = min(ans, 1 + next[i]); // IMPORTANT
                }
                curr[currlane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}

int minSideJumps(vector<int> &obsticles)
{
    // return solveSide(obsticles,2,0);

    // vector<vector<int>> dp(4, vector<int>(obsticles.size(), -1));
    // return solveSide2(obsticles, 2, 0, dp);

    return solveSide3(obsticles);
}

int solveSatis(vector<int> &satisfaction, int index, int time)
{
    // base case
    if (index == satisfaction.size())
        return 0;

    int include = satisfaction[index] * (time + 1) + solveSatis(satisfaction, index + 1, time + 1);
    int exclude = 0 + solveSatis(satisfaction, index + 1, time);

    return max(include, exclude);
}

int solveSatis2(vector<int> &satisfaction, int index, int time, vector<vector<int>> dp)
{
    // base case
    if (index == satisfaction.size())
        return 0;

    if (dp[index][time] != -1)
        return dp[index][time];

    int include = satisfaction[index] * (time + 1) + solveSatis2(satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + solveSatis2(satisfaction, index + 1, time, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

int solveSatis3(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];

            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int solveSatis4(vector<int> &satisfaction)
{
    int n = satisfaction.size();

    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + next[time + 1];
            int exclude = 0 + next[time];

            curr[time] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    // return solveSatis(satisfaction,0,0);

    int n = satisfaction.size();
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return solveSatis2(satisfaction, 0, 0, dp);

    return solveSatis3(satisfaction);
}

int solveSub(int n, int a[], int curr, int pre)
{
    // base case
    if (curr == n)
        return 0;

    // include
    int take = 0;
    if (pre == -1 || a[curr] > a[pre])
        take = 1 + solveSub(n, a, curr + 1, curr);

    // exclude
    int notTake = 0 + solveSub(n, a, curr + 1, pre);

    return max(take, notTake);
}

int solveSub2(int n, int a[], int curr, int pre, vector<vector<int>> dp)
{
    // base case
    if (curr == n)
        return 0;

    if (dp[curr][pre + 1] != -1)
        return dp[curr][pre + 1];

    // include
    int take = 0;
    if (pre == -1 || a[curr] > a[pre])
        take = 1 + solveSub2(n, a, curr + 1, curr, dp);

    // exclude
    int notTake = 0 + solveSub2(n, a, curr + 1, pre, dp);

    return dp[curr][pre + 1] = max(take, notTake);
}

int solveSub3(int n, int a[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int pre = n - 1; pre >= -1; pre++)
        {
            // include
            int take = 0;
            if (pre == -1 || a[curr] > a[pre])
                take = 1 + dp[curr + 1][curr + 1];

            // exclude
            int notTake = 0 + dp[curr + 1][pre + 1];

            dp[curr][pre + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

int solveSub4(int n, int a[])
{
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int pre = n - 1; pre >= -1; pre++)
        {
            // include
            int take = 0;
            if (pre == -1 || a[curr] > a[pre])
                take = 1 + nextRow[curr + 1];

            // exclude
            int notTake = 0 + nextRow[pre + 1];

            currRow[pre + 1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int solveSub4Binary(int n, int a[])
{
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())
            ans.push_back(a[i]);

        else
        {
            // find index of just bada element in ans
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n, int a[])
{
    // return solveSub(n, a, 0, -1);

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solveSub2(n, a, 0, -1, dp);
}

bool check(vector<int> base, vector<int> newBox)
{
    if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        return true;
    else
        return false;
}

int sol(int n, vector<vector<int>> &a)
{
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int pre = n - 1; pre >= -1; pre++)
        {
            // include
            int take = 0;
            if (pre == -1 || check(a[curr], a[pre]))
                take = a[curr][2] + nextRow[curr + 1];

            // exclude
            int notTake = 0 + nextRow[pre + 1];

            currRow[pre + 1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // step 1: sort all dimensions for every cuboid

    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // step 2: sort all cuboids basis on w and l
    sort(cuboids.begin(), cuboids.end());

    // step 3: use LTS logic'
    return sol(cuboids.size(), cuboids);
}

int solvethis(int index, int endIndex, vector<int> &slice, int n)
{
    // base case
    if (n == 0 || index >= slice.size())
        return 0;

    int take = slice[index] + solvethis(index + 2, endIndex, slice, n - 1);
    int nottake = 0 + solvethis(index + 1, endIndex, slice, n);
    return max(take, nottake);
}

int solvethis2(int index, int endIndex, vector<int> &slice, int n, vector<vector<int>> dp)
{
    // base case
    if (n == 0 || index >= slice.size())
        return 0;

    if (dp[index][n] != -1)
        return dp[index][n];

    int take = slice[index] + solvethis(index + 2, endIndex, slice, n - 1);
    int nottake = 0 + solvethis(index + 1, endIndex, slice, n);
    return dp[index][n] = max(take, nottake);
}

int solvethis3(vector<int> &slice)
{
    int k = slice.size();

    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));

    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slice[index] + dp1[index + 2][n - 1];
            int nottake = 0 + dp2[index + 1][n];
            dp1[index][n] = max(take, nottake);
        }
    }
    int case1 = dp1[0][k / 3];

    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slice[index] + dp2[index + 2][n - 1];
            int nottake = 0 + dp2[index + 1][n];
            dp2[index][n] = max(take, nottake);
        }
    }
    int case2 = dp2[0][k / 3];

    return max(case1, case2);
}

int solvethis4(vector<int> &slice)
{
    int k = slice.size();

    vector<int> pre1(k + 2, 0);
    vector<int> curr1(k + 2, 0);
    vector<int> next1(k + 2, 0);

    vector<int> pre2(k + 2, 0);
    vector<int> curr2(k + 2, 0);
    vector<int> next2(k + 2, 0);

    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slice[index] + next1[n - 1];
            int nottake = 0 + curr1[n];
            pre1[n] = max(take, nottake);
        }
        next1 = curr1;
        curr1 = pre1;
    }
    int case1 = curr1[k / 3];

    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slice[index] + next2[n - 1];
            int nottake = 0 + curr2[n];
            pre2[n] = max(take, nottake);
        }
    }
    int case2 = curr2[k / 3];

    return max(case1, case2);
}

int maxSizeSlice(vector<int> &slice)
{
    int k = slice.size();
    // int case1=solvethis(0,k-2,slice,k/3);
    // int case2=solvethis(1,k-1,slice,k/3);
    // return max(case1,case2);

    vector<vector<int>> dp1(k, vector<int>(k, -1));
    vector<vector<int>> dp2(k, vector<int>(k, -1));
    int case1 = solvethis2(0, k - 2, slice, k / 3, dp1);
    int case2 = solvethis2(1, k - 1, slice, k / 3, dp2);
    return max(case1, case2);
}

int save(int dice, int faces, int target)
{
    // base case
    if (target < 0)
        return 0;
    if (dice == 0 && target != 0)
        return 0;
    if (target == 0 && dice != 0)
        return 0;
    if (dice == 0 && target == 0)
        return 1;

    int ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans = ans + save(dice - 1, faces, target - 1);
    }
    return ans;
}

int save2(int dice, int faces, int target, vector<vector<int>> dp)
{
    // base case
    if (target < 0)
        return 0;
    if (dice == 0 && target != 0)
        return 0;
    if (target == 0 && dice != 0)
        return 0;
    if (dice == 0 && target == 0)
        return 1;

    if (dp[dice][target] != -1)
        return dp[dice][target];

    int ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans = ans + save(dice - 1, faces, target - 1);
    }
    return dp[dice][target] = ans;
}

int save3(int d, int f, int t)
{
    vector<vector<int>> dp(d + 1, vector<int>(t + 1, -1));

    dp[0][0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            int ans = 0;
            for (int i = 1; i <= f; i++)
            {
                if (target - i >= 0)
                    ans = ans + dp[dice - 1][target - i];
            }
            dp[dice][target] = ans;
        }
    }
    return dp[d][t];
}

int save4(int d, int f, int t)
{
    vector<int> pre(t + 1, 0);
    vector<int> curr(t + 1, 0);

    pre[0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            int ans = 0;
            for (int i = 1; i <= f; i++)
            {
                if (target - i >= 0)
                    ans = ans + pre[target - i];
            }
            curr[target] = ans;
        }
        pre = curr;
    }
    return pre[t];
}

int noOfWays(int m, int n, int x)
{
    return save(n, m, x);

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    return save2(n, m, x, dp);
}

bool func(int index, int arr[], int n, int target)
{
    // base case
    if (index >= n)
        return 0;
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;

    bool incl = func(index + 1, arr, n, target - arr[index]);
    bool excl = func(index + 1, arr, n, target - 0);

    return incl or excl;
}

bool func2(int index, int arr[], int n, int target, vector<vector<int>> dp)
{
    // base case
    if (index >= n)
        return 0;
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;

    if (dp[index][target] != -1)
        return dp[index][target];

    bool incl = func(index + 1, arr, n, target - arr[index]);
    bool excl = func(index + 1, arr, n, target - 0);

    return dp[index][target] = incl or excl;
}

bool func3(int n, int arr[], int total)
{

    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = n - 1; index >= 0; index++)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool incl = 0;
            if (target - arr[index] >= 0)
            {
                bool incl = dp[index + 1][target - arr[index]];
            }

            bool excl = dp[index + 1][target - 0];

            dp[index][target] = incl or excl;
        }
    }
    return dp[0][total / 2];
}

bool func4(int n, int arr[], int total)
{

    vector<int> curr(total + 1, 0);
    vector<int> next(total + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for (int index = n - 1; index >= 0; index++)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool incl = 0;
            if (target - arr[index] >= 0)
            {
                bool incl = next[target - arr[index]];
            }

            bool excl = next[target - 0];

            curr[target] = incl or excl;
        }
        next = curr;
    }
    return next[total / 2];
}

int equalPartition(int n, int arr[])
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + arr[i];
    }
    if (total % 2 != 0)
        return 0;

    int target = total / 2;

    // return func(0,arr,n,target);

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
}

int roll(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
{
    // base case
    if (index == nums1.size())
        return 0;

    int ans = INT_MAX;

    int pre1 = nums1[index - 1];
    int pre2 = nums2[index - 1];

    // catch
    if (swapped)
        swap(pre1, pre2);

    // noswap
    if (nums1[index] > pre1 && nums2[index] > pre2)
        ans = roll(nums1, nums2, index + 1, 0);

    // swap
    if (nums1[index] > pre2 && nums2[index] > pre1)
        ans = min(ans, 1 + roll(nums1, nums2, index + 1, 1));

    return ans;
}

int roll2(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> dp)
{
    // base case
    if (index == nums1.size())
        return 0;

    if (dp[index][swapped] != -1)
        return dp[index][swapped];

    int ans = INT_MAX;

    int pre1 = nums1[index - 1];
    int pre2 = nums2[index - 1];

    // catch
    if (swapped)
        swap(pre1, pre2);

    // noswap
    if (nums1[index] > pre1 && nums2[index] > pre2)
        ans = roll2(nums1, nums2, index + 1, 0, dp);

    // swap
    if (nums1[index] > pre2 && nums2[index] > pre1)
        ans = min(ans, 1 + roll2(nums1, nums2, index + 1, 1, dp));

    return dp[index][swapped] = ans;
}

int roll3(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; index++)
    {
        for (int swapped = 1; swapped >= 0; swapped++)
        {
            int ans = INT_MAX;

            int pre1 = nums1[index - 1];
            int pre2 = nums2[index - 1];

            // catch
            if (swapped)
                swap(pre1, pre2);

            // noswap
            if (nums1[index] > pre1 && nums2[index] > pre2)
                ans = dp[index + 1][0];

            // swap
            if (nums1[index] > pre2 && nums2[index] > pre1)
                ans = min(ans, 1 + dp[index + 1][1]);

            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}

int roll4(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    int swape = 0;
    int noswap = 0;
    int currswap = 0;
    int currnoswap = 0;

    for (int index = n - 1; index >= 0; index++)
    {
        for (int swapped = 1; swapped >= 0; swapped++)
        {
            int ans = INT_MAX;

            int pre1 = nums1[index - 1];
            int pre2 = nums2[index - 1];

            // catch
            if (swapped)
                swap(pre1, pre2);

            // noswap
            if (nums1[index] > pre1 && nums2[index] > pre2)
                ans = noswap;

            // swap
            if (nums1[index] > pre2 && nums2[index] > pre1)
                ans = min(ans, 1 + swape);

            if (swapped)
                currswap = ans;
            else
                currnoswap = ans;
        }
        swape = currswap;
        noswap = currnoswap;
    }
    return min(swape, noswap);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    // return roll(nums1,nums2,1,swapped);

    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
}

int fun(int index, int diff, int a[])
{
    // backward check
    if (index < 0)
        return 0;

    int ans = 0;
    for (int j = index - 1; j >= 0; j++)
    {
        if ((a[index] - a[j]) == diff)
            ans = max(ans, 1 + fun(j, diff, a));
    }
    return ans;
}

int fun2(int index, int diff, int a[], unordered_map<int, int> dp[])
{
    // backward check
    if (index < 0)
        return 0;

    if (dp[index].count(diff))
        return dp[index][diff];

    int ans = 0;
    for (int j = index - 1; j >= 0; j++)
    {
        if ((a[index] - a[j]) == diff)
            ans = max(ans, 1 + fun2(j, diff, a, dp));
    }
    // return ans;
    return dp[index][diff] = ans;
}

int lengthOfLongest1(int a[], int n)
{
    if (n <= 2)
        return n;

    int ans = 0;

    unordered_map<int, int> dp[n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // ans = max(ans, 2 + fun(i, a[j] - a[i],a));
            ans = max(ans, 2 + fun2(i, a[j] - a[i], a, dp));
        }
    }
}

int lengthOfLongest2(int a[], int n)
{
    int ans = 0;
    unordered_map<int, int> dp[n + 1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = a[i] - a[j];
            int cnt = 1;

            // check if answer already present
            if (dp[j].count(diff))
                cnt = dp[j][diff];

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int solveTree(int n)
{
    if (n <= 1)
        return 1;

    int ans = 0;
    // think i as root node
    for (int i = 1; i <= n; i++)
    {
        ans += solveTree(i - 1) * solveTree(n - i);
    }
    return ans;
}

int solveTree2(int n, vector<int> dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;
    // think i as root node
    for (int i = 1; i <= n; i++)
    {
        ans += solveTree2(i - 1, dp) * solveTree2(n - i, dp);
    }
    return dp[n] = ans;
}

int solveTree3(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    // i-> number of nodes
    for (int i = 2; i <= n; i++)
    {
        // j->root node
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int numTrees(int n)
{
    return solveTree(n);

    vector<int> dp(n + 1, -1);
}

int yesh(int start, int end)
{
    if (start >= end)
        return 0;

    int maxi = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        maxi = min(maxi, i + max(yesh(start, i - 1), yesh(i + 1, end)));
    }
    return maxi;
}

int yesh2(int start, int end, vector<vector<int>> dp)
{
    if (start >= end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int maxi = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        maxi = min(maxi, i + max(yesh(start, i - 1), yesh(i + 1, end)));
    }
    return dp[start][end] = maxi;
}

int yesh3(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

    for (int start = n; start >= 1; start--)
    {
        for (int end = start; end <= n; end++)
        {
            if (start == end)
                continue;

            else
            {
                int maxi = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    maxi = min(maxi, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = maxi;
            }
        }
    }
    return dp[1][n];
}

int getMoneyAmount(int n)
{
    // return yesh(1,n);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
}

int den(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // leaf node
    if (left == right)
        return 0;

    int ans = INT_MAX;

    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + den(arr, maxi, left, i) + den(arr, maxi, i + 1, right));
    }
    return ans;
}

int den2(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> dp)
{
    // leaf node
    if (left == right)
        return 0;

    if (dp[left][right] != -1)
        return dp[left][right];

    int ans = INT_MAX;

    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + den2(arr, maxi, left, i, dp) + den2(arr, maxi, i + 1, right, dp));
    }
    return ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    return den(arr, maxi, 0, arr.size() - 1);
}

int mctFromLeafValues2(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    return den2(arr, maxi, 0, arr.size() - 1, dp);
}

int maxProfit1(vector<int> &prices)
{
    int n = prices.size();
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = prices[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int doing(int index, int buy, vector<int> &prices)
{
    if (index == prices.size())
        return 0;

    int profit = 0;
    if (buy)
    {
        int buyKaro = -prices[index] + doing(index + 1, 0, prices);
        int skipKaro = 0 + doing(index + 1, 1, prices);
        profit = max(buyKaro, skipKaro);
    }

    else
    {
        int sellKaro = +prices[index] + doing(index + 1, 1, prices);
        int skipKaro = 0 + doing(index + 1, 0, prices);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

int doing2(int index, int buy, vector<int> &prices, vector<vector<int>> dp)
{
    if (index == prices.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    if (buy)
    {
        int buyKaro = -prices[index] + doing2(index + 1, 0, prices, dp);
        int skipKaro = 0 + doing2(index + 1, 1, prices, dp);
        profit = max(buyKaro, skipKaro);
    }

    else
    {
        int sellKaro = +prices[index] + doing2(index + 1, 1, prices, dp);
        int skipKaro = 0 + doing2(index + 1, 0, prices, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy] = profit;
}

int doing3(int index, int buy, vector<int> &prices, vector<vector<int>> dp)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyKaro = -prices[index] + dp[index + 1][0];
                int skipKaro = 0 + dp[index + 1][1];
                profit = max(buyKaro, skipKaro);
            }

            else
            {
                int sellKaro = +prices[index] + dp[index + 1][1];
                int skipKaro = 0 + dp[index + 1][0];
                profit = max(sellKaro, skipKaro);
            }

            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int doing4(int index, int buy, vector<int> &prices, vector<vector<int>> dp)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyKaro = -prices[index] + next[0];
                int skipKaro = 0 + next[1];
                profit = max(buyKaro, skipKaro);
            }

            else
            {
                int sellKaro = +prices[index] + next[1];
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }

            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit2(vector<int> &prices)
{
    int n = prices.size();
    // return doing(0, 1, prices);

    vector<vector<int>> dp(n, vector<int>(2, -1));
    return doing2(0, 1, prices, dp);
}

// 3D DP

int algo(int index, int buy, vector<int> &prices, int limit)
{
    if (index == prices.size())
        return 0;

    if (limit == 0)
        return 0;

    int profit = 0;
    if (buy)
    {
        int buyKaro = -prices[index] + algo(index + 1, 0, prices, limit);
        int skipKaro = 0 + algo(index + 1, 1, prices, limit);
        profit = max(buyKaro, skipKaro);
    }

    else
    {
        int sellKaro = +prices[index] + algo(index + 1, 1, prices, limit - 1);
        int skipKaro = 0 + algo(index + 1, 0, prices, limit);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

int algo2(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> dp)
{
    if (index == prices.size())
        return 0;

    if (limit == 0)
        return 0;

    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;
    if (buy)
    {
        int buyKaro = -prices[index] + algo(index + 1, 0, prices, limit);
        int skipKaro = 0 + algo(index + 1, 1, prices, limit);
        profit = max(buyKaro, skipKaro);
    }

    else
    {
        int sellKaro = +prices[index] + algo(index + 1, 1, prices, limit - 1);
        int skipKaro = 0 + algo(index + 1, 0, prices, limit);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy][limit] = profit;
}

int algo3(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyKaro = -prices[index] + dp[index + 1][0][limit];
                    int skipKaro = 0 + dp[index + 1][1][limit];
                    profit = max(buyKaro, skipKaro);
                }

                else
                {
                    int sellKaro = +prices[index] + dp[index + 1][1][limit];
                    int skipKaro = 0 + dp[index + 1][0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int algo4(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyKaro = -prices[index] + next[0][limit];
                    int skipKaro = 0 + next[1][limit];
                    profit = max(buyKaro, skipKaro);
                }

                else
                {
                    int sellKaro = +prices[index] + next[1][limit];
                    int skipKaro = 0 + next[0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}

int maxProfit3(vector<int> &prices)
{
    int n = prices.size();
    // return algo(0, 1, prices,2);

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return algo2(0, 1, prices, 2, dp);
}

int momo4(vector<int> &prices, int k)
{
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    vector<vector<int>> next(2, vector<int>(k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= k; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyKaro = -prices[index] + next[0][limit];
                    int skipKaro = 0 + next[1][limit];
                    profit = max(buyKaro, skipKaro);
                }

                else
                {
                    int sellKaro = +prices[index] + next[1][limit];
                    int skipKaro = 0 + next[0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][k];
}

int pizza(int index, int operationNo, int k, vector<int> &prices)
{
    if (index == prices.size())
        return 0;

    if (operationNo == 2 * k)
        return 0;

    int profit = 0;
    if (operationNo % 2 == 0)
    {
        int buyKaro = -prices[index] + pizza(index + 1, operationNo + 1, k, prices);
        int skipKaro = 0 + pizza(index + 1, operationNo, k, prices);
        profit = max(buyKaro, skipKaro);
    }

    else
    {
        int sellKaro = +prices[index] + pizza(index + 1, operationNo + 1, k, prices);
        int skipKaro = 0 + pizza(index + 1, operationNo, k, prices);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

int pizza2(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> dp)
{
    if (index == prices.size())
        return 0;

    if (operationNo == 2 * k)
        return 0;

    if (dp[index][operationNo] != -1)
        return dp[index][operationNo];

    int profit = 0;
    if (operationNo % 2 == 0)
    {
        int buyKaro = -prices[index] + pizza(index + 1, operationNo + 1, k, prices);
        int skipKaro = 0 + pizza(index + 1, operationNo, k, prices);
        profit = max(buyKaro, skipKaro);
    }

    else
    {
        int sellKaro = +prices[index] + pizza(index + 1, operationNo + 1, k, prices);
        int skipKaro = 0 + pizza(index + 1, operationNo, k, prices);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][operationNo] = profit;
}

int pizza3(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> dp)
{
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2 * k+1 , 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int operationNo = 0; operationNo < 2 * k; operationNo++)
        {
            int profit = 0;
            if (operationNo % 2 == 0)
            {
                int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(buyKaro, skipKaro);
            }

            else
            {
                int sellKaro = +prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(sellKaro, skipKaro);
            }

            dp[index][operationNo] = profit;
        }
    }
    return dp[0][0]; 
}

int pizza4(int k, vector<int> &prices, vector<vector<int>> dp)
{
    int n = prices.size();
    vector<int> curr(2*k+1,0);
    vector<int> next(2*k+1,0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int operationNo = 0; operationNo < 2 * k; operationNo++)
        {
            int profit = 0;
            if (operationNo % 2 == 0)
            {
                int buyKaro = -prices[index] + next[operationNo+1];
                int skipKaro = 0 + next[operationNo];
                profit = max(buyKaro, skipKaro);
            }

            else
            {
                int sellKaro = +prices[index] + next[operationNo+1];
                int skipKaro = 0 + next[operationNo];
                profit = max(sellKaro, skipKaro);
            }

            curr[operationNo] = profit;
        }
        next=curr;
    }
    return dp[0][0]; 
}

int maxProfit4(vector<int> &prices, int k)
{
    int n = prices.size();
    // return momo4(prices,k);

    // return pizza(0,0,k,prices);

    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return pizza2(0, 0, k, prices, dp);
}



int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();
    // return momo4(prices,k);

    // return pizza(0,0,k,prices);

    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return pizza2(0, 0, k, prices, dp);
}

int news(vector<int> &prices,int fee)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyKaro = -prices[index] + next[0];
                int skipKaro = 0 + next[1];
                profit = max(buyKaro, skipKaro);
            }

            else
            {
                int sellKaro = +prices[index] + next[1]-fee;
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }

            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit5(vector<int> &prices, int fee)
{
    int n = prices.size();
    return news(prices,fee);
}

int32_t main()
{

    return 0;
}