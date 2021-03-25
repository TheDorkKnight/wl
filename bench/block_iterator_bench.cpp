#include <benchmark/benchmark.h>
#include <wl/wl.h>
#include <wl/default_map.h>
#include <wl/block_iterator.h>

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
	

} // namespace

BENCHMARK(Benchmark_ClockwiseBlockIteration);
