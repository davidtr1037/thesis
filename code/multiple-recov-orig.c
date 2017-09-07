struct point { int x, y; };

void f(struct point *p, int k) {
    if (k > 0) {
        p->x++;
    } else {
        p->y++;
    }
}

void g() {
    struct point p = { 0, 0 };
    int k; // symbolic

    f(&p, k); // skip
    if (p.x) {
      // ...
    }
    if (p.y) {
      // ...
    }
}
