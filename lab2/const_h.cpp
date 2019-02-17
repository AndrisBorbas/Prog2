void ff(const int *ip) {
    *ip = 3;
}

int main()
{
// 1.
    const int i;

// 2.
    const int j = 10;
    j++;

// 3.
    const int l = 10;
    int *p=&l;
    (*p)++;

// 4.
    extern void f(int *i);
    const int iv = 100;
    f(&iv);

// 5.
    const int ivv = 100;
    ff(&ivv);

// 6.
    const int v[] = {1,2,3}; 
    v[1]++;

// 7.
    const int siz = 20;
    int t[siz];

// 8.
    char s1[] = "Hello konstans szoveg";
    const char *pc = s1;
    pc[0] = 'A';
    pc++;

// 9.
    char s2[] = "Hello konstans pointer";
    char* const cp = s2;
    cp[0] = 'B';
    cp++;

// 10.
    char s3[] = "Hello konstans szoveg konstans pointer";
    const char* const cpc = s3;
    cpc[0] = 'C';
    cpc++;

// 11.
    enum Szinek { tok, zold, makk, piros };
    Szinek adu;
    adu = 1;
    adu = Szinek(10);

    return(0);
}
