struct point_t {
    int x;
    int y;
};

void f(struct point *p) {
    p->x = 0; /*@ \label{line:pa_px_store} @*/
    p->y = 1; /*@ \label{line:pa_py_store} @*/
}

int main() {
    point_t p; /*@ \label{line:pa_p_as} @*/
    f(&p);

    return 0;
}
