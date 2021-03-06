/* Autogenerated with DRAKON Editor 1.27 */
#include "state_machine.h"


static int state_machine_branch 1_receive==tb();

static int state_machine_branch 1_udtl();

static int state_machine_branch 1_udtl_header();

static int state_machine_branch 2_A();

static int state_machine_branch 2_B();

static int state_machine_branch 2_C();


#define STATE_MACHINE_BRANCH 1 1
#define STATE_MACHINE_BRANCH 2 2
typedef int (*state_machine_callback)(void);
state_machine_callback state_machine_A_methods[] = {
    0,
    0,
    state_machine_branch 2_A
};
state_machine_callback state_machine_B_methods[] = {
    0,
    0,
    state_machine_branch 2_B
};
state_machine_callback state_machine_C_methods[] = {
    0,
    0,
    state_machine_branch 2_C
};
state_machine_callback state_machine_receive==tb_methods[] = {
    0,
    state_machine_branch 1_receive==tb,
    0
};
state_machine_callback state_machine_udtl_methods[] = {
    0,
    state_machine_branch 1_udtl,
    0
};
state_machine_callback state_machine_udtl_header_methods[] = {
    0,
    state_machine_branch 1_udtl_header,
    0
};
int state_machine_A(int* machine) {
    state_machine_callback fun;
    int next;
    if (machine == 0) return 0;
    if (*machine <= 0 || *machine > 2) return 0;
    fun = state_machine_A_methods[*machine];
    if (!fun) return 0;
    next = fun();
    *machine = next;
    return 1;
}
int state_machine_B(int* machine) {
    state_machine_callback fun;
    int next;
    if (machine == 0) return 0;
    if (*machine <= 0 || *machine > 2) return 0;
    fun = state_machine_B_methods[*machine];
    if (!fun) return 0;
    next = fun();
    *machine = next;
    return 1;
}
int state_machine_C(int* machine) {
    state_machine_callback fun;
    int next;
    if (machine == 0) return 0;
    if (*machine <= 0 || *machine > 2) return 0;
    fun = state_machine_C_methods[*machine];
    if (!fun) return 0;
    next = fun();
    *machine = next;
    return 1;
}
int state_machine_receive==tb(int* machine) {
    state_machine_callback fun;
    int next;
    if (machine == 0) return 0;
    if (*machine <= 0 || *machine > 2) return 0;
    fun = state_machine_receive==tb_methods[*machine];
    if (!fun) return 0;
    next = fun();
    *machine = next;
    return 1;
}
int state_machine_udtl(int* machine) {
    state_machine_callback fun;
    int next;
    if (machine == 0) return 0;
    if (*machine <= 0 || *machine > 2) return 0;
    fun = state_machine_udtl_methods[*machine];
    if (!fun) return 0;
    next = fun();
    *machine = next;
    return 1;
}
int state_machine_udtl_header(int* machine) {
    state_machine_callback fun;
    int next;
    if (machine == 0) return 0;
    if (*machine <= 0 || *machine > 2) return 0;
    fun = state_machine_udtl_header_methods[*machine];
    if (!fun) return 0;
    next = fun();
    *machine = next;
    return 1;
}
int make_state_machine(void) { return 1; }




static int state_machine_branch 1_receive==tb() {
    // item 45
    return STATE_MACHINE_BRANCH 2;
    
}

static int state_machine_branch 1_udtl() {
    // item 58
    return STATE_MACHINE_BRANCH 1;
    
}

static int state_machine_branch 1_udtl_header() {
    // item 59
    return 999;
    
}

static int state_machine_branch 2_A() {
    // item 48
    return 999;
    
}

static int state_machine_branch 2_B() {
    // item 67
    return STATE_MACHINE_BRANCH 2;
    
}

static int state_machine_branch 2_C() {
    // item 68
    return 999;
    
}



