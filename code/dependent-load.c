void modify(char *s) {
    s[0] = '\0'; /*@ \label{line:modify} @*/
}

int main() {
    char a[] = "123";
    char b[] = "456";

    modify(b);

    printf("%d\n", strlen(a)); /*@ \label{line:load-a} @*/
    printf("%d\n", strlen(b)); /*@ \label{line:load-b} @*/

    return 0;
}
