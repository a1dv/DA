#include <iostream>
#include <vector>

struct KV{
    int key;
    char value;
};

int main()
{
    KV elem;
    std::vector<KV> elem;
    while(std::cin >> elem.key >> elem.value) {
        if(max > elem.key) {
            max = elem.key;
        }
   }
}
