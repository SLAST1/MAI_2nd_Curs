#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

struct coords {
    double x;
    double y;
};

double dist(const coords &f1, const coords &f2) {
    return sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y));
}

class approx {
public:
    int index;
    double path;
    double distance;
    friend bool operator< (const approx &f1, const approx &f2) {
        if ((f1.path + f1.distance) != (f2.path + f2.distance))
            return (f1.path + f1.distance) > (f2.path + f2.distance);
        return f1.index < f2.index;
    }
    approx(const int &new_index, const coords &u, const coords &v, const double &new_path) {
        index = new_index;
        path = new_path;
        distance = dist(u, v);
    }
};

double res(const int u, const int v, int n, const vector<coords> &vert, const vector<vector<int>> &g) {
    vector<double> d(n, -10000);
    priority_queue<approx> pq;
    d[u] = 0;
    pq.push(approx(u, vert[u], vert[v], 0));
    
    while (!pq.empty()) {
        approx tmp = pq.top();
        pq.pop();
        if (tmp.index == v)
            break;
        if (tmp.path > d[tmp.index])
            continue;

        for (int i = 0; i < g[tmp.index].size(); ++i) {
            int next_vert = g[tmp.index][i];
            if (d[next_vert] < 0 || (d[tmp.index] + dist(vert[tmp.index], vert[next_vert])) < d[next_vert]){
                d[next_vert] = d[tmp.index] + dist(vert[tmp.index], vert[next_vert]);
                pq.push(approx(next_vert, vert[next_vert], vert[v], d[next_vert]));
            }
        }
    }
    return d[v];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<coords> vert(n);
    for (auto &i : vert)
        cin >> i.x >> i.y;
    vector<vector<int>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    int q;
    cin >> q;

    while (q) {
        int u, v;
        cin >> u >> v;
        double solve = res(u - 1, v - 1, n, vert, g);
        if (solve > 0)
            cout << fixed << setprecision(6) << solve << '\n';
        else
            cout << "-1\n";
        --q;
    }
    return 0;
}