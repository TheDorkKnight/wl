#ifndef WL_I_NODES_H
#define WL_I_NODES_H

#include <array>
#include <wl/wl.h>

namespace wl {

static constexpr std::array<MapNode::Adjacency, 4> i189_nbors = {
	map_id(1u), map_id(9u), map_id(207u), map_id(8u) };

static constexpr std::array<MapNode::Adjacency, 4> i190_nbors = {
	map_id(1u), map_id(191u), map_id(11u), map_id(9u) };

static constexpr std::array<MapNode::Adjacency, 3> i191_nbors = {
	map_id(12u), map_id(190u), map_id(192u) };

static constexpr std::array<MapNode::Adjacency, 3> i192_nbors = {
	map_id(2u), map_id(14u), map_id(191u) };

static constexpr std::array<MapNode::Adjacency, 2> i193_nbors = {
	map_id(2u), map_id(195u) };

static constexpr std::array<MapNode::Adjacency, 2> i194_nbors = {
	map_id(2u), map_id(16u) };

static constexpr std::array<MapNode::Adjacency, 4> i195_nbors = {
	map_id(3u), map_id(17u), map_id(16u), map_id(193u) };

static constexpr std::array<MapNode::Adjacency, 3> i196_nbors = {
	map_id(3u), map_id(212u), map_id(18u) };

static constexpr std::array<MapNode::Adjacency, 4> i197_nbors = {
	map_id(3u), map_id(4u), map_id(214u), map_id(213u) };

static constexpr std::array<MapNode::Adjacency, 3> i198_nbors = {
	map_id(4u), map_id(5u), map_id(20u) };

static constexpr std::array<MapNode::Adjacency, 3> i199_nbors = {
	map_id(5u), map_id(23u), map_id(22u) };

static constexpr std::array<MapNode::Adjacency, 3> i200_nbors = {
	map_id(6u), map_id(24u), map_id(23u) };

static constexpr std::array<MapNode::Adjacency, 3> i201_nbors = {
	map_id(6u), map_id(25u), map_id(217u) };

static constexpr std::array<MapNode::Adjacency, 2> i202_nbors = {
	map_id(7u), map_id(25u) };

static constexpr std::array<MapNode::Adjacency, 3> i203_nbors = {
	map_id(25u), map_id(204u), map_id(45u) };

static constexpr std::array<MapNode::Adjacency, 4> i204_nbors = {
	map_id(7u), map_id(27u), map_id(26u), map_id(203u) };

static constexpr std::array<MapNode::Adjacency, 3> i205_nbors = {
	map_id(26u), map_id(27u), map_id(47u) };

static constexpr std::array<MapNode::Adjacency, 3> i206_nbors = {
	map_id(8u), map_id(207u), map_id(28u) };

static constexpr std::array<MapNode::Adjacency, 4> i207_nbors = {
	map_id(10u), map_id(29u), map_id(206u), map_id(189u) };

static constexpr std::array<MapNode::Adjacency, 3> i208_nbors = {
	map_id(10u), map_id(11u), map_id(221u) };

static constexpr std::array<MapNode::Adjacency, 3> i209_nbors = {
	map_id(12u), map_id(14u), map_id(13u) };

} // namespace wl

#endif // WL_I_NODES_H
