vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k)
{
    vector<vector<int>> ans;
    int n1 = arr1.size();
    int n2 = arr2.size();

    if (n1 == 0 || n2 == 0)
        return ans;

    // track next element in arr2 for each arr1[i]
    vector<int> index2(n1, 0);

    while (k > 0)
    {
        int min_sum = INT_MAX;
        int min_index = -1;

        // Find the next pair with minimum sum
        for (int i = 0; i < n1; i++)
        {
            if (index2[i] < n2 && arr1[i] + arr2[index2[i]] < min_sum)
            {
                min_sum = arr1[i] + arr2[index2[i]];
                min_index = i;
            }
        }
        // no more pairs available
        if (min_index == -1)
            break;

        ans.push_back({arr1[min_index], arr2[index2[min_index]]});
        index2[min_index]++;
        k--;
    }

    return ans;
}