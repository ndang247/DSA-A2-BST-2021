#include "tree.hpp"

void Test1() {
	BST<int> t;
	
	t.add_vertex("A", 1);
	t.add_vertex("B", 3);
	t.add_vertex("C", 5);
	t.add_vertex("D", 10);
	t.add_vertex("G", 20);
	t.add_vertex("E", 15);
	t.add_vertex("H", 30);
	t.add_vertex("F", 17);
	// t.add_vertex("I", 20);
	// t.add_vertex("J", 15);
	// t.add_vertex("A", 7);

	cout << boolalpha;
	
	//t.remove_vertex("D");

	cout << "number of vertices is: " << endl;
	cout << t.num_vertices() << endl;

	cout << "number of edges is: " << endl;
	cout << t.num_edges() << endl;

	cout << "bst contains Z: " << endl;
	cout << t.contains("Z") << endl;

	cout << "bst contains H: " << endl;
	cout << t.contains("H") << endl;

	cout << "the sum weight of bst is: " << endl;
	cout << t.sum_weight() << endl;

	cout << "preorder_traversal: " << endl;
	for(auto x : t.preorder_traversal()){
		cout << x << " ";
	}
	cout << endl;

	cout << "breadth_first_traversal: " << endl;
	for(auto x : t.breadth_first_traversal()){
		cout << x << " ";
	}
	cout << endl;
	
	cout << "leaves are: " << endl;
	for(auto x : t.get_leaves()){
		cout << x << " " << endl;
	}

	cout << "edges are: " << endl;
	for(auto x : t.get_edges()){
		cout << x.first << " " << x.second << " " << endl;
	}

	cout << "vertices are: " << endl;
	for(auto x : t.get_vertices()){
		cout << x << " " << endl;
	}

	cout << "neighbours of G are: " << endl;
	for(auto x : t.get_neighbours("G")){
		cout << x << " " << endl;
	}

	cout << "path from H to E: " << endl;
	for(auto x : t.path("H", "E")){
		cout << x << " ";
	}
	cout << endl;

	cout << "path from D to B: " << endl;
	for(auto x : t.path("D", "B")){
		cout << x << " ";
	}
	cout << endl;

	cout << "path with largest weight: " << endl;
	for(auto x : t.path_with_largest_weight()){
		cout << x << " ";
	}
	cout << endl;

	cout << "the height of bst is: " << endl;
	cout << t.height() << " " << endl;
}

void Test2() {
	BST<int> t;
	
	t.add_vertex("C", 5);
	t.add_vertex("A", 1);
	t.add_vertex("H", 10);
	t.add_vertex("D", 3);
	t.add_vertex("G", 20);
	t.add_vertex("F", 15);
	t.add_vertex("B", 30);
	t.add_vertex("E", 17);
	// t.add_vertex("I", 20);
	// t.add_vertex("J", 15);
	// t.add_vertex("A", 7);
	
	cout << boolalpha;

	//t.remove_vertex("C");
	
	cout << "number of vertices is: " << endl;
	cout << t.num_vertices() << endl;

	cout << "number of edges is: " << endl;
	cout << t.num_edges() << endl;

	cout << "bst contains Z: " << endl;
	cout << t.contains("Z") << endl;

	cout << "bst contains H: " << endl;
	cout << t.contains("H") << endl;

	cout << "adjacent E and I: " << endl;
	cout << t.adjacent("E", "I") << endl;

	cout << "adjacent G and B: " << endl;
	cout << t.adjacent("G", "B") << endl;

	cout << "the sum weight of bst is: " << endl;
	cout << t.sum_weight() << endl;

	cout << "preorder_traversal: " << endl;
	for(auto x : t.preorder_traversal()){
		cout << x << " ";
	}
	cout << endl;

	cout << "breadth_first_traversal: " << endl;
	for(auto x : t.breadth_first_traversal()){
		cout << x << " ";
	}
	cout << endl;
	
	cout << "leaves are: " << endl;
	for(auto x : t.get_leaves()){
		cout << x << " " << endl;
	}

	cout << "vertices are: " << endl;
	for(auto x : t.get_vertices()){
		cout << x << " " << endl;
	}

	cout << "edges are: " << endl;
	for(auto x : t.get_edges()){
		cout << x.first << " " << x.second << " " << endl;
	}

	cout << "neighbours of G are: " << endl;
	for(auto x : t.get_neighbours("G")){
		cout << x << " " << endl;
	}

	cout << "path from H to E: " << endl;
	for(auto x : t.path("H", "E")){
		cout << x << " ";
	}
	cout << endl;

	cout << "path from D to B: " << endl;
	for(auto x : t.path("D", "B")){
		cout << x << " ";
	}
	cout << endl;

	cout << "path with largest weight: " << endl;
	for(auto x : t.path_with_largest_weight()){
		cout << x << " ";
	}
	cout << endl;

	cout << "the height of bst is: " << endl;
	cout << t.height() << " " << endl;
}

int main() {
	Test1();
	Test2();
}