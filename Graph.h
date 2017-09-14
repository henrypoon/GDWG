#ifndef ASSN3_GRAPH_H
#define ASSN3_GRAPH_H
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

namespace gdwg {
	
	template <typename N, typename E> class Graph {
	
	public:
		Graph() {}; //default constructor
		
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
		public:
			Node(const N& n) : nodePtr{std::make_shared<N>(n)} {};
			bool addEdge(const Node& dst, const E& w);
			bool isExisted(const Node& dest, const E& w) const;
			bool isConnected(const Node& dst) const;
			void printNode() const;
			const N& getNode() const { return *nodePtr; }
			void printEdges() const;
			void replace(const N& newData);
			std::shared_ptr<N> getPtr() const;

		private:
			class Edge {
			public:
				Edge(const Node& n, const E& e) : weight{std::make_shared<E>(e)} {destNode = n.getPtr();};
				const E& getWeight() const { return *weight; }
				N& getDest() const;
				void printEdge() const;
				std::shared_ptr<N> getDestPtr() const;
			private:
				std::shared_ptr<E> weight;	
				std::weak_ptr<N> destNode;
			};

			std::shared_ptr<N> nodePtr;
			std::vector<Edge> edges;

		};
		auto findNode(const N& node) const; 
		auto findNode(const N& node);
		std::vector<Node> nodes;
	};

    #include "Graph.tem"
}

#endif 