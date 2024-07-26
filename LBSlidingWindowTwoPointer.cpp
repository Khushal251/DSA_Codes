#include <bits/stdc++.h>
using namespace std;
#define int long long int

int lengthOfLongestSubstring(string s)
{
    map<char, int> mpp;

    int left = 0, right = 0;
    int len = 0;
    int n = s.size();

    while (right < n)
    {
        if (mpp.find(s[right]) != mpp.end())
        {
            left = max(mpp[s[right]] + 1, left);
        }

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int MaxConsecutiveOnesIII(vector<int> &nums, int k)
{
    int left = 0, right = 0, ans = 0, zerocount = 0;
    int n = nums.size();

    while (right < n)
    {
        if (nums[right] == 0)
            zerocount++;

        while (zerocount > k)
        {
            if (nums[left] == 0)
                zerocount--;

            left++;
        }

        ans = max(ans, right - left + 1);
        right++;
    }

    return ans;
}

int characterReplacement1(string s, int k)
{
    int right = 0, left = 0, ans = 0;
    int cnt[26] = {};

    for (right = 0; right < s.size(); right++)
    {
        cnt[s[right] - 'A']++;
        while ((right - left + 1 - *max_element(cnt, cnt + 26)) > k)
        {
            cnt[s[left] - 'A']--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

// int characterReplacement(string s, int k)
// {
//     int right = 0, left = 0, ans = 0;
//     map<char, int> charCount;
//     int maxFreq = 0;

//     for (right = 0; right < s.size(); right++)
//     {
//         charCount[s[right]]++;
//         maxFreq = max(maxFreq, charCount[s[right]]);

//         while (right - left + 1 - maxFreq > k)
//         {
//             charCount[s[left]]--;
//             if (charCount[s[left]] == 0)
//             {
//                 charCount.erase(s[left]);
//             }
//             left++;
//         }

//         ans = max(ans, right - left + 1);
//     }
//     return ans;
// }

// int characterReplacement(string s, int k)
// {
//     int right = 0, left = 0, ans = 0;
//     map<char, int> charCount;
//     int maxFreq = 0;

//     for (right = 0; right < s.size(); right++)
//     {
//         charCount[s[right]]++;
//         maxFreq = max(maxFreq, charCount[s[right]]);

//         while (right - left + 1 - maxFreq > k)
//         {
//             charCount[s[left]]--;
//             if (charCount[s[left]] == 0)
//             {
//                 charCount.erase(s[left]);
//             }
//             left++;
//             maxFreq=findMaxFrequency(charCount);
//         }

//         ans = max(ans, right - left + 1);
//     }
//     return ans;
// }

int findMaxFrequency(map<char, int> &charCount)
{
    int maxFreq = 0;
    for (auto it = charCount.begin(); it != charCount.end(); ++it)
    {
        maxFreq = max(maxFreq, it->second);
    }
    return maxFreq;
}

int characterReplacement(string s, int k)
{
    int right = 0, left = 0, ans = 0;
    map<char, int> charCount;
    int maxFreq = 0;

    for (right = 0; right < s.size(); right++)
    {
        charCount[s[right]]++;
        // maxFreq = max(maxFreq, charCount[s[right]]);
        maxFreq = findMaxFrequency(charCount);

        while (right - left + 1 - maxFreq > k)
        {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0)
            {
                charCount.erase(s[left]);
            }
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}



int numSubarraysWithSum(vector<int> &nums, int goal)
{
    unordered_map<int,int>mp;
    int sum=0;
    int count=0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum=sum+nums[i];

        if(sum==goal)
        count++;

        if(mp.find(sum-goal)!=mp.end())
        count=count+mp[sum-goal];

        if(mp.find(sum)!=mp.end())
        mp[sum]++;

        else
        mp[sum]=1;
    }
    return count;
    
}



int32_t main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    int ans=numSubarraysWithSum(nums,k);
    cout<<"Answer is: "<<ans<<endl;
    
    

    return 0;
}