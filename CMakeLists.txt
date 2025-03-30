# Add benchmark configuration
option(ENABLE_BENCHMARKS "Enable performance benchmarks" OFF)

if(ENABLE_BENCHMARKS)
    find_package(benchmark REQUIRED)
    
    add_executable(benchmarks
        bench/pathfinding_bench.cpp
        bench/network_bench.cpp
    )
    
    target_link_libraries(benchmarks
        PRIVATE
        benchmark::benchmark
        keeperfx
    )
endif()
