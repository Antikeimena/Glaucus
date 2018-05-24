#ifndef TOOLS_H
#define TOOLS_H

extern void tools_setup(void);
extern uint32_t tools_millis_since(uint32_t in);
extern bool must_run(uint32_t in, uint32_t duration);

#endif
