#ifndef _CYCLES_H
#define _CYCLES_H

#define FREQ_MAX 3600000000

#include <stdint.h>

static inline uint64_t cycle_start(void)
{
	uint32_t cycles_low, cycles_high;

	asm volatile (
#if defined(__i386__)
        "pushl %%ebx;\n\t"
#endif
		"cpuid\n"
		"rdtsc\n"
		"movl %%eax, %0\n"
		"movl %%edx, %1\n"
#if defined(__i386__)
        "popl %%ebx;\n\t"
#endif
		: "=r" (cycles_low), "=r" (cycles_high)
		:
		: "%rax",
#if !defined(__i386__)
        "%rbx",
#endif
        "%rcx", "%rdx");

	return (uint64_t) cycles_high << 32 | (uint64_t) cycles_low;
}

static inline uint64_t cycle_stop(void)
{
	uint32_t cycles_low, cycles_high;

	asm volatile (
		"rdtscp\n"
		"movl %%eax, %0\n"
		"movl %%edx, %1\n"
		"cpuid\n"
		: "=r" (cycles_low), "=r" (cycles_high)
		:
		: "%rax", "%rbx", "%rcx", "%rdx"
	);

	return (uint64_t) cycles_high << 32 | (uint64_t) cycles_low;
}

static inline double cycle_time(uint64_t cycles)
{
	return (double) cycles / (double) FREQ_MAX;
}

#endif

