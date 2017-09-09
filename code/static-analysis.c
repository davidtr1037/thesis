object_t *allocate_object() {
    object_t *o = malloc(...); /*@ \label{line:object_as} @*/
    return o;
}

void f() {
    object *objects[10]; /*@ \label{line:objects_as} @*/
    for (unsigned int i = 0; i < 10; i++) {
        void *o = allocate_object();
        objects[i] = o;
    }
}
