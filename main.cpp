#include <iostream>
#include <future>
#include "chan.h"
#define System_out_println(x) std::cout << (x) << std::endl

auto main() -> int {
    //size_t threads_count = std::thread::hardware_concurrency();
    size_t threads_count = 100;
    size_t vals_per_thread = 100;
    Chan<int> channel{vals_per_thread * threads_count};
    // Single thread send
    for (size_t i = 0; i < vals_per_thread * threads_count; i++) {
        channel.Send(i);
    }
    std::vector<std::future<std::vector<decltype(channel.Recv())>>> futures;
    futures.reserve(threads_count);
    // Multi thread receive
    for (size_t i = 0; i < threads_count; i++) {
        futures.push_back(std::async([&] {
            std::vector<std::pair<int, bool>> vals(vals_per_thread * 2, {INT32_MAX, true});
            for(size_t j = 0; j < vals_per_thread * 2; j++){
                if(j == vals_per_thread) channel.Close();
                vals[j] = channel.Recv();
            }
            return vals;
        }));
    }
    int not_closed = 0;
    int closed = 0;
    for (auto &f : futures) {
        auto vals = f.get();
        for (auto&[val, nc] : vals) {
            if (!nc)not_closed += 1;
            else closed += 1;
        }
    }
    System_out_println(not_closed);
    System_out_println(closed);
}
