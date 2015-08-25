extern struct PrivSec_t {
    char name[100];
    Elf32_Addr add_beg;
    Elf32_Addr add_end;
    struct PrivSec_t *next;
} *head, *curr;
extern int max;
extern bool ex_flag;
extern uint64_t t_start, t_stop;
