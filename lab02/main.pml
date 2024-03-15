int val = 0;
int max_val = 10;

active [2] proctype Worker() {
  do
  :: (val >= max_val) -> break;
#ifdef USE_MUTEX
  :: atomic { (val < max_val) -> val++; printf("Value is %d\n", val); }
#else
  ::          (val < max_val) -> val++; printf("Value is %d\n", val);
#endif
  od
}
