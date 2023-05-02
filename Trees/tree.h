#ifndef TREE_JACTGRL_H
#define TREE_JACTGRL_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

#endif //TREE_JSCTGRL_H
