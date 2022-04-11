#include <stdio.h>
int main(void){
    int seiseki[5][2] = {
        /* {数学，物理} */
        {72,48}, /* 生徒A */
        {88,39}, /* 生徒B */
        {72,91}, /* 生徒C */
        {81,82}, /* 生徒D */
        {68,78}  /* 生徒E */
    };
    
    int size = sizeof(seiseki)/sizeof(int)/2; /* 人数 */
    
    int max[2];
    max[0] = 0; /* 数学最大値 */
    max[1] = 0; /* 物理最大値 */
    
    int min[2];
    min[0] = 1000; /* 数学最小値 */
    min[1] = 1000; /* 物理最小値 */
    
    int sum_subject[2];
    sum_subject[0] = 0; /* 数学合計 */
    sum_subject[1] = 0; /* 物理合計 */
    
    int sum_individual[5]; /* 個人合計点数 */
    int max_sum_individual = 0; /* 個人合計点数の最大値 */

    /* 人数ごとに繰り返す */
    for(int i = 0; i < size; i++){ 
        sum_individual[i] = 0; /* 個人合計点数初期化 */
        /* 教科ごとに繰り返す */
        for(int j = 0; j < 2; j++){
            sum_individual[i] += seiseki[i][j]; /* 個人合計値の更新 */
            sum_subject[j] += seiseki[i][j]; /* 教科合計値の更新 */
            
            /* 最大値の更新 */
            if(seiseki[i][j] > max[j]){
                max[j] = seiseki[i][j]; 
            }
            
            /* 最小値の更新 */
            if(seiseki[i][j] < min[j]){
                min[j] = seiseki[i][j];
            }
        }
        /* 個人合計点数最大値の更新 */
        if(max_sum_individual < sum_individual[i]){
            max_sum_individual = sum_individual[i];
        }
    }

    /* 平均値 */
    float ave[2];
    ave[0] = (float)sum_subject[0] / (float)size; /* 数学 */
    ave[1] = (float)sum_subject[1] / (float)size; /* 物理 */
    
    printf(
        "数学\n"
        "最大値は%d点\n"
        "最小値は%d点\n"
        "平均値は%f点\n"
        ,max[0],min[0],ave[0]
    );
    printf(
        "物理\n"
        "最大値は%d点\n"
        "最小値は%d点\n"
        "平均値は%f点\n"
        ,max[1],min[1],ave[1]
    );
    
    printf("数学と物理の合計が最も高い生徒の点数は\n");
    for(int i = 0; i < size; i++ ){
        if(sum_individual[i] == max_sum_individual){
            printf(
                "数学%d点,物理%d点\n"
                ,seiseki[i][0]
                ,seiseki[i][1]
            );
        }
    }
    printf("の合計%d点",max_sum_individual);
    
}
