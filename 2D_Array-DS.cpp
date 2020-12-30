#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max_hourglass = -63;
    for (size_t i = 0; i < arr.size() - 2; i++)
    {
        for (int j = 2; j < arr[0].size(); j++)
        {
            int k = j - 2, hourglass = 0;
            while (k<=j)
            {
                hourglass += arr[i][k] + arr[i+2][k];
                k++;
            }
            hourglass += arr[i+1][j-1];
            max_hourglass = max(hourglass, max_hourglass);
        }
    }
    return max_hourglass;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}