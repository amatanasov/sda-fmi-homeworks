#include <vector>
#include <iostream>

#define MAX_NODES 100001

int N, M;
std::vector<std::vector<int>> children(MAX_NODES, std::vector<int>());
std::vector<bool> coffees(MAX_NODES);
std::vector<bool> visited(MAX_NODES, false);

int visit(int node, int consecutiveCoffees) {
    consecutiveCoffees = coffees[node] ? consecutiveCoffees + 1 : 0;
    if (consecutiveCoffees > M) return 0;

    int result = 0;
    bool leaf = true;
    visited[node] = true;
    for (auto &i : children[node]) {
        if (!visited[i]) {
            leaf = false;
            result += visit(i, consecutiveCoffees);
        }
    }

    if (leaf) return 1;
    return result;
}

int main() {
    char buff;
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        std::cin >> buff;
        coffees[i] = buff - '0';
    }

    int a, b;
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }

    std::cout << visit(1, 0);
    return 0;
}