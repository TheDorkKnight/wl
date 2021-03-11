#ifndef WL_J_NODES_H
#define WL_J_NODES_H

#include <array>
#include <wl/wl.h>

namespace wl {

static constexpr std::array<MapNode::ID, 2> j001_nbors = {
	map_id(189u), map_id(190u) };

static constexpr std::array<MapNode::ID, 3> j002_nbors = {
	map_id(192u), map_id(193u), map_id(194u) };

static constexpr std::array<MapNode::ID, 3> j003_nbors = {
	map_id(195u), map_id(197u), map_id(196u) };

static constexpr std::array<MapNode::ID, 2> j004_nbors = {
	map_id(197u), map_id(198u) };

static constexpr std::array<MapNode::ID, 2> j005_nbors = {
	map_id(198u), map_id(199u) };

static constexpr std::array<MapNode::ID, 2> j006_nbors = {
	map_id(200u), map_id(201u) };

static constexpr std::array<MapNode::ID, 2> j007_nbors = {
	map_id(202u), map_id(204u) };

} // namespace wl

#endif
