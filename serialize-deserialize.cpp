
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    
        string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    
    TreeNode* deserialize(const string& data) {
         istringstream ss(data);
         queue<string> nodes;
         string node;
        while (getline(ss, node, ',')) {
            nodes.push(node);
        }
        return deserializeHelper(nodes);
    }

private:
    void serializeHelper(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "#,";
        } else {
            result += to_string(root->val) + ",";
            serializeHelper(root->left, result);
            serializeHelper(root->right, result);
        }
    }

    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        if (val == "#") {
            return nullptr;
        } else {
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserializeHelper(nodes);
            root->right = deserializeHelper(nodes);
            return root;
        }
    }
};


TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    return root;
}


void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "# ";
    } else {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    Codec codec;
    TreeNode* root = createTree();

    string serializedTree = codec.serialize(root);
    cout << "Serialized tree: " << serializedTree << endl;

    TreeNode* deserializedTree = codec.deserialize(serializedTree);
    cout << "Deserialized tree (pre-order): ";
    printTree(deserializedTree);
    cout <<endl;

    // Cleanup memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}










