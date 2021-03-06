#include <stdio.h>
#include <fcntl.h>


void main(void) {
	FILE *fp;

	#asm
	phk
	plb
	#endasm

	fputs("hello, world\n", stdout);

	fp = fopen("file.txt", "wb");
	fclose(fp);
}

// these stubs are not provided in the library but could call gs/os.

int open(const char *name, int mode) {
	return -1;
}

int close(int fd) {
	return -1;
}


size_t read(int fd, void *buffer, size_t count) {

static struct {
	unsigned pCount;
	unsigned refNum;
	void *dataBuffer;
	unsigned long requestCount;
	unsigned long transferCount;
	unsigned cachePriority;
} dcb;


	unsigned tool_error = 0x0043;

	dcb.pCount = 4;
	dcb.refNum = fd+1;
	dcb.dataBuffer = buffer;
	dcb.requestCount = count;
	#asm
	pea #^%%dcb
	pea #%%dcb
	pea #$2012
	jsl $e100b0
	sta %%tool_error;
	#endasm
	if (tool_error) return -1;
	return dcb.transferCount;

}

size_t write(int fd, void *buffer, size_t count) {

static struct {
	unsigned pCount;
	unsigned refNum;
	void *dataBuffer;
	unsigned long requestCount;
	unsigned long transferCount;
	unsigned cachePriority;
} dcb;


	unsigned tool_error = 0x0043;

	dcb.pCount = 4;
	dcb.refNum = fd+1;
	dcb.dataBuffer = buffer;
	dcb.requestCount = count;
	#asm
	pea #^%%dcb
	pea #%%dcb
	pea #$2013
	jsl $e100b0
	sta %%tool_error;
	#endasm
	if (tool_error) return -1;
	return dcb.transferCount;
}

long lseek(int fd, long offset, int whence) {
	return -1;
}

int creat(const char *name, int mode) {
	return -1;
}

int unlink(const char *name) {
	return -1;
}

int isatty(int fd) {
	return -1;
}


#pragma section udata=heap
char __heap[8192];
void *heap_start = (void *)__heap;
void *heap_end = (void *)&__heap[8092];
