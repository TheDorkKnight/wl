#ifndef WL_J_NODES_H
#define WL_J_NODES_H

#include <array>
#include <wl/wl.h>

namespace wl {

// node 0 is special: it actually corresponds to node labeled
// 189 on a standard map.
static constexpr std::array<MapNode::Adjacency, 2> j000_nbors = {
	map_id(335u), map_id(337u) };

static constexpr std::array<MapNode::Adjacency, 2> j001_nbors = {
	map_id(189u), map_id(190u) };

static constexpr std::array<MapNode::Adjacency, 3> j002_nbors = {
	map_id(192u), map_id(193u), map_id(194u) };

static constexpr std::array<MapNode::Adjacency, 3> j003_nbors = {
	map_id(195u), map_id(197u), map_id(196u) };

static constexpr std::array<MapNode::Adjacency, 2> j004_nbors = {
	map_id(197u), map_id(198u) };

static constexpr std::array<MapNode::Adjacency, 2> j005_nbors = {
	map_id(198u), map_id(199u) };

static constexpr std::array<MapNode::Adjacency, 2> j006_nbors = {
	map_id(200u), map_id(201u) };

static constexpr std::array<MapNode::Adjacency, 2> j007_nbors = {
	map_id(202u), map_id(204u) };

static constexpr std::array<MapNode::Adjacency, 2> j008_nbors = {
	map_id(189u), map_id(206u) };

static constexpr std::array<MapNode::Adjacency, 2> j009_nbors = {
	map_id(189u), map_id(190u) };

static constexpr std::array<MapNode::Adjacency, 2> j010_nbors = {
	map_id(207u), map_id(208u) };

static constexpr std::array<MapNode::Adjacency, 2> j011_nbors = {
	map_id(190u), map_id(208u) };

static constexpr std::array<MapNode::Adjacency, 2> j012_nbors = {
	map_id(191u), map_id(209u) };

static constexpr std::array<MapNode::Adjacency, 4> j013_nbors = {
	map_id(209u), map_id(210u), map_id(222u), map_id(221u) };

static constexpr std::array<MapNode::Adjacency, 3> j014_nbors = {
	map_id(209u), map_id(192u), map_id(210u) };

static constexpr std::array<MapNode::Adjacency, 2> j015_nbors = {
	map_id(210u), map_id(223u) };

static constexpr std::array<MapNode::Adjacency, 3> j016_nbors = {
	map_id(194u), map_id(195u), map_id(210u) };

static constexpr std::array<MapNode::Adjacency, 2> j017_nbors = {
	map_id(195u), map_id(211u) };

static constexpr std::array<MapNode::Adjacency, 2> j018_nbors = {
	map_id(196u), map_id(211u) };

static constexpr std::array<MapNode::Adjacency, 2> j019_nbors = {
	map_id(212u), map_id(213u) };

static constexpr std::array<MapNode::Adjacency, 3> j020_nbors = {
	map_id(198u), map_id(215u), map_id(214u) };

static constexpr std::array<MapNode::Adjacency, 3> j021_nbors = {
	map_id(214u), map_id(215u), map_id(226u) };

static constexpr std::array<MapNode::Adjacency, 3> j022_nbors = {
	map_id(199u), map_id(216u), map_id(215u) };

static constexpr std::array<MapNode::Adjacency, 3> j023_nbors = {
	map_id(199u), map_id(200u), map_id(216u) };

static constexpr std::array<MapNode::Adjacency, 3> j024_nbors = {
	map_id(217u), map_id(229u), map_id(228u) };

static constexpr std::array<MapNode::Adjacency, 3> j025_nbors = {
	map_id(201u), map_id(202u), map_id(203u) };

static constexpr std::array<MapNode::Adjacency, 3> j026_nbors = {
	map_id(204u), map_id(205u), map_id(218u) };

static constexpr std::array<MapNode::Adjacency, 2> j027_nbors = {
	map_id(204u), map_id(205u) };

static constexpr std::array<MapNode::Adjacency, 2> j028_nbors = {
	map_id(206u), map_id(219u) };

static constexpr std::array<MapNode::Adjacency, 2> j029_nbors = {
	map_id(207u), map_id(220u) };

static constexpr std::array<MapNode::Adjacency, 2> j030_nbors = {
	map_id(219u), map_id(220u) };

static constexpr std::array<MapNode::Adjacency, 2> j031_nbors = {
	map_id(220u), map_id(236u) };

static constexpr std::array<MapNode::Adjacency, 2> j032_nbors = {
	map_id(221u), map_id(237u) };

static constexpr std::array<MapNode::Adjacency, 4> j033_nbors = {
	map_id(222u), map_id(223u), map_id(238u), map_id(237u) };

static constexpr std::array<MapNode::Adjacency, 3> j034_nbors = {
	map_id(223u), map_id(224u), map_id(238u) };

static constexpr std::array<MapNode::Adjacency, 2> j035_nbors = {
	map_id(224u), map_id(239u) };

static constexpr std::array<MapNode::Adjacency, 2> j036_nbors = {
	map_id(240u), map_id(241u) };

static constexpr std::array<MapNode::Adjacency, 4> j037_nbors = {
	map_id(212u), map_id(225u), map_id(241u), map_id(224u) };

static constexpr std::array<MapNode::Adjacency, 2> j038_nbors = {
	map_id(213u), map_id(225u) };

static constexpr std::array<MapNode::Adjacency, 2> j039_nbors = {
	map_id(225u), map_id(242u) };

static constexpr std::array<MapNode::Adjacency, 2> j040_nbors = {
	map_id(225u), map_id(244u) };

static constexpr std::array<MapNode::Adjacency, 2> j041_nbors = {
	map_id(216u), map_id(226u) };

static constexpr std::array<MapNode::Adjacency, 3> j042_nbors = {
	map_id(227u), map_id(245u), map_id(244u) };

static constexpr std::array<MapNode::Adjacency, 4> j043_nbors = {
	map_id(245u), map_id(246u), map_id(247u), map_id(260u) };

static constexpr std::array<MapNode::Adjacency, 3> j044_nbors = {
	map_id(228u), map_id(246u), map_id(245u) };

static constexpr std::array<MapNode::Adjacency, 3> j045_nbors = {
	map_id(203u), map_id(218u), map_id(217u) };

static constexpr std::array<MapNode::Adjacency, 4> j046_nbors = {
	map_id(218u), map_id(231u), map_id(230u), map_id(229u) };

static constexpr std::array<MapNode::Adjacency, 2> j047_nbors = {
	map_id(205u), map_id(233u) };

static constexpr std::array<MapNode::Adjacency, 2> j048_nbors = {
	map_id(219u), map_id(234u) };

static constexpr std::array<MapNode::Adjacency, 2> j049_nbors = {
	map_id(234u), map_id(235u) };

static constexpr std::array<MapNode::Adjacency, 3> j050_nbors = {
	map_id(235u), map_id(252u), map_id(251u) };

static constexpr std::array<MapNode::Adjacency, 4> j051_nbors = {
	map_id(235u), map_id(236u), map_id(254u), map_id(253u) };

static constexpr std::array<MapNode::Adjacency, 3> j052_nbors = {
	map_id(254u), map_id(266u), map_id(265u) };

static constexpr std::array<MapNode::Adjacency, 3> j053_nbors = {
	map_id(237u), map_id(255u), map_id(254u) };

static constexpr std::array<MapNode::Adjacency, 3> j054_nbors = {
	map_id(238u), map_id(239u), map_id(255u) };

static constexpr std::array<MapNode::Adjacency, 3> j055_nbors = {
	map_id(255u), map_id(267u), map_id(266u) };

static constexpr std::array<MapNode::Adjacency, 3> j056_nbors = {
	map_id(241u), map_id(242u), map_id(257u) };

static constexpr std::array<MapNode::Adjacency, 2> j057_nbors = {
	map_id(242u), map_id(258u) };

static constexpr std::array<MapNode::Adjacency, 3> j058_nbors = {
	map_id(243u), map_id(260u), map_id(259u) };

static constexpr std::array<MapNode::Adjacency, 3> j059_nbors = {
	map_id(244u), map_id(245u), map_id(260u) };

static constexpr std::array<MapNode::Adjacency, 2> j060_nbors = {
	map_id(247u), map_id(261u) };

static constexpr std::array<MapNode::Adjacency, 2> j061_nbors = {
	map_id(247u), map_id(248u) };

static constexpr std::array<MapNode::Adjacency, 2> j062_nbors = {
	map_id(230u), map_id(247u) };

static constexpr std::array<MapNode::Adjacency, 2> j063_nbors = {
	map_id(230u), map_id(248u) };

static constexpr std::array<MapNode::Adjacency, 2> j064_nbors = {
	map_id(232u), map_id(250u) };

static constexpr std::array<MapNode::Adjacency, 2> j065_nbors = {
	map_id(231u), map_id(233u) };

static constexpr std::array<MapNode::Adjacency, 2> j066_nbors = {
	map_id(232u), MapNode::Adjacency{map_id(98u), MapNode::Adjacency::WaterBorder{}} };

static constexpr std::array<MapNode::Adjacency, 2> j067_nbors = {
	map_id(232u), map_id(233u) };

static constexpr std::array<MapNode::Adjacency, 3> j068_nbors = {
	map_id(252u), map_id(264u), map_id(263u) };

static constexpr std::array<MapNode::Adjacency, 3> j069_nbors = {
	map_id(252u), map_id(265u), map_id(264u) };

static constexpr std::array<MapNode::Adjacency, 2> j070_nbors = {
	map_id(265u), map_id(278u) };

static constexpr std::array<MapNode::Adjacency, 3> j071_nbors = {
	map_id(266u), map_id(267u), map_id(279u) };

static constexpr std::array<MapNode::Adjacency, 3> j072_nbors = {
	map_id(256u), map_id(268u), map_id(267u) };

static constexpr std::array<MapNode::Adjacency, 3> j073_nbors = {
	map_id(256u), map_id(257u), map_id(258u) };

static constexpr std::array<MapNode::Adjacency, 2> j074_nbors = {
	map_id(258u), map_id(270u) };

static constexpr std::array<MapNode::Adjacency, 3> j075_nbors = {
	map_id(259u), map_id(271u), map_id(270u) };

static constexpr std::array<MapNode::Adjacency, 3> j076_nbors = {
	map_id(259u), map_id(261u), map_id(272u) };

static constexpr std::array<MapNode::Adjacency, 3> j077_nbors = {
	map_id(262u), map_id(274u), map_id(273u) };

static constexpr std::array<MapNode::Adjacency, 2> j078_nbors = {
	map_id(262u), map_id(274u) };

static constexpr std::array<MapNode::Adjacency, 2> j079_nbors = {
	map_id(249u), map_id(275u) };

static constexpr std::array<MapNode::Adjacency, 1> j080_nbors = {
	map_id(249u) };

static constexpr std::array<MapNode::Adjacency, 2> j081_nbors = {
	map_id(264u), map_id(286u) };

static constexpr std::array<MapNode::Adjacency, 2> j082_nbors = {
	map_id(276u), map_id(277u) };

static constexpr std::array<MapNode::Adjacency, 2> j083_nbors = {
	map_id(278u), map_id(289u) };

static constexpr std::array<MapNode::Adjacency, 2> j084_nbors = {
	map_id(278u), map_id(279u) };

static constexpr std::array<MapNode::Adjacency, 2> j085_nbors = {
	map_id(280u), map_id(289u) };

static constexpr std::array<MapNode::Adjacency, 2> j086_nbors = {
	map_id(280u), map_id(281u) };

static constexpr std::array<MapNode::Adjacency, 3> j087_nbors = {
	map_id(268u), map_id(269u), map_id(280u) };

static constexpr std::array<MapNode::Adjacency, 2> j088_nbors = {
	map_id(269u), map_id(281u) };

static constexpr std::array<MapNode::Adjacency, 4> j089_nbors = {
	map_id(281u), map_id(282u), map_id(293u), map_id(292u) };

static constexpr std::array<MapNode::Adjacency, 2> j090_nbors = {
	map_id(271u), map_id(282u) };

static constexpr std::array<MapNode::Adjacency, 2> j091_nbors = {
	map_id(282u), map_id(283u) };

static constexpr std::array<MapNode::Adjacency, 2> j092_nbors = {
	map_id(271u), map_id(283u) };

static constexpr std::array<MapNode::Adjacency, 2> j093_nbors = {
	map_id(273u), map_id(284u) };

static constexpr std::array<MapNode::Adjacency, 2> j094_nbors = {
	map_id(275u), map_id(285u) };

static constexpr std::array<MapNode::Adjacency, 1> j095_nbors = {
	map_id(275u) };

static constexpr std::array<MapNode::Adjacency, 1> j096_nbors = {
	map_id(350u) };

static constexpr std::array<MapNode::Adjacency, 2> j097_nbors = {
	map_id(250u), map_id(351u) };

static constexpr std::array<MapNode::Adjacency, 2> j098_nbors = {
	map_id(351u), MapNode::Adjacency{map_id(66u), MapNode::Adjacency::WaterBorder{}} };

static constexpr std::array<MapNode::Adjacency, 3> j099_nbors = {
	map_id(276u), map_id(287u), map_id(286u) };

static constexpr std::array<MapNode::Adjacency, 3> j100_nbors = {
	map_id(288u), map_id(297u), map_id(296u) };

static constexpr std::array<MapNode::Adjacency, 3> j101_nbors = {
	map_id(277u), map_id(288u), map_id(287u) };

static constexpr std::array<MapNode::Adjacency, 2> j102_nbors = {
	map_id(290u), map_id(297u) };

static constexpr std::array<MapNode::Adjacency, 2> j103_nbors = {
	map_id(289u), map_id(290u) };

static constexpr std::array<MapNode::Adjacency, 2> j104_nbors = {
	map_id(291u), map_id(298u) };

static constexpr std::array<MapNode::Adjacency, 3> j105_nbors = {
	map_id(281u), map_id(292u), map_id(291u) };

static constexpr std::array<MapNode::Adjacency, 2> j106_nbors = {
	map_id(292u), map_id(302u) };

static constexpr std::array<MapNode::Adjacency, 3> j107_nbors = {
	map_id(293u), map_id(303u), map_id(302u) };

static constexpr std::array<MapNode::Adjacency, 3> j108_nbors = {
	map_id(293u), map_id(294u), map_id(304u) };

static constexpr std::array<MapNode::Adjacency, 2> j109_nbors = {
	map_id(283u), map_id(284u) };

static constexpr std::array<MapNode::Adjacency, 1> j110_nbors = {
	map_id(294u) };

static constexpr std::array<MapNode::Adjacency, 1> j111_nbors = {
	map_id(285u) };

static constexpr std::array<MapNode::Adjacency, 2> j112_nbors = {
	map_id(284u), map_id(348u) };

static constexpr std::array<MapNode::Adjacency, 1> j113_nbors = {
	map_id(349u) };

static constexpr std::array<MapNode::Adjacency, 2> j114_nbors = {
	map_id(348u), map_id(349u) };

static constexpr std::array<MapNode::Adjacency, 2> j115_nbors = {
	map_id(349u), map_id(352u) };

static constexpr std::array<MapNode::Adjacency, 2> j116_nbors = {
	map_id(351u), map_id(352u) };

static constexpr std::array<MapNode::Adjacency, 2> j117_nbors = {
	map_id(295u), map_id(308u) };

static constexpr std::array<MapNode::Adjacency, 2> j118_nbors = {
	map_id(295u), map_id(296u) };

static constexpr std::array<MapNode::Adjacency, 2> j119_nbors = {
	map_id(297u), map_id(309u) };

static constexpr std::array<MapNode::Adjacency, 2> j120_nbors = {
	map_id(310u), map_id(311u) };

static constexpr std::array<MapNode::Adjacency, 2> j121_nbors = {
	map_id(298u), map_id(309u) };

static constexpr std::array<MapNode::Adjacency, 3> j122_nbors = {
	map_id(298u), map_id(299u), map_id(312u) };

static constexpr std::array<MapNode::Adjacency, 2> j123_nbors = {
	map_id(291u), map_id(299u) };

static constexpr std::array<MapNode::Adjacency, 2> j124_nbors = {
	map_id(299u), map_id(300u) };

static constexpr std::array<MapNode::Adjacency, 2> j125_nbors = {
	map_id(300u), map_id(314u) };

static constexpr std::array<MapNode::Adjacency, 3> j126_nbors = {
	map_id(301u), map_id(305u), map_id(315u) };

static constexpr std::array<MapNode::Adjacency, 2> j127_nbors = {
	map_id(301u), map_id(303u) };

static constexpr std::array<MapNode::Adjacency, 2> j128_nbors = {
	map_id(304u), map_id(305u) };

static constexpr std::array<MapNode::Adjacency, 2> j129_nbors = {
	map_id(305u), map_id(306u) };

static constexpr std::array<MapNode::Adjacency, 2> j130_nbors = {
	map_id(294u), map_id(306u) };

static constexpr std::array<MapNode::Adjacency, 1> j131_nbors = {
	map_id(347u) };

static constexpr std::array<MapNode::Adjacency, 2> j132_nbors = {
	map_id(348u), map_id(353u) };

static constexpr std::array<MapNode::Adjacency, 3> j133_nbors = {
	map_id(352u), map_id(362u), map_id(353u) };

static constexpr std::array<MapNode::Adjacency, 3> j134_nbors = {
	map_id(308u), map_id(309u), map_id(318u) };

static constexpr std::array<MapNode::Adjacency, 2> j135_nbors = {
	map_id(318u), map_id(319u) };

static constexpr std::array<MapNode::Adjacency, 2> j136_nbors = {
	map_id(319u), map_id(326u) };

static constexpr std::array<MapNode::Adjacency, 2> j137_nbors = {
	map_id(319u), map_id(320u) };

static constexpr std::array<MapNode::Adjacency, 1> j138_nbors = {
	map_id(320u) };

static constexpr std::array<MapNode::Adjacency, 4> j139_nbors = {
	map_id(311u), map_id(312u), map_id(321u), map_id(320u) };

static constexpr std::array<MapNode::Adjacency, 2> j140_nbors = {
	map_id(313u), map_id(314u) };

static constexpr std::array<MapNode::Adjacency, 2> j141_nbors = {
	map_id(315u), map_id(323u) };

static constexpr std::array<MapNode::Adjacency, 2> j142_nbors = {
	map_id(307u), map_id(316u) };

static constexpr std::array<MapNode::Adjacency, 1> j143_nbors = {
	map_id(307u) };

static constexpr std::array<MapNode::Adjacency, 1> j144_nbors = {
	map_id(345u) };

static constexpr std::array<MapNode::Adjacency, 2> j145_nbors = {
	map_id(345u), map_id(346u) };

static constexpr std::array<MapNode::Adjacency, 2> j146_nbors = {
	map_id(345u), map_id(355u) };

static constexpr std::array<MapNode::Adjacency, 2> j147_nbors = {
	map_id(346u), map_id(354u) };

static constexpr std::array<MapNode::Adjacency, 2> j148_nbors = {
	map_id(354u), map_id(355u) };

static constexpr std::array<MapNode::Adjacency, 2> j149_nbors = {
	map_id(353u), map_id(354u) };

} // namespace wl

#endif
