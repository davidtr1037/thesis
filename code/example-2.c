int extract_octet(node_t node, char *der, int der_len) {
 int len2, len3, counter, counter_end, result;
 len2 = get_length(der, der_len, &len3); /*@ \label{line:get_length} @*/
 counter = len3+1;
 counter_end = der_len;
 while (counter < counter_end) {
   len2 = get_length(der+counter,        // heap overflow
                       der_len, &len3);
  if (len2 >= 0) {
   DECR_LEN(der_len, len2+len3);
   append_value(node, der+counter+len3, len2);
  } else {
   DECR_LEN(der_len, len3);
   result = extract_octet(node, der+counter+len3, der_len);
   if (result != SUCCESS) return result;
   len2 = 0;
  }
  counter += len2+len3+1;
 }
 return SUCCESS;
}
