#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

char* readJsonFile(const char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro ao abrir o file %s.\n", fileName);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *content = (char*)malloc((size + 1) * sizeof(char));
    fread(content, sizeof(char), size, file);
    content[size] = '\0';

    fclose(file);
    return content;
}

int main() {
    char* data = readJsonFile("dados.json");
    cJSON *json = cJSON_Parse(data);

    if (json == NULL) {
        printf("Erro ao processar o JSON.\n");
        exit(1);
    }

    int totalDyas = cJSON_GetArraySize(json);
    double smallestInvoice = 0;
    double biggestInvoice = 0;
    double sumInvoice = 0;
    int daysWithValue = 0;
    int daysAboveAverage = 0;

    for (int i = 0; i < totalDyas; i++) {
        cJSON *day = cJSON_GetArrayItem(json, i);
        double value = cJSON_GetObjectItem(day, "valor")->valuedouble;

        if (value > 0) {
            if (value < smallestInvoice || smallestInvoice == 0) {
                smallestInvoice = value;
            }
            if (value > biggestInvoice || biggestInvoice == 0) {
                biggestInvoice = value;
            }
            sumInvoice += value;
            daysWithValue++;
        }
    }

    double avgInvoice = sumInvoice / daysWithValue;

    for (int i = 0; i < totalDyas; i++) {
        cJSON *day = cJSON_GetArrayItem(json, i);
        double value = cJSON_GetObjectItem(day, "valor")->valuedouble;

        if (value > avgInvoice) {
            daysAboveAverage++;
        }
    }

    printf("Menor valor de faturamento: %.2f\n", smallestInvoice);
    printf("Maior valor de faturamento: %.2f\n", biggestInvoice);
    printf("Numero de dias com faturamento acima da media: %d\n", daysAboveAverage);
    getchar();

    cJSON_Delete(json);
    free(data);

    return 0;
}
