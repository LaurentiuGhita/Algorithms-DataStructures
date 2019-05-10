#include <iostream>
#include <memory>
#include <queue>
#include <stack>

template <typename T>
struct TreeNode {
    TreeNode(const T val) : _val(val) {}

    template <typename T>
    void add_left_child(const T v) {
        _left = std::make_unique<TreeNode>(v);
    }

    template <typename T>
    void add_right_child(const T v) {
        _right = std::make_unique<TreeNode>(v);
    }

    std::unique_ptr<TreeNode>& get_left_child() {
        return _left;
    }

    std::unique_ptr<TreeNode>& get_right_child() {
        return _right;
    }

    T get_val() {
        return _val;
    }

    T _val;
    std::unique_ptr<TreeNode> _left{ nullptr };
    std::unique_ptr<TreeNode> _right{ nullptr };
};


template <typename T>
class BinaryTree
{
public:
    BinaryTree() : _root(nullptr) {}

    BinaryTree(T val) : 
        _root(std::make_unique < TreeNode<T>>(val)) {}


    void add_item(T val) {
        add_item(val, _root);
    }

    void ReverseBFSTraversal() {
        std::queue<TreeNode<T>*> q;
        std::stack<T> s;
        q.push(_root.get());

        while (q.empty() == false) {

            s.push(q.front()->get_val());
            auto item = q.front();
            q.pop();

            if (item->get_left_child())
                q.push(item->get_left_child().get());

            if (item->get_right_child())
                q.push(item->get_right_child().get());
        }

        std::cout << "Reverse bfs: ";
        while (s.empty() == false) {
            std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << "\n";
    }


    void BFSTraversal() {
        std::queue<TreeNode<T>*> q;
        
        q.push(_root.get());
        std::cout << "Bfs traversal: ";
        while (q.empty() == false) {
            
            std::cout << q.front()->get_val() << " ";
            auto item = q.front();
            q.pop();

            if (item->get_left_child())
                q.push(item->get_left_child().get());

            if (item->get_right_child())
                q.push(item->get_right_child().get());
        }
        std::cout << "\n";
    }

private:
    void add_item(T val, std::unique_ptr<TreeNode<T>>& node) {
        if (node == nullptr) {
            node = std::make_unique<TreeNode<T>>(val);
        }
        else {
            const auto& node_val = node->get_val();
            if (val <= node_val)
                add_item(std::forward<T>(val), node->get_left_child());
            else
                add_item(std::forward<T>(val), node->get_right_child());
        }
    }

    std::unique_ptr<TreeNode<T>> _root;
};


int main() {
    BinaryTree<int> tree(7);

    tree.add_item(4);
    tree.add_item(1);
    tree.add_item(5);
    tree.add_item(9);
    tree.add_item(8);
    tree.add_item(12);

    tree.BFSTraversal();
    tree.ReverseBFSTraversal();

}