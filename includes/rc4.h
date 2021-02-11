#pragma once

//////////////////////////////////////////
//      print hex function
/////////////////////////////////////////

void print_hex(unsigned char *str);


///////////////////////////////////////
// RC4 Cipher function
//////////////////////////////////////

unsigned int RC4_cipher(unsigned char *input, unsigned char *key, unsigned char *buffer, unsigned long buffer_size, unsigned long size_key);