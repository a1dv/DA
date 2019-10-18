#include <iostream>

struct KV {
    char key[6];
    char value[2050];
};

struct TVector {
    KV* body;
    int size;
    int capacity;
};

TVector* V_create()
{
    TVector* v = (TVector*)malloc(sizeof(TVector));
    v -> size = 0;
    v -> body = NULL;
    v -> capacity = 1;
    return v;
}

void V_set_size(TVector* v, int new_size)
{
	v->size = new_size;
}

void V_cap(TVector* v, int new_size)
{
	KV* reBody = (KV*)realloc(v->body, new_size * sizeof(KV));
	v->body = reBody;
}

void V_destroy(TVector* v)
{
    free(v -> body);
    free(v);
}

KV V_get(TVector* v, int i)
{
    return v -> body[i];
}


void V_set(TVector* v, int i, KV val)
{
    v -> body[i] = val;
}

void CountSort(int it, TVector* res)
{
    int j = 0;
    KV tmp;
    int k = 0;
    int f = 0;
    for (int i = 0; i < res->size; i++) {
        if (i >= 1) {
            j = i;
            k = i;
            f = V_get(res, i).key[it];
            std::cout << "\n" << f  << " " << V_get(res, i).key[it] << "\n";
            while ((V_get(res,j - 1).key[it] > V_get(res,k).key[it]) && (j > 0)) {
                j--;
                tmp = V_get(res,j);
                V_set(res, j, V_get(res, k));
                V_set(res, k, tmp);
                k--;
            }
        }
    }
}

TVector* RadixSort(TVector* npt)
{
    TVector* res = V_create();
    V_cap(res, npt->capacity);
    V_set_size(res, npt->size);
    int it = 5;
    for (int i = 0; i < npt->size; i++) {
        V_set(res, i,V_get(npt, i));
    }
    while (it >= 0) {
        CountSort(it, res);
        it --;
    }
    V_destroy(npt);
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    TVector* kv = V_create();
    KV kv_elem;
    while ((std::cin >> kv_elem.key[0] && std::cin >> kv_elem.key[1] && std::cin >> kv_elem.key[2] && std::cin >> kv_elem.key[3] && std::cin >> kv_elem.key[4] && std::cin >> kv_elem.key[5] && std::cin >> kv_elem.value) == 1) {
        if (kv->size + 1 == kv->capacity) {
        		    kv->capacity *= 2;
                V_cap(kv, kv->capacity);
        		}
            V_set(kv, kv->size, kv_elem);
            V_set_size(kv, kv->size + 1);
    }
    kv = RadixSort(kv);
    for (int i = 0; i < kv->size; i++) {
        std::cout << V_get(kv, i).key[0] << " " << V_get(kv, i).key[1] << V_get(kv, i).key[2] << V_get(kv, i).key[3] << " " << V_get(kv, i).key[4] << V_get(kv,i).key[5] << "  " << V_get(kv,i).value << "\n";
    }
    V_destroy(kv);
    return 0;
}
