/*

Serialization:
 Time complexity :
 Space complexity :
 
 Deserialization:
  Time complexity :
  Space  complexity: 
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream stream;
        serialize(root, stream);
        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream stream(data);
        deque<int> preorder(istream_iterator<int>{stream}, istream_iterator<int>());
        deque<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return deserialize(preorder, inorder, -1);
    }
    
private:
    void serialize(TreeNode* node, stringstream& stream) {
        if (!node) {
            return;
        }
        stream << node->val << " ";
        serialize(node->left, stream);
        serialize(node->right, stream);
    }
    
    TreeNode* deserialize(deque<int>& preorder, deque<int>& inorder, int stop) {
        if (preorder.empty()) {
            return nullptr;
        }
        
        if (inorder.front() == stop) {
            inorder.pop_front();
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(preorder.front());
        preorder.pop_front();
        node->left = deserialize(preorder, inorder, node->val);
        node->right = deserialize(preorder, inorder, stop);
        return node;
    }
};
