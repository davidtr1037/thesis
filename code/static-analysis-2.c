struct point_t {
    int x;
    int y;
};

void f(struct point *p) {
    p->x = 0; /*@ \label{line:px_store} @*/
    p->y = 1; /*@ \label{line:py_store} @*/
}
