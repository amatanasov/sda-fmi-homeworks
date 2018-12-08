#include <iostream>
#include <iomanip>
#include <queue>

struct Node {
    int key;
    Node *left = nullptr, *right = nullptr;

    Node(int key) : key(key) {}

    ~Node() {
        delete left;
        delete right;
    }
};

struct Tree {
public:
    void insert(int key) {
        root = insertLevel(root, key, 0);
    }

    std::vector<float> levelAvgsQueue() {
        using levelNode = std::pair<Node *, int>;
        std::vector<float> result;
        std::queue<levelNode> q;
        if (root) { 
            q.push({root, 0});
        }
        
        int currentSum = 0;
        int currentCount = 0;
        int currentLevel = 0;
        while (!q.empty()) {
            levelNode n = q.front();
            q.pop();
            // Node not null
            if (n.first) {
                if (n.second != currentLevel) {
                    result.push_back(currentSum / (float) currentCount);
                    currentLevel = n.second;
                    currentCount = 1;
                    currentSum = n.first->key;
                } else {
                    currentSum += n.first->key;
                    currentCount++;
                }

                q.push({n.first->left, n.second + 1});
                q.push({n.first->right, n.second + 1});
            }
        }

        result.push_back(currentSum / (float) currentCount);
        return result;
    }

    ~Tree() {
        delete root;
    }

private:
    Node *insertLevel(Node *root, int key, int level) {
        if (!root) {
            maxLevels = std::max(level, maxLevels);
            return new Node(key);
        }

        if (root->key <= key) {
            root->right = insertLevel(root->right, key, level + 1);
        } else {
            root->left = insertLevel(root->left, key, level + 1);
        }

        return root;
    }

    Node *root = nullptr;
    int maxLevels = -1;
};

int main() {
    Tree t;
    int n, buff;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> buff;
        t.insert(buff);
    }

    auto avgs = t.levelAvgsQueue();
    std::cout << std::fixed << std::setprecision(2);
    for (auto &r : avgs) {
        std::cout << r << std::endl;
    }
    return 0;
}