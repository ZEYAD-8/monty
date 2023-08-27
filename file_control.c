#include "monty.h"

/**
 * tokenize_file - tokenizes the file and updates global structure lines.m
 * @filepath: the provided path by the user
 * Return: nothing.
*/
void tokenize_file(const char *filepath)
{
	int numwords, linesCount, lineIndex;
	char buffer[1024];
	char **words;
	FILE *file = fopen(filepath, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filepath);
		exit(EXIT_FAILURE);
	}
	numwords = 0;
	linesCount = count_lines(file);
	lines_m.lines_count = linesCount;

	lines_m.lines = (char ***)malloc(linesCount * sizeof(char **));
	lineIndex = 0;
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		words = tokenize_line(buffer, &numwords);
		lines_m.lines[lineIndex] = words;
		lines_m.word_line[lineIndex] = numwords;
		lineIndex++;
	}
	fclose(file);
}

/**
 * tokenize_line - tokenizes the line provided
 * @line: the provided line to be tokenized
 * @numwords: to be updated with the number words
 *
 * Return: an array of the words in the line
*/
char **tokenize_line(char *line, int *numwords)
{
	int len, wordCount;
	char *token, **words;

	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	words = (char **)malloc(MAX_WORDS_PER_LINE * sizeof(char *));
	wordCount = 0;
	token = strtok(line, " ");
	while (token != NULL)
	{
		len = strlen(token);
		words[wordCount] = malloc(len * sizeof(char));
		strcpy(words[wordCount], token);
		wordCount++;
		token = strtok(NULL, " ");
	}
	words[wordCount] = NULL;
	*numwords = wordCount;
	return (words);
}

/**
 * count_lines - counts the number of lines in file
 * @file: the provided file to count the lines from
 * Return: the number of lines in file
*/
int count_lines(FILE *file)
{
	int linesCount;
	int c;

	linesCount = 0;
	while ((c = fgetc(file)) != EOF)
		if (c == '\n')
			linesCount++;

	if (c != '\n' && linesCount > 0)
		linesCount++;

	rewind(file);
	return (linesCount);
}

