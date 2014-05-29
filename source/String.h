#ifndef STRING_H
#define STRING_H

typedef struct {
	char* rep;
	int n;
	int capacity;
} String;

String* String_new(char*);

String* String_set(String*, char*);

String* String_setString(String*, String*);

String* String_append(String*, char*);

String* String_appendString(String*, String*);

char* String_get(String*);

void String_delete(String*);

#endif