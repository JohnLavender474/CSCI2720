#pragma once

#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <functional>
#include <algorithm>

#include "DynamicArray.h"

template<typename T> class Vertex;

template<typename T> class Graph {

public:
	
	Graph();
	
	~Graph();
	
	bool contains_vertex(T t);
	
	bool add_vertex(T t);
	
	bool contains_edge(T u, T v);
	
	bool put_edge(T u, T v);
	
	int edge_count(T t);
	
	bool remove_vertex(T t);
	
	bool remove_edge(T u, T v);
	
	bool edges(T t, std::vector<T> &edges);
	
	bool highest_edge_count(T &t, std::vector<T> &edges);
	
	std::vector<T> shortest_path(T u, T v);
	
	std::vector<std::vector<T>> shortest_path_tree(T u);
	
	void for_each(std::function<void(const T &, const std::vector<T> &)> function);
	
	int degree(T t);
	
	friend std::ostream &operator<<(std::ostream &stream, const Graph<T> &graph) {
		int index_v = 0;
		graph.vertices
				.for_each([&graph, &stream, &index_v](Vertex<T> *v) {
					stream << "VERTEX " << ++index_v << ": " << *v << std::endl;
					int index_e = 0;
					for (const int &i : v->edges) {
						Vertex<T> *o = *graph.vertices
								.ptr_to(i);
						stream << "\tEDGE " << ++index_e << ": " << *o << std::endl;
					}
				});
		return stream;
	}

private:
	
	DynamicArray<Vertex<T> *> vertices;
	
	int index_of_vertex(T t);
	
	Vertex<T> *get_vertex(T t);
	
	int generate_id();
	
	int max_id;
	
	std::queue<int> recycled_ids;
	
};

template<typename T> class Vertex {
	friend class Graph<T>;

private:
	
	Vertex() = delete;
	
	Vertex(T info, int id);
	
	~Vertex() = default;
	
	T info;
	int id;
	std::set<int> edges;
	bool encountered;
	int predecessor_id;
	
	friend bool operator==(const Vertex<T> &v1, const Vertex<T> &v2) {
		return v1.info == v2.info;
	}
	
	friend std::ostream &operator<<(std::ostream &stream, const Vertex<T> &v) {
		return stream << v.info;
	}
	
};

template<typename T> Vertex<T>::Vertex(T info, int id) :
		info(info), id(id), encountered(false), predecessor_id(-1) {
}

template<typename T> Graph<T>::Graph() :
		max_id(0) {
}

template<typename T> Graph<T>::~Graph() {
	for (Vertex<T> *v : vertices) {
		delete v;
	}
}

template<typename T> bool Graph<T>::contains_vertex(T t) {
	bool contains = false;
	vertices.for_each([&t, &contains](const Vertex<T> *v) {
		if (t == v->info) {
			contains = true;
		}
	});
	return contains;
}

template<typename T> bool Graph<T>::add_vertex(T t) {
	if (contains_vertex(t)) {
		return false;
	}
	int id = generate_id();
	vertices.put(id, new Vertex<T>(t, id));
	return true;
}

template<typename T> bool Graph<T>::contains_edge(T u, T v) {
	int u_index = index_of_vertex(u);
	int v_index = index_of_vertex(v);
	if (u_index == -1 || v_index == -1) {
		return false;
	}
	Vertex<T> *u_v = *vertices.ptr_to(u_index);
	Vertex<T> *v_v = *vertices.ptr_to(v_index);
	std::set<int> u_edges = u_v->edges;
	std::set<int> v_edges = v_v->edges;
	return u_edges.find(v_index) != u_edges.end() && v_edges.find(u_index) != v_edges.end();
}

template<typename T> bool Graph<T>::put_edge(T u, T v) {
	int u_index = index_of_vertex(u);
	int v_index = index_of_vertex(v);
	if (u_index == -1 || v_index == -1) {
		return false;
	}
	Vertex<T> *u_v = *vertices.ptr_to(u_index);
	Vertex<T> *v_v = *vertices.ptr_to(v_index);
	u_v->edges
			.insert(v_index);
	v_v->edges
			.insert(u_index);
	return true;
}

template<typename T> int Graph<T>::edge_count(T t) {
	Vertex<T> *vertex = get_vertex(t);
	return vertex != nullptr ? vertex->edges
			.size() : -1;
}

template<typename T> bool Graph<T>::edges(T t, std::vector<T> &edges) {
	Vertex<T> *vertex = get_vertex(t);
	if (vertex != nullptr) {
		std::set<int> edges_i = vertex->edges;
		for (const int &i : edges_i) {
			Vertex<T> *edge = *vertices.ptr_to(i);
			edges.push_back(edge->info);
		}
		return true;
	}
	return false;
}

template<typename T> bool Graph<T>::highest_edge_count(T &t, std::vector<T> &edges) {
	if (vertices.get_size() == 0) {
		return false;
	}
	Vertex<T> *temp;
	int count = 0;
	vertices.for_each([&temp, &count](Vertex<T> *v) {
		if (count < v->edges
				.size()) {
			count = v->edges
					.size();
			temp = v;
		}
	});
	t = temp->info;
	std::set<int> edges_i = temp->edges;
	for (const int &i : edges_i) {
		Vertex<T> *v = *vertices.ptr_to(i);
		edges.push_back(v->info);
	}
	return true;
}

template<typename T> bool Graph<T>::remove_vertex(T t) {
	int i = index_of_vertex(t);
	if (i == -1) {
		return false;
	}
	Vertex<T> *t_v = *vertices.ptr_to(i);
	std::set<int> edges = t_v->edges;
	for (const int &j : edges) {
		Vertex<T> *o_v = *vertices.ptr_to(j);
		o_v->edges
				.erase(i);
	}
	delete t_v;
	vertices.put(i, nullptr);
	vertices.remove_at(i);
	recycled_ids.push(i);
	return true;
}

template<typename T> bool Graph<T>::remove_edge(T u, T v) {
	int u_index = index_of_vertex(u);
	int v_index = index_of_vertex(v);
	if (u_index == -1 || v_index == -1) {
		return false;
	}
	Vertex<T> *u_v = *vertices.ptr_to(u_index);
	Vertex<T> *v_v = *vertices.ptr_to(v_index);
	u_v->edges
			.erase(v_index);
	v_v->edges
			.erase(u_index);
	return true;
}

template<typename T> int Graph<T>::index_of_vertex(T t) {
	for (auto it = vertices.begin(); it != vertices.end(); ++it) {
		Vertex<T> *v = *it;
		if (v != nullptr) {
			if (t == v->info) {
				return v->id;
			}
		}
	}
	return -1;
}

template<typename T> int Graph<T>::generate_id() {
	if (recycled_ids.empty()) {
		return max_id++;
	} else {
		int i = recycled_ids.front();
		recycled_ids.pop();
		return i;
	}
}

template<typename T> std::vector<T> Graph<T>::shortest_path(T u, T v) {
	std::vector<T> path;
	vertices.for_each([](Vertex<T> *v) {
		v->encountered = false;
		v->predecessor_id = -1;
	});
	Vertex<T> *start = get_vertex(u);
	Vertex<T> *end = get_vertex(v);
	if (start == nullptr || end == nullptr) {
		return path;
	}
	if (start->edges
			    .size() == 0 || end->edges
					                    .size() == 0) {
		return path;
	}
	std::queue<Vertex<T> *> v_q;
	start->encountered = true;
	v_q.push(start);
	Vertex<T> *temp;
	while (!v_q.empty()) {
		temp = v_q.front();
		v_q.pop();
		for (const int &i : temp->edges) {
			Vertex<T> *neighbor = *vertices.ptr_to(i);
			if (!neighbor->encountered) {
				neighbor->encountered = true;
				neighbor->predecessor_id = temp->id;
				v_q.push(neighbor);
			}
		}
	}
	temp = end;
	while (temp->predecessor_id != -1) {
		path.push_back(temp->info);
		int pred_id = temp->predecessor_id;
		temp = *vertices.ptr_to(pred_id);
	}
	path.push_back(temp->info);
	return path;
}

template<typename T> std::vector<std::vector<T>> Graph<T>::shortest_path_tree(T u) {
	DynamicArray<Vertex<T> *> v_cpy = vertices;
	v_cpy.remove_if([&u](const Vertex<T> *v) {
		return u == v->info;
	});
	std::vector<std::vector<T>> vec_of_paths;
	v_cpy.for_each([&](const Vertex<T> *v) {
		std::vector<T> path = shortest_path(u, v->info);
		if (!path.empty()) {
			vec_of_paths.push_back(path);
		}
	});
	sort(vec_of_paths.begin(), vec_of_paths.end(), [](const std::vector<T> &vec1, const std::vector<T> &vec2) {
		return vec1.size() < vec2.size();
	});
	return vec_of_paths;
}

template<typename T> int Graph<T>::degree(T t) {
	Vertex<T> *v = get_vertex(t);
	return v != nullptr ? v->edges
			.size() : -1;
}

template<typename T> Vertex<T> *Graph<T>::get_vertex(T t) {
	int i = index_of_vertex(t);
	return i == -1 ? nullptr : *vertices.ptr_to(index_of_vertex(t));
}

template<typename T> void Graph<T>::for_each(std::function<void(const T &, const std::vector<T> &)> function) {
	vertices.for_each([&, function](Vertex<T> *v) {
		std::vector<T> edges_info;
		for (const int &e : v->edges) {
			Vertex<T> *edge = *vertices.ptr_to(e);
			edges_info.push_back(edge->info);
		}
		function(v->info, edges_info);
	});
}



