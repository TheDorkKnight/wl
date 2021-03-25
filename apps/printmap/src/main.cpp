#include <iostream>
#include <iomanip>
#include <wl/wl.h>
#include <wl/default_map.h>

void print_id(wl::MapNode::ID id) {
	std::cout << std::setfill('0') << std::setw(3) <<
		static_cast<std::size_t>(map_id_to_label(id));
}

void print_adjacency(const wl::MapNode::Adjacency& adjacency) {
	print_id(adjacency.id());
	if (adjacency.is_water_border()) {
		std::cout << "(water border)";
	}
}

void print_adjacency_list(std::span<const wl::MapNode::Adjacency> adjacency_list) {
	const auto num_elements = adjacency_list.size();
	switch (num_elements) {
	case 0: return;
	case 1: print_adjacency(adjacency_list.front()); return;
	default:
		break;
	}

	const auto all_but_last = adjacency_list.first(num_elements - 1);
	for (const auto adjacency : all_but_last) {
		print_adjacency(adjacency);
		std::cout << ",";
	}
	print_adjacency(adjacency_list.back());
}

void print_jack_node(const wl::JackNode& jack_node,
	                 const wl::MapNode& map_node) {
	std::cout << "\t\tneighbors: ";
	print_adjacency_list(map_node.neighbors());
	if (!jack_node.can_drop_evidence()) {
		std::cout << std::endl << "\t\tcan drop evidence: false" << std::endl;
	}
	if (jack_node.is_water()) {
		std::cout << "\t\tis water: true" << std::endl;
	}
}

void print_investigator_node(const wl::InvestigatorNode& investigator_node,
	                         const wl::MapNode& map_node) {
	std::cout << "\t\tneighbors: ";
	print_adjacency_list(map_node.neighbors());
	std::cout << std::endl << "\t\tcan start: " <<
		(investigator_node.is_starting_position() ? "true" : "false") << std::endl;
}

void print_graph(const wl::MapGraph& graph) {
	std::cout << "graph:" << std::endl; 
	{
		wl::MapNode::ID id = graph.base_jack_node_id();
		for (const auto& jack_node : graph.jack_nodes()) {
			std::cout << "\tj ";
			print_id(id);
			std::cout << ":" << std::endl;
			print_jack_node(jack_node, graph.map_node(id));
			++id;
		}
	}
	{
		wl::MapNode::ID id = graph.base_investigator_node_id();
		for (const auto& investigator_node : graph.investigator_nodes()) {
			std::cout << "\ti ";
			print_id(id);
			std::cout << ":" << std::endl;
			print_investigator_node(investigator_node, graph.map_node(id));
			++id;
		}
	}
}


int main(int argc, char** argv) {
	const wl::MapGraph map_graph{wl::default_map()};
	std::cout << "Hello Rigel!" << std::endl;
	print_graph(map_graph);
	return 0;
}
