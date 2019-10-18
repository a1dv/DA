#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>

struct KV {
    std::string key;
    unsigned long long value;
};

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    std::vector<KV> v;
    int i = 0;
    char huy[6];
    unsigned long long value;
    KV tmp;
    while (std::cin >> huy[0] && std::cin >> huy[1] && std::cin >> huy[2] && std::cin >> huy[3] && std::cin >> huy[4] && std::cin >> huy[5]  && std::cin >> tmp.value) {
        tmp.key = huy;
        v.push_back(tmp);
    }
    std::stable_sort(v.begin(), v.end(), [](const KV& left, const KV& right) {return (left.key < right.key);});
  //  for (int j = 0; j < v.size(); j++) {
  //      std::cout << v[j].key[0] << " " << v[j].key[1] << v[j].key[2] << v[j].key[3] << " " << v[j].key[4] << v[j].key[5] <<  "  " << v[j].value << "\n";
  //  }
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds> (end - start).count();
    std::cout << elapsed_seconds;
    return 0;
}
