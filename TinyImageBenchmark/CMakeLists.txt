add_executable(tiny_image_benchmark 
    main.cpp
)

target_link_libraries(tiny_image_benchmark 
    PRIVATE
        tiny_image_library
        benchmark::benchmark 
        benchmark::benchmark_main
)

set_property(TARGET tiny_image_benchmark PROPERTY FOLDER "TinyImageBenchmark")

