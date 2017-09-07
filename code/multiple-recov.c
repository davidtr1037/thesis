void g() {
    struct point p = { 0, 0, 0 };
    int k; // symbolic

    f(&p, k); // skip
    if (p.x) {
      // ...
    }
    if (p.y) {
      // ...
    }
}
