struct point {
    int x;
    int y;
};

void f(point *p, int k) {
    if (k > 0) {
       p->x++;
    } else  {
       p->y++;
    }
}

int main() {
    struct point p = {
        .x = 0,
        .y = 0
    };
    int k; // symbolic

    f(&p, k);
    if (p.x) {
        ...
    } 
    if (p.y) {
        ...
    }

    return 0;
}
