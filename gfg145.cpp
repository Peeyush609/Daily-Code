bool isInterleave(string &s1, string &s2, string &s3)
{
    // If lengths don't match, return false
    if (s1.size() + s2.size() != s3.size())
        return false;

    int n = s1.size(), m = s2.size();

    // Two rows for DP
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    // Base case
    prev[0] = true;

    // Fill first row (s1 empty)
    for (int j = 1; j <= m; ++j)
        prev[j] = prev[j - 1] && (s2[j - 1] == s3[j - 1]);

    // Fill the DP rows
    for (int i = 1; i <= n; ++i)
    {
        // first column
        curr[0] = prev[0] && (s1[i - 1] == s3[i - 1]); 

        for (int j = 1; j <= m; ++j)
        {
            int k = i + j;
            curr[j] = (prev[j] && s1[i - 1] == s3[k - 1]) || 
            (curr[j - 1] && s2[j - 1] == s3[k - 1]);
        }
        
        // move current row to previous
        prev = curr;
    }

    return prev[m];
}
