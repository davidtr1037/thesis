char *tokens[2];
tokens[0] = "a";
tokens[1] = "b";

char *token = tokens; /*@ \label{line:pa_token}  @*/
printf("%s\n", token);
