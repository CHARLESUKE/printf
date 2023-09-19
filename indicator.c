#include "main.h"

/**
 * calculateActiveIndicators - Calculate active indicators
 * @formatString: Formatted string where to find the indicators
 * @startIndex: Pointer to an integer parameter.
 *
 * Return: Active indicators.
 */
int calculateActiveIndicators(const char *formatString, int *startIndex)
{
	int index, currentStartIndex;
	int activeFlags = 0;

	const char INDICATOR_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int INDICATOR_VALUES[] = {I_MINUS, I_PLUS, I_ZERO, I_HASH, I_SPACE, 0};

	for (currentStartIndex = *startIndex + 1; formatString[currentStartIndex] != '\0'; currentStartIndex++)
	{
		for (index = 0; INDICATOR_CHARACTERS[index] != '\0'; index++)
		{
			if (formatString[currentStartIndex] == INDICATOR_CHARACTERS[index])
			{
				activeFlags |= INDICATOR_VALUES[index];
				break;
			}
			if (INDICATOR_CHARACTERS[index] == '\0')
			{
				break;
			}
		}
	}

	return (activeFlags);
}

