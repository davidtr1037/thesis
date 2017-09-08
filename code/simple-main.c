struct point {
    int x;
    int y;
    int z;
};

int main() { /*@ \label{line:main_enter} @*/
    struct point p = {0, 0, 0};
    int j, k; // symbolic

    f(&p, k); // skip  /*@ \label{line:call_f} @*/
    if (j > 0)  /*@ \label{line:if_j} @*/
       if (p.y) /*@ \label{line:if_py} @*/
          bug();
    else
       allgood();      

    return 0;
}
