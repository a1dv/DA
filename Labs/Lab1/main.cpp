#include <iostream>
#include <chrono>

struct KV {
    char key[6];
    char value[2050];
};

struct TVector {
    KV* body;
    int size;
    int capacity;
};

struct TintVect {
    int* body;
    int size;
};

TintVect* Vi_create()
{
    TintVect* v = (TintVect*)malloc(sizeof(TintVect));
    v -> size = 0;
    v -> body = NULL;
    return v;
}

void Vi_destroy(TintVect* v)
{
    free(v -> body);
    free(v);
}

void Vi_set(TintVect* v, int i, int val)
{
    v -> body[i] = val;
}

void Vi_set_size(TintVect* v, int new_size)
{
    int* reBody = (int*)realloc(v->body, new_size * sizeof(int));
    v->body = reBody;
    v->size = new_size;
}

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
  v->capacity = new_size;
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

int Vi_get(TintVect* v, int i)
{
    return v -> body[i];
}


void V_set (TVector* v, int i, KV val)
{
    v -> body[i] = val;
}

int Decryption (char npt) {
    int res;
    res = npt;
    if (res > 57) {
        res -= 65;
    }
    else {
        res -= 48;
    }
    return res;
}

void CountSort(TVector* npt, int it, TVector* res, char max)
{
    int edge;
    TintVect* tmp = Vi_create();
    if (max == 'Z') {
        edge = 26;
    }
    else {
        edge = 10;
    }
    Vi_set_size(tmp, edge);
    for (int i = 0; i < tmp->size; i++) {
        Vi_set(tmp, i, 0);
    }
    for (int i = 0; i  < npt->size; i++) {
        Vi_set(tmp, Decryption(V_get(npt, i).key[it]), Vi_get(tmp, Decryption(V_get(npt, i).key[it])) + 1);
    }

    for (int i = 1; i  < edge; i++) {
        Vi_set(tmp, i, Vi_get(tmp, i) + Vi_get(tmp, i - 1));
    }
    for (int i = npt->size - 1; i >= 0; i--) {
        V_set(res, Vi_get(tmp, Decryption(V_get(npt, i).key[it])) - 1, V_get(npt, i));
        Vi_set(tmp, Decryption(V_get(npt, i).key[it]), Vi_get(tmp, Decryption(V_get(npt, i).key[it])) - 1);
    }
    for (int i = 0; i < res->size; i++) {
        V_set(npt ,i , V_get(res,i));
    }
    Vi_destroy(tmp);
}

TVector* RadixSort(TVector* npt)
{
    TVector* res = V_create();
    V_cap(res, npt->capacity);
    V_set_size(res, npt->size);
    char max;
    int it = 5;
    for (int i = 0; i < npt->size; i++) {
        V_set(res, i, V_get(npt, i));
    }
    while (it >= 0) {
        if ((it > 0) && (it < 4)) {
            max = '9';
        } else {
            max = 'Z';
        }
        CountSort(npt, it, res, max);
        it--;
    }
    V_destroy(npt);
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
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
  //  for (int i = 0; i < kv->size; i++) {
  //      std::cout << V_get(kv, i).key[0] << " " << V_get(kv, i).key[1] << V_get(kv, i).key[2] << V_get(kv, i).key[3] << " " << V_get(kv, i).key[4] << V_get(kv,i).key[5] << "  " << V_get(kv,i).value << "\n";
  //  }
    V_destroy(kv);
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds> (end - start).count();
    std::cout << elapsed_seconds;
    return 0;
}
