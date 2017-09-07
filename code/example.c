node_t set_value(node_t node, void *value, unsigned len) {
  node->value = malloc(len);
  if (node->value == NULL)
    return NULL;
  node->value_len = len;
  memcpy(node->value, value, len);
  return node;
}

node_t append(node_t node, void *value, unsigned len) {
  if (node->value != NULL) {
    int prev_len = node->value_len;
    node->value_len += len;
    node->value = realloc(node->value, node->value_len);
    if (node->value == NULL)
      return NULL;
    memcpy(&node->value[prev_len], value, len);
    return node;
  } else
    return set_value(node, value, len);
}

int extract_octet(node_t node, char *der, int der_len) {
  // some initializations ..
  counter = 0;
  counter_end = der_len;
  while (counter < counter_end) {
    len2 = get_length_der(der+counter,          // heap overflow
                             der_len, &len3);
    if (len2 >= 0) {
      DECR_LEN(der_len, len2+len3);
      append_value(node, der+counter+len3, len2);
    } else {
      DECR_LEN(der_len, len3);
      result = extract_octet(node, der+counter+len3, der_len);
      if (result != SUCCESS)
        return result;
      len2 = 0;
    }
    DECR_LEN(der_len, 1);
    counter += len2+len3+1;
  }
  // ..
}
