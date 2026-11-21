#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 70.0
#define MAX_TORQUE 50.0
#define FILENAME "robot_log.txt"

struct RobotRecord
{
    int id;
    float angle1, angle2, angle3;
    float temperature;
    float torque;
    char status[10];
};

int main()
{
    struct RobotRecord r;
    FILE *fp;

    printf("Enter Record ID: ");
    scanf("%d", &r.id);

    printf("Enter Joint Angles (theta1 theta2 theta3): ");
    scanf("%f %f %f", &r.angle1, &r.angle2, &r.angle3);

    printf("Enter Motor Temperature (C): ");
    scanf("%f", &r.temperature);

    printf("Enter Torque (N-m): ");
    scanf("%f", &r.torque);

    printf("Enter Operational Status (RUN / IDLE / ERROR): ");
    scanf("%9s", r.status);

    fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "%d %.1f %.1f %.1f %.1f %.1f %s\n",
            r.id, r.angle1, r.angle2, r.angle3,
            r.temperature, r.torque, r.status);
    fclose(fp);

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    int alert_count = 0;

    printf("\n=== Robotic Arm Performance Report ===\n");

    while (fscanf(fp, "%d %f %f %f %f %f %9s",
                  &r.id, &r.angle1, &r.angle2, &r.angle3,
                  &r.temperature, &r.torque, r.status) == 7)
      {

        int temp_alert = (r.temperature > MAX_TEMP);
        int torque_alert = (r.torque > MAX_TORQUE);
        int status_alert = (strcmp(r.status, "ERROR") == 0);

        if (temp_alert || torque_alert || status_alert) 
        {
            alert_count++;
            printf("Record %d : ALERT -> ", r.id);

            int first = 1;
            if (temp_alert) {
                printf("High Temperature (%.1f °C)", r.temperature);
                first = 0;
            }
            if (torque_alert)
            {
                if (!first) printf(",\n                    ");
                printf("Excessive Torque (%.1f N-m)", r.torque);
                first = 0;
            }
            if (status_alert)
            {
                if (!first) printf(",\n                    ");
                printf("System ERROR");
            }
            printf("\n");
        }
    }

    if (alert_count >= 2) 
    {
        printf("Possible Mechanical Failure Detected!\n");
        printf("(Repeated abnormal conditions)===\n");
    } else {
        printf("======================================\n");
    }

    fclose(fp);
    return 0;
}

```
