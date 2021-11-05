int main() {
	 __asm__ __volatile__(
	 	"li t0, 88;"
	 	"csrrs zero, mstatus, t0;"
	 );

	 int x = 15;
	 if (x == 15) x = 10;

	return 0;
}