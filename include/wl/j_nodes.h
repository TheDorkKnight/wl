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

static constexpr std::array<JackNode::ID, 4> j005_nbors = {
	jid(4u), jid(20u), jid(22u), jid(23u)};

static constexpr std::array<JackNode::ID, 4> j006_nbors = {
	jid(23u), jid(24u), jid(25u), jid(45u)};

static constexpr std::array<JackNode::ID, 4> j007_nbors = {
	jid(25u), jid(26u), jid(27u), jid(45u)};

} // namespace wl

#endif
