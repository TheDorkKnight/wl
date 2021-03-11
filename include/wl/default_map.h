#ifndef WL_DEFAULT_MAP_H
#define WL_DEFAULT_MAP_H

#include <array>
#include <span>
#include <wl/wl.h>
#include <wl/j_nodes.h>

namespace wl {

static constexpr std::array<MapNode,7> map_nodes = {
	/*j001*/MapNode{j001_nbors},
	/*j002*/MapNode{j002_nbors},
	/*j003*/MapNode{j003_nbors},
	/*j004*/MapNode{j004_nbors},
	/*j005*/MapNode{j005_nbors},
	/*j006*/MapNode{j006_nbors},
	/*j007*/MapNode{j007_nbors}
};

static constexpr std::array<JackNode,7> jack_nodes = {
	/*j001*/JackNode{},
	/*j002*/JackNode{},
	/*j003*/JackNode{},
	/*j004*/JackNode{JackNode::NoEvidence{}},
	/*j005*/JackNode{},
	/*j006*/JackNode{},
	/*j007*/JackNode{}
};

static constexpr std::span<const InvestigatorNode, 0> investigator_nodes;

constexpr MapGraph default_map() noexcept {
	return MapGraph{map_nodes, jack_nodes, investigator_nodes};
}

} // namespace wl

#endif
