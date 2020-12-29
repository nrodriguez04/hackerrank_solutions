#include <bits/stdc++.h>

using namespace std;


// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int n = c.size();
    vector<int> jumps(n);
    jumps[0] = 0;
    jumps[1] = (c[1] == 1) ? 200 : 1;

    for(int i=2; i<n; ++i)
    {
        jumps[i] = (c[i] == 1) ? 200 : 1 + std::min(jumps[i-1], jumps[i-2]);
    }
    return jumps[n-1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        c[i] = temp;
    }

    int result = jumpingOnClouds(c);

    cout << result << std::endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}