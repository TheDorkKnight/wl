#ifndef WL_J_NODES_H
#define WL_J_NODES_H

#include <array>
#include <wl/wl.h>

namespace wl {

// node 0 is special: it actually corresponds to node labeled
// 189 on a standard map.
static constexpr std::array<MapNode::ID, 2> j000_nbors = {
	map_id(335u), map_id(337u) };

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

static constexpr std::array<MapNode::ID, 2> j008_nbors = {
	map_id(189u), map_id(206u) };

static constexpr std::array<MapNode::ID, 2> j009_nbors = {
	map_id(189u), map_id(190u) };

static constexpr std::array<MapNode::ID, 2> j010_nbors = {
	map_id(207u), map_id(208u) };

static constexpr std::array<MapNode::ID, 2> j011_nbors = {
	map_id(190u), map_id(208u) };

static constexpr std::array<MapNode::ID, 2> j012_nbors = {
	map_id(191u), map_id(209u) };

static constexpr std::array<MapNode::ID, 4> j013_nbors = {
	map_id(209u), map_id(210u), map_id(222u), map_id(221u) };

static constexpr std::array<MapNode::ID, 3> j014_nbors = {
	map_id(209u), map_id(192u), map_id(210u) };

static constexpr std::array<MapNode::ID, 2> j015_nbors = {
	map_id(210u), map_id(223u) };

static constexpr std::array<MapNode::ID, 3> j016_nbors = {
	map_id(194u), map_id(195u), map_id(210u) };

static constexpr std::array<MapNode::ID, 2> j017_nbors = {
	map_id(195u), map_id(211u) };

static constexpr std::array<MapNode::ID, 2> j018_nbors = {
	map_id(196u), map_id(211u) };

static constexpr std::array<MapNode::ID, 2> j019_nbors = {
	map_id(212u), map_id(213u) };

static constexpr std::array<MapNode::ID, 3> j020_nbors = {
	map_id(198u), map_id(215u), map_id(214u) };

static constexpr std::array<MapNode::ID, 3> j021_nbors = {
	map_id(214u), map_id(215u), map_id(226u) };

static constexpr std::array<MapNode::ID, 3> j022_nbors = {
	map_id(199u), map_id(216u), map_id(215u) };

static constexpr std::array<MapNode::ID, 3> j023_nbors = {
	map_id(199u), map_id(200u), map_id(216u) };

static constexpr std::array<MapNode::ID, 3> j024_nbors = {
	map_id(217u), map_id(229u), map_id(228u) };

static constexpr std::array<MapNode::ID, 3> j025_nbors = {
	map_id(201u), map_id(202u), map_id(203u) };

static constexpr std::array<MapNode::ID, 3> j026_nbors = {
	map_id(204u), map_id(205u), map_id(218u) };

static constexpr std::array<MapNode::ID, 2> j027_nbors = {
	map_id(204u), map_id(205u) };

} // namespace wl

#endif
