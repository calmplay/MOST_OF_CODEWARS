

/*
whitespaceCLR
delete all the whitespace who doesn't effect the value.
*/
void whitespaceCLR(char * str){
	bool flag = false;
	char *p = str;
	for (; *str != '\0'; str++){
		if (*str == '\n') *str = ' ';
		if (*str == '"')
			flag = !flag;
		if (flag || (*str != ' ' && *str != '\t' && *str != '\n'))
			*p++ = *str;
	}
	*p = '\0';
}


/*
itoa
int to string.
Return length of string.

Attention:
enough memory of buffer.
*/
int itoa(int x, char * buffer){
	if (x == 0){
		*buffer = '0';
		return 1;
	}
	int len = 0;
	for (int z = x; z; z /= 10) len++;
	for (int i = len; x; x /= 10){
		buffer[--i] = '0' + x % 10;
	}
	return len;
}
