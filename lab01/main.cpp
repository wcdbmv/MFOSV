#include <condition_variable>
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>
 
std::mutex m;
std::condition_variable cv;
int name;
bool send = false;
 
void worker_thread() {
  for (int j = 0; j < 4; ++j) {
    // wait until main() sends data
    std::unique_lock lk(m);
    cv.wait(lk, []{ return send; });

    // after the wait, we own the lock
    std::cout << "receive: " << name << '\n';

    // processed
    send = false;

    lk.unlock();
    cv.notify_one();
  }
}
 
int main() {
  std::thread worker(worker_thread);
 
  for (int i = 0; i < 4; ++i) {
    // send data to the worker thread
    name = i % 2 == 0 ? 4 : 1;
    {
      std::lock_guard lk(m);
      send = true;
    }
    cv.notify_one();
 
    // wait for the worker
    {
      std::unique_lock lk(m);
      cv.wait(lk, []{ return !send; });
    }
  }

  worker.join();
}
