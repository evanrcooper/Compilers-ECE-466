int int_;
long long int long_long_int_;
long long unsigned int long_long_unsigned_int_;
unsigned unsigned_;
signed char signed_char_;
signed short signed_short_;
extern unsigned extern_unsigned_;
extern extern_;
void *void_ptr_;
void *void_ptr_ary_[];
int (*ptr_int_ary_)[];
int *(*ptr_int_ptr_ary_)[];
unsigned char unsigned_char_fn_() {
    return 'x';
}
int a;
int i;
void init() {
    i = 0;
    a = 4;
    a = 0;
}

int x;
int y;
int z;

int arr1[10];
int arr2[5][4];
int *ptr;

int get_five() {
    return 5;
}

int val;
int square() {
    int a;
    a = 1233;
    return val * val + a;
}

int main2() {
    x = 1;
    y += 2;
    z = y * 4;

    ptr = &x;
    z = *ptr;
    
    arr1[0] = 7;
    arr1[1] = arr1[0] + 3;

    x = get_five();
    y = square();

    z = (x > y) ? x : y;

    int i;
    i = 0;
    while (i < 5) {
        if (i == 2) {
            i++;
            continue;
        }
        if (i == 4) break;
        i++;
    }

    for (i = 0; i < 3; i++) {
        x += i;
    }

    int ary_12_10[12][10];
    int *a_indexed_1, a_indexed_2;
    a_indexed_1 = ary_12_10[1];
    a_indexed_2 = a_indexed_1[2];

    do {
        x += 24;
    } while (x+ 100 < 100000);

    if (x) {
        x++;
    } else {
        x--;
    }

    if (y) {
        y++;
    } else if (x) {
        x--;
    } else {
        z++;
    }

    return x + y + z;
}