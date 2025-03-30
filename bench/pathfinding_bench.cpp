#include <benchmark/benchmark.h>
#include "ariadne.h"

static void BM_Pathfinding(benchmark::State& state) {
    init_navigation();
    for (auto _ : state) {
        long cost = 0;
        auto route = ma_triangle_route(0, 1, &cost);
        benchmark::DoNotOptimize(route);
        benchmark::DoNotOptimize(cost);
    }
    
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Pathfinding)->Range(8, 8<<10)->Complexity();

static void BM_NavigationInit(benchmark::State& state) {
    for (auto _ : state) {
        init_navigation();
    }
}
BENCHMARK(BM_NavigationInit);

BENCHMARK_MAIN();