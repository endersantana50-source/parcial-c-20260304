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
    int mat[30][30];          /* matriz de datos (no se modifica) */
    int i, j;

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

    /* Etapa 1: solo lectura y validacion; los calculos vienen despues */
    return 0;
}
