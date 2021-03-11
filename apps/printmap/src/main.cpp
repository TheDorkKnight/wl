#include <iostream>
#include <iomanip>
#include <wl/wl.h>
#include <wl/j_nodes.h>

void print_id(wl::MapNode::ID id) {
	std::cout << std::setfill('0') << std::setw(3) << static_cast<std::size_t>(map_id_to_label(id));
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

void print_jack_node(const wl::JackNode& jack_node,
	                 const wl::MapNode& map_node) {
	std::cout << "\t\tneighbors: ";
	print_id_list(map_node.neighbors());
	std::cout << std::endl << "\t\tcan drop evidence: " <<
		(jack_node.can_drop_evidence() ? "true" : "false") << std::endl;
	const auto water_body_id = jack_node.water_body_id();
	if (water_body_id.has_value()) {
		std::cout << std::endl << "\t\twater body id: " << static_cast<std::size_t>(*water_body_id) << std::endl;
	}
}

void print_investigator_node(const wl::InvestigatorNode& investigator_node,
	                         const wl::MapNode& map_node) {
	std::cout << "\t\tneighbors: ";
	print_id_list(map_node.neighbors());
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

static constexpr std::array<wl::MapNode,7> map_nodes = {
	/*j001*/wl::MapNode{wl::j001_nbors},
	/*j002*/wl::MapNode{wl::j002_nbors},
	/*j003*/wl::MapNode{wl::j003_nbors},
	/*j004*/wl::MapNode{wl::j004_nbors},
	/*j005*/wl::MapNode{wl::j005_nbors},
	/*j006*/wl::MapNode{wl::j006_nbors},
	/*j007*/wl::MapNode{wl::j007_nbors}
};

static constexpr std::array<wl::JackNode,7> jack_nodes = {
	/*j001*/wl::JackNode{},
	/*j002*/wl::JackNode{},
	/*j003*/wl::JackNode{},
	/*j004*/wl::JackNode{wl::JackNode::NoEvidence{}},
	/*j005*/wl::JackNode{},
	/*j006*/wl::JackNode{},
	/*j007*/wl::JackNode{}
};

static constexpr std::array<wl::InvestigatorNode,0> investigator_nodes = {
};

int main(int argc, char** argv) {
	const wl::MapGraph map_graph{map_nodes, jack_nodes, investigator_nodes};
	std::cout << "Hello Rigel!" << std::endl;
	print_graph(map_graph);
	return 0;
}
