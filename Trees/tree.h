#ifndef TREE_JACTGRL_H
#define TREE_JACTGRL_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#pragma region DEFINITION
namespace Trees
{

    template <typename T>
    struct TreeNode
    {
        TreeNode<T>* left;
        TreeNode<T>* right;
        T value;

        TreeNode(T n_value = 0, TreeNode<T>* n_left = nullptr, TreeNode<T>* n_right = nullptr);
        ~TreeNode();

        void print();
        inline bool one_free_leaf();
    };

    template <typename T>
    class Tree
    {
    public:

        TreeNode<T>* root;

        Tree(TreeNode<T>* node = nullptr);
        Tree(const Tree<T>& other) = default; // // // // //

        template <typename lambda>
        TreeNode<T>* BFS(lambda criteria);
        void insert_node(TreeNode<T>* node);
        void insert_value(T val);
        void print_recursively();

    };

    template <typename T>
    Tree<T> construct(std::vector<T>& arr);


} //namnespace trees
#pragma endregion DEFINITION

#pragma region IMPLEMENTATION
namespace Trees
{

    template <typename T>
    TreeNode<T>::TreeNode(T n_value, TreeNode<T>* n_left, TreeNode<T>* n_right)
        :left(n_left), right(n_right), value(n_value) {}

    template <typename T>
    TreeNode<T>::~TreeNode()
    {
        delete left;
        delete right;
    }

    template <typename T>
    void TreeNode<T>::print()
    {
        std::cout << value << '\n';
        if (left) left->print();
        else std::cout << "end of left branch\n";

        if (right) right->print();
        else std::cout << "end of right branch\n";
    }

    template <typename T>
    inline bool TreeNode<T>::one_free_leaf()
    {
        return static_cast<bool>(left) != static_cast<bool>(right);
    }

    template <typename T>
    Tree<T>::Tree(TreeNode<T>* node)
        :root(node) {}

    template <typename T>
    template <typename lambda>
    TreeNode<T>* Tree<T>::BFS(lambda criteria)
    {
        if (!root) return nullptr; //nullptrs should never be in the queue

        std::queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode<T>* current_node = q.front();
            q.pop();

            if (criteria(current_node))
                return current_node;

            if (current_node->left)
                q.push(current_node->left);
            if (current_node->right)
                q.push(current_node->right);
        }
        return nullptr;
    }

    template <typename T>
    void Tree<T>::insert_node(TreeNode<T>* node)
    {
        TreeNode<T>* target = BFS(\
            [](TreeNode<T>* n) -> bool           \
        {return !(n->left && n->right); });

        if (!target) { root = node; return; }

        if (!target->left) { target->left = node; return; }
        if (!target->right) { target->right = node; return; }
    }

    template <typename T>
    void Tree<T>::insert_value(T val)
    {
        insert_node(new TreeNode<T>(val));
    }

    template <typename T>
    void Tree<T>::print_recursively()
    {
        root->print();
    }

    template <typename T>
    Tree<T> construct(std::vector<T>& arr)
    {
        Tree<T> ret;
        for (T x : arr)
            ret.insert_value(x);

        return ret;
    }

} //namespace Trees
#pragma endregion IMPLEMENTATION

#endif //TREE_JSCTGRL_H
