void f(struct point *p, int k) {
    if (k % 2)    /*@ \label{line:if_k_z}   @*/
       p->z++;    /*@ \label{line:pz_write} @*/
    if (k > 0)    /*@ \label{line:if_k}     @*/
       p->x++;    /*@ \label{line:px_write} @*/
    else          /*@ \label{line:if_k_else}@*/
       p->y++;    /*@ \label{line:py_write} @*/
}
