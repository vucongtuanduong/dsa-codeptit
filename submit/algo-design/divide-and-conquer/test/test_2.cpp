#include <bits/stdc++.h>
using namespace std;

int maxHist(vector<int> row, int C)
{
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < C)
    {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
        else
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(vector<vector<int>> &A)
{
    int result = maxHist(A[0], A[0].size());
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
            if (A[i][j])
                A[i][j] += A[i - 1][j];
        result = max(result, maxHist(A[i], A[0].size()));
    }
    return result;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << maxRectangle(matrix) << endl;
    }
    return 0;
}