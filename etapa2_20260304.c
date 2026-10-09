/*
 * Reto 20 - Filtrado: reduccion entre etapas consecutivas
 * Matricula: 20260304
 *
 * Regla: desde la segunda fila, un valor x es evento si la reduccion
 * respecto a la fila anterior (v - x) esta entre L y U (inclusive).
 * Impacto del evento: v - x + 1.
 */
#include <stdio.h>

int main(void)
{
    int N, M, L, U;
    int mat[30][30];          /* matriz de datos (no se modifica)  */
    int eventos[30];          /* cantidad de eventos por fila      */
    long impacto[30];         /* suma de impactos por fila         */
    int colEv[30];            /* eventos por columna               */
    int i, j, v, x;

    /* ---------- Lectura y validacion de encabezado ---------- */
    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }
    if (N < 1 || N > 30 || M < 1 || M > 30 ||
        L < 0 || L > 1000 || U < 0 || U > 1000 || L > U) {
        printf("ERROR\n");
        return 0;
    }

    /* ---------- Lectura y validacion de la matriz ---------- */
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (scanf("%d", &mat[i][j]) != 1 ||
                mat[i][j] < 0 || mat[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    for (j = 0; j < M; j++)
        colEv[j] = 0;

    /* ---------- Eventos e impactos por fila ---------- */
    for (i = 0; i < N; i++) {
        eventos[i] = 0;
        impacto[i] = 0;
        for (j = 0; j < M; j++) {
            x = mat[i][j];
            /* i >= 1 evita acceder a la fila -1 (la fila 1 no genera eventos) */
            if (i >= 1) {
                v = mat[i - 1][j];
                if (v - x >= L && v - x <= U) {
                    eventos[i]++;
                    impacto[i] += v - x + 1;
                    colEv[j]++;
                }
            }
        }
    }

    /* Salida parcial (etapa 2): aun sin rachas ni prioridad */
    for (i = 0; i < N; i++)
        printf("FILA %d EVENTOS %d IMPACTO %ld\n", i + 1, eventos[i], impacto[i]);
    printf("COLUMNAS");
    for (j = 0; j < M; j++)
        printf(" %d", colEv[j]);
    printf("\n");

    return 0;
}
