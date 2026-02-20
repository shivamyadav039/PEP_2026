Heaps-> It is a complete binary tree which satisfies the heap property. The heap property states that for a max heap, the value of each node is greater than or equal to the values of its children, and for a min heap, the value of each node is less than or equal to the values of its children.

it is complete binary tree which follows heap order property. It is of two types - max heap and min heap

-- complete binary tree(CBT) -> all levela are completely filled except possibly the last level, the last level filled from left to right

-- heap order property -> for max heap, the value of each node is greater than or equal to the values of its children, and for min heap, the value of each node is less than or equal to the values of its children.


***important**
            heap is not a BST.

            for 1 based index 
                        for any node 
                        left child = 2*i
                        right child = 2*i+1
                        parent i/2;
            for 0 based index 
                        for any node 
                        left child = 2*i+1;
                        right child = 2*i+2;
                        parent (i-1)/2;
