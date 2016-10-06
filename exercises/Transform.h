
template <typename II, typename OI, typename UF> 
OI my_transform(II b, II e, OI c, UF f) {
  while (b != e) {
    *c = f(*b);
    ++b; ++c;}
  return c;
}
