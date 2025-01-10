#include <stdio.h>
#include <stdlib.h>


struct sensor {
    short temp;
    unsigned short minute;
    unsigned short hour;
    unsigned short day;
    unsigned short month;
    unsigned int year;
};

struct result {
    short min_temp;
    short med_temp;
    short max_temp;
    unsigned short month;
    unsigned int year;
};

int file_size_str(FILE *fp);
int data_array_sensor(FILE *fp, struct sensor data[]);
static int error_scanf(struct sensor d_sensor, int d);
int max_temp_year(struct sensor data[], int size);
int min_temp_year(struct sensor data[], int data_size);
int med_temp_year(struct sensor data[], int data_size);
short max_temp_month(struct sensor data[], int data_size, int month);
short min_temp_month(struct sensor data[], int data_size, int month);
short med_temp_month(struct sensor data[], int data_size, int month);
struct result static_month(struct sensor data[], int data_size, unsigned short month);
void print_result(struct result res, int n);
void print_result_year(struct sensor data[], int data_size);