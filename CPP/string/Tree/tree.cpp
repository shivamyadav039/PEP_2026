#include<iostream>
using namespace std;

/*
    Tree -> it is a non-linear, hierarchical data structure consisting of nodes connected by edges
    Binary tree -> a tree is a binary tree when every node has at most two children

    Terminologies -

    1. Leaf -> a node with no children
    2. internal node -> a node which is not a leaf
    3. Siblings -> the children of same parent
    4. Length Path -> length of path is 1 less then the number of nodes on the path
    5. Ancestors and Descendents -> if there is a path from node A to Node B, then A is called an ancestor of B and B is called a descendent of A
    6 -> subtree -> any node of a tree, with all of its descendents is a subtree
    7-> Level -> the level of the node referes to its distance from the root, the root of the tree has generally level 0
    8-> Height -> the height of a node is the length of the longest path from that node to a leaf, the height of a tree is the height of its root
    9-> Depth -> the depth of a node is the length of the path from the root to that node, the depth of the root is 0


    Properties of a binary tree -
    A-> if h = height of a binary tree, then the maximum number of leaves is 2^h
    2-> maximum number of nodes in a binary tree of height h is 2^(h+1) - 1
    B if a binary tree contains m nodes at level 1 it contains at most 2m nodes at level l+1;
    c since a binary tree can contain at most 1 node AT  level 0(root), it can be contain at most 2^l nodes level l
    D the number of edges in a full binary tree with n nodes is n-1

    TYPES OF BINARY TREES -
    1. Full binary tree -> a binary tree is a full binary tree if every node has either 0 or 2 children
    2. Complete binary tree -> a binary tree is a complete binary tree if all levels are completely filled except possibly the last level, the last level filled from last  should left to right
*/

A binary tree is balanced if for every node of the height diff b/w its left and right subtree is at most 1
 

Binary search tree -> a binary tree is a binary search tree if for every node, the value of all the nodes in its left subtree is less than the value of the node and the value of all the nodes in its right subtree is greater than the value of the node
inoreder traversal of a binary search tree gives the sorted order of the elements in the tree
 predecissor of a node in a binary search tree is the node with the largest value smaller than the value of the node
 successor of a node in a binary search tree is the node with the smallest value greater than the value of the node 
 
int main()
{
 
}