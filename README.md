# Rivest-Cipher-4
Simple Rivest Cipher 4 In C

```c
#include "rc4.h"
#include <stdio.h>

int main(void)
{
	unsigned char message[] = "Plaintext";
	unsigned char key[] = "Key";
	unsigned char output_buffer[0x100] = {0};
	unsigned char uncipher_buffer[0x100] = {0};

 	if (RC4_cipher(message, key, output_buffer, 0xFF, 3))
	 	fprintf(stderr,"[-] Error RC4 cipher function call !\n");
		
	// Print Cipher bytes
	printf("[+] Cipher Text : ");
	print_hex(output_buffer);
	printf("\t(%s)\n", message);

	// Uncipher output_buffer with the same key
	RC4_cipher(output_buffer, key, uncipher_buffer, 0xFF, 3);

	printf("[+] Uncipher Text : ");
	// Print UnCipher bytes
	print_hex(uncipher_buffer);
	
	printf("\t(%s)\n", uncipher_buffer);

	return (0);
}
```
