#include "ruby_delegate.h"
#include "ruby.h"

typedef struct { id object; } ObjectHolder_t;

RUBY_EXTERN VALUE rb_mRealGrowl;

RUBY_EXTERN void Init_RealGrowl();