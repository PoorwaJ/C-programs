#include <stdio.h>
#include <string.h>

struct Robot {
    int id;
    char type[50];
    float capacity;
    float load;
    float time;
};

int main() {
    int n, i;

    printf("Enter the number of robots: ");
    if (scanf("%d", &n) != 1) return 1;

    struct Robot robots[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Robot %d ---\n", i + 1);

        printf("Robot ID: ");
        scanf("%d", &robots[i].id);

        printf("Robot Type: ");

        getchar();
        fgets(robots[i].type, sizeof(robots[i].type), stdin);

        robots[i].type[strcspn(robots[i].type, "\n")] = 0;

        printf("Payload Capacity (kg): ");
        scanf("%f", &robots[i].capacity);

        printf("Actual Load (kg): ");
        scanf("%f", &robots[i].load);

        printf("Operating Time (hrs): ");
        scanf("%f", &robots[i].time);
    }

    printf("\n================ ROBOT UTILIZATION REPORT ================\n");
    printf("%-5s %-15s %-12s %-10s %-12s %-12s\n", "ID", "Type", "Capacity", "Load", "Utiliz %", "Status");
    printf("----------------------------------------------------------\n");

    for (i = 0; i < n; i++) {

        float utilization = (robots[i].load / robots[i].capacity) * 100.0;

        char status[20];
        if (robots[i].load > robots[i].capacity) {
            strcpy(status, "Overloaded");
        } else {
            strcpy(status, "Within limit");
        }

        printf("%-5d %-15s %-12.2f %-10.2f %-12.2f %-12s\n",
               robots[i].id,
               robots[i].type,
               robots[i].capacity,
               robots[i].load,
               utilization,
               status);
    }

    return 0;
}

