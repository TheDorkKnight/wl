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

static constexpr std::array<MapNode::ID, 2> j028_nbors = {
	map_id(206u), map_id(219u) };

static constexpr std::array<MapNode::ID, 2> j029_nbors = {
	map_id(207u), map_id(220u) };

static constexpr std::array<MapNode::ID, 2> j030_nbors = {
	map_id(219u), map_id(220u) };

static constexpr std::array<MapNode::ID, 2> j031_nbors = {
	map_id(220u), map_id(236u) };

static constexpr std::array<MapNode::ID, 2> j032_nbors = {
	map_id(221u), map_id(237u) };

static constexpr std::array<MapNode::ID, 4> j033_nbors = {
	map_id(222u), map_id(223u), map_id(238u), map_id(237u) };

static constexpr std::array<MapNode::ID, 3> j034_nbors = {
	map_id(223u), map_id(224u), map_id(238u) };

static constexpr std::array<MapNode::ID, 2> j035_nbors = {
	map_id(224u), map_id(239u) };

static constexpr std::array<MapNode::ID, 2> j036_nbors = {
	map_id(240u), map_id(241u) };

static constexpr std::array<MapNode::ID, 4> j037_nbors = {
	map_id(212u), map_id(225u), map_id(241u), map_id(224u) };

static constexpr std::array<MapNode::ID, 2> j038_nbors = {
	map_id(213u), map_id(225u) };

static constexpr std::array<MapNode::ID, 2> j039_nbors = {
	map_id(225u), map_id(242u) };

static constexpr std::array<MapNode::ID, 2> j040_nbors = {
	map_id(225u), map_id(244u) };

static constexpr std::array<MapNode::ID, 2> j041_nbors = {
	map_id(216u), map_id(226u) };

static constexpr std::array<MapNode::ID, 3> j042_nbors = {
	map_id(227u), map_id(245u), map_id(244u) };

static constexpr std::array<MapNode::ID, 4> j043_nbors = {
	map_id(245u), map_id(246u), map_id(247u), map_id(260u) };

static constexpr std::array<MapNode::ID, 3> j044_nbors = {
	map_id(228u), map_id(246u), map_id(245u) };

static constexpr std::array<MapNode::ID, 3> j045_nbors = {
	map_id(203u), map_id(218u), map_id(217u) };

static constexpr std::array<MapNode::ID, 4> j046_nbors = {
	map_id(218u), map_id(231u), map_id(230u), map_id(229u) };

static constexpr std::array<MapNode::ID, 2> j047_nbors = {
	map_id(205u), map_id(233u) };

static constexpr std::array<MapNode::ID, 2> j048_nbors = {
	map_id(219u), map_id(234u) };

static constexpr std::array<MapNode::ID, 2> j049_nbors = {
	map_id(234u), map_id(235u) };

} // namespace wl

#endif
