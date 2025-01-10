#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"


int main(int argc, char *argv[]) {
    FILE *fp;
    struct sensor *data;
    struct result res_month;
    int res;
    int data_size;
    unsigned short month = 0;
    unsigned int year = 0;
    unsigned int size_str;

    if (argc == 1) {
        printf("    -h справка\n");
        exit(0);
    }

    while ((res = getopt(argc, argv, "hf:m:")) != -1) {
        switch (res) {
            case 'h':
                printf("    -h справка\n");
                printf("    -f <файл>\n");
                printf("    -m <номер месяца> вся статистика за месяц\n");
                exit(0);
            case 'f':
                fp = fopen(optarg, "r");
                if (fp == NULL) {
                    printf("Ошибка открытия файла %s\n", optarg);
                    exit(1);
                }
                year = 1;
                break;
            case 'm':
                if (atoi(optarg) >= 1 && atoi(optarg) <= 12) {
                    month = atoi(optarg);
                } else {
                    printf("Не верно указан месяц\n");
                }
                year = 0;
                break;
        }
    }

    size_str = file_size_str(fp);
    if ((data = malloc(size_str * sizeof(struct sensor))) != NULL) {
        data_size = data_array_sensor(fp, data);
    }

    if (month && !year) {
        printf("=========================================\n");
        printf("#   Year Month MonthAvg MonthMax MonthMin\n");
        res_month = static_month(data, data_size, month);
        print_result(res_month, 1);
    }

    if (!month && year) {
        printf("=========================================\n");
        printf("#   Year Month MonthAvg MonthMax MonthMin\n");
        for (int n = 1; n <= 12; n++) {
            res_month = static_month(data, data_size, n);
            print_result(res_month, n);
        }
        printf("=========================================\n");
        print_result_year(data, data_size);
    }

    free(data);
    fclose(fp);

    return 0;
}