#include <stdio.h>
#define MIN_DISTANCE 20

int findNearest(int *distance, int n)
{
    int min = *distance;

    for (int i = 1; i < n; i++)
    {
        if (*(distance + i) < min)
        {
            min = *(distance + i);
        }
    }
    return min;
}

int main()
{
    int s;
    printf("Enter number of sensors: ");
    scanf("%d", &s);

    int distance[s];
    for (int i = 0; i < s; i++)
    {
        printf("Sensor %d distance: ", i + 1);
        scanf("%d", (distance + i));
    }

    int mindist = findNearest(distance, s);
    printf("Nearest object = %d\n", mindist);

    if (mindist < MIN_DISTANCE)
    {
        printf("Warning\n");
    }
    else
    {
        printf("Path is clear\n");
    }
}
```[cite: 3]
