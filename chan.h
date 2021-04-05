#include <atomic>
#include <condition_variable>
#include <mutex>
#include <utility>
#include <queue>

#ifndef CHAN_CHAN_H
#define CHAN_CHAN_H

template<class T>
class Chan {
public:
    explicit Chan(size_t _size) : size_(_size) {

    }
    auto Close() -> void {
        closed_ = true;
        cv_.notify_all();
    };

    [[nodiscard]] auto Capacity() const -> size_t {
        return size_;
    }

    [[nodiscard]] auto Closed() const -> bool {
        return closed_;
    }

    auto Send(T &&value) -> void {
        std::unique_lock lock{mutex_};
        cv_.wait(lock, [this] { return !(queue_.size() == size_) || closed_; });
        if (Closed()) {
            throw std::runtime_error("Channel was closed");
        }
        queue_.push(std::move(value));
        lock.unlock();
        cv_.notify_all();
    }

    auto Send(const T &value) -> void {
        std::unique_lock lock{mutex_};
        cv_.wait(lock, [this] { return !(queue_.size() == size_); });
        if (Closed()) {
            throw std::runtime_error("Channel was closed");
        }
        queue_.push(value);
        lock.unlock();
        cv_.notify_all();
    }

    // 2nd false if default constructed
    auto Recv() -> std::pair<T, bool> {
        std::unique_lock lock{mutex_};
        if (queue_.empty() && Closed()) {
            return {{}, false};
        }
        cv_.wait(lock, [this] { return queue_.size() != 0; });
        T val = queue_.front();
        queue_.pop();
        lock.unlock();
        cv_.notify_all();
        return {val, true};
    }

private:
    std::atomic<size_t> size_;
    std::atomic<bool> closed_{false};
    mutable std::mutex mutex_{};
    std::queue<T> queue_{};
    std::condition_variable cv_{};

};

#endif //CHAN_CHAN_H
