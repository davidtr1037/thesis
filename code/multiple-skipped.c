struct point { int x, y;};
void f1(struct point *p) {
    p->y = 0;
}
void f2(struct point *p) {
    if (p->y)
        p->x = 1;
}
void g() {
    struct point p;
    f1(&p); // skip
    f2(&p); // skip
    if (p.x) {
        // ...
    }
}
