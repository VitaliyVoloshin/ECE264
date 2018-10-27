//=============================================================================
//== FILENAME:          "october_25.c"
//== WRITTEN BY:        Andrew St. Pierre 
//== LAST MODIFIED:     25/10/2018 13:44:00
//=============================================================================

// ----------------------------------------------------------------------------
//===========================
//== Doubly-linked Lists 
//===========================
typedef struct listnode
{
    struct listnode * next;
    struct listnode * previous;
    int data;
    // ... <more-associated-values>
} Node;
// DOUBLY LINKED LISTS:
//  HEAD --> |_| <--> |_| <-- TAIL 
Node * p;
Node * q; 
// Advantage of doubly linked lists:
if(p==(q->next))
{  q == p->prev;  }

// Not a huge advange... why?
//  If you are performing a search on LL, no avoiding long traversals...
//  So, what is the solution??? Binary trees
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//===========================
//== Binary trees 
//===========================
typedef struct treenode
{
    struct treenode * left;
    struct treenode * right;
    int data;
    // ...
} TNode;
// ----------------------------------------------------------------------------
// Keep track of root node, giving us access to rest of data
treenode * root = NULL;
/*  BALANCED TREE:
                ---         2^0 = 1
               /   \        2^1 = 2
              / \  / \      2^2 = 4
             /\ /\/\ /\     2^3 = 8
*/
// For m nodes, height=log_2(m)
//   Binary search tree has a property where all nodes to left of 'd' are
//   less than 'd'. And 'd' is less than 'd3'
// ----------------------------------------------------------------------------
// Binary search trees:
//     |= root (has no parent)
//    / \
//   P   Z
//  /\   /\
// Q       <-- Q is P's "left-child" and called a "leaf"
// 
// P is called Q's "ancestor" if P is Q's parent or X is Q's ancestor and
// P is X's parent... i.e. has inheritance property.
// Root has no parent
// Leaf has no child
// ----------------------------------------------------------------------------
// Binary search trees (cont.)
//  - each node has a key
//  - keys must be totally ordered
//      |_ Totally ordered set S where a and b are members in the set,
//         and a>b, or a==b, or a<b
//  - wrong if for each node, key of the left chile is less than key
//    of the node or less than key of right child (not necesarilly a b.s.t.)
//  Inserting numbers in a binary search tree...
//      ex. 23,17,36,4,18,42,9,15,82
//          
//          23
//        /    \
//       17    36  
//      /  \     \
//     4   18    42
//      \          \
//       9         82
//        \
//        15

// Create a tree node and initialize values
TNode * TreeNodeCreate(v)
{
    TNode * p;
    p = malloc(sizeof(TNode));
    p->left=NULL;
    p->right=NULL;
    p->value=v;
    return p;
}

// Insert a node w. value v in binary search tree root r
TNode * TreeInsert(TNode * r, int v)
{
    // If tree is empty (exit condition)
    if(r==NULL) return TreeNodeCreate(v);

    // If value same as root, do not insert again
    if((r->value)==v) return r;

    // If not same... insert with recursion
    if((r->value) < v) r->right = TreeInsert(r->right,v);
    else r->left = TreeInsert(r->left,v);
}

// example
TNode * root = NULL;
root = TreeInsert(root,23);
root = TreeInsert(root,17);
//  NULL  -->  23  -->     23    
//                        /
//                       17

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
