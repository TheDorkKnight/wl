#include <iostream>
#include <wl.h>

template<class IDType>
void print_id_list(std::span<const IDType> id_list) {
	const auto num_elements = id_list.size();
	switch (num_elements) {
	case 0: return;
	case 1: std::cout << static_cast<int>(id_list[0]); return;
	default:
		break;
	}

	const auto all_but_last = id_list.first(num_elements - 1);
	for (const auto id : all_but_last) {
		std::cout << static_cast<int>(id) << ",";
	}
	std::cout << static_cast<int>(id_list.back());
}

void print_jack_node(const wl::JackNode& jack_node) {
	std::cout << "\t\tneighbors: ";
	print_id_list(jack_node.neighbors());
	std::cout << std::endl << "\t\tcan drop evidence: " <<
		(jack_node.can_drop_evidence() ? "true" : "false") << std::endl;
	const auto water_body_id = jack_node.water_body_id();
	if (water_body_id.has_value()) {
		std::cout << std::endl << "\t\twater body id: " << static_cast<int>(*water_body_id) << std::endl;
	}
}

void print_investigator_node(const wl::InvestigatorNode& investigator_node) {
	std::cout << "\t\tneighbors: ";
	print_id_list(investigator_node.neighbors());
	std::cout << std::endl << "\t\tjack neighbors: ";
	print_id_list(investigator_node.jack_neighbors());
	std::cout << std::endl << "\t\tcan start: " <<
		(investigator_node.is_starting_position() ? "true" : "false") << std::endl;
}

void print_graph(const wl::MapGraph& graph) {
	std::cout << "graph:" << std::endl; 
	{
		wl::JackNode::ID id = 0u;
		for (const auto& jack_node : graph.jack_nodes()) {
			std::cout << "\tj " << static_cast<int>(id) << ":" << std::endl;
			print_jack_node(jack_node);
			++id;
		}
	}
	{
		wl::InvestigatorNode::ID id = 0u;
		for (const auto& investigator_node : graph.investigator_nodes()) {
			std::cout << "\ti " << static_cast<int>(id) << ":" << std::endl;;
			print_investigator_node(investigator_node);
			++id;
		}
	}
}

using wl::jid;

int main(int argc, char** argv) {
	wl::MapGraph map_graph{
		{
			wl::JackNode{{jid(2u), jid(8u), jid(9u), jid(10u), jid(11u), jid(12u), jid(14u),
				          jid(28u), jid(29u)}}
		},
		{}};

	std::cout << "Hello Rigel!" << std::endl;
	print_graph(map_graph);
	return 0;
}
