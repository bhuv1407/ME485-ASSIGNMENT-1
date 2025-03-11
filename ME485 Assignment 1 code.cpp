#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int start, vector<vector<pii>>& graph, int V) {
    
    vector<int> dist(V, INT_MAX);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        for (auto& edge : graph[curr_node]) {
            int next_node = edge.first;
            int weight = edge.second;

            if (dist[next_node] > curr_dist + weight) {
                dist[next_node] = curr_dist + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

     cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 9;  // Number of vertices

    
    vector<vector<pii>> graph(V);

    // Graph edges from the image
    graph[0].push_back({1, 4});
    graph[0].push_back({7, 8});

    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    graph[1].push_back({7, 11});

    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});
    graph[2].push_back({8, 2});

    graph[3].push_back({2, 7});
    graph[3].push_back({4, 9});
    graph[3].push_back({5, 14});

    graph[4].push_back({3, 9});
    graph[4].push_back({5, 10});

    graph[5].push_back({2, 4});
    graph[5].push_back({3, 14});
    graph[5].push_back({4, 10});
    graph[5].push_back({6, 2});

    graph[6].push_back({5, 2});
    graph[6].push_back({7, 1});
    graph[6].push_back({8, 6});

    graph[7].push_back({0, 8});
    graph[7].push_back({1, 11});
    graph[7].push_back({6, 1});
    graph[7].push_back({8, 7});

    graph[8].push_back({2, 2});
    graph[8].push_back({6, 6});
    graph[8].push_back({7, 7});

    int start_node = 0;
    dijkstra(start_node, graph, V);

    return 0;
}
