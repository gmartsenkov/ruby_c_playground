#include "ruby.h"
#include <stdio.h>

#define NELEMS(x) ( sizeof(x) / sizeof(x[0]))
VALUE MyTest = Qnil;

void init_mytest();
VALUE ary_to_r_ary(int *ary, int ary_size);
VALUE method_sum(VALUE self, int r_value1, int r_value2);
VALUE method_factorial(VALUE self, int r_value1);
VALUE method_arr(VALUE self);
void Init_mytest() {
        MyTest = rb_define_class("MyTest", rb_cObject);
        rb_define_method(MyTest, "sum", method_sum, 2);
        rb_define_method(MyTest, "factorial", method_factorial, 1);
        rb_define_method(MyTest, "arr", method_arr, 0);
}

VALUE method_sum(VALUE self, int r_value1, int r_value2){
        VALUE result = FIX2INT(r_value1) + FIX2INT(r_value2);
         return INT2NUM(result);
}

VALUE method_factorial(VALUE self, int r_value1) {
  int max = FIX2INT(r_value1);
  long double result = 1;
  for(int i=1;i<=max;i++) {
    result *= i;
   /* printf("result is %Lf --- iteration - %i \n", result, i); */
  }
  return DBL2NUM(result);
}

VALUE method_arr(VALUE self) {
  int x[] = {1,2,3,4,5,6,7,8};
  int ary_size = NELEMS(x);
  return ary_to_r_ary(x, ary_size);
}

VALUE ary_to_r_ary(int *ary, int ary_size) {
  VALUE r_ary = rb_ary_new();
  for(int i=0; i <= ary_size - 1; i++) {
    rb_ary_push(r_ary, INT2NUM(ary[i]));
  }
  return r_ary;
}
