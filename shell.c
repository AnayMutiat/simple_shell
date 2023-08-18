#include "shell.h"

/**
 * she_starter - command to start shell
 * @argc: arguments counter
 * @argv: arguments passed
 * @env: environment pointer
 * Return: 0
 */

int she_starter(int argc, char **argv)
{
        size_t n = 0;
        char *prompt = NULL, *prompt_cpy = NULL, *token = NULL;
        const char *delim = " \n";
	int i = 0;

        while(1)
        {
                if(isatty(STDIN_FILENO))
                {
                        write(1, "AI~$ ", 13);
                }
                if (getline(&prompt, &n, stdin) == 1)
                        return -1;
        }
        prompt_cpy = strdup(prompt);
        token = strtok (prompt, delim);
        while(token == NULL)
        {
        token = strtok (NULL, delim);
        argc++;
        }
        argv = malloc(sizeof(char *) *argc);
        token = strtok (prompt_cpy, delim);
        while(token)
        {
                argv[1] = token;
                token = strtok (NULL, delim);
                i++;
        }
        argv[i] = NULL;
        i = 0;
        free(prompt);
        free(prompt_cpy);
        free(argv);

                return 0;
}
