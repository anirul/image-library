#include <benchmark/benchmark.h>

#include "TinyImageLibrary/tiny_image_interface.h"
#include "TinyImageLibrary/tiny_image_factory.h"

const std::string kTestImagePath = "../../background.jpg";

// FIXME(anirul): This should be tested from a RAM disk.
static void BM_Open(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        std::unique_ptr<tiny_image::TinyImageInterface> tiny_image_unique =
            tiny_image::CreateTinyImage(tiny_image::LibraryEnum::OPEN_CV);
        state.ResumeTiming();
        tiny_image_unique->Open(kTestImagePath);
    }
}

static void BM_Clone(benchmark::State& state) {
    std::unique_ptr<tiny_image::TinyImageInterface> tiny_image_unique =
        tiny_image::CreateTinyImage(tiny_image::LibraryEnum::OPEN_CV);
    tiny_image_unique->Open(kTestImagePath);
    for (auto _ : state) {
        auto resized_image = tiny_image_unique->Clone();
    }
}

static void BM_Resize(benchmark::State& state) {
    std::unique_ptr<tiny_image::TinyImageInterface> tiny_image_unique =
        tiny_image::CreateTinyImage(tiny_image::LibraryEnum::OPEN_CV);
    tiny_image_unique->Open(kTestImagePath);
    for (auto _ : state) {
        state.PauseTiming();
        auto resized_image = tiny_image_unique->Clone();
        state.ResumeTiming();
        resized_image->Resize({ 100, 100 });
    }
}

static void BM_Crop(benchmark::State& state) {
    std::unique_ptr<tiny_image::TinyImageInterface> tiny_image_unique =
        tiny_image::CreateTinyImage(tiny_image::LibraryEnum::OPEN_CV);
    tiny_image_unique->Open(kTestImagePath);
    for (auto _ : state) {
        state.PauseTiming();
        auto cropped_image = tiny_image_unique->Clone();
        state.ResumeTiming();
        cropped_image->Crop({ 10, 10, 1000, 1000 });
    }
}

// FIXME(anirul): This should be tested to a RAM disk.
static void BM_Save(benchmark::State& state) {
    std::unique_ptr<tiny_image::TinyImageInterface> tiny_image_unique =
        tiny_image::CreateTinyImage(tiny_image::LibraryEnum::OPEN_CV);
    tiny_image_unique->Open(kTestImagePath);
    tiny_image_unique->Crop({ 10, 10, 50, 50 });
    for (auto _ : state) {
        state.PauseTiming();
        auto cloned_image = tiny_image_unique->Clone();
        state.ResumeTiming();
        cloned_image->Save("test.jpg");
    }
}

BENCHMARK(BM_Open);
BENCHMARK(BM_Clone);
BENCHMARK(BM_Resize);
BENCHMARK(BM_Crop);
BENCHMARK(BM_Save);

BENCHMARK_MAIN();
