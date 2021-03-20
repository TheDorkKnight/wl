#ifndef WL_DEFAULT_MAP_H
#define WL_DEFAULT_MAP_H

#include <array>
#include <span>
#include <wl/wl.h>
#include <wl/j_nodes.h>

namespace wl {

static constexpr std::array<MapNode,60> map_nodes = {
	/*j000*/MapNode{j000_nbors}, // aka j189
	/*j001*/MapNode{j001_nbors},
	/*j002*/MapNode{j002_nbors},
	/*j003*/MapNode{j003_nbors},
	/*j004*/MapNode{j004_nbors},
	/*j005*/MapNode{j005_nbors},
	/*j006*/MapNode{j006_nbors},
	/*j007*/MapNode{j007_nbors},
	/*j008*/MapNode{j008_nbors},
	/*j009*/MapNode{j009_nbors},
	/*j010*/MapNode{j010_nbors}, // 10s
	/*j011*/MapNode{j011_nbors},
	/*j012*/MapNode{j012_nbors},
	/*j013*/MapNode{j013_nbors},
	/*j014*/MapNode{j014_nbors},
	/*j015*/MapNode{j015_nbors},
	/*j016*/MapNode{j016_nbors},
	/*j017*/MapNode{j017_nbors},
	/*j018*/MapNode{j018_nbors},
	/*j019*/MapNode{j019_nbors},
	/*j020*/MapNode{j020_nbors}, // 20s
	/*j021*/MapNode{j021_nbors},
	/*j022*/MapNode{j022_nbors},
	/*j023*/MapNode{j023_nbors},
	/*j024*/MapNode{j024_nbors},
	/*j025*/MapNode{j025_nbors},
	/*j026*/MapNode{j026_nbors},
	/*j027*/MapNode{j027_nbors},
	/*j028*/MapNode{j028_nbors},
	/*j029*/MapNode{j029_nbors},
	/*j030*/MapNode{j030_nbors}, // 30s
	/*j031*/MapNode{j031_nbors},
	/*j032*/MapNode{j032_nbors},
	/*j033*/MapNode{j033_nbors},
	/*j034*/MapNode{j034_nbors},
	/*j035*/MapNode{j035_nbors},
	/*j036*/MapNode{j036_nbors},
	/*j037*/MapNode{j037_nbors},
	/*j038*/MapNode{j038_nbors},
	/*j039*/MapNode{j039_nbors},
	/*j040*/MapNode{j040_nbors}, // 40s
	/*j041*/MapNode{j041_nbors},
	/*j042*/MapNode{j042_nbors},
	/*j043*/MapNode{j043_nbors},
	/*j044*/MapNode{j044_nbors},
	/*j045*/MapNode{j045_nbors},
	/*j046*/MapNode{j046_nbors},
	/*j047*/MapNode{j047_nbors},
	/*j048*/MapNode{j048_nbors},
	/*j049*/MapNode{j049_nbors},
	/*j050*/MapNode{j050_nbors}, // 50s
	/*j051*/MapNode{j051_nbors},
	/*j052*/MapNode{j052_nbors},
	/*j053*/MapNode{j053_nbors},
	/*j054*/MapNode{j054_nbors},
	/*j055*/MapNode{j055_nbors},
	/*j056*/MapNode{j056_nbors},
	/*j057*/MapNode{j057_nbors},
	/*j058*/MapNode{j058_nbors},
	/*j059*/MapNode{j059_nbors}
};

static constexpr std::array<JackNode,60> jack_nodes = {
	/*j000*/JackNode{}, // aka j189
	/*j001*/JackNode{},
	/*j002*/JackNode{},
	/*j003*/JackNode{},
	/*j004*/JackNode{JackNode::NoEvidence{}},
	/*j005*/JackNode{},
	/*j006*/JackNode{},
	/*j007*/JackNode{},
	/*j008*/JackNode{},
	/*j009*/JackNode{},
	/*j010*/JackNode{}, // 10s
	/*j011*/JackNode{},
	/*j012*/JackNode{},
	/*j013*/JackNode{},
	/*j014*/JackNode{},
	/*j015*/JackNode{},
	/*j016*/JackNode{},
	/*j017*/JackNode{},
	/*j018*/JackNode{},
	/*j019*/JackNode{JackNode::NoEvidence{}},
	/*j020*/JackNode{JackNode::NoEvidence{}}, // 20s
	/*j021*/JackNode{JackNode::NoEvidence{}},
	/*j022*/JackNode{JackNode::NoEvidence{}},
	/*j023*/JackNode{},
	/*j024*/JackNode{},
	/*j025*/JackNode{},
	/*j026*/JackNode{},
	/*j027*/JackNode{},
	/*j028*/JackNode{},
	/*j029*/JackNode{},
	/*j030*/JackNode{}, // 30s
	/*j031*/JackNode{},
	/*j032*/JackNode{},
	/*j033*/JackNode{},
	/*j034*/JackNode{},
	/*j035*/JackNode{},
	/*j036*/JackNode{},
	/*j037*/JackNode{JackNode::NoEvidence{}},
	/*j038*/JackNode{JackNode::NoEvidence{}},
	/*j039*/JackNode{JackNode::NoEvidence{}},
	/*j040*/JackNode{JackNode::NoEvidence{}}, // 40s
	/*j041*/JackNode{JackNode::NoEvidence{}},
	/*j042*/JackNode{},
	/*j043*/JackNode{},
	/*j044*/JackNode{},
	/*j045*/JackNode{},
	/*j046*/JackNode{},
	/*j047*/JackNode{},
	/*j048*/JackNode{},
	/*j049*/JackNode{},
	/*j050*/JackNode{}, // 50s
	/*j051*/JackNode{},
	/*j052*/JackNode{},
	/*j053*/JackNode{},
	/*j054*/JackNode{},
	/*j055*/JackNode{},
	/*j056*/JackNode{JackNode::NoEvidence{}},
	/*j057*/JackNode{JackNode::NoEvidence{}},
	/*j058*/JackNode{JackNode::NoEvidence{}},
	/*j059*/JackNode{JackNode::NoEvidence{}}
};

static constexpr std::span<const InvestigatorNode, 0> investigator_nodes;

constexpr MapGraph default_map() noexcept {
	return MapGraph{map_nodes, jack_nodes, investigator_nodes};
}

} // namespace wl

#endif
