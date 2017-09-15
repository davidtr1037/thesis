int _asn1_extract_der_octet(
  asn1_node node, const unsigned char *der, int der_len, unsigned flags
) {
  int len2, len3;
  int counter, counter_end;
  int result;

  len2 = asn1_get_length_der(der, der_len, &len3); /*@ \label{line:get_length} @*/
  if (len2 < -1)
    return ASN1_DER_ERROR;

  counter = len3 + 1;
  if (len2 == -1)
    counter_end = der_len - 2;
  else
    counter_end = der_len;
  while (counter < counter_end) { /*@ \label{line:loop_begin} @*/
    // call to get_length() leads to a heap overflow:
    // der_len should have been decremented
    len2 = asn1_get_length_der(der + counter, der_len, &len3); /*@ \label{line:heap_overflow} @*/
    if (IS_ERR(len2, flags)) {
      warn();
      return ASN1_DER_ERROR;
    }
    if (len2 >= 0) {
      DECR_LEN(der_len, len2 + len3);
      _asn1_append_value(node, der + counter + len3, len2); /*@ \label{line:append} @*/
    } else { /* indefinite */
      DECR_LEN(der_len, len3);
      result = _asn1_extract_der_octet(node, der + counter + len3, der_len, flags); /*@  \label{line:recursion} @*/
      if (result != ASN1_SUCCESS)
        return result;
      len2 = 0;
    }
    DECR_LEN(der_len, 1); /*@ \label{line:bug} @*/
    counter += len2 + len3 + 1;
  } /*@ \label{line:loop_end} @*/

  return ASN1_SUCCESS;
  cleanup: return result;
}
