#include "temp_functions.h"

#define SIZE 30


int data_array_sensor(FILE *fp, struct sensor data[]) {
    struct sensor d_sensor = {0, 0, 0, 0, 0, 0};
    char c[SIZE];
    int data_count = 0;
    int number_string = 1;
    int d;

    while ((d = fscanf(fp, "%d;%hd;%hd;%hd;%hd;%hd",
                       &d_sensor.year,
                       &d_sensor.month,
                       &d_sensor.day,
                       &d_sensor.hour,
                       &d_sensor.minute,
                       &d_sensor.temp)) > 0) {

        if (error_scanf(d_sensor, d)) {
            data[data_count].year = d_sensor.year;
            data[data_count].month = d_sensor.month;
            data[data_count].day = d_sensor.day;
            data[data_count].hour = d_sensor.hour;
            data[data_count].minute = d_sensor.minute;
            data[data_count].temp = d_sensor.temp;
            data_count++;
        } else {
            fscanf(fp, "%[^\n]", c);
            printf("error in the line = %d\n", number_string);
        }
        number_string++;
    }
    return data_count;
}

static int error_scanf(struct sensor d_sensor, int d) {
    if ((d < 6) ||
        (d_sensor.year < 1972 || d_sensor.year > 9999) ||
        (d_sensor.month < 1 || d_sensor.month > 12) ||
        (d_sensor.day < 1 || d_sensor.day > 31) ||
        (d_sensor.hour < 0 || d_sensor.hour > 23) ||
        (d_sensor.minute < 0 || d_sensor.minute > 59) ||
        (d_sensor.temp < -99 || d_sensor.temp > 99)) {
        return 0;
    }
    return 1;
}

int max_temp_year(struct sensor data[], int data_size) {
    int max = -99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].temp > max) {
            max = data[i].temp;
        }
    }
    return max;
}

int min_temp_year(struct sensor data[], int data_size) {
    int min = 99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].temp < min) {
            min = data[i].temp;
        }
    }
    return min;
}

int med_temp_year(struct sensor data[], int data_size) {
    int med_temp;
    int tmp = 0;

    for (int i = 0; i < data_size; i++) {
        tmp += data[i].temp;
    }

    med_temp = tmp / data_size;
    return med_temp;
}

short max_temp_month(struct sensor data[], int data_size, int month) {
    int max_temp = -99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].month == month && data[i].temp > max_temp) {
            max_temp = data[i].temp;
        }
    }

    return max_temp;
}

short min_temp_month(struct sensor data[], int data_size, int month) {
    int min_temp = 99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].month == month && data[i].temp < min_temp) {
            min_temp = data[i].temp;
        }
    }

    return min_temp;
}

short med_temp_month(struct sensor data[], int data_size, int month) {
    short med_temp;
    int temp_count = 0;
    int tmp = 0;

    for (int i = 0; i < data_size; i++) {
        if (data[i].month == month) {
            tmp += data[i].temp;
            temp_count++;
        }
    }

    med_temp = tmp / temp_count;
    return med_temp;
}

struct result static_month(struct sensor data[], int data_size, unsigned short month) {
    struct result res = {0, 0, 0, 0, 0};

    res.min_temp = min_temp_month(data, data_size, month);
    res.med_temp = med_temp_month(data, data_size, month);
    res.max_temp = max_temp_month(data, data_size, month);

    for (int i = 0; i < data_size; i++) {
        if (data[i].month == month) {
            res.month = data[i].month;
            res.year = data[i].year;
            break;
        }
    }
    return res;
}

int file_size_str(FILE *fp) {
    int size_str = 0;

    while (!feof(fp)) {
        fscanf(fp, "%*[^\n]%*c");
        size_str++;
    }

    fseek(fp, SEEK_SET, 0);
    return size_str;
}

void print_result(struct result res_month, int n) {
    if (n < 10) {
        printf("%d %6d %3d %7d %7d %9d\n",
               n,
               res_month.year,
               res_month.month,
               res_month.med_temp,
               res_month.max_temp,
               res_month.min_temp);
    } else {
        printf("%d %5d %3d %7d %7d %9d\n",
               n,
               res_month.year,
               res_month.month,
               res_month.med_temp,
               res_month.max_temp,
               res_month.min_temp);
    }
}

void print_result_year(struct sensor data[], int data_size) {
    printf("YearAvg=%d YearMax=%d YearMin=%d",
           med_temp_year(data, data_size),
           max_temp_year(data, data_size),
           min_temp_year(data, data_size));
}