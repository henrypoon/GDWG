#ifndef ASSN3_GRAPH_H
#define ASSN3_GRAPH_H
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

namespace gdwg {
	
	template <typename N, typename E> class Graph {
	
	class Node;
	class Edge;

	public:
		Graph() {}; //defaust constructor
		
		Graph(const Graph &);	//copy constructor
		Graph(Graph &&);		//move constructor

		Graph &operator=(const Graph &);
		Graph &operator=(const Graph &&);

		bool addNode(const N&);
		bool addEdge(const N& src, const N& dst, const E& w);
		bool replace(const N& oldData, const N& newData);
		void mergeReplace(const N& oldData, const N& newData);
		void deleteNode(const N&) noexcept;
		void deleteEdge(const N& src, const N& dst, const E& w) noexcept;
		void clear() noexcept;
		bool isNode(const N& val) const;
		bool isConnected(const N& src, const N& dst) const;
		void printNodes() const;
		void printEdges(const N& val) const;

	private:
		class Node {
			class Edge;
		public:
			Node(const N& n) : nodePtr{std::make_shared<N>(n)} {};
			void printNode() const;
			const N& getNode() const { return *nodePtr; }
		private:
			class Edge {
			public:
				Edge(const Node& n, const E& e);

			private:
				std::shared_ptr<E> weight;	
				std::weak_ptr<N> destNode;
			};

			std::vector<Edge> edges;
			std::shared_ptr<N> nodePtr;

		};
		std::vector<Node> nodes;
	};

    #include "Graph.tem"
}

#endif 