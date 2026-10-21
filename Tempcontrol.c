#include <stdio.h>

int update_fan(float temp, int previous_fan, float on_temp, float off_temp) {
    if (temp >= on_temp) {
        return 1;
    }
    else if (temp <= off_temp) {
        return 0;
    }
    else {
        return previous_fan;
    }
}

int main (void) {

float temp;
int i;
int fan = 0;
const float fan_on_temp = 80;
const float fan_off_temp = 75;
const float overheat_temp = 95;
const float sensor_min = -40;
const float sensor_max = 125;
float readings[] = {74, 78, 60, 80, 76, 79, 96, 126};
int reading_count = sizeof(readings)/sizeof(readings[0]);
FILE *log_file = fopen("temperature_log.csv", "w");

if (log_file == NULL) {
    printf("Could not open log file\n");
    return 1;
}

fprintf(log_file, "reading,temperature,fan\n");

for (i = 0; i < reading_count; i++) {

temp = readings[i];   

if (temp < sensor_min || temp > sensor_max) {
    printf("Sensor reading out of range\n");
    fclose(log_file);
    return 1;
}

else if (temp >= overheat_temp) {
    printf("Warning Overheating\n");
}

fan = update_fan(temp, fan, fan_on_temp, fan_off_temp);

fprintf(log_file, "%d,%.1f,%d\n", i + 1, temp, fan);

if (fan == 1) {
    printf("Temperature: %.1f F | Fan On\n", temp);
}

else if (fan == 0) {
    printf("Temperature: %.1f F | Fan Off\n", temp);
}
}

fclose(log_file);

return 0;
}