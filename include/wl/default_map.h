#ifndef WL_DEFAULT_MAP_H
#define WL_DEFAULT_MAP_H

#include <array>
#include <span>
#include <wl/wl.h>
#include <wl/j_nodes.h>
#include <wl/i_nodes.h>

namespace wl {

static constexpr std::array<MapNode,MapGraph::num_nodes_total> map_nodes = {
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
	/*j059*/MapNode{j059_nbors},
	/*j060*/MapNode{j060_nbors}, // 60s
	/*j061*/MapNode{j061_nbors},
	/*j062*/MapNode{j062_nbors},
	/*j063*/MapNode{j063_nbors},
	/*j064*/MapNode{j064_nbors},
	/*j065*/MapNode{j065_nbors},
	/*j066*/MapNode{j066_nbors},
	/*j067*/MapNode{j067_nbors},
	/*j068*/MapNode{j068_nbors},
	/*j069*/MapNode{j069_nbors},
	/*j070*/MapNode{j070_nbors}, // 70s
	/*j071*/MapNode{j071_nbors},
	/*j072*/MapNode{j072_nbors},
	/*j073*/MapNode{j073_nbors},
	/*j074*/MapNode{j074_nbors},
	/*j075*/MapNode{j075_nbors},
	/*j076*/MapNode{j076_nbors},
	/*j077*/MapNode{j077_nbors},
	/*j078*/MapNode{j078_nbors},
	/*j079*/MapNode{j079_nbors},
	/*j080*/MapNode{j080_nbors}, // 80s
	/*j081*/MapNode{j081_nbors},
	/*j082*/MapNode{j082_nbors},
	/*j083*/MapNode{j083_nbors},
	/*j084*/MapNode{j084_nbors},
	/*j085*/MapNode{j085_nbors},
	/*j086*/MapNode{j086_nbors},
	/*j087*/MapNode{j087_nbors},
	/*j088*/MapNode{j088_nbors},
	/*j089*/MapNode{j089_nbors},
	/*j090*/MapNode{j090_nbors}, // 90s
	/*j091*/MapNode{j091_nbors},
	/*j092*/MapNode{j092_nbors},
	/*j093*/MapNode{j093_nbors},
	/*j094*/MapNode{j094_nbors},
	/*j095*/MapNode{j095_nbors},
	/*j096*/MapNode{j096_nbors},
	/*j097*/MapNode{j097_nbors},
	/*j098*/MapNode{j098_nbors},
	/*j099*/MapNode{j099_nbors},
	/*j100*/MapNode{j100_nbors}, // 100s
	/*j101*/MapNode{j101_nbors},
	/*j102*/MapNode{j102_nbors},
	/*j103*/MapNode{j103_nbors},
	/*j104*/MapNode{j104_nbors},
	/*j105*/MapNode{j105_nbors},
	/*j106*/MapNode{j106_nbors},
	/*j107*/MapNode{j107_nbors},
	/*j108*/MapNode{j108_nbors},
	/*j109*/MapNode{j109_nbors},
	/*j110*/MapNode{j110_nbors}, // 110s
	/*j111*/MapNode{j111_nbors},
	/*j112*/MapNode{j112_nbors},
	/*j113*/MapNode{j113_nbors},
	/*j114*/MapNode{j114_nbors},
	/*j115*/MapNode{j115_nbors},
	/*j116*/MapNode{j116_nbors},
	/*j117*/MapNode{j117_nbors},
	/*j118*/MapNode{j118_nbors},
	/*j119*/MapNode{j119_nbors},
	/*j120*/MapNode{j120_nbors}, // 120s
	/*j121*/MapNode{j121_nbors},
	/*j122*/MapNode{j122_nbors},
	/*j123*/MapNode{j123_nbors},
	/*j124*/MapNode{j124_nbors},
	/*j125*/MapNode{j125_nbors},
	/*j126*/MapNode{j126_nbors},
	/*j127*/MapNode{j127_nbors},
	/*j128*/MapNode{j128_nbors},
	/*j129*/MapNode{j129_nbors},
	/*j130*/MapNode{j130_nbors}, // 130s
	/*j131*/MapNode{j131_nbors},
	/*j132*/MapNode{j132_nbors},
	/*j133*/MapNode{j133_nbors},
	/*j134*/MapNode{j134_nbors},
	/*j135*/MapNode{j135_nbors},
	/*j136*/MapNode{j136_nbors},
	/*j137*/MapNode{j137_nbors},
	/*j138*/MapNode{j138_nbors},
	/*j139*/MapNode{j139_nbors},
	/*j140*/MapNode{j140_nbors}, // 140s
	/*j141*/MapNode{j141_nbors},
	/*j142*/MapNode{j142_nbors},
	/*j143*/MapNode{j143_nbors},
	/*j144*/MapNode{j144_nbors},
	/*j145*/MapNode{j145_nbors},
	/*j146*/MapNode{j146_nbors},
	/*j147*/MapNode{j147_nbors},
	/*j148*/MapNode{j148_nbors},
	/*j149*/MapNode{j149_nbors},
	/*j150*/MapNode{j150_nbors}, // 150s
	/*j151*/MapNode{j151_nbors},
	/*j152*/MapNode{j152_nbors},
	/*j153*/MapNode{j153_nbors},
	/*j154*/MapNode{j154_nbors},
	/*j155*/MapNode{j155_nbors},
	/*j156*/MapNode{j156_nbors},
	/*j157*/MapNode{j157_nbors},
	/*j158*/MapNode{j158_nbors},
	/*j159*/MapNode{j159_nbors},
	/*j160*/MapNode{j160_nbors}, // 160s
	/*j161*/MapNode{j161_nbors},
	/*j162*/MapNode{j162_nbors},
	/*j163*/MapNode{j163_nbors},
	/*j164*/MapNode{j164_nbors},
	/*j165*/MapNode{j165_nbors},
	/*j166*/MapNode{j166_nbors},
	/*j167*/MapNode{j167_nbors},
	/*j168*/MapNode{j168_nbors},
	/*j169*/MapNode{j169_nbors},
	/*j170*/MapNode{j170_nbors}, // 170s
	/*j171*/MapNode{j171_nbors},
	/*j172*/MapNode{j172_nbors},
	/*j173*/MapNode{j173_nbors},
	/*j174*/MapNode{j174_nbors},
	/*j175*/MapNode{j175_nbors},
	/*j176*/MapNode{j176_nbors},
	/*j177*/MapNode{j177_nbors},
	/*j178*/MapNode{j178_nbors},
	/*j179*/MapNode{j179_nbors},
	/*j180*/MapNode{j180_nbors}, // 180s
	/*j181*/MapNode{j181_nbors},
	/*j182*/MapNode{j182_nbors},
	/*j183*/MapNode{j183_nbors},
	/*j184*/MapNode{j184_nbors},
	/*j185*/MapNode{j185_nbors},
	/*j186*/MapNode{j186_nbors},
	/*j187*/MapNode{j187_nbors},
	/*j188*/MapNode{j188_nbors},
	/*i189*/MapNode{i189_nbors}, // start of i nodes
	/*i190*/MapNode{i190_nbors}, // 190s
	/*i191*/MapNode{i191_nbors},
	/*i192*/MapNode{i192_nbors},
	/*i193*/MapNode{i193_nbors},
	/*i194*/MapNode{i194_nbors},
	/*i195*/MapNode{i195_nbors},
	/*i196*/MapNode{i196_nbors},
	/*i197*/MapNode{i197_nbors},
	/*i198*/MapNode{i198_nbors},
	/*i199*/MapNode{i199_nbors},
	/*i200*/MapNode{i200_nbors}, // 200s
	/*i201*/MapNode{i201_nbors},
	/*i202*/MapNode{i202_nbors},
	/*i203*/MapNode{i203_nbors},
	/*i204*/MapNode{i204_nbors},
	/*i205*/MapNode{i205_nbors},
	/*i206*/MapNode{i206_nbors},
	/*i207*/MapNode{i207_nbors},
	/*i208*/MapNode{i208_nbors},
	/*i209*/MapNode{i209_nbors},
	/*i210*/MapNode{i210_nbors}, // 210s
	/*i211*/MapNode{i211_nbors},
	/*i212*/MapNode{i212_nbors},
	/*i213*/MapNode{i213_nbors},
	/*i214*/MapNode{i214_nbors},
	/*i215*/MapNode{i215_nbors},
	/*i216*/MapNode{i216_nbors},
	/*i217*/MapNode{i217_nbors},
	/*i218*/MapNode{i218_nbors},
	/*i219*/MapNode{i219_nbors},
	/*i220*/MapNode{i220_nbors}, // 220s
	/*i221*/MapNode{i221_nbors},
	/*i222*/MapNode{i222_nbors},
	/*i223*/MapNode{i223_nbors},
	/*i224*/MapNode{i224_nbors},
	/*i225*/MapNode{i225_nbors},
	/*i226*/MapNode{i226_nbors},
	/*i227*/MapNode{i227_nbors},
	/*i228*/MapNode{i228_nbors},
	/*i229*/MapNode{i229_nbors},
	/*i230*/MapNode{i230_nbors}, // 230s
	/*i231*/MapNode{i231_nbors},
	/*i232*/MapNode{i232_nbors},
	/*i233*/MapNode{i233_nbors},
	/*i234*/MapNode{i234_nbors},
	/*i235*/MapNode{i235_nbors},
	/*i236*/MapNode{i236_nbors},
	/*i237*/MapNode{i237_nbors},
	/*i238*/MapNode{i238_nbors},
	/*i239*/MapNode{i239_nbors},
	/*i240*/MapNode{i240_nbors}, // 240s
	/*i241*/MapNode{i241_nbors},
	/*i242*/MapNode{i242_nbors},
	/*i243*/MapNode{i243_nbors},
	/*i244*/MapNode{i244_nbors},
	/*i245*/MapNode{i245_nbors},
	/*i246*/MapNode{i246_nbors},
	/*i247*/MapNode{i247_nbors},
	/*i248*/MapNode{i248_nbors},
	/*i249*/MapNode{i249_nbors},
	/*i250*/MapNode{i250_nbors}, // 250s
	/*i251*/MapNode{i251_nbors},
	/*i252*/MapNode{i252_nbors},
	/*i253*/MapNode{i253_nbors},
	/*i254*/MapNode{i254_nbors},
	/*i255*/MapNode{i255_nbors},
	/*i256*/MapNode{i256_nbors},
	/*i257*/MapNode{i257_nbors},
	/*i258*/MapNode{i258_nbors},
	/*i259*/MapNode{i259_nbors},
	/*i260*/MapNode{i260_nbors}, // 260s
	/*i261*/MapNode{i261_nbors},
	/*i262*/MapNode{i262_nbors},
	/*i263*/MapNode{i263_nbors},
	/*i264*/MapNode{i264_nbors},
	/*i265*/MapNode{i265_nbors},
	/*i266*/MapNode{i266_nbors},
	/*i267*/MapNode{i267_nbors},
	/*i268*/MapNode{i268_nbors},
	/*i269*/MapNode{i269_nbors}
};

static constexpr std::array<JackNode,JackNode::num_nodes_total> jack_nodes = {
	/*j000*/JackNode{}, // aka j189
	/*j001*/JackNode{},
	/*j002*/JackNode{},
	/*j003*/JackNode{},
	/*j004*/JackNode{JackNode::Type::NoEvidence},
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
	/*j019*/JackNode{JackNode::Type::NoEvidence},
	/*j020*/JackNode{JackNode::Type::NoEvidence}, // 20s
	/*j021*/JackNode{JackNode::Type::NoEvidence},
	/*j022*/JackNode{JackNode::Type::NoEvidence},
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
	/*j037*/JackNode{JackNode::Type::NoEvidence},
	/*j038*/JackNode{JackNode::Type::NoEvidence},
	/*j039*/JackNode{JackNode::Type::NoEvidence},
	/*j040*/JackNode{JackNode::Type::NoEvidence}, // 40s
	/*j041*/JackNode{JackNode::Type::NoEvidence},
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
	/*j056*/JackNode{JackNode::Type::NoEvidence},
	/*j057*/JackNode{JackNode::Type::NoEvidence},
	/*j058*/JackNode{JackNode::Type::NoEvidence},
	/*j059*/JackNode{JackNode::Type::NoEvidence},
	/*j060*/JackNode{}, // 60s
	/*j061*/JackNode{},
	/*j062*/JackNode{},
	/*j063*/JackNode{},
	/*j064*/JackNode{},
	/*j065*/JackNode{},
	/*j066*/JackNode{JackNode::Type::Water},
	/*j067*/JackNode{},
	/*j068*/JackNode{},
	/*j069*/JackNode{},
	/*j070*/JackNode{JackNode::Type::NoEvidence}, // 70s
	/*j071*/JackNode{},
	/*j072*/JackNode{},
	/*j073*/JackNode{JackNode::Type::NoEvidence},
	/*j074*/JackNode{JackNode::Type::NoEvidence},
	/*j075*/JackNode{JackNode::Type::NoEvidence},
	/*j076*/JackNode{JackNode::Type::NoEvidence},
	/*j077*/JackNode{},
	/*j078*/JackNode{},
	/*j079*/JackNode{},
	/*j080*/JackNode{JackNode::Type::Water}, // 80s
	/*j081*/JackNode{JackNode::Type::NoEvidence},
	/*j082*/JackNode{JackNode::Type::NoEvidence},
	/*j083*/JackNode{JackNode::Type::NoEvidence},
	/*j084*/JackNode{JackNode::Type::NoEvidence},
	/*j085*/JackNode{JackNode::Type::NoEvidence},
	/*j086*/JackNode{JackNode::Type::NoEvidence},
	/*j087*/JackNode{JackNode::Type::NoEvidence},
	/*j088*/JackNode{JackNode::Type::NoEvidence},
	/*j089*/JackNode{JackNode::Type::NoEvidence},
	/*j090*/JackNode{JackNode::Type::NoEvidence}, // 90s
	/*j091*/JackNode{JackNode::Type::NoEvidence},
	/*j092*/JackNode{JackNode::Type::NoEvidence},
	/*j093*/JackNode{JackNode::Type::NoEvidence},
	/*j094*/JackNode{JackNode::Type::NoEvidence},
	/*j095*/JackNode{JackNode::Type::Water},
	/*j096*/JackNode{JackNode::Type::Water},
	/*j097*/JackNode{JackNode::Type::NoEvidence},
	/*j098*/JackNode{JackNode::Type::Water},
	/*j099*/JackNode{JackNode::Type::NoEvidence},
	/*j100*/JackNode{JackNode::Type::NoEvidence}, // 100s
	/*j101*/JackNode{JackNode::Type::NoEvidence},
	/*j102*/JackNode{JackNode::Type::NoEvidence},
	/*j103*/JackNode{JackNode::Type::NoEvidence},
	/*j104*/JackNode{JackNode::Type::NoEvidence},
	/*j105*/JackNode{JackNode::Type::NoEvidence},
	/*j106*/JackNode{JackNode::Type::NoEvidence},
	/*j107*/JackNode{JackNode::Type::NoEvidence},
	/*j108*/JackNode{JackNode::Type::NoEvidence},
	/*j109*/JackNode{JackNode::Type::NoEvidence},
	/*j110*/JackNode{JackNode::Type::Water}, // 110s
	/*j111*/JackNode{JackNode::Type::Water},
	/*j112*/JackNode{JackNode::Type::NoEvidence},
	/*j113*/JackNode{JackNode::Type::Water},
	/*j114*/JackNode{JackNode::Type::NoEvidence},
	/*j115*/JackNode{JackNode::Type::NoEvidence},
	/*j116*/JackNode{JackNode::Type::NoEvidence},
	/*j117*/JackNode{JackNode::Type::Normal},
	/*j118*/JackNode{JackNode::Type::NoEvidence},
	/*j119*/JackNode{JackNode::Type::Normal},
	/*j120*/JackNode{JackNode::Type::Normal}, // 120s
	/*j121*/JackNode{JackNode::Type::Normal},
	/*j122*/JackNode{JackNode::Type::Normal},
	/*j123*/JackNode{JackNode::Type::Normal},
	/*j124*/JackNode{JackNode::Type::NoEvidence},
	/*j125*/JackNode{JackNode::Type::NoEvidence},
	/*j126*/JackNode{JackNode::Type::NoEvidence},
	/*j127*/JackNode{JackNode::Type::NoEvidence},
	/*j128*/JackNode{JackNode::Type::NoEvidence},
	/*j129*/JackNode{JackNode::Type::Normal},
	/*j130*/JackNode{JackNode::Type::Normal}, // 130s
	/*j131*/JackNode{JackNode::Type::Water},
	/*j132*/JackNode{JackNode::Type::Normal},
	/*j133*/JackNode{JackNode::Type::Normal},
	/*j134*/JackNode{JackNode::Type::Normal},
	/*j135*/JackNode{JackNode::Type::Normal},
	/*j136*/JackNode{JackNode::Type::Normal},
	/*j137*/JackNode{JackNode::Type::Normal},
	/*j138*/JackNode{JackNode::Type::Water},
	/*j139*/JackNode{JackNode::Type::Normal},
	/*j140*/JackNode{JackNode::Type::NoEvidence}, // 140s
	/*j141*/JackNode{JackNode::Type::NoEvidence},
	/*j142*/JackNode{JackNode::Type::Normal},
	/*j143*/JackNode{JackNode::Type::Water},
	/*j144*/JackNode{JackNode::Type::Water},
	/*j145*/JackNode{JackNode::Type::Normal},
	/*j146*/JackNode{JackNode::Type::Normal},
	/*j147*/JackNode{JackNode::Type::Normal},
	/*j148*/JackNode{JackNode::Type::Normal},
	/*j149*/JackNode{JackNode::Type::Normal},
	/*j150*/JackNode{JackNode::Type::Normal}, // 150s
	/*j151*/JackNode{JackNode::Type::Normal},
	/*j152*/JackNode{JackNode::Type::Normal},
	/*j153*/JackNode{JackNode::Type::Normal},
	/*j154*/JackNode{JackNode::Type::Water},
	/*j155*/JackNode{JackNode::Type::Normal},
	/*j156*/JackNode{JackNode::Type::Normal},
	/*j157*/JackNode{JackNode::Type::Water},
	/*j158*/JackNode{JackNode::Type::Water},
	/*j159*/JackNode{JackNode::Type::Normal},
	/*j160*/JackNode{JackNode::Type::Water}, // 160s
	/*j161*/JackNode{JackNode::Type::Normal},
	/*j162*/JackNode{JackNode::Type::NoEvidence},
	/*j163*/JackNode{JackNode::Type::NoEvidence},
	/*j164*/JackNode{JackNode::Type::NoEvidence},
	/*j165*/JackNode{JackNode::Type::Normal},
	/*j166*/JackNode{JackNode::Type::Water},
	/*j167*/JackNode{JackNode::Type::Water},
	/*j168*/JackNode{JackNode::Type::Normal},
	/*j169*/JackNode{JackNode::Type::Normal},
	/*j170*/JackNode{JackNode::Type::Normal}, // 170s
	/*j171*/JackNode{JackNode::Type::Normal},
	/*j172*/JackNode{JackNode::Type::Normal},
	/*j173*/JackNode{JackNode::Type::Normal},
	/*j174*/JackNode{JackNode::Type::Water},
	/*j175*/JackNode{JackNode::Type::Normal},
	/*j176*/JackNode{JackNode::Type::Normal},
	/*j177*/JackNode{JackNode::Type::Normal},
	/*j178*/JackNode{JackNode::Type::Normal},
	/*j179*/JackNode{JackNode::Type::NoEvidence},
	/*j180*/JackNode{JackNode::Type::NoEvidence}, // 180s
	/*j181*/JackNode{JackNode::Type::NoEvidence},
	/*j182*/JackNode{JackNode::Type::NoEvidence},
	/*j183*/JackNode{JackNode::Type::Normal},
	/*j184*/JackNode{JackNode::Type::Water},
	/*j185*/JackNode{JackNode::Type::Normal},
	/*j186*/JackNode{JackNode::Type::Normal},
	/*j187*/JackNode{JackNode::Type::Normal},
	/*j188*/JackNode{JackNode::Type::Normal}
};

static constexpr std::array<InvestigatorNode, InvestigatorNode::num_nodes_total> investigator_nodes = {
	/*i189*/InvestigatorNode{},
	/*i190*/InvestigatorNode{}, // 190s
	/*i191*/InvestigatorNode{},
	/*i192*/InvestigatorNode{},
	/*i193*/InvestigatorNode{},
	/*i194*/InvestigatorNode{},
	/*i195*/InvestigatorNode{},
	/*i196*/InvestigatorNode{},
	/*i197*/InvestigatorNode{},
	/*i198*/InvestigatorNode{},
	/*i199*/InvestigatorNode{},
	/*i200*/InvestigatorNode{}, // 200s
	/*i201*/InvestigatorNode{},
	/*i202*/InvestigatorNode{},
	/*i203*/InvestigatorNode{},
	/*i204*/InvestigatorNode{},
	/*i205*/InvestigatorNode{},
	/*i206*/InvestigatorNode{},
	/*i207*/InvestigatorNode{},
	/*i208*/InvestigatorNode{},
	/*i209*/InvestigatorNode{},
	/*i210*/InvestigatorNode{}, // 210s
	/*i211*/InvestigatorNode{},
	/*i212*/InvestigatorNode{},
	/*i213*/InvestigatorNode{},
	/*i214*/InvestigatorNode{},
	/*i215*/InvestigatorNode{},
	/*i216*/InvestigatorNode{},
	/*i217*/InvestigatorNode{},
	/*i218*/InvestigatorNode{},
	/*i219*/InvestigatorNode{},
	/*i220*/InvestigatorNode{}, // 220s
	/*i221*/InvestigatorNode{},
	/*i222*/InvestigatorNode{},
	/*i223*/InvestigatorNode{},
	/*i224*/InvestigatorNode{},
	/*i225*/InvestigatorNode{},
	/*i226*/InvestigatorNode{},
	/*i227*/InvestigatorNode{},
	/*i228*/InvestigatorNode{},
	/*i229*/InvestigatorNode{},
	/*i230*/InvestigatorNode{}, // 230s
	/*i231*/InvestigatorNode{},
	/*i232*/InvestigatorNode{},
	/*i233*/InvestigatorNode{},
	/*i234*/InvestigatorNode{},
	/*i235*/InvestigatorNode{},
	/*i236*/InvestigatorNode{},
	/*i237*/InvestigatorNode{},
	/*i238*/InvestigatorNode{},
	/*i239*/InvestigatorNode{},
	/*i240*/InvestigatorNode{}, // 240s
	/*i241*/InvestigatorNode{},
	/*i242*/InvestigatorNode{},
	/*i243*/InvestigatorNode{},
	/*i244*/InvestigatorNode{},
	/*i245*/InvestigatorNode{},
	/*i246*/InvestigatorNode{},
	/*i247*/InvestigatorNode{},
	/*i248*/InvestigatorNode{},
	/*i249*/InvestigatorNode{},
	/*i250*/InvestigatorNode{}, // 250s
	/*i251*/InvestigatorNode{},
	/*i252*/InvestigatorNode{},
	/*i253*/InvestigatorNode{},
	/*i254*/InvestigatorNode{},
	/*i255*/InvestigatorNode{},
	/*i256*/InvestigatorNode{},
	/*i257*/InvestigatorNode{},
	/*i258*/InvestigatorNode{},
	/*i259*/InvestigatorNode{},
	/*i260*/InvestigatorNode{}, // 260s
	/*i261*/InvestigatorNode{},
	/*i262*/InvestigatorNode{},
	/*i263*/InvestigatorNode{},
	/*i264*/InvestigatorNode{},
	/*i265*/InvestigatorNode{},
	/*i266*/InvestigatorNode{},
	/*i267*/InvestigatorNode{},
	/*i268*/InvestigatorNode{},
	/*i269*/InvestigatorNode{InvestigatorNode::StartPosition{}}
};

constexpr MapGraph default_map() noexcept {
	return MapGraph{map_nodes, jack_nodes, investigator_nodes};
}

} // namespace wl

#endif
