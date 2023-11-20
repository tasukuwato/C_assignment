#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year, month, day;
    double power[24];
    int count[24];
} DailyPowerData;

int main() {
    FILE* file = fopen("juyo-2014.csv", "r");
    if (!file) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    char line[1024];
    DailyPowerData data[92]; // 7月から9月の最大日数
    int dataCount = 0;

    // ヘッダー行を読み飛ばす
    fgets(line, 1024, file);

    while (fgets(line, 1024, file)) {
        char* token;
        int year, month, day, hour;
        double power;

        // 日付の解析
        token = strtok(line, "/");
        year = strtol(token, NULL, 10);

        token = strtok(NULL, "/");
        month = strtol(token, NULL, 10);

        token = strtok(NULL, " ,");
        day = strtol(token, NULL, 10);

        // 時刻の解析
        token = strtok(NULL, ":");
        hour = strtol(token, NULL, 10);

        // 消費電力の解析
        token = strtok(NULL, ",");
        power = strtod(token, NULL);

        // 2014年7月から9月のデータのみを処理
        if (year == 2014 && month >= 7 && month <= 9) {
            // 日付ごとのデータを検索
            int found = 0;
            for (int i = 0; i < dataCount; i++) {
                if (data[i].year == year && data[i].month == month && data[i].day == day) {
                    data[i].power[hour] += power;
                    data[i].count[hour]++;
                    found = 1;
                    break;
                }
            }

            // 新しい日付の場合、データを追加
            if (!found) {
                DailyPowerData newDay = { year, month, day };
                newDay.power[hour] = power;
                newDay.count[hour] = 1;
                data[dataCount++] = newDay;
            }
        }
    }

    fclose(file);

    // 結果を計算し表示
    double totalPower[24] = { 0 };
    int totalCount[24] = { 0 };
    for (int i = 0; i < dataCount; i++) {
        for (int j = 0; j < 24; j++) {
            totalPower[j] += data[i].power[j];
            totalCount[j] += data[i].count[j];
        }
    }

    printf("2014年: ");
    for (int i = 0; i < 24; i++) {
        if (totalCount[i] > 0) {
            printf("%d ", (int)(totalPower[i] / totalCount[i]));
        }
    }
    printf("\n");

    return 0;
}
