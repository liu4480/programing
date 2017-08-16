#define FSHIFT   11     /* nr of bits of precision */
#define FIXED_1  (1<<FSHIFT)    /* 1.0 as fixed-point */
#define LOAD_FREQ (5*HZ)    /* 5 sec intervals */
#define EXP_1  1884     /* 1/exp(5sec/1min) as fixed-point */
#define EXP_5  2014     /* 1/exp(5sec/5min) */
#define EXP_15 2037     /* 1/exp(5sec/15min) */

#define CALC_LOAD(load,exp,n) \
   load *= exp; \
   load += n*(FIXED_1-exp); \
   load >>= FSHIFT;

unsigned long avenrun[3];

static inline void calc_load(unsigned long ticks)
{
   unsigned long active_tasks; /* fixed-point */
   static int count = LOAD_FREQ;

   count -= ticks;
   if (count < 0) {
      count += LOAD_FREQ;
      active_tasks = count_active_tasks();
      CALC_LOAD(avenrun[0], EXP_1, active_tasks);
      CALC_LOAD(avenrun[1], EXP_5, active_tasks);
      CALC_LOAD(avenrun[2], EXP_15, active_tasks);
   }
}
