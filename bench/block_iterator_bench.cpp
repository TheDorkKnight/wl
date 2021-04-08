#include <benchmark/benchmark.h>
#include <wl/wl.h>
#include <wl/default_map.h>
#include <wl/block_iterator.h>
#include <wl/node_blocks_iterator.h>

namespace {

const wl::MapGraph default_map = wl::default_map();

void Benchmark_ClockwiseBlockIteration(benchmark::State& state) {
	const wl::ClockwiseBlock first_block{ wl::map_id(189u), wl::map_id(1u), default_map };

	for (auto _ : state) {
		for (const auto node_id : first_block) {
			benchmark::DoNotOptimize(node_id);
		}
	}
}

void Benchmark_ClockwiseNodeBlocksIteration(benchmark::State& state) {
	const wl::ClockwiseNodeBlocks blocks_for_node_9{ wl::map_id(9u), default_map };

	for (auto _ : state) {
		for (const auto& block : blocks_for_node_9) {
			for (const auto node_id : block) {
				benchmark::DoNotOptimize(node_id);
			}
		}
	}
}

} // namespace

BENCHMARK(Benchmark_ClockwiseBlockIteration);
BENCHMARK(Benchmark_ClockwiseNodeBlocksIteration);
