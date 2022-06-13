
int string_hash(void *string)
{
	/* This is the djb2 string hash function */

	int result = 5381;
	unsigned char *p;

	p = (unsigned char *) string;

	while (*p != '\0') {
		result = (result << 4) + result*2 + *p;
		++p;
	}

	return result;
}
