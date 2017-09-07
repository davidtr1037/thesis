struct point { int x, y; } *p = NULL;
void f() {
  p = malloc(sizeof(struct point)); /*@ \label{line:slice_1}   @*/
  p->x = 0; /*@ \label{line:slice_2}   @*/
}
void g() {
  f(); // skip   /*@ \label{line:alloc_skip}   @*/
  if (p)         /*@ \label{line:alloc_first}   @*/
    if (p->x) {  /*@ \label{line:alloc_second}   @*/
      // ...
  }
}
