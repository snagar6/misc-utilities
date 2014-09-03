/* Simple check to see if a 64 address in Canonical or not */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

void x86_mmu_check_map_addr(unsigned long long address)
{
        unsigned long long addr = (unsigned long long)address;
        unsigned int addr_width = 48;

        if(addr >> (addr_width-1)) { 
                if((addr >> (addr_width-1)) ^ ((1ul << (64-(addr_width-1))) -1)) {
			printf(" Addr: 0x%llx Result: NON-canonical Address\n\n", addr);
			return;
		}
	}

	printf(" Addr: 0x%llx Result: Canonical Address\n\n", addr);		
}

void main() {

/* Test cases */
	x86_mmu_check_map_addr(0x00007fffffffffff);
	x86_mmu_check_map_addr(0xffffffffffffffff);
	x86_mmu_check_map_addr(0x0);
	x86_mmu_check_map_addr(0xffff800000000000);
	x86_mmu_check_map_addr(0xff78810000000001);
	x86_mmu_check_map_addr(0x0000800000000000);
	x86_mmu_check_map_addr(0x00010000ffff0011);
	x86_mmu_check_map_addr(0xee01800011115555);
	x86_mmu_check_map_addr(0xffff700000000000);
	x86_mmu_check_map_addr(0xfffff00000000000);
}
