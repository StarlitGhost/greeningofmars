#include "Files.h"

#include <stdlib.h>
#include <iostream>

char* Files::ReadText(const char *fileName)
{
	char* text;

	if (fileName != NULL) {
		FILE *file = fopen(fileName, "rt");

		if (file != NULL) {
			fseek(file, 0, SEEK_END);
			int count = ftell(file);
			rewind(file);

			if (count > 0) {
				text = (char*)malloc(sizeof(char) * (count + 1));
				count = fread(text, sizeof(char), count, file);
				text[count] = '\0';
			}
			fclose(file);
		}
	}
	return text;
}