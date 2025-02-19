#include <stdio.h>

int main() {
    int n = 4, i, j, temp;
    int p[] = {1, 2, 3, 4};
    int at[] = {0, 1, 2, 3};
    int bt[] = {4, 3, 1, 2};
    int ct[4], tat[4], wt[4];
    float totalTAT = 0, totalWT = 0;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(at[j] > at[j+1]) {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("Avg TAT = %.2f\nAvg WT = %.2f\n", totalTAT / n, totalWT / n);
    return 0;
}
