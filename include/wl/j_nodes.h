#ifndef WL_J_NODES_H
#define WL_J_NODES_H

#include <array>
#include <wl/wl.h>

namespace wl {

static constexpr std::array<JackNode::ID, 9> j001_nbors = {
	jid(2u), jid(8u), jid(9u), jid(10u), jid(11u), jid(12u), jid(14u), jid(28u),
	jid(29u)};

static constexpr std::array<JackNode::ID, 8> j002_nbors = {
	jid(1u), jid(3u), jid(9u), jid(11u), jid(12u), jid(14u), jid(16u), jid(17u)};

static constexpr std::array<JackNode::ID, 10> j003_nbors = {
	jid(2u), jid(4u), jid(16u), jid(17u), jid(18u), jid(19u), jid(20u), jid(21u),
	jid(37u), jid(38u)};

static constexpr std::array<JackNode::ID, 6> j004_nbors = {
	jid(3u), jid(5u), jid(19u), jid(20u), jid(21u), jid(38u)};

} // namespace wl

#endif
