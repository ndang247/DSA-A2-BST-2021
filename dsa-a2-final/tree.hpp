#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <utility> 
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
template <typename T> // the template allows the weight of vertex to take any numeric data type (denoted by T).
class Node {
    public:
        string node_id;
        T weight;
        Node<T> *left;
        Node<T> *right;
        Node(const string&, const T&);
        ~Node();
};
template <typename T> // the template allows the weight of vertex to take any numeric data type (denoted by T).
class BST {
	public:
        /* define your data structure to represent a binary search tree (bst) */
        Node<T> *root = NULL;

        /* test1 */
        BST(); // the contructor function.
        ~BST(); // the destructor function.
        size_t num_vertices(); // returns the total number of vertices in the bst.
        size_t num_edges(); // returns the total number of edges in the bst.
        T sum_weight(); // return the total weight of all the vertices in the bst.
        void sum_weight_util(const Node<T>*, T&); // extra util function for test 1.

        /* test2 */
        void add_vertex(const string&, const T&); // adds a vertex, which has a weight, to the tree -- every vertex uses a string as its unique identifier.
        Node<T>* add_vertex_util(Node<T>*, const string&, const T&); // extra util function for test 2.
        bool contains(const string&); // checks if a vertex is in the bst -- returns true if the bst contains the given vertex; otherwise, returns false.
        
        /* test3 */
        vector<string> get_vertices(); // returns a vector of all the vertices in the bst.
        vector<string> get_leaves(); // returns a vector of all the leaves in the bst.
        // Leaves are the vertices that do not have any children in the bst.
        void get_leaves_util(const Node<T>*, vector<string>&); // extra util function for test 3.

        /* test4 */
        bool adjacent(const string&, const string&); // check if there is an edge between the two vertices in the bst -- returns true if the edge exists; otherwise, returns false.
		
        /* test5 */
        vector<pair<string,string>> get_edges(); // returns a vector of all the edges in the bst -- each edge is represented by a pair of vertices incident to the edge.
        void get_edges_util(const Node<T>*, vector<pair<string, string>>&); // extra util function for test 5.

        /* test6 */
        vector<string> get_neighbours(const string&); // returns a vector of all the vertices, each of which is directly connected with the given vertex via an edge.
        void get_neighbours_util(const Node<T>*, const Node<T>*, vector<string>&, const string&); // extra util function for test 6.
        size_t degree(const string&); // returns the degree of a vertex.

        /* test7 */
		vector<string> preorder_traversal(); // returns a vector of all the vertices in the visiting order of a preorder traversal over the bst.
		void preorder_traversal_util(const Node<T>*, vector<string>&); // extra util function for test 7.
        
        /* test8 */
        vector<string> inorder_traversal(); // returns a vector of all the vertices in the visiting order of an inorder traversal over the bst.
        void inorder_traversal_util(const Node<T>*, vector<string>&); // extra util function for test 8.

        /* test9 */
        vector<string> postorder_traversal(); // returns a vector of all the vertices in the visiting order of a postorder traversal over the bst.
        void postorder_traversal_util(const Node<T>*, vector<string>&); // extra util function for test 9.

        /* test10 */
        vector<string> breadth_first_traversal(); // returns a vector of all the vertices in the visiting order of a breadth first traversal over the bst.
		void breadth_first_traversal_util(const Node<T>*, vector<string>&); // extra util function for test 19.

        /* test11 */
        vector<string> path(const string&, const string&); // returns a vector of all the vertices in the path from the first vertex to the second vertex.
        // A path should include the source and destination vertices at the begining and the end, respectively.
        bool is_path_existed(const Node<T>*, vector<string>&, const string&); // extra util function for test 11.

        /* test12 */
        vector<string> path_with_largest_weight(); // returns a path that has the largest weight in the bst.
        // The weight of a path is the sum of the weights of all the vertices (including the source and destination vertices) in the path.
        T compute_path_sum(vector<string>&); // extra util function for test 12.
        const Node<T>* get_node(const Node<T>*, const string&); // extra util function for test 12.

        /* test13 */
        size_t height(); // returns the height of bst. Height of a tree is the number of edges that form the longest path from root to any leaf.

        /* test14 */
        void remove_vertex(const string&); // delete the given vertex from bst -- note that, all incident edges of the vertex should be deleted as well.
        Node<T>* remove_vertex_util(Node<T>*, const string&); // extra util function for test 14.
        Node<T>* min_node(Node<T>*); // extra util function for test 14.
};
template <typename T>
Node<T>::Node(const string& id, const T& w) {
    node_id = id;
    weight = w;
    left = NULL, right = NULL;
}
template <typename T>
Node<T>::~Node() {}
/* test1 */
template <typename T>
BST<T>::BST() {}
template <typename T>
BST<T>::~BST() {}

template <typename T>
size_t BST<T>::num_vertices() { return get_vertices().size(); }

template <typename T>
size_t BST<T>::num_edges() { return get_edges().size(); }

template <typename T>
T BST<T>::sum_weight() {
    T total_weight = 0;
    sum_weight_util(root, total_weight); // util function to calculation sum weight of bst.
    return total_weight;
}

template <typename T>
void BST<T>::sum_weight_util(const Node<T> *node, T& total_weight) {
    if (node == NULL) return;
    total_weight += node->weight;
    sum_weight_util(node->left, total_weight); // traverse to the left and add all the weight in left sub-tree.
    sum_weight_util(node->right, total_weight); // traverse to the right and add all the weight in right sub-tree.
}
/* test2 */
template <typename T>
void BST<T>::add_vertex(const string& u, const T& w) {
    if (contains(u)) return; // only add u if u is not in bst yet.
    // adding root.
    if (root == NULL) {
        root = add_vertex_util(root, u, w);
        return;
    }
    else add_vertex_util(root, u, w);
}

template <typename T>
Node<T>* BST<T>::add_vertex_util(Node<T> *node, const string& u, const T& w) {
    if (node == NULL) return new Node<T>(u, w);
    if (w < node->weight) node->left = add_vertex_util(node->left, u, w);
    else if (w >= node->weight) node->right = add_vertex_util(node->right, u, w); // if weight is greater than or equal to current parent node then add to the right.
    return node;
}

template <typename T>
bool BST<T>::contains(const string& u) {
    auto vertices = get_vertices();
    return find(vertices.begin(), vertices.end(), u) != vertices.end(); // true if u is in vertices otherwise false.
}
/* test3 */
template <typename T>
vector<string> BST<T>::get_vertices() { return preorder_traversal(); } // any traversal would be able to get vertices.

template <typename T>
vector<string> BST<T>::get_leaves() {
    vector<string> bst_leaves;
    get_leaves_util(root, bst_leaves);
    return bst_leaves;
}

template <typename T>
void BST<T>::get_leaves_util(const Node<T> *node, vector<string>& bst_leaves) {
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) { // push back the node that has left and right child == NULL (leaf).
            bst_leaves.push_back(node->node_id);
            return;
        }
        get_leaves_util(node->left, bst_leaves); // if the node does not has left and right == NULL continue traversing to left sub-tree.
        get_leaves_util(node->right, bst_leaves); // if the node does not has left and right == NULL continue traversing to right sub-tree.
    }
}
/* test4 */
template <typename T>
bool BST<T>::adjacent(const string& u, const string& v) { // if there is an edge {u, v} or {v, u} means that u is adjacent to v.
    auto edges = get_edges();
    return (find(edges.begin(), edges.end(), make_pair(u, v)) != edges.end() || find(edges.begin(), edges.end(), make_pair(v, u)) != edges.end()); // true if {u, v} or {v, u} is in edges.
}
/* test5 */
template <typename T>
vector<pair<string,string>> BST<T>::get_edges() {
    vector<pair<string, string>> edges;
    get_edges_util(root, edges);
    return edges;
}

template <typename T>
void BST<T>::get_edges_util(const Node<T> *node, vector<pair<string, string>>& edges) {
    if (node != NULL) {
        if (node->left != NULL) edges.push_back({node->node_id, node->left->node_id}); // push the current node id with its left child id.
        if (node->right != NULL) edges.push_back({node->node_id, node->right->node_id}); // push the current node id with its right child id.
        get_edges_util(node->left, edges); // traverse to the left to find all edges.
        get_edges_util(node->right, edges); // traverse to the right to find all edges.
    }
}
/* test6 */
template <typename T>
vector<string> BST<T>::get_neighbours(const string& u) {
    vector<string> neighbours;
    get_neighbours_util(NULL, root, neighbours, u);
    return neighbours;
}

template <typename T>
void BST<T>::get_neighbours_util(const Node<T> *parent, const Node<T> *node, vector<string>& neighbours, const string& u) {
    if (node == NULL) return;
    if (parent != NULL && node != NULL && node->node_id == u) {
        neighbours.push_back(parent->node_id);
        if (node->left != NULL) neighbours.push_back(node->left->node_id);
        if (node->right != NULL) neighbours.push_back(node->right->node_id);
        return;
    }
    else if (parent == NULL && node != NULL && node->node_id == u) { // root case when parent is null and when u is node id of parent.
        if (node->left != NULL) neighbours.push_back(node->left->node_id); // if the left of root is not null then it is a neighbour of root.
        if (node->right != NULL) neighbours.push_back(node->right->node_id); // if the right of root is not null then it is a neighbour of root.
        return;
    }
    get_neighbours_util(node, node->left, neighbours, u);
    get_neighbours_util(node, node->right, neighbours, u);
}

template <typename T>
size_t BST<T>::degree(const string& u) { return get_neighbours(u).size(); } // degree is just the size of neighbours.
/* test7 */
template <typename T>
vector<string> BST<T>::preorder_traversal() {
    vector<string> preorder_traversal_nodes;
    preorder_traversal_util(root, preorder_traversal_nodes);
    return preorder_traversal_nodes;
}

template <typename T>
void BST<T>::preorder_traversal_util(const Node<T> *node, vector<string>& preorder_traversal_nodes) {
    if (node == NULL) return;
    preorder_traversal_nodes.push_back(node->node_id);
    preorder_traversal_util(node->left, preorder_traversal_nodes);
    preorder_traversal_util(node->right, preorder_traversal_nodes);
}
/* test8 */
template <typename T>
vector<string> BST<T>::inorder_traversal() {
    vector<string> inorder_traversal_nodes;
    inorder_traversal_util(root, inorder_traversal_nodes);
    return inorder_traversal_nodes;
}

template <typename T>
void BST<T>::inorder_traversal_util(const Node<T> *node, vector<string>& inorder_traversal_nodes) {
    if (node == NULL) return;
    inorder_traversal_util(node->left, inorder_traversal_nodes);
    inorder_traversal_nodes.push_back(node->node_id);
    inorder_traversal_util(node->right, inorder_traversal_nodes);
}
/* test9 */
template <typename T>
vector<string> BST<T>::postorder_traversal() {
    vector<string> postorder_traversal_nodes;
    postorder_traversal_util(root, postorder_traversal_nodes);
    return postorder_traversal_nodes;
}

template <typename T>
void BST<T>::postorder_traversal_util(const Node<T> *node, vector<string>& postorder_traversal_nodes) {
    if (node == NULL) return;
    postorder_traversal_util(node->left, postorder_traversal_nodes);
    postorder_traversal_util(node->right, postorder_traversal_nodes);
    postorder_traversal_nodes.push_back(node->node_id);
}
/* test10 */
template <typename T>
vector<string> BST<T>::breadth_first_traversal() {
    vector<string> breadth_first_traversal_nodes;
    breadth_first_traversal_util(root, breadth_first_traversal_nodes);
    return breadth_first_traversal_nodes;
}

template <typename T>
void BST<T>::breadth_first_traversal_util(const Node<T> *node, vector<string>& breadth_first_traversal_nodes) {
    queue<const Node<T>*> q;
    q.push(node);
    while (!q.empty()) {
        const Node<T>* curr = q.front();
        q.pop();
        breadth_first_traversal_nodes.push_back(curr->node_id);
        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
    }
}
/* test11 */
template <typename T>
vector<string> BST<T>::path(const string& u, const string& v) {
    vector<string> result;
    vector<string> paths_1;
    vector<string> paths_2;
    is_path_existed(root, paths_1, u); // is there a path from root to u if true add that path in path 1 otherwise path 1 is empty.
    is_path_existed(root, paths_2, v); // is there a path from root to v if true add that path in path 2 otherwise path 2 is empty.
    int intersection = -1; // the intersection of path 1 and path 2 (that is the point where there is no duplicate path end).
    int i = 0, j = 0;
    while(i != paths_1.size() || j != paths_2.size()) {
        if (i == j && paths_1[i] == paths_2[j]) {
            i++;
            j++;
        } else {
            intersection = j - 1;
            break;
        }
    }
    for (int i = paths_1.size() - 1; i > intersection; i--)
        result.push_back(paths_1[i]);
    for (int i = intersection; i < paths_2.size(); i++)
        result.push_back(paths_2[i]);
    return result;
}

template <typename T>
bool BST<T>::is_path_existed(const Node<T> *node, vector<string>& paths, const string& x) {
    if (node == NULL) return false;
    paths.push_back(node->node_id); // store / add the node id along the path from root to x.
    if (node->node_id == x) return true;
    if (is_path_existed(node->left, paths, x) || is_path_existed(node->right, paths, x)) return true;
    paths.pop_back(); // back track and remove all the added node id if there is no exisiting path from root to x.
    return false;
}
/* test12 */
template <typename T>
vector<string> BST<T>::path_with_largest_weight() {
    map<T, vector<string>> paths; // since map is ordered the last key is the largest weight and its value is the path.
    vector<string> largest_weight_path;
    for (auto src : get_leaves()) {
        for (int i = 0; i < get_leaves().size(); i++) {
            if (src != get_leaves()[i]) {
                vector<string> leaf_to_leaf_path = path(src, get_leaves()[i]);
                T path_sum = compute_path_sum(leaf_to_leaf_path);
                if (!paths.count(path_sum)) paths.insert({path_sum, leaf_to_leaf_path}); // if the path sum (key) is not in paths then insert.
            }
        }
        largest_weight_path = prev(paths.end())->second; // get the last element value in the map.
    }
    return largest_weight_path;
}

template <typename T>
T BST<T>::compute_path_sum(vector<string>& path) {
    T sum = 0;
    for (auto vertex : path) {
        auto node = get_node(root, vertex); // get the node of given vertex.
        sum += node->weight;
    }
    return sum;
}

template <typename T>
const Node<T>* BST<T>::get_node(const Node<T>* node, const string& u) {
    if (contains(u) && node != NULL) { // if u is in bst then traverse to get node u.
        if (node->node_id == u) return node;
        else if (get_node(node->left, u) != NULL) return get_node(node->left, u); // return the left node if not null.
        else if (get_node(node->right, u) != NULL) return get_node(node->right, u); // return the right node if not null.
    }
    return NULL;
}
/* test13 */
template <typename T>
size_t BST<T>::height() {
    vector<vector<string>> path_root_to_leaf;
    size_t height = 0;
    for (auto leaf : get_leaves())
        path_root_to_leaf.push_back(path(root->node_id, leaf)); // store all the path from root to leaf.
    for (auto path : path_root_to_leaf)
        if (path.size() > height) height = path.size(); // the longest path will be assigned to height.
    return height - 1; // minus 1 to get the number edges.
}
/* test14 */
template <typename T>
void BST<T>::remove_vertex(const string& u) { root = remove_vertex_util(root, u); }

template <typename T>
Node<T>* BST<T>::remove_vertex_util(Node<T>* node, const string& u) {
    auto node_to_delete = get_node(root, u);
    if (node == NULL) return node;
    if (node_to_delete->weight < node->weight) node->left = remove_vertex_util(node->left, u);
    else if (node_to_delete->weight > node->weight) node->right = remove_vertex_util(node->right, u);
    else if (node_to_delete->weight == node->weight) { // when the node
        if (node->left == NULL && node->right == NULL) return NULL;
        else if (node->left == NULL) { // node with left child is null.
            Node<T>* temp = node->right; // store the right tree in a temp variable.
            delete node; // then delete the current node.
            return temp; // then return the temp to connect to the previous node.
        }
        else if (node->right == NULL) { // node with right child is null.
            Node<T>* temp = node->left; // store the left tree in a temp variable.
            delete node; // then delete the current node.
            return temp; // then return the temp to connect to the previous node.
        }
        // node with two children.
        Node<T>* temp = min_node(node->right);
        node->node_id = temp->node_id;
        node->weight = temp->weight;
        node->right = remove_vertex_util(node->right, temp->node_id);
    }
    return node;
}

template <typename T>
Node<T>* BST<T>::min_node(Node<T>* node) {
    Node<T>* curr = node;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}