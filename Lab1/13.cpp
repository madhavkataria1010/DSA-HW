    /*Given a matrix M, return the sum of the odd columns from it.
    Input Format: - First line states the value of N and M, which indicates N*M matrix.
    Followed by N lines containing M integers.
    Example:
    Sample Input 1:
    5 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5

    Sample Output 1:
    45*/

    #include <bits/stdc++.h>
    using namespace std;

    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef long long ll;

    class matrix
    {
    public:
        int n, m;
        vvi M;
        matrix(int shape0, int shape1)
        {
            n = shape0;
            m = shape1;
            M = vvi(n, vi(m, 0));
        }
        void displayMatrix()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << M[i][j] << ' ';
                cout << '\n';
            }
        }
    };

    class solution
    {
    public:
        int solve(matrix &mat)
        {
            int total = 0;
            for (int j = 0; j < mat.m; j++)
            {
                if ((j + 1) % 2 != 0)
                {
                    for (int i = 0; i < mat.n; i++)
                    {
                        total += mat.M[i][j];
                    }
                }
            }
            return total;
        }
    };

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        matrix mat(n, m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat.M[i][j];

        solution sol;
        cout << sol.solve(mat);

        return 0;
    }