#include <iostream>
#include <iomanip>
#include <wl/wl.h>
#include <wl/j_nodes.h>

void print_id(wl::JackNode::ID id) {
	std::cout << std::setfill('0') << std::setw(3) << static_cast<int>(jid_to_label(id));
}

void print_id(wl::InvestigatorNode::ID id) {
	std::cout << static_cast<int>(id);
}

template<class IDType>
void print_id_list(std::span<const IDType> id_list) {
	const auto num_elements = id_list.size();
	switch (num_elements) {
	case 0: return;
	case 1: print_id(id_list.front()); return;
	default:
		break;
	}

	const auto all_but_last = id_list.first(num_elements - 1);
	for (const auto id : all_but_last) {
		print_id(id);
		std::cout << ",";
	}
	print_id(id_list.back());
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
		wl::JackNode::ID id{ static_cast<std::uint8_t>(0u) };
		for (const auto& jack_node : graph.jack_nodes()) {
			std::cout << "\tj ";
			print_id(id);
			std::cout << ":" << std::endl;
			print_jack_node(jack_node);
			++id;
		}
	}
	{
		wl::InvestigatorNode::ID id{ static_cast<std::uint8_t>(0u) };
		for (const auto& investigator_node : graph.investigator_nodes()) {
			std::cout << "\ti ";
			print_id(id);
			std::cout << ":" << std::endl;
			print_investigator_node(investigator_node);
			++id;
		}
	}
}

using wl::jid;

int main(int argc, char** argv) {
	wl::MapGraph map_graph{
		{
		/*j001*/wl::JackNode{wl::j001_nbors},
		/*j002*/wl::JackNode{wl::j002_nbors},
		/*j003*/wl::JackNode{wl::j003_nbors},
		/*j004*/wl::JackNode{wl::j004_nbors, wl::JackNode::NoEvidence{}},
		/*j005*/wl::JackNode{wl::j005_nbors},
		/*j006*/wl::JackNode{wl::j006_nbors},
		/*j007*/wl::JackNode{wl::j007_nbors}
		},
		{}};

	std::cout << "Hello Rigel!" << std::endl;
	print_graph(map_graph);
	return 0;
}
