#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char name[32];
    int  id;
} Record;

// TODO objective 2: add a typedef for your function pointer here
typedef bool (*compare_fn_t)(Record, Record);

// TODO objective 1: fix sort() function to take a function pointer as a parameter
void sort(Record a[], int n, compare_fn_t compare_fn) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (compare_fn(a[j], a[j+1])) {
                Record tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

bool cmp_id_asc(Record r1, Record r2) {
    return r1.id > r2.id;
}

bool cmp_id_desc(Record r1, Record r2) {
    return r1.id < r2.id;
}

bool cmp_name_asc(Record r1, Record r2) {
    return strcmp(r1.name, r2.name) > 0;
}

int main(void) {
    Record a[] = {
        {"Alice", 42},
        {"Bob",   25},
        {"Eve",   33},
        {"Dave",  17}
    };
    int n = 4;

    // your generic sort fn should allow any such comparison fns to be given as input
    // sort(a, n, cmp_id_asc);
    // sort(a, n, cmp_id_desc);
    sort(a, n, cmp_name_asc);

    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", a[i].name, a[i].id);
    }
    return 0;
}
