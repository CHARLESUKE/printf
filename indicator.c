#include "main.h"

/**
 * _ind - Calculate active indicators
 * @format: Formatted string where to print the arguments
 * @i: Pointer to an integer parameter.
 * 
 * Return: Indicator.
 */
int _ind(const char *format, int *i)
{
    int j, curr_i;
    int flags = 0;

    const char INDICATOR_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int INDICATOR_ARR[] = {I_MINUS, I_PLUS, I_ZERO, I_HASH, I_SPACE, 0};

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        for (j = 0; INDICATOR_CH[j] != '\0'; j++)
        {
            if (format[curr_i] == INDICATOR_CH[j])
            {
                flags |= INDICATOR_ARR[j];
                break;
            }
        }

        if (INDICATOR_CH[j] == '\0')
            break;
    }

    return flags;
}
