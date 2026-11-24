#include <stdio.h>

struct protocol {
	unsigned int flags: 4;
	unsigned int checksum: 6;
};

int main(int argc, char* argv[]){
	struct protocol prot;
	prot.flags = 7;
	
	printf("Size: %u\n", sizeof(prot));
	printf("Flags: %u\n", prot.flags);
	prot.flags = 17u;
	printf("Flags: %u\n", prot.flags);

	return 0;
}
